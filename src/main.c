//#include <stdio.h>
//#include <stdlib.h>
//#include <GL/glew.h>
//#include <GLFW/glfw3.h>

#include "window.h"
#include "game_state.h"
#include "util.h"
#include "../common/loadShaders.h"

struct GameState state;

void init() {
  state.window = &window;
  renderer_init(&state.renderer);
}

void destroy() {
}

void tick() {
}

void update() {
}

void render() {
}


int main() {
  window_create(init, destroy, tick, update, render);
  //window_loop();
}
