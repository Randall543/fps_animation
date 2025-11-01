#include "SDL3/SDL_error.h"
#include "SDL3/SDL_init.h"
#include "SDL3/SDL_render.h"
#include "SDL3/SDL_video.h"
#include <stdio.h>
#include <SDL3/SDL.h>

int main(){
    // pointers for the window we'll use and renderer.
    SDL_Window* window;
    SDL_Renderer* render;
    
    // this is to initialize the library & handling it if it fails.
    // Also I want to use it's video subsystem, not anything else.
    if (!SDL_Init(SDL_INIT_VIDEO)){
        printf("library couldn't be initialized: %s\n", SDL_GetError());
        return 1;
    }
    
    // library provides a simple function to create a window and set the render to target this window. This'll connect the two.
    // if it fails, then we say so and return.
    if (!SDL_CreateWindowAndRenderer("My First Window", 360, 360, SDL_WINDOW_RESIZABLE, &window, &render)) {
            printf("library couldn't be initialized: %s\n", SDL_GetError());
            return 1;
    }

    
}
