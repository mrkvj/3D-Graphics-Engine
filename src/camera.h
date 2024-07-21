#ifndef CAMERA_H
#define CAMERA_H

#include <cglm/mat4.h>

struct Camera {
    vec3 camPos;
    vec3 camTarget;
    vec3 upVec;
};

#endif
