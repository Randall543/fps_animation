#include "SDL3/SDL_error.h"
#include "SDL3/SDL_init.h"
#include "SDL3/SDL_render.h"
#include "SDL3/SDL_video.h"
#include <stdio.h>
#include <SDL3/SDL.h>

int main(){
    SDL_Window* window;
    SDL_Renderer* render;

    if (!SDL_Init(SDL_INIT_VIDEO)){
        printf("library couldn't be initialized: %s\n", SDL_GetError());
        return 1;
    }


    
}
