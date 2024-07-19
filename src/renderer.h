#ifndef RENDERER_H
#define RENDERER_H
#define SHADERS_LAST SHADER_BASIC_COLOR

#include "util.h"
#include "shader.h"
#include "vao.h"

#define SHADERS_LAST SHADER_BASIC_COLOR
enum ShaderType {
    SHADER_NONE = 0,
    // ADD MORE SHADERS HERE
    SHADER_BASIC_COLOR
};

struct Renderer {
    // Camera here

    struct Shader shaders[SHADERS_LAST + 1];
    enum ShaderType current_shader;
    struct Shader shader;
    
    struct VAO vao;
};

void renderer_init(struct Renderer *self);
void renderer(struct Renderer *self);

#endif

