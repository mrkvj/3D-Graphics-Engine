#include "window.h"

struct Window window;

//static void _key_callback(/*GLFWwindow *handle, */int key, int action) {
//  if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
//    _close_window(); 
//  }
//}

void window_create(FWindow init, FWindow destroy, FWindow tick, FWindow update, FWindow render) {

  window.init = init;
  window.destroy = destroy;
  window.tick = tick;
  window.update = update;
  window.render = render;

  //glewExperimental = true;

  if (!glfwInit()) {
    fprintf(stderr, "%s", "ERROR: GLFW initialization failed\n");
    exit(1);
  }

  //glfwWindowHint(GLFW_RESIZABLE, GL_TRUE); 
  glfwWindowHint(GLFW_SAMPLES, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); 

  window.size = (ivec2s) {{1280, 720}};
  window.handle = glfwCreateWindow(window.size.x, window.size.y, "Graphics Engine", NULL, NULL);

  if (window.handle == NULL) {
    fprintf(stderr, "%s", "ERROR: Window creation failed\n ");
    glfwTerminate();
    exit(1);
  };

  // Create context
  glfwMakeContextCurrent(window.handle);

  glewExperimental=true;

  // Set callbacks
  //glfwSetKeyCallback(window.handle, _key_callback);

  // Init GLEW
  if (glewInit() != GLEW_OK) {
    fprintf(stderr, "ERROR: GLEW initialization failed\n");
    exit(1);
  }
}

void window_loop() {
  window.init();
  while (/*glfwGetKey(window.handle, GLFW_KEY_ESCAPE) != GLFW_PRESS && */glfwWindowShouldClose(window.handle) == 0) {
    window.render();
    glfwSwapBuffers(window.handle);
    glfwPollEvents();
  }

}
