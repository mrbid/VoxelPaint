/*
--------------------------------------------------
    James William Fletcher (github.com/mrbid)
        July 2023 - esVoxel.h v1.0
--------------------------------------------------

    A pretty good color converter: https://www.easyrgb.com/en/convert.php

    A voxel is: vec4(x,y,z,texture_offset)

    Requires:
        - vec.h: https://gist.github.com/mrbid/77a92019e1ab8b86109bf103166bd04e
        - mat.h: https://gist.github.com/mrbid/cbc69ec9d99b0fda44204975fcbeae7c
    
*/

#ifndef AUX_H
#define AUX_H

#include "vec.h"
#include "mat.h"

//*************************************
// MATRIX
//*************************************

// structures
typedef struct
{
    GLuint vid; // Vertex Array Buffer ID
    GLuint iid;	// Index Array Buffer ID
    GLuint nid;	// Normal Array Buffer ID
    GLuint tid;	// TexCoord Array Buffer ID
} ESModel;

//*************************************
// UTILITY
//*************************************

GLuint  esRand(const GLuint min, const GLuint max);
GLfloat esRandFloat(const GLfloat min, const GLfloat max);
void    esBind(const GLenum target, GLuint* buffer, const void* data, const GLsizeiptr datalen, const GLenum usage);
void    esRebind(const GLenum target, GLuint* buffer, const void* data, const GLsizeiptr datalen, const GLenum usage);
GLuint  esLoadTexture(const GLuint w, const GLuint h, const unsigned char* data, const GLuint linear);
GLuint  esLoadTextureA(const GLuint w, const GLuint h, const unsigned char* data, const GLuint linear);

//*************************************
// SHADER
//*************************************

GLuint debugShader(GLuint shader_program);

void makeAllShaders();

void makeHud();
void makeVoxel();
void shadeHud(GLint* position, GLint* projection, GLint* modelview, GLint* texcoord, GLint* sampler);
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


GLuint esLoadTexture(const GLuint w, const GLuint h, const unsigned char* data, const GLuint linear)
{
    // https://registry.khronos.org/OpenGL-Refpages/es3/html/glTexParameter.xhtml
    // https://docs.gl/es2/glTexParameter
    GLuint textureId;

    // Use tightly packed data
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

    // Generate a texture object
    glGenTextures(1, &textureId);

    // Bind the texture object
    glBindTexture(GL_TEXTURE_2D, textureId);

    // Load the texture
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, w, h, 0, GL_RGB, GL_UNSIGNED_BYTE, data);

    // Set the filtering mode
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    if(linear == 1)
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

GLuint esLoadTextureA(const GLuint w, const GLuint h, const unsigned char* data, const GLuint linear)
{
    GLuint textureId;
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    glGenTextures(1, &textureId);
    glBindTexture(GL_TEXTURE_2D, textureId);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    if(linear == 1)
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

#ifdef GL_DEBUG
// https://registry.khronos.org/OpenGL-Refpages/gl4/html/glDebugMessageControl.xhtml
// https://registry.khronos.org/OpenGL-Refpages/es3/html/glDebugMessageControl.xhtml
// OpenGL ES 3.2 or OpenGL 4.3 and above only.
void GLAPIENTRY MessageCallback( GLenum source,
                 GLenum type,
                 GLuint id,
                 GLenum severity,
                 GLsizei length,
                 const GLchar* message,
                 const void* userParam )
{
    printf("GL CALLBACK: %s type = 0x%x, severity = 0x%x, message = %s\n",
        ( type == GL_DEBUG_TYPE_ERROR ? "** GL ERROR **" : "" ),
        type, severity, message );
}

void esDebug(const GLuint state)
{
    if(state == 1)
    {
        glEnable(GL_DEBUG_OUTPUT);
        glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
        glDebugMessageCallback(MessageCallback, 0);
        glDebugMessageControl(GL_DEBUG_SOURCE_API, GL_DONT_CARE, GL_DEBUG_SEVERITY_NOTIFICATION, 0, NULL, GL_FALSE);
    }
    else
    {
        glDisable(GL_DEBUG_OUTPUT);
        glDisable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
    }
}
#endif

GLuint debugShader(GLuint shader_program)
{
    GLint linked;
    glGetProgramiv(shader_program, GL_LINK_STATUS, &linked);
    if(linked == GL_FALSE) 
    {
        GLint infoLen = 0;
        glGetProgramiv(shader_program, GL_INFO_LOG_LENGTH, &infoLen);
        if(infoLen > 1)
        {
            char* infoLog = malloc(sizeof(char) * infoLen);
            if(infoLog != NULL)
            {
                glGetProgramInfoLog(shader_program, infoLen, NULL, infoLog);
                printf("!!! error linking shader !!!\n%s\n", infoLog);            
                free(infoLog);
            }
        }
        else
        {
            printf("!!! failed to link shader with no returned debug output !!!\n");
        }
        glDeleteProgram(shader_program);
        return linked;
    }
    return linked;
}

//*************************************
// SHADER CODE
//*************************************

const GLchar* v0 =
    "#version 100\n"
    "uniform mat4 modelview;\n"
    "uniform mat4 projection;\n"
    "attribute vec4 position;\n"
    "attribute vec2 texcoord;\n"
    "varying vec2 vtc;\n"
    "void main()\n"
    "{\n"
        "vtc = texcoord;\n"
        "gl_Position = projection * modelview * position;\n"
    "}\n";

const GLchar* f0 =
    "#version 100\n"
    "precision mediump float;\n"
    "varying vec2 vtc;\n"
    "uniform sampler2D tex;\n"
    "void main()\n"
    "{\n"
        "gl_FragColor = texture2D(tex, vtc);\n"
    "}\n";

//#define VERTEX_SHADE
#ifdef VERTEX_SHADE

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
            "vertPos = vertPos4.xyz / vertPos4.w;\n"
            "vertNorm = vec3(modelview * vec4(normal, 0.0));\n"
            "vec3 lightDir = normalize(-vertPos);\n"
            "lambertian = max(dot(lightDir, normalize(vertNorm)), 0.0) * clamp(1.0 - (length(vertPos)*0.002), 0.0, 1.0);\n"
            "vto = voxel.w;\n"
            "gl_Position = projection * vertPos4;\n"
        "}\n";

    const GLchar* f1 =
        "#version 100\n"
        "precision mediump float;\n"
        "varying float lambertian;\n"
        "varying vec2 vtc;\n"
        "varying float vto;\n"
        "uniform sampler2D tex;\n"
        "void main()\n"
        "{\n"
            "vec4 tcol = texture2D(tex, vec2(vtc.x+(0.058823529*vto), vtc.y));\n"
            "gl_FragColor = vec4((tcol.xyz * 0.64) + lambertian*tcol.xyz, 1.f);\n"
        "}\n";

#else

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
            "vec3 lightDir = normalize(-vertPos);\n"
            "float lambertian = max(dot(lightDir, normalize(vertNorm)), 0.0);\n"
            //"gl_FragColor = vec4(ambientColor + lambertian*tcol.xyz, 1.0);\n"
    #ifndef SKYBLUE
            "gl_FragColor = vec4((ambientColor + lambertian*tcol.xyz) * clamp(1.0 - (length(vertPos)*0.002), 0.0, 1.0), 1.0);\n"
    #else
            "float amt = clamp(1.0 - (length(vertPos)*0.002), 0.0, 1.0);\n"
            "gl_FragColor = vec4( ((ambientColor + lambertian*tcol.xyz) * amt) + (vec3(0.3, 0.745, 0.8863) * (1.0-amt)) , 1.0);\n"
    #endif
        "}\n";

#endif

//

GLuint shdHud;
GLint  shdHud_position;
GLint  shdHud_projection;
GLint  shdHud_modelview;
GLint  shdHud_texcoord;
GLint  shdHud_sampler;

GLuint shdVoxel;
GLint  shdVoxel_position;
GLint  shdVoxel_projection;
GLint  shdVoxel_view;
GLint  shdVoxel_voxel;
GLint  shdVoxel_texcoord;
GLint  shdVoxel_sampler;
GLint  shdVoxel_normal;

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

    if(debugShader(shdHud) == GL_FALSE){return;}

    shdHud_position   = glGetAttribLocation(shdHud,  "position");
    shdHud_texcoord   = glGetAttribLocation(shdHud,  "texcoord");

    shdHud_projection = glGetUniformLocation(shdHud, "projection");
    shdHud_modelview  = glGetUniformLocation(shdHud, "modelview");
    shdHud_sampler    = glGetUniformLocation(shdHud, "tex");
}

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

    if(debugShader(shdVoxel) == GL_FALSE){return;}

    shdVoxel_position   = glGetAttribLocation(shdVoxel,  "position");
    shdVoxel_normal     = glGetAttribLocation(shdVoxel,  "normal");
    shdVoxel_texcoord   = glGetAttribLocation(shdVoxel,  "texcoord");

    shdVoxel_projection = glGetUniformLocation(shdVoxel, "projection");
    shdVoxel_view       = glGetUniformLocation(shdVoxel, "view");
    shdVoxel_voxel      = glGetUniformLocation(shdVoxel, "voxel");
    shdVoxel_sampler    = glGetUniformLocation(shdVoxel, "tex");
}

void makeAllShaders()
{
    makeHud();
    makeVoxel();
}

void shadeHud(GLint* position, GLint* projection, GLint* modelview, GLint* texcoord, GLint* sampler)
{
    *position = shdHud_position;
    *projection = shdHud_projection;
    *modelview = shdHud_modelview;
    *texcoord = shdHud_texcoord;
    *sampler = shdHud_sampler;
    glUseProgram(shdHud);
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

#endif
