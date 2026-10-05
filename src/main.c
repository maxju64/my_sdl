#include "../include/utils.h"
int main(int argc, char *argv[]) {
  SDL_Window *window;
  SDL_Renderer *renderer;
  SDL_Texture *texture;
  SDL_Event event;
  if (!SDL_Init(SDL_INIT_VIDEO)) {
    fprintf(stderr, "SDL_Init failed! %s\n", SDL_GetError());
  }

  window = SDL_CreateWindow("SDL Framebuffer", WIDTH * 4, HEIGHT * 4, 0);
  if (window == NULL) {
    fprintf(stderr, "SDL_Init failed! %s\n", SDL_GetError());
  }
  renderer = SDL_CreateRenderer(window, NULL);
  if (renderer == NULL) {
    fprintf(stderr, "SDL_Init failed! %s\n", SDL_GetError());
  }
  texture = SDL_CreateTexture(
      renderer,
      SDL_PIXELFORMAT_XRGB8888,
      SDL_TEXTUREACCESS_STREAMING,
      WIDTH,
      HEIGHT);
  if (texture == NULL) {
    fprintf(stderr, "SDL_Init failed! %s\n", SDL_GetError());
  }

  uint32_t framebuffer[WIDTH * HEIGHT];
  SDL_SetTextureScaleMode(texture, SDL_SCALEMODE_NEAREST);

  uint8_t is_running = 1;

  // Display window and renderer
  while (is_running) {
    // Poll events
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_EVENT_QUIT) {
        is_running = 0;
      }
    }
    // Manipulate framebuffer array as we wish
    // framebuffer[16000] = 0xff0000;
    int state = RED;
    draw(framebuffer);

    // Update contents of framebuffer to the texture
    SDL_UpdateTexture(texture, NULL, framebuffer, WIDTH * sizeof(uint32_t));
    SDL_RenderClear(renderer);
    SDL_RenderTexture(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);
  }

  SDL_DestroyTexture(texture);
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();

  return EXIT_SUCCESS;
}
