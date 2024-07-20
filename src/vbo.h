#ifndef VBO_H
#define VBO_H

#include <GL/glew.h>

#include "math/matrix.h"
#include "math/vector.h"

static const GLfloat g_vertex_buffer_data[] = {
    -1.0f, -1.0f, 0.0f,
    1.0f, -1.0f, 0.0f,
    0.0f,  1.0f, 0.0f,
};


struct VBO {
    GLuint handle;
};

struct VBO vbo_create();
void vbo_bind(struct VBO self);
void vbo_buff();

#endif
