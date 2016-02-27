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
"COMPAT_VARYING     vec4 _color1;\n"
"COMPAT_VARYING     float _frame_rotation;\n"
"struct input_dummy {\n"
"    vec2 _video_size;\n"
"    vec2 _texture_size;\n"
"    vec2 _output_dummy_size;\n"
"    float _frame_count;\n"
"    float _frame_direction;\n"
"    float _frame_rotation;\n"
"};\n"
"struct output_dummy {\n"
"    vec4 _color1;\n"
"};\n"
"vec4 _oPosition1;\n"
"input_dummy _IN1;\n"
"vec4 _r0006;\n"
"COMPAT_ATTRIBUTE vec4 VertexCoord;\n"
"COMPAT_ATTRIBUTE vec4 COLOR;\n"
"COMPAT_ATTRIBUTE vec4 TexCoord;\n"
"COMPAT_VARYING vec4 COL0;\n"
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
"    vec2 _otexCoord;\n"
"    vec2 _shift;\n"
"    vec2 _overscan_coord;\n"
"    _r0006 = VertexCoord.x*MVPMatrix[0];\n"
"    _r0006 = _r0006 + VertexCoord.y*MVPMatrix[1];\n"
"    _r0006 = _r0006 + VertexCoord.z*MVPMatrix[2];\n"
"    _r0006 = _r0006 + VertexCoord.w*MVPMatrix[3];\n"
"    _oPosition1 = _r0006;\n"
"    _oColor = COLOR;\n"
"    _shift = (5.00000000E-01*InputSize)/TextureSize;\n"
"    _overscan_coord = (TexCoord.xy - _shift) + _shift;\n"
"    _otexCoord = _overscan_coord;\n"
"    gl_Position = _r0006;\n"
"    COL0 = COLOR;\n"
"    TEX0.xy = _overscan_coord;\n"
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
"COMPAT_VARYING     vec4 _color;\n"
"COMPAT_VARYING     float _frame_rotation;\n"
"struct input_dummy {\n"
"    vec2 _video_size;\n"
"    vec2 _texture_size;\n"
"    vec2 _output_dummy_size;\n"
"    float _frame_count;\n"
"    float _frame_direction;\n"
"    float _frame_rotation;\n"
"};\n"
"struct output_dummy {\n"
"    vec4 _color;\n"
"};\n"
"vec4 _ret_0;\n"
"vec3 _TMP5;\n"
"float _TMP4;\n"
"float _TMP3;\n"
"float _TMP2;\n"
"float _TMP1;\n"
"vec4 _TMP0;\n"
"uniform sampler2D Texture;\n"
"input_dummy _IN1;\n"
"vec3 _TMP29;\n"
"COMPAT_VARYING vec4 TEX0;\n"
" \n"
"uniform int FrameDirection;\n"
"uniform int FrameCount;\n"
"uniform COMPAT_PRECISION vec2 OutputSize;\n"
"uniform COMPAT_PRECISION vec2 TextureSize;\n"
"uniform COMPAT_PRECISION vec2 InputSize;\n"
"void main()\n"
"{\n"
"    vec2 _fragcoord;\n"
"    vec3 _satColor;\n"
"    vec3 _conColor;\n"
"    _fragcoord = TEX0.xy*(TextureSize.xy/InputSize.xy);\n"
"    _TMP0 = COMPAT_TEXTURE(Texture, TEX0.xy);\n"
"    _TMP1 = dot(_TMP0.xyz, vec3( 2.12599993E-01, 7.15200007E-01, 7.22000003E-02));\n"
"    _satColor = vec3(_TMP1, _TMP1, _TMP1) + (_TMP0.xyz - vec3(_TMP1, _TMP1, _TMP1));\n"
"    _conColor = vec3( 5.00000000E-01, 5.00000000E-01, 5.00000000E-01) + (_satColor - vec3( 5.00000000E-01, 5.00000000E-01, 5.00000000E-01));\n"
"    _TMP2 = pow(_conColor.x, 1.09090912E+00);\n"
"    _TMP3 = pow(_conColor.y, 1.09090912E+00);\n"
"    _TMP4 = pow(_conColor.z, 1.09090912E+00);\n"
"    _conColor = vec3(_TMP2, _TMP3, _TMP4);\n"
"    _TMP5 = min(vec3( 1.00000000E+00, 1.00000000E+00, 1.00000000E+00), _conColor);\n"
"    _TMP29 = max(vec3( 0.00000000E+00, 0.00000000E+00, 0.00000000E+00), _TMP5);\n"
"    _conColor = _TMP29;\n"
"    if (_fragcoord.y > 0.00000000E+00 && _fragcoord.y < 1.00000000E+00) { \n"
"    } else {\n"
"        _conColor = vec3( 0.00000000E+00, 0.00000000E+00, 0.00000000E+00);\n"
"    } \n"
"    if (_fragcoord.x > 0.00000000E+00 && _fragcoord.x < 1.00000000E+00) { \n"
"    } else {\n"
"        _conColor = vec3( 0.00000000E+00, 0.00000000E+00, 0.00000000E+00);\n"
"    } \n"
"    _ret_0 = vec4(_conColor.x, _conColor.y, _conColor.z, 1.00000000E+00);\n"
"    FragColor = _ret_0;\n"
"    return;\n"
"} \n"
"#endif\n"
},
