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
"COMPAT_VARYING     float _frame_rotation;\n"
"struct input_dummy {\n"
"    vec2 _video_size;\n"
"    vec2 _texture_size;\n"
"    vec2 _output_dummy_size;\n"
"    float _frame_count;\n"
"    float _frame_direction;\n"
"    float _frame_rotation;\n"
"float _placeholder26;\n"
"};\n"
"vec4 _oPosition1;\n"
"vec4 _r0006;\n"
"COMPAT_ATTRIBUTE vec4 VertexCoord;\n"
"COMPAT_ATTRIBUTE vec4 COLOR;\n"
"COMPAT_VARYING vec4 COL0;\n"
"COMPAT_ATTRIBUTE vec4 TexCoord;\n"
"COMPAT_VARYING vec4 TEX0;\n"
" \n"
"uniform mat4 MVPMatrix;\n"
"uniform int FrameDirection;\n"
"uniform int FrameCount;\n"
"uniform COMPAT_PRECISION vec2 OutputSize;\n"
"uniform COMPAT_PRECISION vec2 TextureSize;\n"
"uniform COMPAT_PRECISION vec2 InputSize;\n"
"void main()\n"
"{\n"
"    vec4 _oColor;\n"
"    vec2 _oTexCoord;\n"
"    _r0006 = VertexCoord.x*MVPMatrix[0];\n"
"    _r0006 = _r0006 + VertexCoord.y*MVPMatrix[1];\n"
"    _r0006 = _r0006 + VertexCoord.z*MVPMatrix[2];\n"
"    _r0006 = _r0006 + VertexCoord.w*MVPMatrix[3];\n"
"    _oPosition1 = _r0006;\n"
"    _oColor = COLOR;\n"
"    _oTexCoord = TexCoord.xy;\n"
"    gl_Position = _r0006;\n"
"    COL0 = COLOR;\n"
"    TEX0.xy = TexCoord.xy;\n"
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
"COMPAT_VARYING     float _frame_rotation;\n"
"struct input_dummy {\n"
"    vec2 _video_size;\n"
"    vec2 _texture_size;\n"
"    vec2 _output_dummy_size;\n"
"    float _frame_count;\n"
"    float _frame_direction;\n"
"    float _frame_rotation;\n"
"float _placeholder27;\n"
"};\n"
"vec4 _ret_0;\n"
"float _TMP2;\n"
"float _TMP6;\n"
"float _TMP5;\n"
"float _TMP4;\n"
"float _TMP3;\n"
"vec4 _TMP0;\n"
"input_dummy _IN1;\n"
"float _a0012;\n"
"float _c0012;\n"
"float _a0014;\n"
"COMPAT_VARYING vec4 TEX0;\n"
" \n"
"uniform sampler2D Texture;\n"
"uniform int FrameDirection;\n"
"uniform int FrameCount;\n"
"uniform COMPAT_PRECISION vec2 OutputSize;\n"
"uniform COMPAT_PRECISION vec2 TextureSize;\n"
"uniform COMPAT_PRECISION vec2 InputSize;\n"
"void main()\n"
"{\n"
"    vec3 _res;\n"
"    vec3 _dotMaskWeights;\n"
"    _TMP0 = COMPAT_TEXTURE(Texture, TEX0.xy);\n"
"    _a0012 = (TEX0.x*TextureSize.x*OutputSize.x)/InputSize.x;\n"
"    _a0014 = _a0012/2.00000000E+00;\n"
"    _TMP3 = abs(_a0014);\n"
"    _TMP4 = fract(_TMP3);\n"
"    _TMP5 = abs(2.00000000E+00);\n"
"    _c0012 = _TMP4*_TMP5;\n"
"    if (_a0012 < 0.00000000E+00) { \n"
"        _TMP6 = -_c0012;\n"
"    } else {\n"
"        _TMP6 = _c0012;\n"
"    } \n"
"    _TMP2 = floor(_TMP6);\n"
"    _dotMaskWeights = vec3( 1.00000000E+00, 6.99999988E-01, 1.00000000E+00) + _TMP2*vec3( -3.00000012E-01, 3.00000012E-01, -3.00000012E-01);\n"
"    _res = _TMP0.xyz*_dotMaskWeights;\n"
"    _ret_0 = vec4(_res.x, _res.y, _res.z, 1.00000000E+00);\n"
"    FragColor = _ret_0;\n"
"    return;\n"
"} \n"
"#endif\n"
},
