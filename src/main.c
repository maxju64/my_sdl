#include <SDL3/SDL.h>
#include <SDL3/SDL_init.h>
#include <SDL3/SDL_pixels.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_video.h>
#include <stdint.h>
#include <stdlib.h>
// #include <stdio.h>

#define WIDTH 320
#define HEIGHT 200

uint32_t framebuffer[WIDTH * HEIGHT];

int main(int argc, char *argv[])
{
  SDL_Window *window;
  SDL_Renderer *renderer;
  SDL_Texture *texture;

  window = SDL_CreateWindow("SDL Framebuffer",
      WIDTH,
      HEIGHT,
      0
      );

  renderer = SDL_CreateRenderer(
      window,
      NULL
      );

  texture = SDL_CreateTexture(renderer, 
      SDL_PIXELFORMAT_XRGB8888,
      SDL_TEXTUREACCESS_STREAMING,
      WIDTH,
      HEIGHT
      );

  while(true){
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
  }

  SDL_Init(SDL_INIT_VIDEO);
  return EXIT_SUCCESS;
}
