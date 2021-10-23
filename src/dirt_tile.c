#include "dirt_tile.h"

#include <SDL2/SDL_image.h>

void dirt_tile_initializeDirtTile(struct dirt_tile *dirt_tile,
                                    SDL_Renderer *renderer) {
  dirt_tile->sprite.w = 32;
  dirt_tile->sprite.h = 32;

  dirt_tile->spriteImagePosition.x = 16 * 17;
  dirt_tile->spriteImagePosition.y = 16 * 2;
  dirt_tile->spriteImagePosition.w = 16;
  dirt_tile->spriteImagePosition.h = 16;

  dirt_tile->texture = IMG_LoadTexture(renderer, "resources/tf_jungle_tileset.png");
}

void dirt_tile_renderDirtTile(struct dirt_tile *dirt_tile, SDL_Renderer *renderer) {
  SDL_RenderCopy(renderer, dirt_tile->texture, &dirt_tile->spriteImagePosition,
                 &dirt_tile->sprite);
}

void dirt_tile_destroyDirtTile(struct dirt_tile *dirt_tile) {
  SDL_DestroyTexture(dirt_tile->texture);
}