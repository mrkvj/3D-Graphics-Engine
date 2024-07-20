#include "matrix.h"
#include "vector.h"

mat4* mat4_mul(const mat4 A, const mat4 B) {
    mat4 M;
    for (short i = 0; i <= 4; i++) {
        for (short j = 0; j <= 4; j++) {
            M[i][j] = A[i][j] * B[i][j];
        }
    }
    return *M;
}

mat4* mat4_vec4_mul(const mat4 A, const vec4 v) {
    mat4 M; 
    for (short i = 0; i <= 4; i++) {
        for (short j = 0; j <= 4; j++) {
            M[i][j] = A[i][j] * v[i];
        }
    }
    return *M;
}