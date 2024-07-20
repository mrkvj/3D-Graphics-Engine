#include "vbo.h"

struct VBO vbo_create() {
    struct VBO self;
    glGenBuffers(1, &self.handle);
    return self;
}

void vbo_bind(struct VBO self) {
    glBindBuffer(GL_ARRAY_BUFFER, self.handle);
}

void vbo_buff() {
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);
}

