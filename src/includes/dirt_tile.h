#ifndef DIRT_TILE_H
#define DIRT_TILE_H

#include <SDL2/SDL.h>

struct dirt_tile
{
  SDL_Texture *texture;
  SDL_Rect sprite;
  SDL_Rect spriteImagePosition;
};

void dirt_tile_initializeDirtTile(struct dirt_tile *dirt_tile, SDL_Renderer *renderer);
void dirt_tile_renderDirtTile(struct dirt_tile *dirt_tile, SDL_Renderer *renderer);
void dirt_tile_destroyDirtTile(struct dirt_tile *dirt_tile);

#endif