#include "Window.h"

int main(int argc, char** args) {
  Window window = window_new(600, 600);
  window_init(&window, "Tick Tac Toe");
  window_main(&window);

  return 0;
}