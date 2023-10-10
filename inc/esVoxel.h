/*
--------------------------------------------------
    James William Fletcher (github.com/mrbid)
        July 2023 - esVoxel.h v1.0
--------------------------------------------------

    A pretty good color converter: https://www.easyrgb.com/en/convert.php

    A voxel is: vec4(x,y,z,texture_offset)
    voxel_uvmap has one "float" change that is based on: 1.f/(tiles_image_width/16.f) = 1/(272/16) = 0.058823529529

    Requires:
        - vec.h: https://gist.github.com/mrbid/77a92019e1ab8b86109bf103166bd04e
        - mat.h: https://gist.github.com/mrbid/cbc69ec9d99b0fda44204975fcbeae7c
    
*/

#ifndef AUX_H
#define AUX_H

#include "vec.h"
#include "mat.h"

//*************************************
// VOXEL STRUCTURE
//*************************************
typedef struct
{
    GLuint vid; // Vertex Array Buffer ID
    GLuint iid;	// Index Array Buffer ID
    GLuint nid;	// Normal Array Buffer ID
    GLuint tid;	// TexCoord Array Buffer ID
} ESModel;
const GLfloat voxel_vertices[] = {-0.5,0.5,0.5,0.5,-0.5,0.5,0.5,0.5,0.5,0.5,-0.5,0.5,-0.5,-0.5,-0.5,0.5,-0.5,-0.5,-0.5,-0.5,0.5,-0.5,0.5,-0.5,-0.5,-0.5,-0.5,0.5,0.5,-0.5,-0.5,-0.5,-0.5,-0.5,0.5,-0.5,0.5,0.5,0.5,0.5,-0.5,-0.5,0.5,0.5,-0.5,-0.5,0.5,0.5,0.5,0.5,-0.5,-0.5,0.5,-0.5,-0.5,-0.5,0.5,-0.5,-0.5,0.5,-0.5,0.5,0.5,0.5,-0.5,-0.5,0.5,-0.5,0.5,0.5,0.5,0.5,0.5,0.5,-0.5};
const GLfloat voxel_normals[] = {0,0,1,0,0,1,0,0,1,0,-1,0,0,-1,0,0,-1,0,-1,0,0,-1,0,0,-1,0,0,0,0,-1,0,0,-1,0,0,-1,1,0,-0,1,0,-0,1,0,-0,0,1,-0,0,1,-0,0,1,-0,0,-0,1,0,-1,0,-1,0,0,0,0,-1,1,0,0,0,1,-0,0,1,-0};
const GLfloat voxel_uvmap[] = {0,1,0.058823529529,0,0.058823529529,1,0.058823529529,1,0,0,0.058823529529,0,0,0,0.058823529,1,0,1,0.058823529,0,0,1,0,0,0.058823529529,1,0,0,0.058823529529,0,0,0,0.058823529529,1,0,1,0,0,0,1,0.058823529,0,0.058823529,1,0,1,0.058823529,0,0.058823529,1};
const GLubyte voxel_indices[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,0,18,1,3,19,4,6,20,7,9,21,10,12,22,13,15,23,24};
const GLsizeiptr voxel_numind = 36;
ESModel mdlVoxel;
GLuint texmap;
unsigned char tiles[];

const GLfloat hud_vertices[] = {-1,1,0,1,-1,0,1,1,0,-1,-1,0};
const GLfloat hud_uvmap[] = {0,0, 1,1, 1,0, 0,1};
const GLubyte hud_indices[] = {0,1,2,0,3,1};
const GLsizeiptr hud_numind = 6;
ESModel mdlPlane;
SDL_Surface* sHud;
GLuint hudmap;

//*************************************
// SHADER
//*************************************
void makeHud();
void shadeHud(GLint* position, GLint* texcoord, GLint* sampler);
void flipHud()
{
    glBindTexture(GL_TEXTURE_2D, hudmap);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, sHud->w, sHud->h, 0, GL_RGBA, GL_UNSIGNED_BYTE, sHud->pixels);
}

void makeVoxel();
void shadeVoxel(GLint* position, GLint* projection, GLint* view, GLint* voxel, GLint* normal, GLint* texcoord, GLint* sampler);

//*************************************
// UTILITY CODE
//*************************************
GLuint esRand(const GLuint min, const GLuint max)
{
    return (rand()%(max+1-min))+min;
}
GLfloat esRandFloat(const GLfloat min, const GLfloat max)
{
    static GLfloat rrndmax = 1.f/(GLfloat)RAND_MAX;
    return (((GLfloat)rand()) * rrndmax) * (max-min) + min;
}
void esBind(const GLenum target, GLuint* buffer, const void* data, const GLsizeiptr datalen, const GLenum usage)
{
    glGenBuffers(1, buffer);
    glBindBuffer(target, *buffer);
    glBufferData(target, datalen, data, usage);
}
void esRebind(const GLenum target, GLuint* buffer, const void* data, const GLsizeiptr datalen, const GLenum usage)
{
    glBindBuffer(target, *buffer);
    glBufferData(target, datalen, data, usage);
}
GLuint esLoadTexture(const GLuint w, const GLuint h, const unsigned char* data)
{
    GLuint textureId;
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    glGenTextures(1, &textureId);
    glBindTexture(GL_TEXTURE_2D, textureId);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, w, h, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    return textureId;
}
GLuint esLoadTextureA(const GLuint w, const GLuint h, const unsigned char* data, const GLuint linear)
{
    GLuint textureId;
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    glGenTextures(1, &textureId);
    glBindTexture(GL_TEXTURE_2D, textureId);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    if(linear == 0)
    {
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    }
    else
    {
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    }
    return textureId;
}

//*************************************
// SHADER CODE
//*************************************
const GLchar* v0 =
    "#version 100\n"
    "attribute vec4 position;\n"
    "attribute vec2 texcoord;\n"
    "varying vec2 vtc;\n"
    "void main()\n"
    "{\n"
        "vtc = texcoord;\n"
        "gl_Position = position;\n"
    "}\n";

const GLchar* f0 =
    "#version 100\n"
    "precision highp float;\n"
    "varying vec2 vtc;\n"
    "uniform sampler2D tex;\n"
    "void main()\n"
    "{\n"
        "gl_FragColor = texture2D(tex, vtc);\n"
    "}\n";

#define VERTEX_SHADE
#ifdef VERTEX_SHADE

/*
    > darker darks
*/

    const GLchar* v1 =
        "#version 100\n"
        "uniform mat4 view;\n"
        "uniform mat4 projection;\n"
        "uniform vec4 voxel;\n"
        "attribute vec4 position;\n"
        "attribute vec3 normal;\n"
        "attribute vec2 texcoord;\n"
        "varying float lambertian;\n"
        "varying vec2 vtc;\n"
        "varying float vto;\n"
        "void main()\n"
        "{\n"
            "vtc = texcoord;\n"
            "mat4 model;\n"
            "model[0] = vec4(1.0, 0.0, 0.0, 0.0);\n"
            "model[1] = vec4(0.0, 1.0, 0.0, 0.0);\n"
            "model[2] = vec4(0.0, 0.0, 1.0, 0.0);\n"
            "model[3] = vec4(voxel.x, voxel.y, voxel.z, 1.0);\n"
            "mat4 modelview = view * model;\n"
            "vec4 vertPos4 = modelview * position;\n"
            "vec3 vertPos = vertPos4.xyz / vertPos4.w;\n"
#ifdef SKYBLUE
            "lambertian = max(dot(normalize(-vertPos), normalize(vec3(modelview * vec4(normal, 0.0)))), 0.0);\n"
#else
            "lambertian = max(dot(normalize(-vertPos), normalize(vec3(modelview * vec4(normal, 0.0)))), 0.0) * clamp(1.0 - (length(vertPos)*0.002), 0.0, 1.0);\n"
#endif
            "vto = voxel.w;\n"
            "gl_Position = projection * vertPos4;\n"
        "}\n";

    const GLchar* f1 =
        "#version 100\n"
        "precision highp float;\n"
        "varying float lambertian;\n"
        "varying vec2 vtc;\n"
        "varying float vto;\n"
        "uniform sampler2D tex;\n"
        "void main()\n"
        "{\n"
            "vec4 tcol = texture2D(tex, vec2(vtc.x+(0.058823529*vto), vtc.y));\n"
            "gl_FragColor = vec4((tcol.xyz*0.64)+(lambertian*tcol.xyz), 1.0);\n"
        "}\n";

/*
    > smoother shading
*/

//     const GLchar* v1 =
//         "#version 100\n"
//         "uniform mat4 view;\n"
//         "uniform mat4 projection;\n"
//         "uniform vec4 voxel;\n"
//         "attribute vec4 position;\n"
//         "attribute vec3 normal;\n"
//         "attribute vec2 texcoord;\n"
//         "varying float lambertian;\n"
//         "varying vec2 vtc;\n"
//         "varying float vto;\n"
//         "void main()\n"
//         "{\n"
//             "vtc = texcoord;\n"
//             "mat4 model;\n"
//             "model[0] = vec4(1.0, 0.0, 0.0, 0.0);\n"
//             "model[1] = vec4(0.0, 1.0, 0.0, 0.0);\n"
//             "model[2] = vec4(0.0, 0.0, 1.0, 0.0);\n"
//             "model[3] = vec4(voxel.x, voxel.y, voxel.z, 1.0);\n"
//             "mat4 modelview = view * model;\n"
//             "vec4 vertPos4 = modelview * position;\n"
//             "vec3 vertPos = vertPos4.xyz / vertPos4.w;\n"
// #ifdef SKYBLUE
//             "lambertian = clamp(max(dot(normalize(-vertPos), normalize(vec3(modelview * vec4(normal, 0.0)))), 0.0), 0.64, 1.0);\n"
// #else
//             "lambertian = clamp(max(dot(normalize(-vertPos), normalize(vec3(modelview * vec4(normal, 0.0)))), 0.0) * clamp(1.0 - (length(vertPos)*0.002), 0.0, 1.0), 0.64, 1.0);\n"
// #endif
//             "vto = voxel.w;\n"
//             "gl_Position = projection * vertPos4;\n"
//         "}\n";

//     const GLchar* f1 =
//         "#version 100\n"
//         "precision mediump float;\n"
//         "varying float lambertian;\n"
//         "varying vec2 vtc;\n"
//         "varying float vto;\n"
//         "uniform sampler2D tex;\n"
//         "void main()\n"
//         "{\n"
//             "vec4 tcol = texture2D(tex, vec2(vtc.x+(0.058823529*vto), vtc.y));\n"
// #ifdef SKYBLUE
//             "gl_FragColor = vec4((tcol.xyz*0.64)+(lambertian*tcol.xyz), 1.0);\n"
// #else
//             "gl_FragColor = vec4((tcol.xyz*0.62)+(lambertian*tcol.xyz), 1.0);\n"
// #endif
//         "}\n";

#else

/*
    > darker darks
*/

    const GLchar* v1 =
        "#version 100\n"
        "uniform mat4 view;\n"
        "uniform mat4 projection;\n"
        "uniform vec4 voxel;\n"
        "attribute vec4 position;\n"
        "attribute vec3 normal;\n"
        "attribute vec2 texcoord;\n"
        "varying vec3 vertPos;\n"
        "varying vec3 vertNorm;\n"
        "varying vec2 vtc;\n"
        "varying float vto;\n"
        "void main()\n"
        "{\n"
            "vtc = texcoord;\n"
            "mat4 model;\n"
            "model[0] = vec4(1.0, 0.0, 0.0, 0.0);\n"
            "model[1] = vec4(0.0, 1.0, 0.0, 0.0);\n"
            "model[2] = vec4(0.0, 0.0, 1.0, 0.0);\n"
            "model[3] = vec4(voxel.x, voxel.y, voxel.z, 1.0);\n"
            "mat4 modelview = view * model;\n"
            "vec4 vertPos4 = modelview * position;\n"
            "vertPos = vertPos4.xyz / vertPos4.w;\n"
            "vertNorm = vec3(modelview * vec4(normal, 0.0));\n"
            "vto = voxel.w;\n"
            "gl_Position = projection * vertPos4;\n"
        "}\n";

    const GLchar* f1 =
        "#version 100\n"
        "precision mediump float;\n"
        "varying vec3 vertPos;\n"
        "varying vec3 vertNorm;\n"
        "varying vec2 vtc;\n"
        "varying float vto;\n"
        "uniform sampler2D tex;\n"
        "void main()\n"
        "{\n"
            "vec4 tcol = texture2D(tex, vec2(vtc.x+(0.058823529*vto), vtc.y));\n"
            "vec3 ambientColor = tcol.xyz * 0.64;\n"
            "float lambertian = max(dot(normalize(-vertPos), normalize(vertNorm)), 0.0);\n"
            "gl_FragColor = vec4(ambientColor + lambertian*tcol.xyz, 1.0);\n"
        "}\n";

/*
    > bright at distance
*/

    // const GLchar* v1 =
    //     "#version 100\n"
    //     "uniform mat4 view;\n"
    //     "uniform mat4 projection;\n"
    //     "uniform vec4 voxel;\n"
    //     "attribute vec4 position;\n"
    //     "attribute vec3 normal;\n"
    //     "attribute vec2 texcoord;\n"
    //     "varying vec3 lightDir;\n"
    //     "varying vec3 vertNorm;\n"
    //     "varying vec2 vtc;\n"
    //     "varying float vto;\n"
    //     "void main()\n"
    //     "{\n"
    //         "vtc = texcoord;\n"
    //         "mat4 model;\n"
    //         "model[0] = vec4(1.0, 0.0, 0.0, 0.0);\n"
    //         "model[1] = vec4(0.0, 1.0, 0.0, 0.0);\n"
    //         "model[2] = vec4(0.0, 0.0, 1.0, 0.0);\n"
    //         "model[3] = vec4(voxel.x, voxel.y, voxel.z, 1.0);\n"
    //         "mat4 modelview = view * model;\n"
    //         "vec4 vertPos4 = modelview * position;\n"
    //         "vec3 vertPos = vertPos4.xyz / vertPos4.w;\n"
    //         "lightDir = normalize(-vertPos);\n"
    //         "vertNorm = vec3(modelview * vec4(normal, 0.0));\n"
    //         "vto = voxel.w;\n"
    //         "gl_Position = projection * vertPos4;\n"
    //     "}\n";

    // const GLchar* f1 =
    //     "#version 100\n"
    //     "precision mediump float;\n"
    //     "varying vec3 lightDir;\n"
    //     "varying vec3 vertNorm;\n"
    //     "varying vec2 vtc;\n"
    //     "varying float vto;\n"
    //     "uniform sampler2D tex;\n"
    //     "void main()\n"
    //     "{\n"
    //         "vec4 tcol = texture2D(tex, vec2(vtc.x+(0.058823529*vto), vtc.y));\n"
    //         "vec3 ambientColor = tcol.xyz * 0.64;\n"
    //         "float lambertian = max(dot(lightDir, normalize(vertNorm)), 0.0);\n"
    //         "gl_FragColor = vec4(ambientColor + lambertian*tcol.xyz, 1.0);\n"
    //     "}\n";

#endif

//

GLuint shdHud;
GLint  shdHud_position;
GLint  shdHud_texcoord;
GLint  shdHud_sampler;

GLuint shdVoxel;
GLint  shdVoxel_projection;
GLint  shdVoxel_view;
GLint  shdVoxel_voxel;
GLint  shdVoxel_position;
GLint  shdVoxel_normal;
GLint  shdVoxel_texcoord;
GLint  shdVoxel_sampler;

//

void makeVoxel()
{
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &v1, NULL);
    glCompileShader(vertexShader);

    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &f1, NULL);
    glCompileShader(fragmentShader);

    shdVoxel = glCreateProgram();
        glAttachShader(shdVoxel, vertexShader);
        glAttachShader(shdVoxel, fragmentShader);
    glLinkProgram(shdVoxel);

    shdVoxel_position   = glGetAttribLocation(shdVoxel,  "position");
    shdVoxel_normal     = glGetAttribLocation(shdVoxel,  "normal");
    shdVoxel_texcoord   = glGetAttribLocation(shdVoxel,  "texcoord");
    //<><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
    shdVoxel_projection = glGetUniformLocation(shdVoxel, "projection");
    shdVoxel_view       = glGetUniformLocation(shdVoxel, "view");
    shdVoxel_voxel      = glGetUniformLocation(shdVoxel, "voxel");
    shdVoxel_sampler    = glGetUniformLocation(shdVoxel, "tex");

    esBind(GL_ARRAY_BUFFER,         &mdlVoxel.tid, voxel_uvmap,    sizeof(voxel_uvmap),    GL_STATIC_DRAW);
    esBind(GL_ARRAY_BUFFER,         &mdlVoxel.vid, voxel_vertices, sizeof(voxel_vertices), GL_STATIC_DRAW);
    esBind(GL_ARRAY_BUFFER,         &mdlVoxel.nid, voxel_normals,  sizeof(voxel_normals),  GL_STATIC_DRAW);
    esBind(GL_ELEMENT_ARRAY_BUFFER, &mdlVoxel.iid, voxel_indices,  sizeof(voxel_indices),  GL_STATIC_DRAW);

    texmap = esLoadTexture(272, 16, tiles);
}
void shadeVoxel(GLint* position, GLint* projection, GLint* view, GLint* voxel, GLint* normal, GLint* texcoord, GLint* sampler)
{
    *position = shdVoxel_position;
    *projection = shdVoxel_projection;
    *view = shdVoxel_view;
    *voxel = shdVoxel_voxel;
    *normal = shdVoxel_normal;
    *texcoord = shdVoxel_texcoord;
    *sampler = shdVoxel_sampler;
    glUseProgram(shdVoxel);
}

//

void makeHud()
{
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &v0, NULL);
    glCompileShader(vertexShader);

    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &f0, NULL);
    glCompileShader(fragmentShader);

    shdHud = glCreateProgram();
        glAttachShader(shdHud, vertexShader);
        glAttachShader(shdHud, fragmentShader);
    glLinkProgram(shdHud);

    shdHud_position   = glGetAttribLocation(shdHud,  "position");
    shdHud_texcoord   = glGetAttribLocation(shdHud,  "texcoord");
    //<><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
    shdHud_sampler    = glGetUniformLocation(shdHud, "tex");

    esBind(GL_ARRAY_BUFFER, &mdlPlane.vid, &hud_vertices, sizeof(hud_vertices), GL_STATIC_DRAW);
    esBind(GL_ELEMENT_ARRAY_BUFFER, &mdlPlane.iid, &hud_indices, sizeof(hud_indices), GL_STATIC_DRAW);
    esBind(GL_ARRAY_BUFFER, &mdlPlane.tid, &hud_uvmap, sizeof(hud_uvmap), GL_STATIC_DRAW);
}
void shadeHud(GLint* position, GLint* texcoord, GLint* sampler)
{
    *position = shdHud_position;
    *texcoord = shdHud_texcoord;
    *sampler = shdHud_sampler;
    glUseProgram(shdHud);
}

//

unsigned char tiles[] = { // 272, 16, 3
  "///,,,\060\060\060,,,***\060\060\060\060\060\060\060\060\060\060\060\060\060\060\060\060\060"
  "\060\060\060\060\060\060\060(((,,,,,,HHH;;;<<<???FFFDDDGGG<<<FFFFFFHHHGGGHHHAAA"
  ";;;DDDdddiiippp^^^aaahhhdddeeefff]]]eeeiii___]]]kkk\\\\\\\235\064\064\243\066"
  "\066\217\060\060\230\063\063\225\062\062\240\065\065\217\060\060\225\062\062\232\063\063"
  "\243\066\066\221\060\060\232\063\063\241\066\066\246\067\067\213..\233\064\064\233d\064"
  "\217]\060\225a\062\246k\067\243i\066\211Y.\221^\060\233d\064\214[/\216\\/\224`"
  "\061\241h\066\221^\060\214[/\230c\063\217]\060\216v/\225}\062\221y\060\233\202\064"
  "\230\177\063\221y\060\214u/\221y\060\243\210\066\235\203\064\224{\061\246\212\067"
  "\247\214\070\211s.\230\177\063\235\203\064\221\220\060\216\215/\224\223\061\216"
  "\215/\247\246\070\221\220\060\246\244\067\230\227\063\235\234\064\225\224\062\230"
  "\227\063\221\220\060\241\240\066\244\243\067\213\212.\243\242\066h\241\066c\230"
  "\063k\246\067[\214/i\243\066Z\213.[\214/h\241\066j\244\067a\225\062Z\213.Z\213"
  ".i\243\066j\244\067g\240\065a\225\062/\216/\062\225\062\060\221\060\064\233\064\063"
  "\230\063\060\221\060/\214/\060\221\060\066\243\066\064\235\064\061\224\061\067\246\067"
  "\070\247\070.\211.\063\230\063\064\235\064\064\233l\065\240o\061\224g\064\235m\062\225"
  "h\061\224g\060\221d.\211_\066\241p\070\247t\067\246s\061\224g\062\227i.\213`\062"
  "\225h\064\235m/\214\211.\213\210\067\244\240.\211\206\063\230\225/\216\212\066"
  "\243\237\067\244\240\062\227\223/\216\212\060\221\215\064\235\231\062\225\222"
  "\064\235\231\065\240\234\067\244\240/q\214\067\204\244\067\204\244\066\203\243"
  "\067\204\244\067\204\244\066\202\241\067\204\244\065\200\240.n\211\063z\230\061"
  "w\224\064}\233\070\206\247\060t\221\061w\224\060I\221\066R\241\064O\235\067S\244"
  "/G\214\066R\243\066R\241\067T\246\067S\244\070U\247\062L\227.E\211\064O\235.F\213"
  "\062L\227\060H\217E/\214G\060\221L\064\233I\062\225J\062\227K\063\230D.\213J\062"
  "\227M\064\235E/\216D.\213N\065\240C.\211E/\214L\064\233N\065\240q\063\230o\062"
  "\225v\065\240j\060\217o\062\225r\063\232y\066\243k\060\221r\063\232x\066\241{\067"
  "\246g.\213s\064\233v\065\240y\066\243k\060\221\246\067\225\243\066\222\211.{\221"
  "\060\202\233\064\213\214/~\216/\177\224\061\205\241\066\221\221\060\202\214/~"
  "\230\063\211\217\060\201\213.}\232\063\212\227\062\207\232\063\\\227\062Z\221\060"
  "W\211.R\213.S\235\064^\241\066a\243\066b\221\060W\225\062Z\240\065`\240\065`\235"
  "\064^\224\061Y\243\066b\217\060V...HHHAAAAAADDDDDDDDDHHHHHH???AAAAAAFFFFFFGG"
  "G***<<<aaa___hhheeefffhhhdddaaaeeeiii]]]```dddaaaAAA^^^\233\233\233\236\236"
  "\236\226\226\226\222\222\222\217\217\217\220\220\220\235\235\235\240\240"
  "\240\223\223\223\231\231\231\227\227\227\236\236\236\223\223\223\227\227"
  "\227ggg\240\065\065\317pp\310]]\316oo\310]]\317rr\314ii\313dd\314ii\310]]\312"
  "cc\320ss\317pp\306WW\310]]\233\064\064\213Z.\314\227g\313\224d\316\233m\306"
  "\213W\307\214X\312\223c\316\234o\307\215Z\307\215Z\313\224d\314\227g\313"
  "\224d\311\221`\306\213W\213Z.\244\211\067\307\253X\310\256]\316\266m\316\266"
  "m\313\261d\307\253X\307\253X\314\264i\316\266m\312\260a\315\264j\312\261"
  "c\312\260a\310\256]\211s.\217\216\060\306\305W\317\316r\320\317u\316\315o"
  "\314\313i\316\315m\316\315o\313\312f\320\317s\307\306Z\317\316p\307\305X"
  "\307\306Z\316\315o\244\243\067`\224\061\226\313f\240\320u\240\320u\217\310"
  "]\235\317p\232\315l\237\320s\216\310[\223\312c\221\311`\230\314i\226\313"
  "f\217\310]\215\307Z^\221\060\067\244\067X\307X]\310]m\316mm\316md\313dX\307"
  "XX\307Xi\314im\316ma\312aj\315jc\312ca\312a]\310].\211.\066\243q`\311\231"
  "`\311\231r\317\244m\316\241o\316\242m\316\241Z\307\225X\307\224r\317\244"
  "W\306\223f\313\235[\310\226p\317\243r\317\244\062\227i\064\233\230]\310\304"
  "W\306\302a\312\306j\315\311f\313\310m\316\312c\312\307Z\307\303r\317\314"
  "r\317\314p\317\313r\317\314r\317\314o\316\313\067\244\240\063|\232g\256\314"
  "f\255\313s\265\320s\265\320W\245\306[\250\310`\252\311o\262\316l\261\315"
  "r\264\317Z\247\307p\263\317o\262\316s\265\320\067\204\244\067T\246l\205\315"
  "o\207\316r\212\317i\202\314c~\312l\205\315u\214\320Zv\307`{\311i\202\314"
  "c~\312d\177\313f\200\313Xu\307\062L\227H\061\224u[\310qW\306rX\307\203l\315"
  "\206p\317v]\310~f\313{c\312\204m\316v]\310{c\312\177g\314\206p\317v]\310"
  "K\063\232x\066\241\237]\310\253r\317\246i\314\243d\313\246i\314\237]\310\242"
  "c\312\254s\320\252p\317\233W\306\237]\310\246i\314\235Z\307\236[\310n\061"
  "\224\240\065\217\306W\265\307X\266\312c\272\316o\300\307Z\267\307Z\267\313"
  "d\273\314g\274\313d\273\311`\271\306W\265\307X\266\315j\276\316o\300\243"
  "\066\222\221\060W\313f\216\314i\221\315j\222\310]\210\310[\207\312a\213\310"
  "[\207\320u\231\310]\210\320s\230\313f\216\315j\222\312c\214\313f\216\221"
  "\060W\060\060\060FFFHHHGGGHHHCCC???EEE@@@CCCAAAHHHFFFFFFGGG...AAA]]]aaaeee^^"
  "^]]]fff\\\\\\]]]dddfff```^^^\\\\\\]]]DDDmmm\223\223\223\232\232\232\237\237"
  "\237\242\242\242\220\220\220\233\233\233\236\236\236\240\240\240\223\223"
  "\223\237\237\237\223\223\223\241\241\241\233\233\233\230\230\230hhh\214/"
  "/\310[[\312aa\316oo\311``\307ZZ\313ff\310]]\307XX\314gg\313dd\316mm\306W"
  "W\307XX\312cc\241\066\066\235e\064\316\234o\317\235p\311\221`\312\223c\316\233"
  "m\316\233m\315\232l\312\222a\317\235p\310\217]\311\221`\313\226f\314\230"
  "i\315\231j\221^\060\241\207\066\320\272u\320\271s\312\260a\313\261d\307\253"
  "X\312\261c\315\264j\317\267p\311\257`\311\257`\317\270r\316\266m\316\267"
  "o\316\266m\214u/\225\224\062\307\305X\307\305X\317\316p\317\316r\316\315m"
  "\312\311c\312\311a\313\312f\320\317u\320\317u\310\307]\317\316p\315\314l"
  "\320\317s\216\215/i\243\066\231\315j\222\312a\237\320s\240\320u\213\306W\226"
  "\313f\232\315l\236\317r\214\307X\217\310]\233\316m\233\316m\224\313d\214"
  "\307XZ\213.\066\241\066u\320us\320sa\312ad\313dX\307Xc\312cj\315jp\317p`\311"
  "``\311`r\317rm\316mo\316om\316m/\214//\216b]\310\227l\315\241c\312\233j\315"
  "\240m\316\241r\317\244i\314\237]\310\227W\306\223a\312\232j\315\240f\313"
  "\235m\316\241c\312\233/\214a\065\240\234W\306\302f\313\310a\312\306i\314\311"
  "u\320\315]\310\304a\312\306g\314\310g\314\310f\313\310s\320\315s\320\315"
  "W\306\302[\310\304\060\221\215\070\206\247d\255\313W\245\306j\260\315X\246"
  "\307d\255\313]\251\310s\265\320l\261\315o\262\316r\264\317i\257\314c\254"
  "\312l\261\315u\265\320/q\214\064O\235[w\310Xu\307m\206\316Wt\306Zv\307i\202"
  "\314m\206\316a|\312[w\310Wt\306Xu\307l\205\315p\211\317]y\310\063M\230O\066"
  "\241\211s\320rX\307\200i\314\204m\316\206p\317v]\310\205o\316v]\310\210r"
  "\317\200i\314|d\313\200i\314v]\310{c\312Q\067\246x\066\241\240`\311\235Z\307"
  "\244f\313\237]\310\234X\307\245g\314\243d\313\250m\316\233W\306\234X\307"
  "\242c\312\251o\316\235Z\307\235Z\307p\062\227\221\060\202\312c\272\316m\277"
  "\316m\277\315l\276\312a\272\317p\300\310]\270\311`\271\313f\274\314i\275"
  "\315j\276\310]\270\310[\267\312a\272\216/\177\241\066a\317r\227\307X\204\317"
  "p\226\310]\210\306W\203\317r\227\320u\231\316o\225\314i\221\316m\224\316"
  "o\225\313f\216\320s\230\307Z\206\243\066b,,,FFFHHH@@@AAAEEECCCCCCDDD@@@CC"
  "CFFFAAA@@@FFF(((FFF___aaaaaafff___aaacccggg___cccfffhhh]]]dddEEE```\227\227"
  "\227\242\242\242\240\240\240\217\217\217\223\223\223\233\233\233\221\221"
  "\221\222\222\222\226\226\226\237\237\237\225\225\225\221\221\221\231\231"
  "\231\223\223\223]]]\214//\307ZZ\313dd\314gg\313dd\311``\306WW\307XX\315j"
  "j\316oo\317pp\311``\312cc\316mm\316mm\235\064\064\216\\/\312\222a\310\216["
  "\320\240u\310\217]\320\237s\313\226f\315\231j\312\223c\313\226f\311\221`"
  "\316\234o\317\236r\307\214X\317\235p\217]\060\213t.\317\270r\306\253W\313"
  "\262f\310\255[\317\267p\317\270r\313\261d\310\255[\310\256]\315\265l\312"
  "\261c\315\264j\316\266m\317\270r\233\202\064\225\224\062\311\310`\314\313i"
  "\313\312f\310\307]\307\306Z\311\310`\317\316p\315\314j\312\311a\320\317s"
  "\320\317u\306\305W\313\312f\315\314l\244\243\067d\233\064\233\316m\222\312"
  "a\231\315j\223\312c\222\312a\217\310]\213\306W\234\316o\240\320u\237\320"
  "s\222\312a\224\313d\214\307X\223\312ce\235\064.\213.r\317rW\306Wf\313f[\310"
  "[p\317pr\317rd\313d[\310[]\310]l\315lc\312cj\315jm\316mr\317r\064\233\064\067"
  "\244rr\317\244p\317\243r\317\244r\317\244o\316\242r\317\244m\316\241W\306"
  "\223f\313\235a\312\232i\314\237u\320\246]\310\227a\312\232\063\232k\066\241"
  "\235l\315\312r\317\314Z\307\303p\317\313o\316\313s\320\315r\317\314u\320"
  "\315d\313\307W\306\302j\315\311X\307\303d\313\307]\310\304\067\246\242\060"
  "t\221i\257\314c\254\312d\255\313f\255\313X\246\307d\255\313l\261\315[\250"
  "\310X\246\307m\261\316W\245\306Z\247\307i\257\314m\261\316\061w\224\062K\225"
  "m\206\316]y\310c~\312g\201\314p\211\317]y\310g\201\314o\207\316s\213\320"
  "Xu\307i\202\314m\206\316p\211\317]y\310\066R\241P\066\243qW\306v]\310\200i"
  "\314sZ\307u[\310za\312\205o\316y`\311sZ\307~f\313v]\310rX\307\177g\314|d"
  "\313N\065\240r\063\232\243d\313\240`\311\233W\306\234X\307\247j\315\251o\316"
  "\252p\317\240`\311\242c\312\250m\316\250m\316\247l\315\241a\312\252p\317"
  "j\060\217\247\070\226\310]\270\320s\302\313f\274\315j\276\312c\272\313f\274"
  "\311`\271\316o\300\317r\301\307X\266\317p\300\310]\270\306W\265\317r\301"
  "\247\070\226\213.S\307Z\206\316o\225\317r\227\312c\214\307X\204\307X\204\317"
  "p\226\317r\227\316m\224\312c\214\312a\213\313f\216\320u\231\320u\231\217"
  "\060V***EEEFFFAAAAAA???@@@FFFGGGAAADDDCCCFFFAAACCC...FFF___fff___hhhdddaa"
  "addd___aaahhhggg\\\\\\___ddd<<<ggg\230\230\230\236\236\236\217\217\217\220"
  "\220\220\227\227\227\237\237\237\221\221\221\221\221\221\230\230\230\232"
  "\232\232\230\230\230\225\225\225\217\217\217\220\220\220iii\224\061\061\317"
  "pp\310]]\311``\313ff\314ii\315jj\310]]\310[[\312aa\310[[\320uu\310]]\320"
  "ss\313ff\235\064\064\211Y.\317\236r\320\240u\316\234o\314\230i\316\233m\316"
  "\234o\313\226f\320\237s\307\215Z\317\235p\307\214X\307\215Z\316\234o\317"
  "\236r\225a\062\221y\060\306\253W\312\260a\315\264j\313\262f\316\266m\312\261"
  "c\307\254Z\317\270r\317\270r\317\267p\317\270r\317\270r\316\267o\317\270"
  "r\240\205\065\213\212.\310\307]\316\315m\316\315m\313\312d\307\305X\307\305"
  "X\314\313i\316\315m\312\311a\315\314j\312\311c\312\311a\310\307]\306\305"
  "W\241\240\066i\243\066\221\311`\221\311`\236\317r\233\316m\234\316o\233\316"
  "m\215\307Z\214\307X\236\317r\213\306W\226\313f\216\310[\235\317p\236\317"
  "rb\227\062\060\221\060W\306Wa\312aj\315jf\313fm\316mc\312cZ\307Zr\317rr\317"
  "rp\317pr\317rr\317ro\316or\317r\065\240\065\063\232kf\313\235s\320\245s\320"
  "\245W\306\223[\310\226`\311\231o\316\242l\315\241r\317\244Z\307\225p\317"
  "\243o\316\242s\320\245r\317\244\070\247t\064\235\231o\316\313r\317\314i\314"
  "\311c\312\307l\315\312u\320\315Z\307\303`\311\306i\314\311c\312\307d\313"
  "\307f\313\310X\307\303d\313\307\064\235\231/r\216W\245\306X\246\307l\261\315"
  "p\263\317]\251\310f\255\313c\254\312m\261\316]\251\310c\254\312g\256\314"
  "p\263\317]\251\310g\256\314\066\202\241\060H\217r\212\317i\202\314d\177\313"
  "i\202\314]y\310c~\312s\213\320p\211\317Wt\306]y\310i\202\314Zv\307[w\310"
  "a|\312\066R\241C.\211rX\307{c\312\205o\316sZ\307sZ\307|d\313\177g\314|d\313"
  "y`\311qW\306rX\307\201j\315\205o\316\206p\317G\060\221k\060\221\244f\313\246"
  "i\314\247j\315\237]\310\236[\310\241a\312\236[\310\255u\320\237]\310\254"
  "s\320\244f\313\247j\315\242c\312\244f\313k\060\221\241\066\221\314i\275\316"
  "m\277\316o\300\313f\274\320s\302\307Z\267\317p\300\307X\266\307Z\267\316"
  "o\300\317r\301\312c\272\307X\266\307X\266\243\066\222\243\066b\315l\223\320"
  "s\230\310[\207\312c\214\311`\212\314i\221\313f\216\310]\210\307Z\206\311"
  "`\212\317p\226\315j\222\312a\213\320s\230\247\070d\060\060\060AAADDDFFFHHH@@"
  "@EEEFFFGGGAAAFFFAAAGGGEEECCC...<<<```fff```]]]aaa___]]]cccaaafff\\\\\\]]"
  "]aaafff<<<lll\240\240\240\225\225\225\227\227\227\236\236\236\236\236\236"
  "\235\235\235\226\226\226\240\240\240\223\223\223\225\225\225\231\231\231"
  "\233\233\233\234\234\234\223\223\223___\225\062\062\313ff\311``\316oo\317r"
  "r\307XX\317pp\310]]\306WW\317rr\320uu\316oo\314ii\316mm\316oo\230\063\063\213"
  "Z.\307\214X\317\235p\317\236r\316\233m\312\223c\312\222a\313\226f\320\240"
  "u\320\240u\310\217]\317\235p\315\232l\320\237s\310\216[\225a\062\211s.\313"
  "\262f\312\260a\314\264i\320\272u\310\256]\312\260a\314\263g\314\263g\313"
  "\262f\320\271s\320\271s\306\253W\310\255[\311\257`\241\207\066\247\246\070"
  "\320\317s\312\311a\313\312d\307\305X\312\311c\315\314j\317\316p\311\310`"
  "\311\310`\317\316r\316\315m\316\315o\316\315m\307\306Z\213\212.\\\216/\217"
  "\310]\232\315l\223\312c\231\315j\233\316m\236\317r\230\314i\217\310]\213"
  "\306W\222\312a\231\315j\226\313f\233\316m\223\312c[\214/.\211.f\313fa\312"
  "ai\314iu\320u]\310]a\312ag\314gg\314gf\313fs\320ss\320sW\306W[\310[`\311"
  "`\066\241\066\062\227iW\306\223j\315\240X\307\224d\313\234]\310\227s\320\245"
  "l\315\241o\316\242r\317\244i\314\237c\312\233l\315\241u\320\246Z\307\225"
  "\060\221d/\216\212X\307\303m\316\312W\306\302Z\307\303i\314\311m\316\312a"
  "\312\306[\310\304W\306\302X\307\303l\315\312p\317\313]\310\304f\313\310\062"
  "\225\222\067\205\246X\246\307i\257\314m\261\316p\263\317]\251\310o\262\316"
  "]\251\310r\264\317i\257\314d\255\313i\257\314]\251\310c\254\312s\265\320"
  "\066\203\243\060I\221Zv\307f\200\313]y\310Xu\307g\201\314d\177\313m\206\316"
  "Wt\306Xu\307c~\312o\207\316Zv\307Zv\307d\177\313\063N\232I\062\225\204m\316"
  "\204m\316\203l\315za\312\206p\317v]\310y`\311~f\313\200i\314\201j\315v]\310"
  "u[\310za\312u[\310R\070\247x\066\241\253r\317\234X\307\252p\317\237]\310\233"
  "W\306\253r\317\255u\320\251o\316\246i\314\250m\316\251o\316\244f\313\254"
  "s\320\235Z\307y\066\243\244\067\224\316m\277\312c\272\312a\272\313f\274\320"
  "u\302\320u\302\310]\270\317p\300\315l\276\320s\302\310[\267\312c\272\311"
  "`\271\314i\275\230\063\211\211.R\313f\216\315l\223\317r\227\307X\204\310]"
  "\210\316m\224\316m\224\313d\215\307X\204\307X\204\314i\221\316m\224\312a"
  "\213\315j\222\225\062Z+++CCCHHHGGG???AAAEEE@@@AAAAAAFFFAAA@@@DDDAAA(((<<<"
  "aaacccaaa```\\\\\\]]]dddfffggg```aaaffffffeee@@@ccc\222\222\222\243\243\243"
  "\223\223\223\242\242\242\231\231\231\234\234\234\227\227\227\231\231\231"
  "\225\225\225\237\237\237\241\241\241\220\220\220\240\240\240\223\223\223"
  "\\\\\\\246\067\067\307ZZ\317pp\307XX\307ZZ\316oo\317rr\312cc\307XX\307XX\317"
  "pp\317rr\316mm\312cc\312aa\230\063\063\221^\060\314\230i\313\226f\310\217]\307"
  "\215Z\311\221`\317\235p\315\231j\312\222a\320\237s\320\240u\306\213W\313"
  "\226f\315\232l\317\236r\213Z.\235\203\064\317\270r\307\254Z\317\267p\316\267"
  "o\320\271s\317\270r\320\272u\313\261d\306\253W\315\264j\307\253X\313\261"
  "d\310\256]\320\271s\235\203\064\244\243\067\306\305W\313\312f\310\307[\317"
  "\316p\317\316r\313\312d\310\307[\310\307]\315\314l\312\311c\315\314j\316"
  "\315m\317\316r\314\313i\221\220\060j\244\067\236\317r\235\317p\236\317r\236"
  "\317r\234\316o\236\317r\233\316m\213\306W\226\313f\222\312a\230\314i\240"
  "\320u\217\310]\222\312ac\232\063\064\235\064r\317rZ\307Zp\317po\316os\320sr"
  "\317ru\320ud\313dW\306Wj\315jX\307Xd\313d]\310]s\320s\064\235\064\064\233lc"
  "\312\233d\313\234f\313\235X\307\224d\313\234l\315\241[\310\226X\307\224m"
  "\316\241W\306\223Z\307\225i\314\237m\316\241a\312\232/\216b\065\240\234]\310"
  "\304c\312\307g\314\310p\317\313]\310\304g\314\310o\316\313s\320\315X\307"
  "\303i\314\311m\316\312p\317\313]\310\304o\316\313\060\217\214.n\211]\251\310"
  "i\257\314Z\247\307[\250\310a\253\312o\262\316`\252\311Z\247\307f\255\313"
  "]\251\310X\246\307g\256\314d\255\313m\261\316.n\211\062L\227`{\311Wt\306X"
  "u\307j\204\315o\207\316p\211\317`{\311c~\312m\206\316m\206\316l\205\315a"
  "|\312p\211\317]y\310\060I\221G\060\221\211s\320~f\313\201j\315{c\312~f\313"
  "y`\311\205o\316\210r\317rX\307\206p\317v]\310qW\306\210r\317\212u\320O\066"
  "\241g.\213\235Z\307\251o\316\253r\317\242c\312\234X\307\234X\307\252p\317"
  "\253r\317\250m\316\242c\312\241a\312\244f\313\255u\320\255u\320j\060\217\221"
  "\060\202\307Z\267\311`\271\317p\300\315j\276\312a\272\320s\302\320u\302\306"
  "W\265\313f\274\315l\276\317r\301\307X\266\310]\270\316m\277\240\065\217\224"
  "\061Y\310]\210\306W\203\316o\225\320u\231\320s\230\312a\213\313d\215\307X"
  "\204\312c\214\315j\222\317p\226\311`\212\311`\212\317r\227\240\065`...CCC"
  "FFF???@@@CCCFFF@@@@@@CCCDDDCCCAAA???@@@///FFF___```aaadddddd___^^^```^^^"
  "iii___hhhaaaddd@@@nnn\243\243\243\237\237\237\233\233\233\236\236\236\237"
  "\237\237\231\231\231\242\242\242\221\221\221\240\240\240\220\220\220\221"
  "\221\221\237\237\237\241\241\241\227\227\227]]]\247\070\070\320uu\310]]\317"
  "pp\315ll\320ss\310[[\312cc\311``\314ii\313ff\310]]\307ZZ\311``\317pp\235"
  "\064\064\217]\060\316\233m\316\233m\313\224d\307\214X\307\214X\314\230i\316"
  "\233m\312\222a\315\231j\312\223c\312\222a\310\217]\306\213W\316\234o\247"
  "l\070\241\207\066\317\270r\314\264i\312\261c\315\265l\320\272u\307\254Z\311"
  "\257`\314\264i\312\261c\313\261d\313\262f\307\253X\313\261d\315\265l\216"
  "v/\211\210.\312\311a\315\314j\313\312f\316\315m\312\311c\307\306Z\317\316"
  "r\317\316r\317\316p\317\316r\317\316r\316\315o\317\316r\316\315m\211\210"
  ".c\232\063\226\313f\237\320s\237\320s\213\306W\216\310[\221\311`\234\316o"
  "\232\315l\236\317r\215\307Z\235\317p\234\316o\237\320s\236\317rl\247\070\066"
  "\241\066r\317ri\314ic\312cl\315lu\320uZ\307Z`\311`i\314ic\312cd\313df\313"
  "fX\307Xd\313dl\315l/\216/.\211_X\307\224l\315\241p\317\243]\310\227f\313"
  "\235c\312\233m\316\241]\310\227c\312\233g\314\236p\317\243]\310\227g\314"
  "\236o\316\242\067\246s\067\244\240i\314\311d\313\307i\314\311]\310\304c\312"
  "\307s\320\315p\317\313W\306\302]\310\304i\314\311Z\307\303[\310\304a\312"
  "\306o\316\313\060\221\215.p\213c\254\312o\262\316Z\247\307Z\247\307d\255\313"
  "g\256\314d\255\313`\252\311W\245\306X\246\307j\260\315o\262\316p\263\317"
  "`\252\311\062x\225\063M\230i\202\314j\204\315]y\310[w\310a|\312[w\310u\214"
  "\320]y\310s\213\320f\200\313j\204\315c~\312f\200\313`{\311\066R\241L\064\233"
  "\204m\316\205o\316~f\313\211s\320sZ\307\206p\317rX\307sZ\307\205o\316\210"
  "r\317{c\312rX\307rX\307\206p\317P\067\244y\066\243\247l\315\254s\320\236[\310"
  "\242c\312\240`\311\246i\314\244f\313\237]\310\235Z\307\240`\311\252p\317"
  "\247j\315\241a\312\254s\320|\070\247\227\062\207\307X\266\307X\266\314i\275"
  "\316m\277\312a\272\315j\276\312c\272\312a\272\310]\270\306W\265\316o\300"
  "\320u\302\320s\302\312a\272\227\062\207\241\066a\316m\224\307Z\206\307X\204"
  "\317r\227\306W\203\313f\216\310[\207\317p\226\317r\227\313d\215\310[\207"
  "\310]\210\315l\223\312c\214\235\064^\060\060\060GGGAAACCCFFFFFFFFFAAAGGGAAAA"
  "AADDDEEEEEEAAA***AAA```fffhhh]]]ggg___\\\\\\hhhiiifffdddffffffaaaHHH]]]\240"
  "\240\240\241\241\241\236\236\236\227\227\227\226\226\226\231\231\231\243"
  "\243\243\243\243\243\223\223\223\240\240\240\235\235\235\242\242\242\222"
  "\222\222\227\227\227aaa\224\061\061\320ss\320uu\306WW\313ff\315ll\317rr\307"
  "XX\310]]\316mm\316mm\313dd\307XX\307XX\314ii\240\065\065\246k\067\312\222a\313"
  "\224d\307\214X\312\223c\315\231j\317\235p\311\221`\311\221`\317\236r\316"
  "\233m\316\234o\316\233m\307\215Z\307\214X\244j\067\213t.\316\266m\306\253"
  "W\307\254Z\314\264i\316\266m\312\260a\310\255[\306\253W\307\253X\315\265"
  "l\317\267p\310\256]\313\262f\312\261c\240\205\065\230\227\063\312\311a\314"
  "\313i\320\317u\310\307]\312\311a\314\313g\314\313g\313\312f\320\317s\320"
  "\317s\306\305W\310\307[\311\310`\316\315o\235\234\064b\227\062\213\306W\231"
  "\315j\214\307X\224\313d\217\310]\237\320s\232\315l\234\316o\236\317r\230"
  "\314i\223\312c\232\315l\240\320u\215\307Z^\221\060.\213.m\316mW\306WZ\307"
  "Zi\314im\316ma\312a[\310[W\306WX\307Xl\315lp\317p]\310]f\313fc\312c\065\240"
  "\065.\213`i\314\237m\316\241p\317\243]\310\227o\316\242]\310\227r\317\244"
  "i\314\237d\313\234i\314\237]\310\227c\312\233s\320\245p\317\243.\211_/\214"
  "\211f\313\310]\310\304X\307\303g\314\310d\313\307m\316\312W\306\302X\307"
  "\303c\312\307o\316\313Z\307\303Z\307\303d\313\307g\314\310\062\227\223\065"
  "\200\240m\261\316l\261\315a\253\312p\263\317]\251\310`\252\311f\255\313i"
  "\257\314j\260\315]\251\310[\250\310a\253\312[\250\310u\265\320\060t\221\067"
  "S\244Xu\307p\211\317]y\310Wt\306r\212\317u\214\320o\207\316i\202\314m\206"
  "\316o\207\316f\200\313s\213\320Zv\307p\211\317.F\213N\065\240{c\312za\312"
  "~f\313\212u\320\212u\320v]\310\206p\317\203l\315\211s\320u[\310{c\312y`\311"
  "\200i\314~f\313G\060\221f.\211\244f\313\247l\315\253r\317\234X\307\237]\310"
  "\250m\316\250m\316\243d\313\234X\307\234X\307\246i\314\250m\316\241a\312"
  "\247j\315o\062\225\213.}\312c\272\315j\276\317p\300\311`\271\311`\271\317"
  "r\301\316m\277\316o\300\316m\277\307Z\267\307X\266\317r\301\306W\265\313"
  "f\274\216/\177\240\065`\317r\227\314i\221\310]\210\306W\203\312a\213\315j"
  "\222\313f\216\316m\224\312c\214\307Z\206\317r\227\317r\227\317p\226\317r"
  "\227\244\067c,,,AAAHHHAAAHHHDDDEEECCCDDDAAAFFFGGG@@@GGGAAA(((<<<ggg]]]]]]"
  "fffhhhaaa]]]]]]ggghhhfffaaa```aaaHHHhhh\231\231\231\223\223\223\221\221\221"
  "\225\225\225\240\240\240\234\234\234\226\226\226\242\242\242\243\243\243"
  "\217\217\217\231\231\231\235\235\235\241\241\241\220\220\220```\224\061\061"
  "\315jj\312cc\312aa\310]]\306WW\316oo\320uu\320ss\312aa\313dd\307XX\312cc"
  "\315jj\317pp\221\060\060\211Y.\313\226f\310\216[\317\235p\317\236r\313\224"
  "d\310\216[\310\217]\315\232l\312\223c\315\231j\316\233m\317\236r\314\230"
  "i\310\217]\211Y.\217x\060\312\261c\314\263g\317\267p\310\256]\314\263g\316"
  "\267o\320\271s\307\253X\314\264i\316\266m\317\267p\310\256]\316\267o\310"
  "\256]\244\211\067\244\243\067\307\306Z\317\316p\316\315o\320\317s\317\316r"
  "\320\317u\313\312d\306\305W\315\314j\307\305X\313\312d\310\307]\320\317s"
  "\315\314l\241\240\066d\233\064\223\312c\224\313d\226\313f\214\307X\224\313"
  "d\232\315l\216\310[\214\307X\233\316m\213\306W\215\307Z\230\314i\233\316"
  "m\222\312a\\\216/\060\217\060c\312cg\314gp\317p]\310]g\314go\316os\320sX\307"
  "Xi\314im\316mp\317p]\310]o\316o]\310]\067\244\067\060\221di\314\237Z\307\225"
  "[\310\226a\312\232o\316\242`\311\231Z\307\225f\313\235]\310\227X\307\224"
  "g\314\236d\313\234m\316\241W\306\223.\213`\060\221\215W\306\302X\307\303j"
  "\315\311o\316\313p\317\313`\311\306c\312\307m\316\312m\316\312l\315\312a"
  "\312\306p\317\313]\310\304`\311\306\063\230\225\067\205\246f\255\313j\260\315"
  "c\254\312f\255\313`\252\311o\262\316r\264\317X\246\307p\263\317]\251\310"
  "W\245\306r\264\317u\265\320o\262\316\064}\233/G\214o\207\316r\212\317c~\312"
  "Xu\307Xu\307p\211\317r\212\317m\206\316c~\312a|\312f\200\313u\214\320u\214"
  "\320]y\310\066R\243E/\214y`\311\206p\317\201j\315za\312\211s\320\212u\320"
  "qW\306~f\313\203l\315\210r\317rX\307v]\310\204m\316\204m\316J\062\227n\061"
  "\224\237]\310\233W\306\251o\316\255u\320\254s\320\241a\312\243d\313\234X"
  "\307\242c\312\247j\315\252p\317\240`\311\240`\311\253r\317v\065\240\243\066"
  "\222\317r\301\313d\273\310[\267\310]\270\315l\276\312c\272\315j\276\316m"
  "\277\317r\301\314i\275\310]\270\306W\265\312a\272\315j\276\230\063\211\241"
  "\066a\317r\227\316m\224\306W\203\313f\216\312a\213\314i\221\320u\231\310]"
  "\210\312a\213\314g\217\314g\217\313f\216\320s\230\320s\230\211.R\060\060\060"
  "HHHFFFEEEFFFFFFDDDHHH@@@GGG@@@@@@FFFGGGCCC(((HHH___gggeeehhh^^^aaa```ddd"
  "aaa___]]]```gggddd@@@kkk\236\236\236\230\230\230\220\220\220\220\220\220"
  "\233\233\233\236\236\236\226\226\226\234\234\234\227\227\227\226\226\226"
  "\223\223\223\217\217\217\237\237\237\243\243\243ooo\221\060\060\317rr\316m"
  "m\316oo\316mm\307ZZ\307XX\317rr\306WW\313ff\310[[\317pp\317rr\313dd\310["
  "[\221\060\060\224`\061\315\231j\313\226f\316\233m\312\223c\307\215Z\317\236"
  "r\317\236r\317\235p\317\236r\317\236r\316\234o\317\236r\316\233m\306\213"
  "W\230c\063\233\202\064\313\261d\314\264i\310\256]\312\261c\320\271s\317\267"
  "p\306\253W\310\256]\314\264i\307\254Z\310\255[\312\260a\316\267o\311\257"
  "`\214u/\244\243\067\314\313i\312\311c\315\314l\320\317u\307\306Z\311\310`"
  "\314\313i\312\311c\313\312d\313\312f\307\305X\313\312d\315\314l\310\307["
  "\213\212.Y\211.\214\307X\232\315l\235\317p\217\310]\226\313f\223\312c\233"
  "\316m\217\310]\223\312c\227\314g\235\317p\217\310]\227\314g\234\316ok\246"
  "\067\064\233\064d\313di\314i]\310]c\312cs\320sp\317pW\306W]\310]i\314iZ\307"
  "Z[\310[a\312ao\316o`\311`/\214/\062\225ho\316\242Z\307\225Z\307\225d\313\234"
  "g\314\236d\313\234`\311\231W\306\223X\307\224j\315\240o\316\242p\317\243"
  "`\311\231c\312\233\065\240o\064\233\230j\315\311]\310\304[\310\304a\312\306"
  "[\310\304u\320\315]\310\304s\320\315f\313\310j\315\311c\312\307f\313\310"
  "`\311\306o\316\313\067\244\240\065\200\240o\262\316f\255\313s\265\320Z\247"
  "\307p\263\317X\246\307Z\247\307o\262\316r\264\317c\254\312X\246\307X\246"
  "\307p\263\317r\264\317\065\200\240\064O\235s\213\320[w\310c~\312`{\311i\202"
  "\314f\200\313]y\310Zv\307`{\311p\211\317j\204\315a|\312s\213\320u\214\320"
  ".E\211D.\213rX\307\200i\314\204m\316za\312\201j\315{c\312za\312v]\310qW\306"
  "\205o\316\212u\320\211s\320za\312|d\313D.\213x\066\241\250m\316\235Z\307\234"
  "X\307\253r\317\233W\306\244f\313\236[\310\252p\317\253r\317\243d\313\236"
  "[\310\237]\310\247l\315\242c\312t\064\235\240\065\217\312c\272\307Z\267\317"
  "r\301\317r\301\317p\300\317r\301\317r\301\316o\300\317r\301\316m\277\306"
  "W\265\313f\274\312a\272\314i\275\247\070\226\216/U\311`\212\316o\225\315l"
  "\223\317r\227\307Z\206\317p\226\316o\225\320s\230\317r\227\320u\231\313d"
  "\215\306W\203\315j\222\307X\204\227\062Z(((GGGGGGFFFCCCAAADDDHHHHHHAAAGGG"
  "FFFHHHAAACCC+++HHHiii\\\\\\aaaeeehhh]]]___ffffffaaa]]]]]]dddfff@@@ccc\230"
  "\230\230\220\220\220\227\227\227\234\234\234\240\240\240\225\225\225\225"
  "\225\225\241\241\241\236\236\236\237\237\237\236\236\236\221\221\221\220"
  "\220\220\241\241\241\\\\\\\235\064\064\312cc\315jj\316mm\317rr\314ii\310]]"
  "\306WW\312aa\315jj\313ff\316mm\312cc\307ZZ\317rr\244\067\067\224`\061\314\230"
  "i\320\240u\310\217]\312\222a\314\227g\314\227g\313\226f\320\237s\320\237"
  "s\306\213W\310\216[\311\221`\316\234o\315\232l\244j\067\230\177\063\310\256"
  "]\307\253X\314\263g\313\261d\316\266m\306\253W\307\253X\312\261c\316\267"
  "o\307\254Z\307\254Z\313\261d\314\263g\313\261d\221y\060\240\237\065\306\305"
  "W\307\306Z\314\313i\316\315m\312\311a\310\307[\306\305W\307\305X\315\314"
  "l\317\316p\310\307]\313\312f\312\311c\316\315m\217\216\060Z\213.\230\314i"
  "\233\316m\235\317p\217\310]\234\316o\217\310]\236\317r\230\314i\224\313d"
  "\230\314i\217\310]\223\312c\237\320s\235\317pY\211.\063\230\063]\310]X\307"
  "Xg\314gd\313dm\316mW\306WX\307Xc\312co\316oZ\307ZZ\307Zd\313dg\314gd\313"
  "d\060\221\060\065\240ol\315\241a\312\232p\317\243]\310\227`\311\231f\313\235"
  "i\314\237j\315\240]\310\227[\310\226a\312\232[\310\226u\320\246]\310\227"
  "\067\246s.\213\210p\317\313]\310\304W\306\302r\317\314u\320\315o\316\313i"
  "\314\311m\316\312o\316\313f\313\310s\320\315Z\307\303p\317\313X\307\303/"
  "\214\211\062x\225a\253\312f\255\313u\265\320u\265\320]\251\310p\263\317l\261"
  "\315s\265\320[\250\310c\254\312`\252\311i\257\314f\255\313]\251\310/q\214"
  "\063M\230l\205\315r\212\317Xu\307]y\310m\206\316m\206\316d\177\313Xu\307X"
  "u\307i\202\314m\206\316a|\312j\204\315c~\312\061K\224I\062\225\201j\315\206"
  "p\317y`\311y`\311\210r\317\204m\316\205o\316\204m\316sZ\307rX\307\210r\317"
  "qW\306~f\313u[\310P\066\243v\065\240\253r\317\246i\314\237]\310\233W\306\241"
  "a\312\247j\315\244f\313\250m\316\242c\312\235Z\307\253r\317\253r\317\252"
  "p\317\253r\317z\067\244\221\060\202\312a\272\314g\274\314g\274\313f\274\320"
  "s\302\320s\302\306W\265\310[\267\311`\271\316o\300\315l\276\317r\301\307"
  "Z\267\317p\300\241\066\221\217\060V\320s\230\315l\223\316o\225\317r\227\314"
  "i\221\312c\214\315l\223\320u\231\307Z\206\311`\212\314i\221\312c\214\313"
  "d\215\313f\216\213.S...DDDAAA@@@AAAGGGEEEAAAHHHHHH???DDDFFFGGG@@@+++DDDa"
  "aa```___\\\\\\fffiiihhh```aaa]]]aaadddggg```???fff\222\222\222\240\240\240"
  "\241\241\241\230\230\230\222\222\222\223\223\223\235\235\235\227\227\227"
  "\234\234\234\236\236\236\241\241\241\233\233\233\223\223\223\217\217\217"
  "ccc\243\066\066\317rr\317rr\316oo\317rr\316mm\306WW\313ff\312aa\314ii\320u"
  "u\310]]\312aa\314gg\314gg\230\063\063\214[/\317\235p\316\234o\320\237s\317"
  "\236r\320\240u\313\224d\306\213W\315\231j\307\214X\313\224d\310\217]\320"
  "\237s\315\232l\316\234o\244j\067\211s.\307\253X\315\264j\316\267o\317\267"
  "p\311\257`\312\261c\316\266m\316\266m\315\265l\312\260a\317\267p\310\256"
  "]\311\257`\313\262f\233\202\064\225\224\062\314\313g\317\316p\310\307]\314"
  "\313g\316\315o\320\317s\307\305X\314\313i\316\315m\317\316p\310\307]\316"
  "\315o\310\307]\317\316r\233\232\064^\221\060\230\314i\215\307Z\216\310[\222"
  "\312a\234\316o\221\311`\215\307Z\226\313f\217\310]\214\307X\227\314g\224"
  "\313d\233\316m\213\306WZ\213..\211.X\307Xj\315jo\316op\317p`\311`c\312cm"
  "\316mm\316ml\315la\312ap\317p]\310]`\311`f\313f\064\233\064\063\230jj\315\240"
  "c\312\233f\313\235`\311\231o\316\242r\317\244X\307\224p\317\243]\310\227"
  "W\306\223r\317\244u\320\246o\316\242i\314\237\065\240o\066\241\235r\317\314"
  "c\312\307X\307\303X\307\303p\317\313r\317\314m\316\312c\312\307a\312\306"
  "f\313\310u\320\315u\320\315]\310\304p\317\313\064\235\231\060t\221p\263\317"
  "j\260\315a\253\312s\265\320u\265\320W\245\306f\255\313l\261\315r\264\317"
  "X\246\307]\251\310m\261\316m\261\316d\255\313.p\213\060I\221Wt\306o\207\316"
  "u\214\320s\213\320a|\312d\177\313Xu\307c~\312j\204\315p\211\317`{\311`{\311"
  "r\212\317m\206\316\066R\241P\067\244|d\313u[\310v]\310\203l\315{c\312\201j"
  "\315\204m\316\210r\317\200i\314v]\310qW\306za\312\201j\315~f\313N\065\240"
  "x\066\241\253r\317\250m\316\233W\306\244f\313\241a\312\246i\314\255u\320\237"
  "]\310\241a\312\245g\314\245g\314\244f\313\254s\320\254s\320f.\211\246\067"
  "\225\317r\301\320u\302\313d\273\306W\265\315j\276\307X\266\313d\273\310]"
  "\270\320s\302\315l\276\316o\300\317r\301\314i\275\312c\272\235\064\215\227"
  "\062Z\315l\223\310[\207\307X\204\316m\224\306W\203\307Z\206\314i\221\316m"
  "\224\312a\213\310[\207\306W\203\307X\204\315l\223\317p\226\217\060V\060\060"
  "\060FFFCCC@@@@@@EEEFFFAAAEEECCCAAAAAA???FFFHHH\060\060\060GGGfffffffff]]]]]]"
  "hhh\\\\\\aaa^^^ggghhhaaa^^^___DDDiii\231\231\231\236\236\236\227\227\227"
  "\221\221\221\241\241\241\241\241\241\240\240\240\241\241\241\241\241\241"
  "\237\237\237\241\241\241\236\236\236\217\217\217\231\231\231ccc\246\067\067"
  "\320ss\306WW\310[[\311``\316oo\315ll\317rr\307ZZ\317pp\316oo\320ss\317rr"
  "\320uu\313dd\211..\233d\064\312\223c\315\232l\320\240u\307\215Z\311\221`\314"
  "\230i\312\223c\313\224d\313\226f\307\214X\313\224d\315\232l\310\216[\307"
  "\214X\240g\065\235\203\064\310\256]\310\255[\312\260a\310\255[\320\272u\310"
  "\256]\320\271s\313\262f\315\264j\312\261c\313\262f\311\257`\316\267o\317"
  "\270r\213t.\227\226\062\314\313i\310\307]\312\311c\320\317s\317\316p\306\305"
  "W\310\307]\314\313i\307\306Z\310\307[\312\311a\316\315o\311\310`\307\306"
  "Z\230\227\063a\225\062\234\316o\215\307Z\215\307Z\224\313d\227\314g\224\313"
  "d\221\311`\213\306W\214\307X\231\315j\234\316o\235\317p\221\311`\223\312"
  "cg\240\065\064\235\064]\310][\310[a\312a[\310[u\320u]\310]s\320sf\313fj\315"
  "jc\312cf\313f`\311`o\316or\317r.\213.\066\241pf\313\235s\320\245Z\307\225"
  "p\317\243X\307\224Z\307\225o\316\242r\317\244c\312\233X\307\224X\307\224"
  "p\317\243r\317\244m\316\241\062\225h\067\246\242[\310\304c\312\307`\311\306"
  "i\314\311f\313\310]\310\304Z\307\303`\311\306p\317\313j\315\311a\312\306"
  "s\320\315u\320\315W\306\302\063\230\225.p\213i\257\314m\261\316a\253\312j"
  "\260\315c\254\312a\253\312]\251\310W\245\306o\262\316u\265\320s\265\320a"
  "\253\312d\255\313X\246\307\062x\225\065Q\240Zv\307Xu\307r\212\317Wt\306f\200"
  "\313[w\310p\211\317r\212\317d\177\313[w\310]y\310l\205\315c~\312j\204\315"
  "\065Q\240I\062\225sZ\307\210r\317\210r\317\206p\317\210r\317\210r\317\205o"
  "\316\210r\317\204m\316qW\306~f\313za\312\200i\314\212u\320G\060\221i/\216"
  "\240`\311\251o\316\247l\315\253r\317\235Z\307\252p\317\251o\316\254s\320"
  "\253r\317\255u\320\243d\313\233W\306\247j\315\234X\307p\062\227\247\070\226"
  "\307Z\267\311`\271\314i\275\312c\272\313d\273\313f\274\307X\266\313d\273"
  "\315l\276\310[\267\307X\266\316m\277\306W\265\307Z\267\233\064\213\230\063"
  "[\312c\214\316m\224\310]\210\312c\214\314g\217\317p\226\310]\210\314g\217"
  "\316o\225\320s\230\307X\204\314i\221\316m\224\317p\226\221\060W,,,CCC@@@C"
  "CCEEEGGGAAAAAAGGGFFFFFFFFF@@@@@@GGG(((@@@dddfffhhhddd___\\\\\\```dddaaaf"
  "ffaaa]]]hhhhhhFFFhhh\243\243\243\223\223\223\226\226\226\232\232\232\232"
  "\232\232\231\231\231\242\242\242\242\242\242\217\217\217\222\222\222\225"
  "\225\225\237\237\237\235\235\235\241\241\241^^^\235\064\064\307XX\313dd\310"
  "]]\320ss\315ll\316oo\317rr\314ii\312cc\315ll\320uu\307ZZ\311``\314ii\225"
  "\062\062\211Y.\307\215Z\314\230i\316\233m\312\222a\310\216[\306\213W\307\214"
  "X\315\232l\317\235p\310\217]\313\226f\312\223c\316\233m\310\217]\225a\062"
  "\243\210\066\310\256]\306\253W\317\270r\320\272u\316\267o\314\264i\316\266"
  "m\316\267o\313\262f\320\271s\307\254Z\317\267p\307\253X\307\254Z\241\207"
  "\066\217\216\060\307\305X\314\313g\313\312d\316\315m\306\305W\307\305X\312"
  "\311c\316\315o\307\306Z\307\306Z\313\312d\314\313g\313\312d\311\310`\211"
  "\210.g\240\065\232\315l\222\312a\235\317p\217\310]\221\311`\226\313f\230\314"
  "i\231\315j\217\310]\216\310[\222\312a\216\310[\240\320u\217\310]k\246\067"
  "\066\243\066]\310]W\306Wr\317ru\320uo\316oi\314im\316mo\316of\313fs\320sZ\307"
  "Zp\317pX\307XZ\307Z\066\241\066\061\224gf\313\235u\320\246u\320\246]\310\227"
  "p\317\243l\315\241s\320\245[\310\226c\312\233`\311\231i\314\237f\313\235"
  "]\310\227Z\307\225\060\221d\064\235\231r\317\314X\307\303]\310\304m\316\312"
  "m\316\312d\313\307X\307\303X\307\303i\314\311m\316\312a\312\306j\315\311"
  "c\312\307a\312\306\060\221\215\064~\235p\263\317`\252\311`\252\311r\264\317"
  "m\261\316o\262\316m\261\316Z\247\307X\246\307r\264\317W\245\306f\255\313"
  "[\250\310p\263\317\067\204\244\067S\244i\202\314]y\310Wt\306a|\312j\204\315"
  "f\200\313m\206\316c~\312Zv\307r\212\317r\212\317p\211\317r\212\317r\212\317"
  "\066R\241H\061\224\177g\314\177g\314~f\313\211s\320\211s\320qW\306u[\310y`"
  "\311\205o\316\203l\315\210r\317sZ\307\206p\317\205o\316Q\067\246j\060\217\254"
  "s\320\247l\315\251o\316\253r\317\246i\314\242c\312\247l\315\255u\320\235"
  "Z\307\240`\311\246i\314\242c\312\243d\313\244f\313g.\213\240\065\217\312a"
  "\272\310[\267\306W\265\307X\266\315l\276\317p\300\310]\270\313f\274\312c"
  "\272\316m\277\310]\270\312c\272\314g\274\317p\300\221\060\202\241\066a\310"
  "]\210\317r\227\314i\221\313d\215\314i\221\310]\210\312c\214\320s\230\317"
  "p\226\306W\203\310]\210\314i\221\307Z\206\310[\207\224\061Y,,,***\060\060\060"
  "\060\060\060,,,***+++///,,,///\060\060\060\060\060\060...+++(((,,,GGGGGGFFFGGGEEE"
  ";;;AAA@@@CCCHHH???@@@AAAAAAAAAHHHmmmlllooonnnpppeee\\\\\\iii]]]eee```ooo"
  "iiilllnnnhhh\227\062\062\230\063\063\213..\227\062\062\235\064\064\216//\213..\240"
  "\065\065\211..\214//\233\064\064\240\065\065\224\061\061\216//\211..\213..\232c\063"
  "\243i\066\221^\060\232c\063\241h\066\246k\067\213Z.\233d\064\240g\065\243i\066\221"
  "^\060\241h\066\217]\060\244j\067\233d\064\227b\062\244\211\067\225}\062\213t.\213"
  "t.\243\210\066\244\211\067\240\205\065\225}\062\224{\061\230\177\063\247\214\070"
  "\247\214\070\217x\060\243\210\066\235\203\064\246\212\067\213\212.\235\234\064"
  "\241\240\066\243\242\066\221\220\060\225\224\062\240\237\065\240\237\065\235\234"
  "\064\224\223\061\243\242\066\217\216\060\221\220\060\230\227\063\233\232\064\235"
  "\234\064c\230\063e\235\064a\225\062c\230\063^\221\060h\241\066j\244\067Z\213.i\243"
  "\066]\217\060Y\211.j\244\067l\247\070h\241\066d\233\064g\240\065\067\244\067\062\225"
  "\062.\213..\213.\066\243\066\067\244\067\065\240\065\062\225\062\061\224\061\063\230"
  "\063\070\247\070\070\247\070\060\217\060\066\243\066\064\235\064\067\246\067\066\243q\064"
  "\235m\061\224g\067\246s\070\247t.\211_\063\230j\064\235m\067\244r.\213`\060\217"
  "c\065\240o\065\240o\062\227i.\213`.\213`.\211\206\066\241\235\070\247\243\067\246"
  "\242\061\224\220\062\227\223.\213\210\062\225\222\064\235\231\066\243\237\060\221"
  "\215\060\221\215\067\244\240\065\240\234\066\241\235\065\240\234\062y\227/r\216"
  "\060t\221\064~\235\062x\225\064~\235\065\200\240\067\204\244\064}\233\060t\221.n"
  "\211\061w\224\064~\235\063z\230\065\200\240\062x\225\067S\244\065Q\240.E\211\063"
  "M\230\061K\224\064O\233\070U\247\060I\221\061K\224\063N\232\063N\232\063M\230\067"
  "T\246\067T\246.E\211/H\216P\067\244R\070\247J\062\227C.\211M\064\235D.\213J\062"
  "\227F\060\217Q\067\246M\064\235O\066\241P\067\244L\064\233I\062\225M\064\235R\070"
  "\247p\062\227t\064\235i/\216g.\213v\065\240f.\211h/\214s\064\233v\065\240n\061"
  "\224i/\216f.\211g.\213t\064\235y\066\243j\060\217\232\063\212\241\066\221\246"
  "\067\225\213.}\233\064\213\240\065\217\243\066\222\221\060\202\241\066\221\217"
  "\060\201\244\067\224\233\064\213\227\062\207\233\064\213\217\060\201\225\062\206"
  "\241\066a\221\060W\214/T\230\063[\217\060V\213.S\232\063\\\227\062Z\240\065`\211"
  ".R\213.S\225\062Z\241\066a\214/T\214/T\227\062Z"
};

#endif
