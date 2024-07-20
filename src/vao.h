#ifndef VAO_H
#define VAO_H

#include <GL/glew.h>

struct VAO {
    GLuint handle;
};

struct VAO vao_create();
void vao_enable(GLuint index);
void vao_disable(GLuint index);
void vao_bind(struct VAO self);
void vao_attrib(/*struct VAO self, */GLuint index, GLint size, GLenum type, GLboolean normalized, GLint stride/*, GLint offset*/);

#endif
