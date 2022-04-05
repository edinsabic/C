#include "Window.h"

int main(int argc, char** args) {
  Window window = window_new(600, 600);
  window_init(&window, "Ping pong");
  window_main(&window);

  return 0;
}