#ifndef GAME_STATE_H
#define GAME_STATE_H

#include "renderer.h"
#include "window.h"
//#include "world.h"


struct GameState {
    struct Window *window;
    struct Renderer renderer;
    //struct World world;
    //struct UI ui;
    //size_t ticks;
};

extern struct GameState state;

#endif
