#ifndef GAME_STATE_H
#define GAME_STATE_H

#include "renderer.h"
#include "window.h"

struct State {
    struct Window *window;
    struct Renderer renderer;
};

// Global state
extern struct State state;

#endif
