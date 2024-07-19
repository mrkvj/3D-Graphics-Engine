#ifndef SHADER_H
#define SHADER_H

#include "util.h"

struct VertexAttr {
    GLuint index;
    const GLchar *name;
};

struct Shader {
    GLuint handle, vs_handle, fs_handle;
};

struct Shader shader_create(char *vs_path, char *fs_path, size_t n, struct VertexAttr atrributes[]);

#endif
