#include "window.h"
//#include "vao.h"
#include "renderer.h"
#include "game_state.h"
#include "../common/loadShaders.h"

#include <stdio.h>
#include <stdlib.h>


struct Window window;

void window_create(FWindow init, FWindow destroy, FWindow tick, FWindow update, FWindow render) {
  window.init = init;
  window.destroy = destroy;
  window.tick = tick;
  window.update = update;
  window.render = render;

  /////////////////
  glewExperimental = true;
  /////////////////

  if (!glfwInit()) {
    fprintf(stderr, "%s", "error initializing GLFW\n");
    exit(1);
  }

  //glfwWindowHint(GLFW_RESIZABLE, GL_TRUE); 
  glfwWindowHint(GLFW_SAMPLES, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); //macos compatability

  window.size = (ivec2s) {{1280, 720}};
  window.handle = glfwCreateWindow(window.size.x, window.size.y, "Test", NULL, NULL);
  //window.handle = glfwCreateWindow(1000, 1000, "Test", NULL, NULL);

  if (window.handle == NULL) {
    fprintf(stderr, "%s", "ERROR: Window creation failed.\n ");
    glfwTerminate();
    exit(1);
  };

  glfwMakeContextCurrent(window.handle);

  glewExperimental=true;

  if (glewInit() != GLEW_OK) {
    fprintf(stderr, "Failed to initialize GLEW\n");
    exit(1);
  }

  // Create and compile our GLSL program from the shaders
  GLuint programID = LoadShaders( "res/shaders/SimpleVertexShader.vs", "res/shaders/SimpleFractureShader.fs");
  glUseProgram(programID);

  GLuint VertexArrayID;
  glGenVertexArrays(1, &VertexArrayID);
  glBindVertexArray(VertexArrayID);

  // An array of 3 vectors which represents 3 vertices
  static const GLfloat g_vertex_buffer_data[] = {
    -1.0f, -1.0f, 0.0f,
    1.0f, -1.0f, 0.0f,
    0.0f,  1.0f, 0.0f,
  };

  // This will identify our vertex buffer
  GLuint vertexbuffer;
  // Generate 1 buffer, put the resulting identifier in vertexbuffer
  glGenBuffers(1, &vertexbuffer);
  // The following commands will talk about our 'vertexbuffer' buffer
  glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
  // Give our vertices to OpenGL.
  glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);

  glfwSetInputMode(window.handle, GLFW_STICKY_KEYS, GL_TRUE);

  //while (!glfwWindowShouldClose(window.handle)) {
  while (glfwGetKey(window.handle, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(window.handle) == 0) {
    // Clear the screen. It's not mentioned before Tutorial 02, but it can cause flickering, so it's there nonetheless.
    glClear( GL_COLOR_BUFFER_BIT );

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    // Draw nothing, see you in tutorial 2 !
    // 1st attribute buffer : vertices
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    glVertexAttribPointer(
      0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
      3,                  // size
      GL_FLOAT,           // type
      GL_FALSE,           // normalized?
      0,                  // stride
      (void*)0            // array buffer offset
    );
    // Draw the triangle !
    glDrawArrays(GL_TRIANGLES, 0, 3); // Starting from vertex 0; 3 vertices total -> 1 triangle
    glDisableVertexAttribArray(0);


    // Swap buffers
    glfwSwapBuffers(window.handle);
    glfwPollEvents();

  }
}



//static void _init() {
//  window.init();
//}

//static void _update() {
//  window.update;
//}

//static void _render() {
//  window.frames++;
//  window.render();
//}

void window_loop() {
  //_init();

  glfwSetInputMode(window.handle, GLFW_STICKY_KEYS, GL_TRUE);

  //while (!glfwWindowShouldClose(window.handle)) {
  //while (glfwGetKey(window.handle, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(window.handle) == 0) {
  //  // Clear the screen. It's not mentioned before Tutorial 02, but it can cause flickering, so it's there nonetheless.
  //  glClear( GL_COLOR_BUFFER_BIT );


  //  // Draw nothing, see you in tutorial 2 !
  //  // 1st attribute buffer : vertices
  //  glEnableVertexAttribArray(0);
  //  glBindBuffer(GL_ARRAY_BUFFER, window.handle);
  //  glVertexAttribPointer(
  //    0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
  //    3,                  // size
  //    GL_FLOAT,           // type
  //    GL_FALSE,           // normalized?
  //    0,                  // stride
  //    (void*)0            // array buffer offset
  //  );
  //  // Draw the triangle !
  //  glDrawArrays(GL_TRIANGLES, 0, 3); // Starting from vertex 0; 3 vertices total -> 1 triangle
  //  glDisableVertexAttribArray(0);


  //  // Swap buffers
  //  glfwSwapBuffers(window.handle);
  //  glfwPollEvents();

  //}
}
