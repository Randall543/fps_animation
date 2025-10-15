#include "SDL3/SDL.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
    SDL_Window* window = NULL;
    SDL_Renderer* render = NULL;
    
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        printf("Couldn't initialize SDL: %s\n", SDL_GetError());
        return 1;
    }
    
    if (!SDL_CreateWindowAndRenderer("First Example", 700, 800, SDL_WINDOW_RESIZABLE, &window, &render) != 0) {
        printf("Window could not be created: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }
    
    int running = 1;
    while (running) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                running = 0;
            }
        }
        
        const double now = ((double)SDL_GetTicks()) / 1000.0;
        const float red = (float)(0.5 + 0.5 * SDL_sin(now));
        const float green = (float)(0.5 + 0.5 * SDL_sin(now + SDL_PI_D * 2 / 3));
        const float blue = (float)(0.5 + 0.5 * SDL_sin(now + SDL_PI_D * 4 / 3));
        
        SDL_SetRenderDrawColorFloat(render, red, green, blue, SDL_ALPHA_OPAQUE_FLOAT);
        SDL_RenderClear(render);
        SDL_RenderPresent(render);
        
        SDL_Delay(16);
    }
    
    SDL_DestroyRenderer(render);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
