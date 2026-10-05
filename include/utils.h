#ifndef UTILS_H

#include <SDL3/SDL.h>
#include <SDL3/SDL_error.h>
#include <SDL3/SDL_events.h>
#include <SDL3/SDL_init.h>
#include <SDL3/SDL_pixels.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_surface.h>
#include <SDL3/SDL_video.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define SDL_WINDOW_FULLSCREEN SDL_UINT64_C(0x0000000000000001)
#define WIDTH 320
#define HEIGHT 200

enum state { RED = 0, GREEN = 1, BLUE = 2 };

void draw_rgb(uint32_t *framebuffer);

void draw(uint32_t *framebuffer);

uint32_t get_coordinates(uint32_t x, uint32_t y);

#endif // !UTILS_H
