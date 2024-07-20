#ifndef MATRIX_H
#define MATRIX_H

#include <stdio.h>
#include "vector.h"

typedef float mat4[4][4];

mat4* mat4_mul(const mat4 A, const mat4 B);
mat4* mat4_vec4_mul(const mat4 A, const vec4 v);

#endif
