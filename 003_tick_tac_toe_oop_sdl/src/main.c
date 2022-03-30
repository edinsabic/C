#include "app/Window.h"

int main(int argc, char** args)
{
    Window window = window_new(600, 600);
    window_init(&window);
    window_main(&window);
    window_close(&window);
    
    return 0;
}