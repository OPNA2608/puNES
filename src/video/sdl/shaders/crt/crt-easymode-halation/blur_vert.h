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
"};\n"
"vec4 _oPosition1;\n"
"vec4 _r0005;\n"
"COMPAT_ATTRIBUTE vec4 VertexCoord;\n"
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
"    vec2 _otexCoord;\n"
"    _r0005 = VertexCoord.x*MVPMatrix[0];\n"
"    _r0005 = _r0005 + VertexCoord.y*MVPMatrix[1];\n"
"    _r0005 = _r0005 + VertexCoord.z*MVPMatrix[2];\n"
"    _r0005 = _r0005 + VertexCoord.w*MVPMatrix[3];\n"
"    _oPosition1 = _r0005;\n"
"    _otexCoord = TexCoord.xy;\n"
"    gl_Position = _r0005;\n"
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
"};\n"
"vec4 _ret_0;\n"
"vec4 _TMP1;\n"
"uniform sampler2D Texture;\n"
"input_dummy _IN1;\n"
"float _TMP5;\n"
"float _x0006;\n"
"vec2 _c0010;\n"
"COMPAT_VARYING vec4 TEX0;\n"
" \n"
"uniform int FrameDirection;\n"
"uniform int FrameCount;\n"
"uniform COMPAT_PRECISION vec2 OutputSize;\n"
"uniform COMPAT_PRECISION vec2 TextureSize;\n"
"uniform COMPAT_PRECISION vec2 InputSize;\n"
"void main()\n"
"{\n"
"    vec3 _col;\n"
"    float _dy;\n"
"    float _k_total;\n"
"    int _i1;\n"
"    vec3 _TMP4;\n"
"    _col = vec3( 0.00000000E+00, 0.00000000E+00, 0.00000000E+00);\n"
"    _dy = 1.00000000E+00/TextureSize.y;\n"
"    _k_total = 0.00000000E+00;\n"
"    _i1 = -4;\n"
"    for (; _i1 <= 4; _i1 = _i1 + 1) { \n"
"        _x0006 = float((-3.49999994E-01*float(_i1)*float(_i1)));\n"
"        _TMP5 = pow(2.71828198E+00, _x0006);\n"
"        _k_total = _k_total + _TMP5;\n"
"        _c0010 = TEX0.xy + vec2(0.00000000E+00, float(_i1)*_dy);\n"
"        _TMP1 = COMPAT_TEXTURE(Texture, _c0010);\n"
"        _col = _col + _TMP5*_TMP1.xyz;\n"
"    } \n"
"    _TMP4 = _col/_k_total;\n"
"    _ret_0 = vec4(_TMP4.x, _TMP4.y, _TMP4.z, 1.00000000E+00);\n"
"    FragColor = _ret_0;\n"
"    return;\n"
"} \n"
"#endif\n"
},
