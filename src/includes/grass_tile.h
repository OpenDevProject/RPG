#ifndef GRASS_TILE_H
#define GRASS_TILE_H

#include <SDL2/SDL.h>

struct grass_tile
{
  SDL_Texture *texture;
  SDL_Rect sprite;
  SDL_Rect spriteImagePosition;
};

void grass_tile_initializeGrassTile(struct grass_tile *grass_tile, SDL_Renderer *renderer);
void grass_tile_renderGrassTile(struct grass_tile *grass_tile, SDL_Renderer *renderer);
void grass_tile_destroyGrassTile(struct grass_tile *grass_tile);

#endif