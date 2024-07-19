#ifndef VAO_H
#define VAO_H

#include "util.h"

static const GLfloat g_vertex_buffer_data[] = {
    -1.0f, -1.0f, 0.0f,
    1.0f, -1.0f, 0.0f,
    0.0f,  1.0f, 0.0f,
};

struct VAO {
    GLuint handle;
};

struct VAO vao_create();

void vao_bind(struct VAO self);
void vao_attr(struct VAO self, /*struct VBO vbo,*/ GLuint index, GLint size, GLenum type, GLsizei stride, size_t offset);

#endif
