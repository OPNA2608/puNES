/*
 * gfx.c
 *
 *  Created on: 01/mar/2013
 *      Author: fhorse
 */

#include <d3d9.h>
#include "win.h"
#include "emu.h"
#include "palette.h"
#include "gfx.h"
#include "cfg_file.h"
#include "ppu.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

#define ntsc_width(wdt, a, flag)\
{\
	wdt = 0;\
	/*\
	if (filter == NTSC_FILTER) {\
		wdt = NES_NTSC_OUT_WIDTH(gfx.rows, a);\
		if (overscan.enabled) {\
			wdt -= (a - nes_ntsc_in_chunk);\
		}\
		if (flag) {\
			gfx.w[CURRENT] = wdt;\
			gfx.w[NO_OVERSCAN] = (NES_NTSC_OUT_WIDTH(SCR_ROWS, a));\
		}\
	}\
	*/\
}

enum { NO_POWER_OF_TWO, POWER_OF_TWO };

struct _d3d9 {
	LPDIRECT3D9 d3d;
	LPDIRECT3DDEVICE9 dev;
	LPDIRECT3DVERTEXBUFFER9 textured_vertex;
	LPDIRECT3DTEXTURE9 texture;
	D3DDISPLAYMODE display_mode;

	uint32_t *palette;
	GFX_EFFECT_ROUTINE;

	DWORD flags;
	BYTE bpp;
	BOOL auto_gen_mipmap;
	BOOL dynamic_texture;
	WORD texture_create_usage;
	int scale;
} d3d9;

typedef struct {
	FLOAT X, Y, Z, RHW;
	FLOAT TU, TV;
} CUSTOMVERTEX;
#define CUSTOMFVF (D3DFVF_XYZRHW | D3DFVF_TEX1)

BYTE d3d9_create_context(void);
BYTE d3d9_create_texture(LPDIRECT3DTEXTURE9 *texture, uint32_t width, uint32_t height,
        uint8_t interpolation, uint8_t pow);
int d3d9_power_of_two(int base);

BYTE gfx_init(void) {
	if (gui_create()) {
		fprintf(stderr, "gui initialization failed\n");
		return (EXIT_ERROR);
	}

	memset(&d3d9, 0x00, sizeof(d3d9));

	cfg->scale = X2;
	d3d9.scale = X1;

	{
		D3DCAPS9 d3dcaps;

		if ((d3d9.d3d = Direct3DCreate9(D3D_SDK_VERSION)) == NULL) {
			fprintf(stderr, "Unable to create d3d device\n");
			return (EXIT_ERROR);
		}

		if (IDirect3D9_GetAdapterDisplayMode(d3d9.d3d, D3DADAPTER_DEFAULT, &d3d9.display_mode)
		        != D3D_OK) {
			fprintf(stderr, "Unable to get adapter display mode\n");
			return (EXIT_ERROR);
		}

		{
			BOOL supported = FALSE;

			/* 32 bit */
			if ((d3d9.display_mode.Format == D3DFMT_X8R8G8B8)
					|| (d3d9.display_mode.Format == D3DFMT_A8R8G8B8)) {
				supported = TRUE;
				d3d9.bpp = 32;
			}
			/* 24 bit */
			if (d3d9.display_mode.Format == D3DFMT_R8G8B8) {
				supported = TRUE;
				d3d9.bpp = 24;
			}
			/* 16 bit */
			if ((d3d9.display_mode.Format == D3DFMT_A1R5G5B5)
					|| (d3d9.display_mode.Format == D3DFMT_X1R5G5B5)) {
				supported = TRUE;
				d3d9.bpp = 16;
			}
			/* 16 bit */
			if (d3d9.display_mode.Format == D3DFMT_R5G6B5) {
				supported = TRUE;
				d3d9.bpp = 16;
			}

			if (supported == FALSE) {
				fprintf(stderr, "Sorry but video mode < 16 bits are not supported\n");
				return (EXIT_ERROR);
			}
		}

		/* Check for hardware T&L */
		if (IDirect3D9_GetDeviceCaps(d3d9.d3d,
				D3DADAPTER_DEFAULT,
				D3DDEVTYPE_HAL,
				&d3dcaps) != D3D_OK) {
			fprintf(stderr, "Unable to get device caps\n");
			return (EXIT_ERROR);
		}

		/* The driver is capable of automatically generating mipmaps */
		/*
		 * The resource will automatically generate mipmaps. See Automatic
		 * Generation of Mipmaps (Direct3D 9). Automatic generation of mipmaps
		 * is not supported for volume textures and depth stencil
		 * surfaces/textures. This usage is not valid for a resource in
		 * system memory (D3DPOOL_SYSTEMMEM).
		 */
		if ((d3dcaps.Caps2 & D3DCAPS2_CANAUTOGENMIPMAP) && (IDirect3D9_CheckDeviceFormat(d3d9.d3d,
				D3DADAPTER_DEFAULT,
				D3DDEVTYPE_HAL,
				d3d9.display_mode.Format,
				D3DUSAGE_AUTOGENMIPMAP,
				D3DRTYPE_TEXTURE,
				d3d9.display_mode.Format) == D3D_OK)) {
			d3d9.auto_gen_mipmap = TRUE;
		} else {
			printf("Video driver don't support automatic generation of mipmap\n");
			d3d9.auto_gen_mipmap = FALSE;
		}

		if (d3dcaps.Caps2 & D3DCAPS2_DYNAMICTEXTURES) {
			d3d9.dynamic_texture = TRUE;
		} else {
			printf("Video driver don't support dynamic texture\n");
			d3d9.dynamic_texture = FALSE;
		}

		/*
		 * Device can accelerate a memory copy from system memory to local video memory.
		 * This cap guarantees that UpdateSurface and UpdateTexture calls will be hardware
		 * accelerated. If this cap is absent, these calls will succeed but will be slower.
		 */
		if (!(d3dcaps.Caps3 & D3DCAPS3_COPY_TO_VIDMEM)) {
			printf("Video driver don't support accelerated texture update\n");
		}

		if (d3dcaps.DevCaps & D3DDEVCAPS_HWTRANSFORMANDLIGHT) {
			d3d9.flags = D3DCREATE_HARDWARE_VERTEXPROCESSING;
			/* Check for pure device */
			if (d3dcaps.DevCaps & D3DDEVCAPS_PUREDEVICE) {
				d3d9.flags |= D3DCREATE_PUREDEVICE;
			}
		} else {
			printf("Video driver don't support hardware accelaration\n");
			d3d9.flags = D3DCREATE_SOFTWARE_VERTEXPROCESSING;
		}

	}

	/*
	 * inizializzo l'ntsc che utilizzero' non solo
	 * come filtro ma anche nel gfx_set_screen() per
	 * generare la paletta dei colori.
	 */
	if (ntsc_init(0, 0, 0, 0, 0)) {
		return (EXIT_ERROR);
	}

	/*
	 * mi alloco una zona di memoria dove conservare la
	 * paletta nel formato di visualizzazione.
	 */
	if (!(d3d9.palette = malloc(NUM_COLORS * sizeof(uint32_t)))) {
		fprintf(stderr, "Out of memory\n");
		return (EXIT_ERROR);
	}

	gfx_set_screen(NO_CHANGE, NO_CHANGE, NO_CHANGE, NO_CHANGE, TRUE);

	return (EXIT_OK);
}
void gfx_set_render(BYTE render) {
	return;
}
void gfx_set_screen(BYTE scale, BYTE filter, BYTE fullscreen, BYTE palette, BYTE force_scale) {
	BYTE set_mode;
	WORD width, height, w_for_pr, h_for_pr;

	//gfx_set_screen_start:
	set_mode = FALSE;
	width = 0, height = 0;
	w_for_pr = 0, h_for_pr = 0;

	/*
	 * l'ordine dei vari controlli non deve essere cambiato:
	 * 0) overscan
	 * 1) filtro
	 * 2) fullscreen
	 * 3) fattore di scala
	 * 4) tipo di paletta (IMPORTANTE: dopo il SDL_SetVideoMode)
	 */

	/* overscan */
	{
		//overscan.enabled = cfg->oscan;

		gfx.rows = SCR_ROWS;
		gfx.lines = SCR_LINES;

		//if (overscan.enabled == OSCAN_DEFAULT) {
		//	overscan.enabled = cfg->oscan_default;
		//}

		//if (overscan.enabled) {
		//	gfx.rows -= (overscan.left + overscan.right);
		//	gfx.lines -= (overscan.up + overscan.down);
		//}
	}

	// .......................
	// .......................
	// .......................
	// mancano un saaaaaaacco di cose
	// .......................
	// .......................
	// .......................

	/* fattore di scala */
	if (scale == NO_CHANGE) {
		scale = cfg->scale;
	}
	if ((scale != cfg->scale) || info.on_cfg || force_scale) {
/*
#define ctrl_filter_scale(scalexf, hqxf)\
	if ((filter >= SCALE2X) && (filter <= SCALE4X)) {\
		filter = scalexf;\
	} else  if ((filter >= HQ2X) && (filter <= HQ4X)) {\
		filter = hqxf;\
	}
*/
		switch (scale) {
			case X1:
				/*
				 * il fattore di scala a 1 e' possibile
				 * solo senza filtro.
				 */
				if (filter != NO_FILTER) {
					/*
					 * con un fattore di scala X1 effect deve essere
					 * sempre impostato su scale_surface.
					 */
					effect = scale_surface;
					return;
				}
				set_mode = TRUE;
				break;
			case X2:
				//ctrl_filter_scale(SCALE2X, HQ2X)
				ntsc_width(width, ntsc_width_pixel[scale], TRUE);
				set_mode = TRUE;
				break;
			case X3:
				//ctrl_filter_scale(SCALE3X, HQ3X)
				ntsc_width(width, ntsc_width_pixel[scale], TRUE);
				set_mode = TRUE;
				break;
			case X4:
				//ctrl_filter_scale(SCALE4X, HQ4X)
				ntsc_width(width, ntsc_width_pixel[scale], TRUE);
				set_mode = TRUE;
				break;
		}
		if (!width) {
			width = gfx.rows * scale;
			gfx.w[CURRENT] = width;
			gfx.w[NO_OVERSCAN] = SCR_ROWS * scale;
		}
		height = gfx.lines * scale;
		gfx.h[CURRENT] = height;
		gfx.h[NO_OVERSCAN] = SCR_LINES * scale;
	}

	d3d9.effect = scale_surface;

	/*
	 * cfg->scale e cfg->filter posso aggiornarli prima
	 * del set_mode, mentre cfg->fullscreen e cfg->palette
	 * devo farlo necessariamente dopo.
	 */
	/* salvo il nuovo fattore di scala */
	cfg->scale = scale;
	/* salvo ill nuovo filtro */
	//cfg->filter = filter;
	/* devo eseguire un SDL_SetVideoMode? */
	if (set_mode) {
		//uint32_t flags = software_flags;

		gfx.w[VIDEO_MODE] = width;
		gfx.h[VIDEO_MODE] = height;

		/*
		if (gfx.opengl) {
			flags = opengl.flags;

			SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 5);
			SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 5);
			SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 5);
			SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);

			SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, TRUE);
			SDL_GL_SetAttribute(SDL_GL_SWAP_CONTROL, cfg->vsync);

			if (fullscreen) {
				gfx.w[VIDEO_MODE] = gfx.w[MONITOR];
				gfx.h[VIDEO_MODE] = gfx.h[MONITOR];
			}
		}
		*/

		/* faccio quello che serve prima del setvideo */
		gui_set_video_mode();

		/*
		 * nella versione a 32 bit (GTK) dopo un gfx_reset_video,
		 * se non lo faccio anche qui, crasha tutto.
		 */
		//sdl_wid();

		/* inizializzo la superfice video */
		//surface_sdl = SDL_SetVideoMode(gfx.w[VIDEO_MODE], gfx.h[VIDEO_MODE], 0, flags);
		if (d3d9_create_context() == EXIT_ERROR) {
			fprintf(stderr, "Unable to initialize d3d context\n");
		}

		/* in caso di errore */
		/*if (!surface_sdl) {
			fprintf(stderr, "SDL_SetVideoMode failed : %s\n", SDL_GetError());
			return;
		}*/

		//gfx.bit_per_pixel = surface_sdl->format->BitsPerPixel;
	}

	ntsc_set(cfg->ntsc_format, FALSE, 0, 0, (BYTE *) palette_RGB);

	/* memorizzo i colori della paletta nel formato di visualizzazione */
	{
		WORD i;

		for (i = 0; i < NUM_COLORS; i++) {
			d3d9.palette[i] =
			        D3DCOLOR_ARGB(255, palette_RGB[i].r, palette_RGB[i].g, palette_RGB[i].b);
		}
	}

	return;
}
void gfx_draw_screen(BYTE forced) {
	{
		static BOOL unable_lock = FALSE;
		D3DLOCKED_RECT locked_rect;

		/* lock della texture */
		if (IDirect3DTexture9_LockRect(d3d9.texture, 0, &locked_rect, NULL, D3DLOCK_DISCARD)
		        == D3D_OK) {

			/* applico l'effetto */
			d3d9.effect(screen.data, screen.line, d3d9.palette, d3d9.bpp, locked_rect.Pitch,
					locked_rect.pBits, gfx.rows, gfx.lines, d3d9.scale);

			/* unlock della texture */
			IDirect3DTexture9_UnlockRect(d3d9.texture, 0);
		} else if (unable_lock == FALSE) {
			printf("Unable to lock texture\n");
			unable_lock = TRUE;
		}
	}

	IDirect3DDevice9_Clear(d3d9.dev, 0, NULL, D3DCLEAR_TARGET, d3d9.palette[40], 1.0f, 0);

	IDirect3DDevice9_BeginScene(d3d9.dev);    // begins the 3D scene

		IDirect3DDevice9_SetTextureStageState(d3d9.dev, 0, D3DTSS_COLOROP, D3DTOP_MODULATE);
		IDirect3DDevice9_SetTextureStageState(d3d9.dev, 0, D3DTSS_COLORARG1, D3DTA_TEXTURE);
		IDirect3DDevice9_SetTextureStageState(d3d9.dev, 0, D3DTSS_COLORARG2, D3DTA_DIFFUSE);
		IDirect3DDevice9_SetTextureStageState(d3d9.dev, 0, D3DTSS_ALPHAOP, D3DTOP_DISABLE);

		IDirect3DDevice9_SetTexture(d3d9.dev, 0, (IDirect3DBaseTexture9 *) d3d9.texture);

		// select which vertex format we are using
		IDirect3DDevice9_SetFVF(d3d9.dev, CUSTOMFVF);

		// select the vertex buffer to display
		IDirect3DDevice9_SetStreamSource(d3d9.dev, 0, d3d9.textured_vertex, 0, sizeof(CUSTOMVERTEX));

		// copy the vertex buffer to the back buffer
		IDirect3DDevice9_DrawPrimitive(d3d9.dev, D3DPT_TRIANGLELIST, 0, 2);

	IDirect3DDevice9_EndScene(d3d9.dev);    // ends the 3D scene

	IDirect3DDevice9_Present(d3d9.dev, NULL, NULL, NULL, NULL);    // displays the created frame
}
void gfx_reset_video(void) {
	return;
}
void gfx_quit(void) {
	ntsc_quit();

	if (d3d9.palette) {
		free(d3d9.palette);
		d3d9.palette = NULL;
	}

	if (d3d9.texture) {
		IDirect3DTexture9_Release(d3d9.texture);
		d3d9.texture = NULL;
	}

	if (d3d9.textured_vertex) {
		IDirect3DVertexBuffer9_Release(d3d9.textured_vertex);
		d3d9.textured_vertex = NULL;
	}

	if (d3d9.dev) {
		IDirect3DDevice9_Release(d3d9.dev);
		d3d9.dev = NULL;
	}

	if (d3d9.d3d) {
		IDirect3D9_Release(d3d9.d3d);
		d3d9.d3d = NULL;
	}

    return;
}





BYTE d3d9_create_context(void) {

	if (d3d9.textured_vertex) {
		IDirect3DVertexBuffer9_Release(d3d9.textured_vertex);
		d3d9.textured_vertex = NULL;
	}

	if (d3d9.dev) {
		IDirect3DDevice9_Release(d3d9.dev);
		d3d9.dev = NULL;
	}

	{
		D3DPRESENT_PARAMETERS d3dpp;

		ZeroMemory(&d3dpp, sizeof(d3dpp));
		d3dpp.Windowed = TRUE;
		d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
		d3dpp.hDeviceWindow = gui_window_id();
		d3dpp.BackBufferFormat = d3d9.display_mode.Format;
		d3dpp.BackBufferWidth = gfx.w[VIDEO_MODE];
		d3dpp.BackBufferHeight = gfx.h[VIDEO_MODE];

		// create a device class using this information and the info from the d3dpp stuct
		if (IDirect3D9_CreateDevice(d3d9.d3d,
				D3DADAPTER_DEFAULT,
				D3DDEVTYPE_HAL,
				gui_window_id(),
				d3d9.flags,
				&d3dpp,
				&d3d9.dev) != D3D_OK) {
			fprintf(stderr, "Unable to create d3d device\n");
			return (EXIT_ERROR);
		}
	}

	{
		VOID *tv_vertices;
		CUSTOMVERTEX vertices[] = {
			/* primo triangolo */
			{ 0.0f,  0.0f, 0.5f, 1.0f, 0, 0 },
			{ gfx.w[VIDEO_MODE], 0.0f, 0.5f, 1.0f, 1, 0 },
			{ gfx.w[VIDEO_MODE], gfx.h[VIDEO_MODE], 0.5f, 1.0f, 1, 1 },
			/* secondo triangolo */
			{ 0.0f, 0.0f, 0.5f, 1.0f, 0, 0 },
			{ gfx.w[VIDEO_MODE], gfx.h[VIDEO_MODE], 0.5f, 1.0f, 1, 1 },
			{ 0.0f,  gfx.h[VIDEO_MODE], 0.5f, 1.0f, 0, 1 },

		};

		if (IDirect3DDevice9_CreateVertexBuffer(d3d9.dev,
				6 * sizeof(CUSTOMVERTEX),
				D3DUSAGE_WRITEONLY,
				CUSTOMFVF,
				D3DPOOL_DEFAULT,
				&d3d9.textured_vertex,
				NULL) != D3D_OK) {
			fprintf(stderr, "Unable to create the vertex buffer\n");
			return (EXIT_ERROR);
		}

		IDirect3DVertexBuffer9_Lock(d3d9.textured_vertex, 0, 0, (void**) &tv_vertices, 0);
		memcpy(tv_vertices, vertices, sizeof(vertices));
		IDirect3DVertexBuffer9_Unlock(d3d9.textured_vertex);
	}

	/* creo la texture principale */
	if (d3d9_create_texture(&d3d9.texture, SCR_ROWS * d3d9.scale, SCR_LINES * d3d9.scale, 0,
	        POWER_OF_TWO) == EXIT_ERROR) {
		fprintf(stderr, "Unable to create main texture\n");
		return (EXIT_ERROR);
	}

	return (EXIT_OK);
}


BYTE d3d9_create_texture(LPDIRECT3DTEXTURE9 *texture, uint32_t width, uint32_t height,
        uint8_t interpolation, uint8_t pow) {
	int w, h;

	if (pow) {
		w = d3d9_power_of_two(width);
		h = d3d9_power_of_two(height);
	} else {
		w = width;
		h = height;
	}

	if ((*texture)) {
		IDirect3DTexture9_Release((*texture));
	}

	{
		DWORD usage = D3DUSAGE_WRITEONLY;

		if (d3d9.dynamic_texture == TRUE) {
			usage |= D3DUSAGE_DYNAMIC;
		}
		if (d3d9.auto_gen_mipmap == TRUE) {
			usage |= D3DUSAGE_AUTOGENMIPMAP;
		}

		{
			HRESULT hresult = IDirect3DDevice9_CreateTexture(d3d9.dev, w, h, 0, usage,
					d3d9.display_mode.Format, D3DPOOL_DEFAULT, texture, NULL);

			if (hresult == D3DERR_INVALIDCALL) {
				if (IDirect3DDevice9_CreateTexture(d3d9.dev, w, h, 0,
						usage & ~D3DUSAGE_WRITEONLY, d3d9.display_mode.Format, D3DPOOL_DEFAULT,
						texture, NULL ) == D3D_OK) {
					printf("Video driver don't support use of D3DUSAGE_WRITEONLY on the texture\n");
				} else {
					return (EXIT_ERROR);
				}
			} else if (hresult != D3D_OK) {
				return (EXIT_ERROR);
			}
		}
	}

	return (EXIT_OK);

	/*glGenTextures(1, &texture->data);
	glBindTexture(GL_TEXTURE_2D, texture->data);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	if (interpolation) {
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	} else {
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	}

	if (opengl.glew && !GLEW_VERSION_3_1) {
		glTexParameteri(GL_TEXTURE_2D, GL_GENERATE_MIPMAP, GL_TRUE);
	}

	{
		SDL_Surface *blank = gfx_create_RGB_surface(opengl.surface_gl, texture->w * 2,
		        texture->h * 2);

		memset(blank->pixels, 0, blank->w * blank->h * blank->format->BytesPerPixel);

		glTexImage2D(GL_TEXTURE_2D, 0, texture->format_internal, texture->w, texture->h, 0,
		        texture->format, texture->type, blank->pixels);

		SDL_FreeSurface(blank);
	}

	if (opengl.glew && GLEW_VERSION_3_1) {
		glGenerateMipmap(GL_TEXTURE_2D);
	}

	glDisable(GL_TEXTURE_2D);
	*/
}

int d3d9_power_of_two(int base) {
	int pot = 1;

	while (pot < base) {
		pot <<= 1;
	}
	return (pot);
}