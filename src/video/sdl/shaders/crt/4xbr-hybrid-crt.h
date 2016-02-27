{
"// GLSL shader autogenerated by cg2glsl.py.\n"
"#if defined(VERTEX)\n"
"\n"
"#if __VERSION__ >= 130\n"
"#define COMPAT_VARYING out\n"
"#define COMPAT_ATTRIBUTE in\n"
"#define COMPAT_TEXTURE texture\n"
"#else\n"
"#define COMPAT_VARYING varying\n"
"#define COMPAT_ATTRIBUTE attribute\n"
"#define COMPAT_TEXTURE texture2D\n"
"#endif\n"
"\n"
"#ifdef GL_ES\n"
"#define COMPAT_PRECISION mediump\n"
"#else\n"
"#define COMPAT_PRECISION\n"
"#endif\n"
"COMPAT_VARYING     vec4 _t7;\n"
"COMPAT_VARYING     vec4 _t6;\n"
"COMPAT_VARYING     vec4 _t5;\n"
"COMPAT_VARYING     vec4 _t4;\n"
"COMPAT_VARYING     vec4 _t3;\n"
"COMPAT_VARYING     vec4 _t2;\n"
"COMPAT_VARYING     vec4 _t1;\n"
"COMPAT_VARYING     vec2 _texCoord2;\n"
"COMPAT_VARYING     vec4 _color1;\n"
"COMPAT_VARYING     vec4 _position1;\n"
"struct input_dummy {\n"
"    vec2 _video_size;\n"
"    vec2 _texture_size;\n"
"    vec2 _output_dummy_size;\n"
"};\n"
"struct out_vertex {\n"
"    vec4 _position1;\n"
"    vec4 _color1;\n"
"    vec2 _texCoord2;\n"
"    vec4 _t1;\n"
"    vec4 _t2;\n"
"    vec4 _t3;\n"
"    vec4 _t4;\n"
"    vec4 _t5;\n"
"    vec4 _t6;\n"
"    vec4 _t7;\n"
"};\n"
"out_vertex _ret_0;\n"
"input_dummy _IN1;\n"
"vec4 _r0010;\n"
"COMPAT_ATTRIBUTE vec4 VertexCoord;\n"
"COMPAT_ATTRIBUTE vec4 COLOR;\n"
"COMPAT_ATTRIBUTE vec4 TexCoord;\n"
"COMPAT_VARYING vec4 COL0;\n"
"COMPAT_VARYING vec4 TEX0;\n"
"COMPAT_VARYING vec4 TEX1;\n"
"COMPAT_VARYING vec4 TEX2;\n"
"COMPAT_VARYING vec4 TEX3;\n"
"COMPAT_VARYING vec4 TEX4;\n"
"COMPAT_VARYING vec4 TEX5;\n"
"COMPAT_VARYING vec4 TEX6;\n"
"COMPAT_VARYING vec4 TEX7;\n"
" \n"
"uniform mat4 MVPMatrix;\n"
"uniform int FrameDirection;\n"
"uniform int FrameCount;\n"
"uniform COMPAT_PRECISION vec2 OutputSize;\n"
"uniform COMPAT_PRECISION vec2 TextureSize;\n"
"uniform COMPAT_PRECISION vec2 InputSize;\n"
"void main()\n"
"{\n"
"    out_vertex _OUT;\n"
"    vec2 _ps;\n"
"    vec2 _texCoord;\n"
"    _r0010 = VertexCoord.x*MVPMatrix[0];\n"
"    _r0010 = _r0010 + VertexCoord.y*MVPMatrix[1];\n"
"    _r0010 = _r0010 + VertexCoord.z*MVPMatrix[2];\n"
"    _r0010 = _r0010 + VertexCoord.w*MVPMatrix[3];\n"
"    _ps = vec2(1.00000000E+00/TextureSize.x, 1.00000000E+00/TextureSize.y);\n"
"    _texCoord = TexCoord.xy + vec2( 1.00000001E-07, 1.00000001E-07);\n"
"    _OUT._t1 = _texCoord.xxxy + vec4(float(float(-_ps.x)), 0.00000000E+00, float(float(_ps.x)), float(float((-2.00000000E+00*_ps.y))));\n"
"    _OUT._t2 = _texCoord.xxxy + vec4(float(float(-_ps.x)), 0.00000000E+00, float(float(_ps.x)), float(float(-_ps.y)));\n"
"    _OUT._t3 = _texCoord.xxxy + vec4(float(float(-_ps.x)), 0.00000000E+00, float(float(_ps.x)), 0.00000000E+00);\n"
"    _OUT._t4 = _texCoord.xxxy + vec4(float(float(-_ps.x)), 0.00000000E+00, float(float(_ps.x)), float(float(_ps.y)));\n"
"    _OUT._t5 = _texCoord.xxxy + vec4(float(float(-_ps.x)), 0.00000000E+00, float(float(_ps.x)), float(float((2.00000000E+00*_ps.y))));\n"
"    _OUT._t6 = _texCoord.xyyy + vec4(float(float((-2.00000000E+00*_ps.x))), float(float(-_ps.y)), 0.00000000E+00, float(float(_ps.y)));\n"
"    _OUT._t7 = _texCoord.xyyy + vec4(float(float((2.00000000E+00*_ps.x))), float(float(-_ps.y)), 0.00000000E+00, float(float(_ps.y)));\n"
"    _ret_0._position1 = _r0010;\n"
"    _ret_0._color1 = COLOR;\n"
"    _ret_0._texCoord2 = _texCoord;\n"
"    _ret_0._t1 = _OUT._t1;\n"
"    _ret_0._t2 = _OUT._t2;\n"
"    _ret_0._t3 = _OUT._t3;\n"
"    _ret_0._t4 = _OUT._t4;\n"
"    _ret_0._t5 = _OUT._t5;\n"
"    _ret_0._t6 = _OUT._t6;\n"
"    _ret_0._t7 = _OUT._t7;\n"
"    gl_Position = vec4(float(_r0010.x), float(_r0010.y), float(_r0010.z), float(_r0010.w));\n"
"    COL0 = COLOR;\n"
"    TEX0.xy = _texCoord;\n"
"    TEX1 = _OUT._t1;\n"
"    TEX2 = _OUT._t2;\n"
"    TEX3 = _OUT._t3;\n"
"    TEX4 = _OUT._t4;\n"
"    TEX5 = _OUT._t5;\n"
"    TEX6 = _OUT._t6;\n"
"    TEX7 = _OUT._t7;\n"
"    return;\n"
"    COL0 = _ret_0._color1;\n"
"    TEX0.xy = _ret_0._texCoord2;\n"
"    TEX1 = _ret_0._t1;\n"
"    TEX2 = _ret_0._t2;\n"
"    TEX3 = _ret_0._t3;\n"
"    TEX4 = _ret_0._t4;\n"
"    TEX5 = _ret_0._t5;\n"
"    TEX6 = _ret_0._t6;\n"
"    TEX7 = _ret_0._t7;\n"
"} \n"
"#elif defined(FRAGMENT)\n"
"\n"
"#if __VERSION__ >= 130\n"
"#define COMPAT_VARYING in\n"
"#define COMPAT_TEXTURE texture\n"
"out vec4 FragColor;\n"
"#else\n"
"#define COMPAT_VARYING varying\n"
"#define FragColor gl_FragColor\n"
"#define COMPAT_TEXTURE texture2D\n"
"#endif\n"
"\n"
"#ifdef GL_ES\n"
"#ifdef GL_FRAGMENT_PRECISION_HIGH\n"
"precision highp float;\n"
"#else\n"
"precision mediump float;\n"
"#endif\n"
"#define COMPAT_PRECISION mediump\n"
"#else\n"
"#define COMPAT_PRECISION\n"
"#endif\n"
"COMPAT_VARYING     vec4 _t7;\n"
"COMPAT_VARYING     vec4 _t6;\n"
"COMPAT_VARYING     vec4 _t5;\n"
"COMPAT_VARYING     vec4 _t4;\n"
"COMPAT_VARYING     vec4 _t3;\n"
"COMPAT_VARYING     vec4 _t2;\n"
"COMPAT_VARYING     vec4 _t1;\n"
"COMPAT_VARYING     vec2 _texCoord;\n"
"COMPAT_VARYING     vec4 _color1;\n"
"struct input_dummy {\n"
"    vec2 _video_size;\n"
"    vec2 _texture_size;\n"
"    vec2 _output_dummy_size;\n"
"};\n"
"struct out_vertex {\n"
"    vec4 _color1;\n"
"    vec2 _texCoord;\n"
"    vec4 _t1;\n"
"    vec4 _t2;\n"
"    vec4 _t3;\n"
"    vec4 _t4;\n"
"    vec4 _t5;\n"
"    vec4 _t6;\n"
"    vec4 _t7;\n"
"};\n"
"vec4 _ret_0;\n"
"vec3 _TMP76;\n"
"vec3 _TMP92;\n"
"float _TMP91;\n"
"float _TMP90;\n"
"float _TMP89;\n"
"vec3 _TMP75;\n"
"float _TMP88;\n"
"float _TMP87;\n"
"float _TMP86;\n"
"float _TMP95;\n"
"float _TMP74;\n"
"float _TMP73;\n"
"float _TMP72;\n"
"vec3 _TMP94;\n"
"vec3 _TMP71;\n"
"vec3 _TMP70;\n"
"vec3 _TMP69;\n"
"vec3 _TMP68;\n"
"vec3 _TMP67;\n"
"vec3 _TMP66;\n"
"vec3 _TMP65;\n"
"vec3 _TMP64;\n"
"vec3 _TMP63;\n"
"vec3 _TMP62;\n"
"vec4 _TMP61;\n"
"float _TMP60;\n"
"float _TMP59;\n"
"float _TMP58;\n"
"vec3 _TMP85;\n"
"vec3 _TMP56;\n"
"vec3 _TMP55;\n"
"vec3 _TMP54;\n"
"vec3 _TMP53;\n"
"vec4 _TMP46;\n"
"vec4 _TMP45;\n"
"vec4 _TMP96;\n"
"bvec4 _TMP44;\n"
"bvec4 _TMP43;\n"
"bvec4 _TMP42;\n"
"bvec4 _TMP41;\n"
"bvec4 _TMP40;\n"
"bvec4 _TMP39;\n"
"bvec4 _TMP38;\n"
"bvec4 _TMP37;\n"
"bvec4 _TMP36;\n"
"bvec4 _TMP35;\n"
"bvec4 _TMP34;\n"
"bvec4 _TMP33;\n"
"bvec4 _TMP32;\n"
"bvec4 _TMP31;\n"
"bvec4 _TMP30;\n"
"bvec4 _TMP29;\n"
"bvec4 _TMP28;\n"
"bvec4 _TMP27;\n"
"float _TMP93;\n"
"vec4 _TMP20;\n"
"vec4 _TMP19;\n"
"vec4 _TMP18;\n"
"vec4 _TMP17;\n"
"vec4 _TMP16;\n"
"vec4 _TMP15;\n"
"vec4 _TMP14;\n"
"vec4 _TMP13;\n"
"vec4 _TMP12;\n"
"vec4 _TMP11;\n"
"vec4 _TMP10;\n"
"vec4 _TMP9;\n"
"vec4 _TMP8;\n"
"vec4 _TMP7;\n"
"vec4 _TMP6;\n"
"vec4 _TMP5;\n"
"vec4 _TMP4;\n"
"vec4 _TMP3;\n"
"vec4 _TMP2;\n"
"vec4 _TMP1;\n"
"vec4 _TMP0;\n"
"uniform sampler2D Texture;\n"
"input_dummy _IN1;\n"
"vec2 _x0110;\n"
"vec4 _r0154;\n"
"vec4 _r0164;\n"
"vec4 _r0174;\n"
"vec4 _r0184;\n"
"vec4 _r0194;\n"
"vec4 _r0204;\n"
"vec4 _TMP215;\n"
"vec4 _a0218;\n"
"vec4 _TMP221;\n"
"vec4 _a0224;\n"
"vec4 _TMP227;\n"
"vec4 _a0230;\n"
"vec4 _TMP233;\n"
"vec4 _a0236;\n"
"vec4 _TMP239;\n"
"vec4 _a0242;\n"
"vec4 _TMP245;\n"
"vec4 _a0248;\n"
"vec4 _TMP251;\n"
"vec4 _a0254;\n"
"vec4 _TMP257;\n"
"vec4 _a0260;\n"
"vec4 _TMP263;\n"
"vec4 _a0266;\n"
"vec4 _TMP269;\n"
"vec4 _a0272;\n"
"vec4 _TMP275;\n"
"vec4 _a0278;\n"
"vec4 _TMP281;\n"
"vec4 _a0284;\n"
"vec4 _TMP287;\n"
"vec4 _a0290;\n"
"vec4 _TMP293;\n"
"vec4 _a0296;\n"
"vec4 _TMP299;\n"
"vec4 _a0302;\n"
"vec4 _TMP305;\n"
"vec4 _a0308;\n"
"vec4 _TMP311;\n"
"vec4 _a0314;\n"
"vec4 _TMP317;\n"
"vec4 _a0320;\n"
"vec4 _x0324;\n"
"vec4 _TMP325;\n"
"vec4 _x0334;\n"
"vec4 _TMP335;\n"
"vec4 _x0344;\n"
"vec4 _TMP345;\n"
"vec4 _TMP353;\n"
"vec4 _a0356;\n"
"vec4 _TMP357;\n"
"vec4 _a0360;\n"
"vec4 _TMP361;\n"
"vec4 _a0364;\n"
"vec4 _TMP365;\n"
"vec4 _a0368;\n"
"vec4 _TMP369;\n"
"vec4 _a0372;\n"
"vec4 _TMP375;\n"
"vec4 _a0378;\n"
"vec4 _TMP379;\n"
"vec4 _a0382;\n"
"vec4 _TMP383;\n"
"vec4 _a0386;\n"
"vec4 _TMP387;\n"
"vec4 _a0390;\n"
"vec4 _TMP391;\n"
"vec4 _a0394;\n"
"vec4 _TMP395;\n"
"vec4 _a0398;\n"
"vec4 _TMP399;\n"
"vec4 _a0402;\n"
"vec4 _TMP403;\n"
"vec4 _a0406;\n"
"vec4 _TMP407;\n"
"vec4 _a0410;\n"
"vec4 _TMP411;\n"
"vec4 _a0414;\n"
"vec4 _TMP415;\n"
"vec4 _a0418;\n"
"vec3 _b0422;\n"
"vec3 _b0426;\n"
"vec3 _TMP427;\n"
"vec3 _a0428;\n"
"vec3 _b0436;\n"
"vec3 _b0440;\n"
"vec3 _TMP441;\n"
"vec3 _a0442;\n"
"vec4 _a0448;\n"
"vec4 _a0450;\n"
"vec4 _a0452;\n"
"vec3 _b0458;\n"
"vec3 _b0460;\n"
"vec3 _df0462;\n"
"vec3 _a0464;\n"
"vec3 _df0466;\n"
"vec3 _a0468;\n"
"vec3 _TMP497;\n"
"COMPAT_VARYING vec4 TEX0;\n"
"COMPAT_VARYING vec4 TEX1;\n"
"COMPAT_VARYING vec4 TEX2;\n"
"COMPAT_VARYING vec4 TEX3;\n"
"COMPAT_VARYING vec4 TEX4;\n"
"COMPAT_VARYING vec4 TEX5;\n"
"COMPAT_VARYING vec4 TEX6;\n"
"COMPAT_VARYING vec4 TEX7;\n"
" \n"
"uniform int FrameDirection;\n"
"uniform int FrameCount;\n"
"uniform COMPAT_PRECISION vec2 OutputSize;\n"
"uniform COMPAT_PRECISION vec2 TextureSize;\n"
"uniform COMPAT_PRECISION vec2 InputSize;\n"
"void main()\n"
"{\n"
"    bvec4 _edr;\n"
"    bvec4 _edr_left;\n"
"    bvec4 _edr_up;\n"
"    bvec4 _px;\n"
"    bvec4 _interp_restriction_lv1;\n"
"    bvec4 _interp_restriction_lv2_left;\n"
"    bvec4 _interp_restriction_lv2_up;\n"
"    bvec4 _nc;\n"
"    bvec4 _nc30;\n"
"    bvec4 _nc60;\n"
"    bvec4 _nc45;\n"
"    vec4 _fx;\n"
"    vec4 _fx_left;\n"
"    vec4 _fx_up;\n"
"    vec3 _res1;\n"
"    vec3 _res2;\n"
"    vec3 _pix1;\n"
"    vec3 _pix2;\n"
"    float _blend1;\n"
"    float _blend2;\n"
"    vec2 _fp;\n"
"    vec3 _A11;\n"
"    vec3 _B11;\n"
"    vec3 _C1;\n"
"    vec3 _A3;\n"
"    vec3 _B3;\n"
"    vec3 _C;\n"
"    vec3 _D;\n"
"    vec3 _E;\n"
"    vec3 _F;\n"
"    vec3 _G;\n"
"    vec3 _H;\n"
"    vec3 _I;\n"
"    vec3 _G5;\n"
"    vec3 _H5;\n"
"    vec3 _I5;\n"
"    vec3 _A0;\n"
"    vec3 _D0;\n"
"    vec3 _G0;\n"
"    vec3 _C4;\n"
"    vec3 _F4;\n"
"    vec3 _I4;\n"
"    vec4 _b1;\n"
"    vec4 _c3;\n"
"    vec4 _e1;\n"
"    vec4 _i4;\n"
"    vec4 _i5;\n"
"    vec4 _h5;\n"
"    vec4 _fx45;\n"
"    vec4 _fx30;\n"
"    vec4 _fx60;\n"
"    vec3 _res;\n"
"    vec3 _n1;\n"
"    vec3 _n2;\n"
"    vec3 _n3;\n"
"    vec3 _n4;\n"
"    vec3 _s;\n"
"    vec3 _aa;\n"
"    vec3 _bb;\n"
"    vec3 _cc;\n"
"    vec3 _dd;\n"
"    vec3 _t;\n"
"    vec3 _m;\n"
"    vec3 _s1;\n"
"    vec3 _s0;\n"
"    vec4 _maximo;\n"
"    vec3 _color;\n"
"    float _ddy;\n"
"    float _v_weight_00;\n"
"    vec3 _coords10;\n"
"    vec3 _colorNB;\n"
"    float _v_weight_10;\n"
"    _x0110 = TEX0.xy*TextureSize;\n"
"    _fp = fract(_x0110);\n"
"    _TMP0 = COMPAT_TEXTURE(Texture, TEX1.xw);\n"
"    _A11 = vec3(float(_TMP0.x), float(_TMP0.y), float(_TMP0.z));\n"
"    _TMP1 = COMPAT_TEXTURE(Texture, TEX1.yw);\n"
"    _B11 = vec3(float(_TMP1.x), float(_TMP1.y), float(_TMP1.z));\n"
"    _TMP2 = COMPAT_TEXTURE(Texture, TEX1.zw);\n"
"    _C1 = vec3(float(_TMP2.x), float(_TMP2.y), float(_TMP2.z));\n"
"    _TMP3 = COMPAT_TEXTURE(Texture, TEX2.xw);\n"
"    _A3 = vec3(float(_TMP3.x), float(_TMP3.y), float(_TMP3.z));\n"
"    _TMP4 = COMPAT_TEXTURE(Texture, TEX2.yw);\n"
"    _B3 = vec3(float(_TMP4.x), float(_TMP4.y), float(_TMP4.z));\n"
"    _TMP5 = COMPAT_TEXTURE(Texture, TEX2.zw);\n"
"    _C = vec3(float(_TMP5.x), float(_TMP5.y), float(_TMP5.z));\n"
"    _TMP6 = COMPAT_TEXTURE(Texture, TEX3.xw);\n"
"    _D = vec3(float(_TMP6.x), float(_TMP6.y), float(_TMP6.z));\n"
"    _TMP7 = COMPAT_TEXTURE(Texture, TEX3.yw);\n"
"    _E = vec3(float(_TMP7.x), float(_TMP7.y), float(_TMP7.z));\n"
"    _TMP8 = COMPAT_TEXTURE(Texture, TEX3.zw);\n"
"    _F = vec3(float(_TMP8.x), float(_TMP8.y), float(_TMP8.z));\n"
"    _TMP9 = COMPAT_TEXTURE(Texture, TEX4.xw);\n"
"    _G = vec3(float(_TMP9.x), float(_TMP9.y), float(_TMP9.z));\n"
"    _TMP10 = COMPAT_TEXTURE(Texture, TEX4.yw);\n"
"    _H = vec3(float(_TMP10.x), float(_TMP10.y), float(_TMP10.z));\n"
"    _TMP11 = COMPAT_TEXTURE(Texture, TEX4.zw);\n"
"    _I = vec3(float(_TMP11.x), float(_TMP11.y), float(_TMP11.z));\n"
"    _TMP12 = COMPAT_TEXTURE(Texture, TEX5.xw);\n"
"    _G5 = vec3(float(_TMP12.x), float(_TMP12.y), float(_TMP12.z));\n"
"    _TMP13 = COMPAT_TEXTURE(Texture, TEX5.yw);\n"
"    _H5 = vec3(float(_TMP13.x), float(_TMP13.y), float(_TMP13.z));\n"
"    _TMP14 = COMPAT_TEXTURE(Texture, TEX5.zw);\n"
"    _I5 = vec3(float(_TMP14.x), float(_TMP14.y), float(_TMP14.z));\n"
"    _TMP15 = COMPAT_TEXTURE(Texture, TEX6.xy);\n"
"    _A0 = vec3(float(_TMP15.x), float(_TMP15.y), float(_TMP15.z));\n"
"    _TMP16 = COMPAT_TEXTURE(Texture, TEX6.xz);\n"
"    _D0 = vec3(float(_TMP16.x), float(_TMP16.y), float(_TMP16.z));\n"
"    _TMP17 = COMPAT_TEXTURE(Texture, TEX6.xw);\n"
"    _G0 = vec3(float(_TMP17.x), float(_TMP17.y), float(_TMP17.z));\n"
"    _TMP18 = COMPAT_TEXTURE(Texture, TEX7.xy);\n"
"    _C4 = vec3(float(_TMP18.x), float(_TMP18.y), float(_TMP18.z));\n"
"    _TMP19 = COMPAT_TEXTURE(Texture, TEX7.xz);\n"
"    _F4 = vec3(float(_TMP19.x), float(_TMP19.y), float(_TMP19.z));\n"
"    _TMP20 = COMPAT_TEXTURE(Texture, TEX7.xw);\n"
"    _I4 = vec3(float(_TMP20.x), float(_TMP20.y), float(_TMP20.z));\n"
"    _TMP93 = dot(vec3(float(_B3.x), float(_B3.y), float(_B3.z)), vec3( 1.43593750E+01, 2.81718750E+01, 5.47265625E+00));\n"
"    _r0154.x = float(_TMP93);\n"
"    _TMP93 = dot(vec3(float(_D.x), float(_D.y), float(_D.z)), vec3( 1.43593750E+01, 2.81718750E+01, 5.47265625E+00));\n"
"    _r0154.y = float(_TMP93);\n"
"    _TMP93 = dot(vec3(float(_H.x), float(_H.y), float(_H.z)), vec3( 1.43593750E+01, 2.81718750E+01, 5.47265625E+00));\n"
"    _r0154.z = float(_TMP93);\n"
"    _TMP93 = dot(vec3(float(_F.x), float(_F.y), float(_F.z)), vec3( 1.43593750E+01, 2.81718750E+01, 5.47265625E+00));\n"
"    _r0154.w = float(_TMP93);\n"
"    _b1 = vec4(float(_r0154.x), float(_r0154.y), float(_r0154.z), float(_r0154.w));\n"
"    _TMP93 = dot(vec3(float(_C.x), float(_C.y), float(_C.z)), vec3( 1.43593750E+01, 2.81718750E+01, 5.47265625E+00));\n"
"    _r0164.x = float(_TMP93);\n"
"    _TMP93 = dot(vec3(float(_A3.x), float(_A3.y), float(_A3.z)), vec3( 1.43593750E+01, 2.81718750E+01, 5.47265625E+00));\n"
"    _r0164.y = float(_TMP93);\n"
"    _TMP93 = dot(vec3(float(_G.x), float(_G.y), float(_G.z)), vec3( 1.43593750E+01, 2.81718750E+01, 5.47265625E+00));\n"
"    _r0164.z = float(_TMP93);\n"
"    _TMP93 = dot(vec3(float(_I.x), float(_I.y), float(_I.z)), vec3( 1.43593750E+01, 2.81718750E+01, 5.47265625E+00));\n"
"    _r0164.w = float(_TMP93);\n"
"    _c3 = vec4(float(_r0164.x), float(_r0164.y), float(_r0164.z), float(_r0164.w));\n"
"    _TMP93 = dot(vec3(float(_E.x), float(_E.y), float(_E.z)), vec3( 1.43593750E+01, 2.81718750E+01, 5.47265625E+00));\n"
"    _r0174.x = float(_TMP93);\n"
"    _TMP93 = dot(vec3(float(_E.x), float(_E.y), float(_E.z)), vec3( 1.43593750E+01, 2.81718750E+01, 5.47265625E+00));\n"
"    _r0174.y = float(_TMP93);\n"
"    _TMP93 = dot(vec3(float(_E.x), float(_E.y), float(_E.z)), vec3( 1.43593750E+01, 2.81718750E+01, 5.47265625E+00));\n"
"    _r0174.z = float(_TMP93);\n"
"    _TMP93 = dot(vec3(float(_E.x), float(_E.y), float(_E.z)), vec3( 1.43593750E+01, 2.81718750E+01, 5.47265625E+00));\n"
"    _r0174.w = float(_TMP93);\n"
"    _e1 = vec4(float(_r0174.x), float(_r0174.y), float(_r0174.z), float(_r0174.w));\n"
"    _TMP93 = dot(vec3(float(_I4.x), float(_I4.y), float(_I4.z)), vec3( 1.43593750E+01, 2.81718750E+01, 5.47265625E+00));\n"
"    _r0184.x = float(_TMP93);\n"
"    _TMP93 = dot(vec3(float(_C1.x), float(_C1.y), float(_C1.z)), vec3( 1.43593750E+01, 2.81718750E+01, 5.47265625E+00));\n"
"    _r0184.y = float(_TMP93);\n"
"    _TMP93 = dot(vec3(float(_A0.x), float(_A0.y), float(_A0.z)), vec3( 1.43593750E+01, 2.81718750E+01, 5.47265625E+00));\n"
"    _r0184.z = float(_TMP93);\n"
"    _TMP93 = dot(vec3(float(_G5.x), float(_G5.y), float(_G5.z)), vec3( 1.43593750E+01, 2.81718750E+01, 5.47265625E+00));\n"
"    _r0184.w = float(_TMP93);\n"
"    _i4 = vec4(float(_r0184.x), float(_r0184.y), float(_r0184.z), float(_r0184.w));\n"
"    _TMP93 = dot(vec3(float(_I5.x), float(_I5.y), float(_I5.z)), vec3( 1.43593750E+01, 2.81718750E+01, 5.47265625E+00));\n"
"    _r0194.x = float(_TMP93);\n"
"    _TMP93 = dot(vec3(float(_C4.x), float(_C4.y), float(_C4.z)), vec3( 1.43593750E+01, 2.81718750E+01, 5.47265625E+00));\n"
"    _r0194.y = float(_TMP93);\n"
"    _TMP93 = dot(vec3(float(_A11.x), float(_A11.y), float(_A11.z)), vec3( 1.43593750E+01, 2.81718750E+01, 5.47265625E+00));\n"
"    _r0194.z = float(_TMP93);\n"
"    _TMP93 = dot(vec3(float(_G0.x), float(_G0.y), float(_G0.z)), vec3( 1.43593750E+01, 2.81718750E+01, 5.47265625E+00));\n"
"    _r0194.w = float(_TMP93);\n"
"    _i5 = vec4(float(_r0194.x), float(_r0194.y), float(_r0194.z), float(_r0194.w));\n"
"    _TMP93 = dot(vec3(float(_H5.x), float(_H5.y), float(_H5.z)), vec3( 1.43593750E+01, 2.81718750E+01, 5.47265625E+00));\n"
"    _r0204.x = float(_TMP93);\n"
"    _TMP93 = dot(vec3(float(_F4.x), float(_F4.y), float(_F4.z)), vec3( 1.43593750E+01, 2.81718750E+01, 5.47265625E+00));\n"
"    _r0204.y = float(_TMP93);\n"
"    _TMP93 = dot(vec3(float(_B11.x), float(_B11.y), float(_B11.z)), vec3( 1.43593750E+01, 2.81718750E+01, 5.47265625E+00));\n"
"    _r0204.z = float(_TMP93);\n"
"    _TMP93 = dot(vec3(float(_D0.x), float(_D0.y), float(_D0.z)), vec3( 1.43593750E+01, 2.81718750E+01, 5.47265625E+00));\n"
"    _r0204.w = float(_TMP93);\n"
"    _h5 = vec4(float(_r0204.x), float(_r0204.y), float(_r0204.z), float(_r0204.w));\n"
"    _fx = vec4( 1.00000000E+00, -1.00000000E+00, -1.00000000E+00, 1.00000000E+00)*_fp.y + vec4( 1.00000000E+00, 1.00000000E+00, -1.00000000E+00, -1.00000000E+00)*_fp.x;\n"
"    _fx_left = vec4( 1.00000000E+00, -1.00000000E+00, -1.00000000E+00, 1.00000000E+00)*_fp.y + vec4( 5.00000000E-01, 2.00000000E+00, -5.00000000E-01, -2.00000000E+00)*_fp.x;\n"
"    _fx_up = vec4( 1.00000000E+00, -1.00000000E+00, -1.00000000E+00, 1.00000000E+00)*_fp.y + vec4( 2.00000000E+00, 5.00000000E-01, -2.00000000E+00, -5.00000000E-01)*_fp.x;\n"
"    _a0218 = _e1 - _b1;\n"
"    _TMP215 = abs(_a0218);\n"
"    _TMP27 = bvec4(_TMP215.x < 2.00000000E+00, _TMP215.y < 2.00000000E+00, _TMP215.z < 2.00000000E+00, _TMP215.w < 2.00000000E+00);\n"
"    _a0224 = _e1 - _b1.yzwx;\n"
"    _TMP221 = abs(_a0224);\n"
"    _TMP28 = bvec4(_TMP221.x < 2.00000000E+00, _TMP221.y < 2.00000000E+00, _TMP221.z < 2.00000000E+00, _TMP221.w < 2.00000000E+00);\n"
"    _a0230 = _e1 - _c3.yzwx;\n"
"    _TMP227 = abs(_a0230);\n"
"    _TMP29 = bvec4(_TMP227.x < 2.00000000E+00, _TMP227.y < 2.00000000E+00, _TMP227.z < 2.00000000E+00, _TMP227.w < 2.00000000E+00);\n"
"    _a0236 = _b1.wxyz - _h5.yzwx;\n"
"    _TMP233 = abs(_a0236);\n"
"    _TMP30 = bvec4(_TMP233.x < 2.00000000E+00, _TMP233.y < 2.00000000E+00, _TMP233.z < 2.00000000E+00, _TMP233.w < 2.00000000E+00);\n"
"    _a0242 = _b1.wxyz - _c3;\n"
"    _TMP239 = abs(_a0242);\n"
"    _TMP31 = bvec4(_TMP239.x < 2.00000000E+00, _TMP239.y < 2.00000000E+00, _TMP239.z < 2.00000000E+00, _TMP239.w < 2.00000000E+00);\n"
"    _a0248 = _b1.zwxy - _h5;\n"
"    _TMP245 = abs(_a0248);\n"
"    _TMP32 = bvec4(_TMP245.x < 2.00000000E+00, _TMP245.y < 2.00000000E+00, _TMP245.z < 2.00000000E+00, _TMP245.w < 2.00000000E+00);\n"
"    _a0254 = _b1.zwxy - _c3.zwxy;\n"
"    _TMP251 = abs(_a0254);\n"
"    _TMP33 = bvec4(_TMP251.x < 2.00000000E+00, _TMP251.y < 2.00000000E+00, _TMP251.z < 2.00000000E+00, _TMP251.w < 2.00000000E+00);\n"
"    _a0260 = _b1.wxyz - _b1;\n"
"    _TMP257 = abs(_a0260);\n"
"    _TMP34 = bvec4(_TMP257.x < 1.50000000E+01, _TMP257.y < 1.50000000E+01, _TMP257.z < 1.50000000E+01, _TMP257.w < 1.50000000E+01);\n"
"    _a0266 = _b1.wxyz - _c3;\n"
"    _TMP263 = abs(_a0266);\n"
"    _TMP35 = bvec4(_TMP263.x < 1.50000000E+01, _TMP263.y < 1.50000000E+01, _TMP263.z < 1.50000000E+01, _TMP263.w < 1.50000000E+01);\n"
"    _a0272 = _b1.zwxy - _b1.yzwx;\n"
"    _TMP269 = abs(_a0272);\n"
"    _TMP36 = bvec4(_TMP269.x < 1.50000000E+01, _TMP269.y < 1.50000000E+01, _TMP269.z < 1.50000000E+01, _TMP269.w < 1.50000000E+01);\n"
"    _a0278 = _b1.zwxy - _c3.zwxy;\n"
"    _TMP275 = abs(_a0278);\n"
"    _TMP37 = bvec4(_TMP275.x < 1.50000000E+01, _TMP275.y < 1.50000000E+01, _TMP275.z < 1.50000000E+01, _TMP275.w < 1.50000000E+01);\n"
"    _a0284 = _e1 - _c3.wxyz;\n"
"    _TMP281 = abs(_a0284);\n"
"    _TMP38 = bvec4(_TMP281.x < 1.50000000E+01, _TMP281.y < 1.50000000E+01, _TMP281.z < 1.50000000E+01, _TMP281.w < 1.50000000E+01);\n"
"    _a0290 = _b1.wxyz - _h5.yzwx;\n"
"    _TMP287 = abs(_a0290);\n"
"    _TMP39 = bvec4(_TMP287.x < 1.50000000E+01, _TMP287.y < 1.50000000E+01, _TMP287.z < 1.50000000E+01, _TMP287.w < 1.50000000E+01);\n"
"    _a0296 = _b1.wxyz - _i4;\n"
"    _TMP293 = abs(_a0296);\n"
"    _TMP40 = bvec4(_TMP293.x < 1.50000000E+01, _TMP293.y < 1.50000000E+01, _TMP293.z < 1.50000000E+01, _TMP293.w < 1.50000000E+01);\n"
"    _a0302 = _b1.zwxy - _h5;\n"
"    _TMP299 = abs(_a0302);\n"
"    _TMP41 = bvec4(_TMP299.x < 1.50000000E+01, _TMP299.y < 1.50000000E+01, _TMP299.z < 1.50000000E+01, _TMP299.w < 1.50000000E+01);\n"
"    _a0308 = _b1.zwxy - _i5;\n"
"    _TMP305 = abs(_a0308);\n"
"    _TMP42 = bvec4(_TMP305.x < 1.50000000E+01, _TMP305.y < 1.50000000E+01, _TMP305.z < 1.50000000E+01, _TMP305.w < 1.50000000E+01);\n"
"    _a0314 = _e1 - _c3.zwxy;\n"
"    _TMP311 = abs(_a0314);\n"
"    _TMP43 = bvec4(_TMP311.x < 1.50000000E+01, _TMP311.y < 1.50000000E+01, _TMP311.z < 1.50000000E+01, _TMP311.w < 1.50000000E+01);\n"
"    _a0320 = _e1 - _c3;\n"
"    _TMP317 = abs(_a0320);\n"
"    _TMP44 = bvec4(_TMP317.x < 1.50000000E+01, _TMP317.y < 1.50000000E+01, _TMP317.z < 1.50000000E+01, _TMP317.w < 1.50000000E+01);\n"
"    _interp_restriction_lv1 = bvec4(_e1.x != _b1.w && _e1.x != _b1.z && (_TMP27.x || _TMP28.x || !_TMP29.x) && (_TMP30.x || _TMP31.x || _TMP32.x || _TMP33.x) && (!_TMP34.x && !_TMP35.x || !_TMP36.x && !_TMP37.x || _TMP38.x && (!_TMP39.x && !_TMP40.x || !_TMP41.x && !_TMP42.x) || _TMP43.x || _TMP44.x), _e1.y != _b1.x && _e1.y != _b1.w && (_TMP27.y || _TMP28.y || !_TMP29.y) && (_TMP30.y || _TMP31.y || _TMP32.y || _TMP33.y) && (!_TMP34.y && !_TMP35.y || !_TMP36.y && !_TMP37.y || _TMP38.y && (!_TMP39.y && !_TMP40.y || !_TMP41.y && !_TMP42.y) || _TMP43.y || _TMP44.y), _e1.z != _b1.y && _e1.z != _b1.x && (_TMP27.z || _TMP28.z || !_TMP29.z) && (_TMP30.z || _TMP31.z || _TMP32.z || _TMP33.z) && (!_TMP34.z && !_TMP35.z || !_TMP36.z && !_TMP37.z || _TMP38.z && (!_TMP39.z && !_TMP40.z || !_TMP41.z && !_TMP42.z) || _TMP43.z || _TMP44.z), _e1.w != _b1.z && _e1.w != _b1.y && (_TMP27.w || _TMP28.w || !_TMP29.w) && (_TMP30.w || _TMP31.w || _TMP32.w || _TMP33.w) && (!_TMP34.w && !_TMP35.w || !_TMP36.w && !_TMP37.w || _TMP38.w && (!_TMP39.w && !_TMP40.w || !_TMP41.w && !_TMP42.w) || _TMP43.w || _TMP44.w));\n"
"    _interp_restriction_lv2_left = bvec4(_e1.x != _c3.z && _b1.y != _c3.z, _e1.y != _c3.w && _b1.z != _c3.w, _e1.z != _c3.x && _b1.w != _c3.x, _e1.w != _c3.y && _b1.x != _c3.y);\n"
"    _interp_restriction_lv2_up = bvec4(_e1.x != _c3.x && _b1.x != _c3.x, _e1.y != _c3.y && _b1.y != _c3.y, _e1.z != _c3.z && _b1.z != _c3.z, _e1.w != _c3.w && _b1.w != _c3.w);\n"
"    _x0324 = (_fx - vec4( 1.10000002E+00, 9.99999940E-02, -8.99999976E-01, 9.99999940E-02))/vec4( 7.99999952E-01, 7.99999952E-01, 7.99999952E-01, 7.99999952E-01);\n"
"    _TMP96 = min(vec4( 1.00000000E+00, 1.00000000E+00, 1.00000000E+00, 1.00000000E+00), _x0324);\n"
"    _TMP325 = max(vec4( 0.00000000E+00, 0.00000000E+00, 0.00000000E+00, 0.00000000E+00), _TMP96);\n"
"    _fx45 = _TMP325*_TMP325*(3.00000000E+00 - 2.00000000E+00*_TMP325);\n"
"    _x0334 = (_fx_left - vec4( 6.00000024E-01, 6.00000024E-01, -8.99999976E-01, -4.00000006E-01))/vec4( 7.99999952E-01, 7.99999952E-01, 7.99999952E-01, 8.00000012E-01);\n"
"    _TMP96 = min(vec4( 1.00000000E+00, 1.00000000E+00, 1.00000000E+00, 1.00000000E+00), _x0334);\n"
"    _TMP335 = max(vec4( 0.00000000E+00, 0.00000000E+00, 0.00000000E+00, 0.00000000E+00), _TMP96);\n"
"    _fx30 = _TMP335*_TMP335*(3.00000000E+00 - 2.00000000E+00*_TMP335);\n"
"    _x0344 = (_fx_up - vec4( 1.60000002E+00, -4.00000006E-01, -1.39999998E+00, 9.99999940E-02))/vec4( 8.00000072E-01, 8.00000012E-01, 7.99999952E-01, 7.99999952E-01);\n"
"    _TMP96 = min(vec4( 1.00000000E+00, 1.00000000E+00, 1.00000000E+00, 1.00000000E+00), _x0344);\n"
"    _TMP345 = max(vec4( 0.00000000E+00, 0.00000000E+00, 0.00000000E+00, 0.00000000E+00), _TMP96);\n"
"    _fx60 = _TMP345*_TMP345*(3.00000000E+00 - 2.00000000E+00*_TMP345);\n"
"    _a0356 = _e1 - _c3;\n"
"    _TMP353 = abs(_a0356);\n"
"    _a0360 = _e1 - _c3.zwxy;\n"
"    _TMP357 = abs(_a0360);\n"
"    _a0364 = _c3.wxyz - _h5;\n"
"    _TMP361 = abs(_a0364);\n"
"    _a0368 = _c3.wxyz - _h5.yzwx;\n"
"    _TMP365 = abs(_a0368);\n"
"    _a0372 = _b1.zwxy - _b1.wxyz;\n"
"    _TMP369 = abs(_a0372);\n"
"    _TMP45 = _TMP353 + _TMP357 + _TMP361 + _TMP365 + 4.00000000E+00*_TMP369;\n"
"    _a0378 = _b1.zwxy - _b1.yzwx;\n"
"    _TMP375 = abs(_a0378);\n"
"    _a0382 = _b1.zwxy - _i5;\n"
"    _TMP379 = abs(_a0382);\n"
"    _a0386 = _b1.wxyz - _i4;\n"
"    _TMP383 = abs(_a0386);\n"
"    _a0390 = _b1.wxyz - _b1;\n"
"    _TMP387 = abs(_a0390);\n"
"    _a0394 = _e1 - _c3.wxyz;\n"
"    _TMP391 = abs(_a0394);\n"
"    _TMP46 = _TMP375 + _TMP379 + _TMP383 + _TMP387 + 4.00000000E+00*_TMP391;\n"
"    _edr = bvec4((_TMP45 + 3.50000000E+00).x < _TMP46.x && _interp_restriction_lv1.x, (_TMP45 + 3.50000000E+00).y < _TMP46.y && _interp_restriction_lv1.y, (_TMP45 + 3.50000000E+00).z < _TMP46.z && _interp_restriction_lv1.z, (_TMP45 + 3.50000000E+00).w < _TMP46.w && _interp_restriction_lv1.w);\n"
"    _a0398 = _b1.wxyz - _c3.zwxy;\n"
"    _TMP395 = abs(_a0398);\n"
"    _a0402 = _b1.zwxy - _c3;\n"
"    _TMP399 = abs(_a0402);\n"
"    _edr_left = bvec4((2.00000000E+00*_TMP395).x <= _TMP399.x && _interp_restriction_lv2_left.x, (2.00000000E+00*_TMP395).y <= _TMP399.y && _interp_restriction_lv2_left.y, (2.00000000E+00*_TMP395).z <= _TMP399.z && _interp_restriction_lv2_left.z, (2.00000000E+00*_TMP395).w <= _TMP399.w && _interp_restriction_lv2_left.w);\n"
"    _a0406 = _b1.wxyz - _c3.zwxy;\n"
"    _TMP403 = abs(_a0406);\n"
"    _a0410 = _b1.zwxy - _c3;\n"
"    _TMP407 = abs(_a0410);\n"
"    _edr_up = bvec4(_TMP403.x >= (2.00000000E+00*_TMP407).x && _interp_restriction_lv2_up.x, _TMP403.y >= (2.00000000E+00*_TMP407).y && _interp_restriction_lv2_up.y, _TMP403.z >= (2.00000000E+00*_TMP407).z && _interp_restriction_lv2_up.z, _TMP403.w >= (2.00000000E+00*_TMP407).w && _interp_restriction_lv2_up.w);\n"
"    _nc45 = bvec4(_edr.x && bool(_fx45.x), _edr.y && bool(_fx45.y), _edr.z && bool(_fx45.z), _edr.w && bool(_fx45.w));\n"
"    _nc30 = bvec4(_edr.x && _edr_left.x && bool(_fx30.x), _edr.y && _edr_left.y && bool(_fx30.y), _edr.z && _edr_left.z && bool(_fx30.z), _edr.w && _edr_left.w && bool(_fx30.w));\n"
"    _nc60 = bvec4(_edr.x && _edr_up.x && bool(_fx60.x), _edr.y && _edr_up.y && bool(_fx60.y), _edr.z && _edr_up.z && bool(_fx60.z), _edr.w && _edr_up.w && bool(_fx60.w));\n"
"    _a0414 = _e1 - _b1.wxyz;\n"
"    _TMP411 = abs(_a0414);\n"
"    _a0418 = _e1 - _b1.zwxy;\n"
"    _TMP415 = abs(_a0418);\n"
"    _px = bvec4(_TMP411.x <= _TMP415.x, _TMP411.y <= _TMP415.y, _TMP411.z <= _TMP415.z, _TMP411.w <= _TMP415.w);\n"
"    _n1 = vec3(float(_B11.x), float(_B11.y), float(_B11.z));\n"
"    _n2 = vec3(float(_B3.x), float(_B3.y), float(_B3.z));\n"
"    _s = vec3(float(_E.x), float(_E.y), float(_E.z));\n"
"    _n3 = vec3(float(_H.x), float(_H.y), float(_H.z));\n"
"    _n4 = vec3(float(_H5.x), float(_H5.y), float(_H5.z));\n"
"    _aa = _n2 - _n1;\n"
"    _bb = _s - _n2;\n"
"    _cc = _n3 - _s;\n"
"    _dd = _n4 - _n3;\n"
"    _t = (7.00000000E+00*(_bb + _cc) - 3.00000000E+00*(_aa + _dd))/1.60000000E+01;\n"
"    _m = vec3(_s.x < 5.00000000E-01 ? (2.00000000E+00*_s).x : (2.00000000E+00*(1.00000000E+00 - _s)).x, _s.y < 5.00000000E-01 ? (2.00000000E+00*_s).y : (2.00000000E+00*(1.00000000E+00 - _s)).y, _s.z < 5.00000000E-01 ? (2.00000000E+00*_s).z : (2.00000000E+00*(1.00000000E+00 - _s)).z);\n"
"    _TMP53 = abs(_bb);\n"
"    _b0422 = 6.49999976E-01*_TMP53;\n"
"    _m = min(_m, _b0422);\n"
"    _TMP54 = abs(_cc);\n"
"    _b0426 = 6.49999976E-01*_TMP54;\n"
"    _m = min(_m, _b0426);\n"
"    _a0428 = -_m;\n"
"    _TMP85 = min(_m, _t);\n"
"    _TMP427 = max(_a0428, _TMP85);\n"
"    _s1 = (2.00000000E+00*_fp.y - 1.00000000E+00)*_TMP427 + _s;\n"
"    _n1 = vec3(float(_D0.x), float(_D0.y), float(_D0.z));\n"
"    _n2 = vec3(float(_D.x), float(_D.y), float(_D.z));\n"
"    _n3 = vec3(float(_F.x), float(_F.y), float(_F.z));\n"
"    _n4 = vec3(float(_F4.x), float(_F4.y), float(_F4.z));\n"
"    _aa = _n2 - _n1;\n"
"    _bb = _s1 - _n2;\n"
"    _cc = _n3 - _s1;\n"
"    _dd = _n4 - _n3;\n"
"    _t = (7.00000000E+00*(_bb + _cc) - 3.00000000E+00*(_aa + _dd))/1.60000000E+01;\n"
"    _m = vec3(_s1.x < 5.00000000E-01 ? (2.00000000E+00*_s1).x : (2.00000000E+00*(1.00000000E+00 - _s1)).x, _s1.y < 5.00000000E-01 ? (2.00000000E+00*_s1).y : (2.00000000E+00*(1.00000000E+00 - _s1)).y, _s1.z < 5.00000000E-01 ? (2.00000000E+00*_s1).z : (2.00000000E+00*(1.00000000E+00 - _s1)).z);\n"
"    _TMP55 = abs(_bb);\n"
"    _b0436 = 6.49999976E-01*_TMP55;\n"
"    _m = min(_m, _b0436);\n"
"    _TMP56 = abs(_cc);\n"
"    _b0440 = 6.49999976E-01*_TMP56;\n"
"    _m = min(_m, _b0440);\n"
"    _a0442 = -_m;\n"
"    _TMP85 = min(_m, _t);\n"
"    _TMP441 = max(_a0442, _TMP85);\n"
"    _s0 = (2.00000000E+00*_fp.x - 1.00000000E+00)*_TMP441 + _s1;\n"
"    _nc = bvec4(_nc30.x || _nc60.x || _nc45.x, _nc30.y || _nc60.y || _nc45.y, _nc30.z || _nc60.z || _nc45.z, _nc30.w || _nc60.w || _nc45.w);\n"
"    _blend2 = 0.00000000E+00;\n"
"    _blend1 = 0.00000000E+00;\n"
"    _a0448 = vec4(float(_nc45.x), float(_nc45.y), float(_nc45.z), float(_nc45.w));\n"
"    _TMP58 = dot(_a0448, _fx45);\n"
"    _a0450 = vec4(float(_nc30.x), float(_nc30.y), float(_nc30.z), float(_nc30.w));\n"
"    _TMP59 = dot(_a0450, _fx30);\n"
"    _a0452 = vec4(float(_nc60.x), float(_nc60.y), float(_nc60.z), float(_nc60.w));\n"
"    _TMP60 = dot(_a0452, _fx60);\n"
"    _TMP61 = max(vec4(_TMP59, _TMP59, _TMP59, _TMP59), vec4(_TMP60, _TMP60, _TMP60, _TMP60));\n"
"    _maximo = max(_TMP61, vec4(_TMP58, _TMP58, _TMP58, _TMP58));\n"
"    if (_nc.x) { \n"
"        if (_px.x) { \n"
"            _TMP62 = _F;\n"
"        } else {\n"
"            _TMP62 = _H;\n"
"        } \n"
"        _pix1 = _TMP62;\n"
"        _blend1 = _maximo.x;\n"
"    } else {\n"
"        if (_nc.y) { \n"
"            if (_px.y) { \n"
"                _TMP63 = _B3;\n"
"            } else {\n"
"                _TMP63 = _F;\n"
"            } \n"
"            _pix1 = _TMP63;\n"
"            _blend1 = _maximo.y;\n"
"        } else {\n"
"            if (_nc.z) { \n"
"                if (_px.z) { \n"
"                    _TMP64 = _D;\n"
"                } else {\n"
"                    _TMP64 = _B3;\n"
"                } \n"
"                _pix1 = _TMP64;\n"
"                _blend1 = _maximo.z;\n"
"            } else {\n"
"                if (_nc.w) { \n"
"                    if (_px.w) { \n"
"                        _TMP65 = _H;\n"
"                    } else {\n"
"                        _TMP65 = _D;\n"
"                    } \n"
"                    _pix1 = _TMP65;\n"
"                    _blend1 = _maximo.w;\n"
"                } \n"
"            } \n"
"        } \n"
"    } \n"
"    if (_nc.w) { \n"
"        if (_px.w) { \n"
"            _TMP66 = _H;\n"
"        } else {\n"
"            _TMP66 = _D;\n"
"        } \n"
"        _pix2 = _TMP66;\n"
"        _blend2 = _maximo.w;\n"
"    } else {\n"
"        if (_nc.z) { \n"
"            if (_px.z) { \n"
"                _TMP67 = _D;\n"
"            } else {\n"
"                _TMP67 = _B3;\n"
"            } \n"
"            _pix2 = _TMP67;\n"
"            _blend2 = _maximo.z;\n"
"        } else {\n"
"            if (_nc.y) { \n"
"                if (_px.y) { \n"
"                    _TMP68 = _B3;\n"
"                } else {\n"
"                    _TMP68 = _F;\n"
"                } \n"
"                _pix2 = _TMP68;\n"
"                _blend2 = _maximo.y;\n"
"            } else {\n"
"                if (_nc.x) { \n"
"                    if (_px.x) { \n"
"                        _TMP69 = _F;\n"
"                    } else {\n"
"                        _TMP69 = _H;\n"
"                    } \n"
"                    _pix2 = _TMP69;\n"
"                    _blend2 = _maximo.x;\n"
"                } \n"
"            } \n"
"        } \n"
"    } \n"
"    _b0458 = vec3(float(_pix1.x), float(_pix1.y), float(_pix1.z));\n"
"    _TMP70 = _s0 + _blend1*(_b0458 - _s0);\n"
"    _res1 = vec3(float(_TMP70.x), float(_TMP70.y), float(_TMP70.z));\n"
"    _b0460 = vec3(float(_pix2.x), float(_pix2.y), float(_pix2.z));\n"
"    _TMP71 = _s0 + _blend2*(_b0460 - _s0);\n"
"    _res2 = vec3(float(_TMP71.x), float(_TMP71.y), float(_TMP71.z));\n"
"    _a0464 = _E - _res1;\n"
"    _TMP94 = abs(vec3(float(_a0464.x), float(_a0464.y), float(_a0464.z)));\n"
"    _df0462 = vec3(float(_TMP94.x), float(_TMP94.y), float(_TMP94.z));\n"
"    _TMP72 = _df0462.x + _df0462.y + _df0462.z;\n"
"    _a0468 = _E - _res2;\n"
"    _TMP94 = abs(vec3(float(_a0468.x), float(_a0468.y), float(_a0468.z)));\n"
"    _df0466 = vec3(float(_TMP94.x), float(_TMP94.y), float(_TMP94.z));\n"
"    _TMP73 = _df0466.x + _df0466.y + _df0466.z;\n"
"    _TMP74 = float((_TMP73 >= _TMP72));\n"
"    _res = _res1 + _TMP74*(_res2 - _res1);\n"
"    _TMP95 = pow(float(_res.x), 2.40039062E+00);\n"
"    _TMP86 = float(_TMP95);\n"
"    _TMP95 = pow(float(_res.y), 2.40039062E+00);\n"
"    _TMP87 = float(_TMP95);\n"
"    _TMP95 = pow(float(_res.z), 2.40039062E+00);\n"
"    _TMP88 = float(_TMP95);\n"
"    _TMP75 = vec3(_TMP86, _TMP87, _TMP88);\n"
"    _color = vec3(float(_TMP75.x), float(_TMP75.y), float(_TMP75.z));\n"
"    _ddy = _fp.y - 5.00000000E-01;\n"
"    _v_weight_00 = _ddy/5.79999983E-01;\n"
"    if (_v_weight_00 > 1.00000000E+00) { \n"
"        _v_weight_00 = 1.00000000E+00;\n"
"    } \n"
"    _v_weight_00 = 1.00000000E+00 - _v_weight_00*_v_weight_00;\n"
"    _v_weight_00 = _v_weight_00*_v_weight_00;\n"
"    _color = _color*vec3(_v_weight_00, _v_weight_00, _v_weight_00);\n"
"    if (_ddy > 0.00000000E+00) { \n"
"        _coords10 = vec3(float(_H.x), float(_H.y), float(_H.z));\n"
"        _ddy = 1.00000000E+00 - _ddy;\n"
"    } else {\n"
"        _coords10 = vec3(float(_B3.x), float(_B3.y), float(_B3.z));\n"
"        _ddy = 1.00000000E+00 + _ddy;\n"
"    } \n"
"    _TMP89 = pow(_coords10.x, 2.40000010E+00);\n"
"    _TMP90 = pow(_coords10.y, 2.40000010E+00);\n"
"    _TMP91 = pow(_coords10.z, 2.40000010E+00);\n"
"    _colorNB = vec3(_TMP89, _TMP90, _TMP91);\n"
"    _v_weight_10 = _ddy/5.79999983E-01;\n"
"    if (_v_weight_10 > 1.00000000E+00) { \n"
"        _v_weight_10 = 1.00000000E+00;\n"
"    } \n"
"    _v_weight_10 = 1.00000000E+00 - _v_weight_10*_v_weight_10;\n"
"    _v_weight_10 = _v_weight_10*_v_weight_10;\n"
"    _color = _color + _colorNB*vec3(_v_weight_10, _v_weight_10, _v_weight_10);\n"
"    _color = _color*vec3( 1.45000005E+00, 1.45000005E+00, 1.45000005E+00);\n"
"    _TMP89 = pow(_color.x, 4.54545438E-01);\n"
"    _TMP90 = pow(_color.y, 4.54545438E-01);\n"
"    _TMP91 = pow(_color.z, 4.54545438E-01);\n"
"    _TMP76 = vec3(_TMP89, _TMP90, _TMP91);\n"
"    _TMP92 = min(vec3( 1.00000000E+00, 1.00000000E+00, 1.00000000E+00), _TMP76);\n"
"    _TMP497 = max(vec3( 0.00000000E+00, 0.00000000E+00, 0.00000000E+00), _TMP92);\n"
"    _ret_0 = vec4(_TMP497.x, _TMP497.y, _TMP497.z, 1.00000000E+00);\n"
"    FragColor = _ret_0;\n"
"    return;\n"
"} \n"
"#endif\n"
},
