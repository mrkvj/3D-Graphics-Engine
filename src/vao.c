#include "vao.h"

struct VAO vao_create() {
    struct VAO self;
    glGenVertexArrays(1, &self.handle);
    return self;
}

void vao_enable(GLuint index) {
    glEnableVertexAttribArray(index);
}

void vao_disable(GLuint index) {
    glDisableVertexAttribArray(index);
}

void vao_bind(struct VAO self) {
    glBindVertexArray(self.handle);
}

void vao_attrib(/*struct VAO self, */GLuint index, GLint size, GLenum type, GLboolean normalized, GLint stride/*, GLint offset*/) {
    glVertexAttribPointer(index, size, type, normalized, stride, (void*)0);
}
