#include "state.h"

struct State state;

// Initialize everything
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

// Render frame
void render() {
  renderer(&state.renderer);
}

int main() {
  window_create(init, destroy, tick, update, render);
  window_loop();
}
