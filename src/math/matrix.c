#include "matrix.h"
#include "vector.h"


// TODO: Own impementation for math (low priority do when everything else works). 

// Calculate translation matrix
void translationMatrix(vec3 xyz, mat4* dest) {
    mat4 trans;
    glm_mat4_identity(trans);
    trans[3][0] = xyz[0];
    trans[3][1] = xyz[1];
    trans[3][2] = xyz[2];
    memcpy(dest, trans, sizeof(mat4));
}

// Calculate rotation matrix
void rotationMatrix(mat4* dest, float deg, vec3 axis) {
    glm_mat4_identity(*dest);
    float rad = M_PI * deg/180;
    glm_rotate(*dest, rad, axis);
}

// Calculate scaling matrix
void scalingMatrix(vec4 v, mat4* dest) {
    mat4 scale;
    glm_mat4_identity(scale);
    scale[0][0] = v[0];
    scale[1][1] = v[1];
    scale[2][2] = v[2];
    memcpy(dest, scale, sizeof(mat4));
}

// Calculate model matrix
void modelMatrix(mat4 trans, mat4 rot, mat4 scal, mat4* dest) {
    mat4 temp;
    glm_mat4_mul(trans, rot, temp);
    glm_mat4_mul(temp, scal, *dest);
}


// Calculate view matrix
void cameraMatrix(vec3 camPos, vec3 camTarget, vec3 upVec, mat4 dest) {
    glm_lookat(camPos, camTarget, upVec, dest);
}

// Calculate projection matrix
void projectionMatrix(struct Perspective p, mat4 dest) {
    float m1n1 = 1/(p.aspect * tan(p.fov/2));
    float m2n2 = 1/tan(p.fov/2);
    float m3n3 = -(p.far + p.near) / (p.far - p.near);
    float m3n4 = -2 * (p.far * p.near) / (p.far - p.near);
    glm_mat4_zero(dest);
    dest[0][0] = m1n1;
    dest[1][1] = m2n2;
    dest[2][2] = m3n3;
    dest[2][3] = m3n4;
    dest[3][2] = -1;
}

// Calculate mvp matrix to dest
void mvpMatrix(mat4 projMat, mat4 viewMat, mat4 modelMat, mat4 dest) {
    mat4 temp;
    glm_mat4_mul(projMat, viewMat, temp);
    glm_mat4_mul(temp, modelMat, dest);
}

void mat4ToFloat(fmat dest, mat4 mat) {
    for (u8 i = 0; i < 4; i++) {
        for (u8 j = 0; j < 4; j++) {
            dest[i][j] = (float) mat[i][j];
        }
    }
}
