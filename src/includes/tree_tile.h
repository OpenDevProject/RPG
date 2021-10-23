#ifndef TREE_TILE_H
#define TREE_TILE_H

#include <SDL2/SDL.h>

struct tree_tile
{
  SDL_Texture *texture;
  SDL_Rect sprite;
  SDL_Rect spriteImagePosition;
};

void tree_tile_initializeTreeTile(struct tree_tile *tree_tile, SDL_Renderer *renderer);
void tree_tile_renderTreeTile(struct tree_tile *tree_tile, SDL_Renderer *renderer);
void tree_tile_destroyTreeTile(struct tree_tile *tree_tile);

#endif