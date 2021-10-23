#ifndef BOARD_TILE_H
#define BOARD_TILE_H

#include <SDL2/SDL.h>

struct board_tile
{
  SDL_Texture *texture;
  SDL_Rect sprite;
  SDL_Rect spriteImagePosition;
};

void board_tile_initializeBoardTile(struct board_tile *board_tile, SDL_Renderer *renderer);
void board_tile_renderBoardTile(struct board_tile *board_tile, SDL_Renderer *renderer);
void board_tile_destroyBoardTile(struct board_tile *board_tile);

#endif