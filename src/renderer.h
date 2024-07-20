#ifndef RENDERER_H
#define RENDERER_H
#define SHADERS_LAST SIMPLE_SHADER

#include <GL/glew.h>
#include "vao.h"
#include "vbo.h"
#include "../common/loadShaders.h"

#define SHADERS_LAST SIMPLE_SHADER

enum ShaderType {
    SHADER_NONE = 0,
    // ADD MORE SHADERS HERE
    SIMPLE_SHADER
};

struct Shader {
    GLuint handle;
};

struct Renderer {
    // Camera here

    struct Shader shaders[SHADERS_LAST + 1];
    enum ShaderType current_shader;
    struct Shader shader;
    
    struct VAO vao;
    struct VBO vbo;
};

void renderer_init(struct Renderer *self);
void renderer_prep(struct Renderer *self);
void renderer(struct Renderer *self);

#endif

