#include "board_tile.h"

#include <SDL2/SDL_image.h>

void board_tile_initializeBoardTile(struct board_tile *board_tile,
                                    SDL_Renderer *renderer) {
  board_tile->sprite.w = 32;
  board_tile->sprite.h = 32;

  board_tile->spriteImagePosition.x = 64;
  board_tile->spriteImagePosition.y = 0;
  board_tile->spriteImagePosition.w = 32;
  board_tile->spriteImagePosition.h = 32;

  board_tile->texture = IMG_LoadTexture(renderer, "resources/RPG_Nature_Tileset.png");
}

void board_tile_renderBoardTile(struct board_tile *board_tile, SDL_Renderer *renderer) {
  SDL_RenderCopy(renderer, board_tile->texture, &board_tile->spriteImagePosition,
                 &board_tile->sprite);
}

void board_tile_destroyBoardTile(struct board_tile *board_tile) {
  SDL_DestroyTexture(board_tile->texture);
}