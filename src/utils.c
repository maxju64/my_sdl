#include "../include/utils.h"
#include <stdint.h>

void draw(uint32_t *framebuffer) {
  for (int i = 0; i < WIDTH * HEIGHT; i++) {
    framebuffer[i] = i;
  }
}

uint32_t get_coordinates(uint32_t x, uint32_t y) {
  // function should return the equivalent 1D element for the 2D coordinates
  uint32_t coordinates;
  return coordinates;
}

void draw_rgb(uint32_t *framebuffer) {
  int state = RED;
  for (int i = 0; i < WIDTH * HEIGHT; i++) {
    if (i % WIDTH == 0)
      goto Black;
    switch (state) {
      case RED: {
        framebuffer[i] = 0xff0000;
        state = GREEN;
        break;
      }
      case GREEN: {
        framebuffer[i] = 0x00ff00;
        state = BLUE;
        break;
      }
      case BLUE: {
        framebuffer[i] = 0x0000ff;
        state = RED;
        break;
      }
      Black:
        framebuffer[i] = 0x000000;
        state = RED;
    }
  }
}
