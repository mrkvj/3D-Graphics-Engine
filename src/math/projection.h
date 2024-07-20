#ifndef PROJECTION_H
#define PROJECTION_H

#include "matrix.h"

typedef struct Perspective {
    float rad;// The vertical Field of View, in radians: the amount of "zoom". Think "camera lens". Usually between 90° (extra wide) and 30° (quite zoomed in)
    float aspect_ratio;// Aspect Ratio. Depends on the size of your window. Notice that 4/3 == 800/600 == 1280/960, sounds familiar?
    float near_plane; // Near clipping plane. Keep as big as possible, or you'll get precision issues.
    float far_plane; // Far clipping plane. Keep as little as possible.
};

mat4* projectionMatrix(struct Perspective perspective);

#endif
