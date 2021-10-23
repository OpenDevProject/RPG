#include <stdio.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "stagesObserver.h"

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

int main(int argc, char *argv[]) {
  SDL_Window *window = NULL;
  SDL_Renderer *renderer = NULL;

  if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
    fprintf(stderr, "Error initializing SDL, SDL Error: %s\n", SDL_GetError());

    return 1;
  }

  int imgFlags = IMG_INIT_JPG | IMG_INIT_PNG;
  if (!(IMG_Init(imgFlags) & imgFlags)) {
    fprintf(stderr, "Error initializing SDL_image, SDL Error: %s\n", SDL_GetError());

    SDL_Quit();
    return 1;
  }

  window = SDL_CreateWindow("RPG Game", SDL_WINDOWPOS_CENTERED,
                            SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT,
                            SDL_WINDOW_OPENGL);
  if (window == NULL) {
    fprintf(stderr, "Error creating window, SDL Error: %s\n", SDL_GetError());

    IMG_Quit();
    SDL_Quit();
    return 1;
  }

  renderer = SDL_CreateRenderer(
      window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  if (renderer == NULL) {
    fprintf(stderr, "Error creating renderer, SDL Error: %s\n", SDL_GetError());

    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();
    return 1;
  }

  runStage(1, window, renderer);

  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  IMG_Quit();
  SDL_Quit();
  return 0;
}