#ifndef WINDOW_H
#define WINDOW_H

#include <GL/glew.h> 
#include <GLFW/glfw3.h>     // For Windows, Contexts and Input.
#include <cglm/struct.h>    // For ivec2s

typedef void (*FWindow)();

struct Window {
    GLFWwindow *handle;
    ivec2s size;
    FWindow init, destroy, tick, update, render;
    uint64_t frames, fps, last_frame, frame_delta;
};

// Global window
extern struct Window window;

void window_loop();
void window_create(FWindow init, FWindow destroy, FWindow tick, FWindow update, FWindow render);


#endif
