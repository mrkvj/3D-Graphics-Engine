#ifndef MATRIX_H
#define MATRIX_H

#include <stdio.h>
//#include "vector.h"
#include <cglm/mat4.h>
#include <cglm/vec3.h>
//#include <cglm/affine-pre.h>
#include <cglm/affine.h>
#include <cglm/cam.h>
#include <string.h>
#include <math.h>

typedef unsigned short u8;
typedef float fmat[4][4];

struct Perspective {
    float fov;// The vertical Field of View, in radians: the amount of "zoom". Think "camera lens". Usually between 90° (extra wide) and 30° (quite zoomed in)
    float aspect;// Aspect Ratio. Depends on the size of your window. Notice that 4/3 == 800/600 == 1280/960, sounds familiar?
    float near; // Near clipping plane. Keep as big as possible, or you'll get precision issues.
    float far; // Far clipping plane. Keep as little as possible.
};

void translationMatrix(vec3 xyz, mat4* dest);
void rotationMatrix(mat4* dest, float rad, vec3 axis);
void scalingMatrix(vec4 v, mat4* dest);
void modelMatrix(mat4 trans, mat4 rot, mat4 scal, mat4* dest);
void cameraMatrix(vec3 camPos, vec3 camTarget, vec3 upVec, mat4 dest);
void projectionMatrix(struct Perspective p, mat4 dest);
void mvpMatrix(mat4 projMat, mat4 viewMat, mat4 modelMat, mat4 dest);
void mat4ToFloat(fmat dest, mat4 mat);

//mat4* mat4Mul(const mat4 A, const mat4 B);
//vec4* mat4Vec4Mul(const mat4 A, const vec4 v);

#endif
