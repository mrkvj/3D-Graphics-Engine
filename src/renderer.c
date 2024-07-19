#include "util.h"
#include "renderer.h"
#include "vao.h"

void renderer_init(struct Renderer *self) {
    *self = (struct Renderer) {0};
    self->current_shader = SHADER_NONE;

    self->shaders[SHADER_BASIC_COLOR] = shader_create(
        "res/shaders/basic_color.vs", "res/shaders/basic_color.fs",
        1, (struct VertexAttr[]) {
            { .index = 0, .name = "position" }
        }
    );
    self->vao = vao_create();
}

//void renderer() {
//    struct Renderer *self;
//    glEnableVertexAttribArray(0);
//    vao_bind(self->vao);
//    glVertexAttribPointer(
//        0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
//        3,                  // size
//        GL_FLOAT,           // type
//        GL_FALSE,           // normalized?
//        0,                  // stride
//        (void*)0            // array buffer offset
//    );
//    // Draw the triangle !
//    glDrawArrays(GL_TRIANGLES, 0, 3); // Starting from vertex 0; 3 vertices total -> 1 triangle
//    glDisableVertexAttribArray(0);
//}
