#include "state.h"

struct State state;

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
  renderer(&state.renderer);
}

int main() {
  window_create(init, destroy, tick, update, render);
  window_loop();
}
