#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include "SDL.h"

typedef struct
{
    SDL_Window *window;
    SDL_Renderer *renderer;
} sdlw_t;

typedef struct
{
    uint32_t window_height;
    uint32_t window_width;
    uint32_t fg;
    uint32_t bg;
} config_t;

bool init_sdl(sdlw_t *sdlw, const config_t config)
{
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
    {
        SDL_Log("Couldnt initialize %s/n", SDL_GetError());
        return false;
    }
    sdlw->window = SDL_CreateWindow("default window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, config.window_width*2, config.window_height*2, 0);
    if (!sdlw->window)
    {
        SDL_Log("Could not create window %s\n", SDL_GetError());
        return false;
    }

    sdlw->renderer = SDL_CreateRenderer(sdlw->window, -1, SDL_RENDERER_ACCELERATED);
    if (!sdlw->renderer)
    {
        SDL_Log("Could not render window %s\n", SDL_GetError());
        return false;
    }
    return true;
};

bool config_from_args(config_t *config, int argc, char **argv)
{
    // Defaults
    *config = (config_t){
        .window_height = 640,
        .window_width = 480,
        .bg = 0xFFFF00FF,
        .fg = 0x00000000};

    // Override defaults
    for (int i = 1; i < argc; i++)
    {
        (void)argv[i];
    };
    return true;
}

void final_cleanup(const sdlw_t sdlw)
{
    SDL_DestroyWindow(sdlw.window);
    SDL_DestroyRenderer(sdlw.renderer);
    SDL_Quit();
}

void clear_screen(const sdlw_t sdlw, const config_t config)
{
    const uint8_t r = (config.bg >> 24) & 0xFF;
    const uint8_t g = (config.bg >> 16) & 0xFF;
    const uint8_t b = (config.bg >> 8) & 0xFF;
    const uint8_t a = (config.bg >> 0) & 0xFF;
    SDL_SetRenderDrawColor(sdlw.renderer, r, g, b, a);
    SDL_RenderClear(sdlw.renderer);
}

void update_screen(const sdlw_t sdlw)
{
    SDL_RenderPresent(sdlw.renderer);
}


int main(int argc, char **argv)
{
    sdlw_t sdlw = {0};
    config_t config = {0};

    if (!config_from_args(&config, argc, argv))
    {
        exit(EXIT_FAILURE);
    }

    if (!init_sdl(&sdlw, config))
    {
        exit(EXIT_FAILURE);
    }

    clear_screen(sdlw, config);

    while (true)
    {
        SDL_Delay(15);
        update_screen(sdlw);
    }

    final_cleanup(sdlw);
    exit(EXIT_SUCCESS);
}