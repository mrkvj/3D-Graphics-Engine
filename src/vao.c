#include "util.h"
#include "vao.h"

struct VAO vao_create() {
    struct VAO self;
    glGenVertexArrays(1, &self.handle);
    return self;
}

void vao_bind(struct VAO self) {
    glBindVertexArray(self.handle);
}

void vao_attr(struct VAO self, /*struct VBO vbo,*/ GLuint index, GLint size, GLenum type, GLsizei stride, size_t offset) {
    vao_bind(self);
    glVertexAttribPointer(
      index,        //  atribute 0 (must match layout in the shader)
      size,     // size
      type, // type
      GL_FALSE, // normalized
      stride,        // stride
      (void*) offset  // buff offset
    );

    glEnableVertexAttribArray(index); // ?

}
