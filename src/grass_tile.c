#include "grass_tile.h"

#include <SDL2/SDL_image.h>

void grass_tile_initializeGrassTile(struct grass_tile *grass_tile,
                                    SDL_Renderer *renderer) {
  grass_tile->sprite.w = 32;
  grass_tile->sprite.h = 32;

  grass_tile->spriteImagePosition.x = 16 * 11;
  grass_tile->spriteImagePosition.y = 16 * 2;
  grass_tile->spriteImagePosition.w = 16;
  grass_tile->spriteImagePosition.h = 16;

  grass_tile->texture = IMG_LoadTexture(renderer, "resources/tf_jungle_tileset.png");
}

void grass_tile_renderGrassTile(struct grass_tile *grass_tile, SDL_Renderer *renderer) {
  SDL_RenderCopy(renderer, grass_tile->texture, &grass_tile->spriteImagePosition,
                 &grass_tile->sprite);
}

void grass_tile_destroyGrassTile(struct grass_tile *grass_tile) {
  SDL_DestroyTexture(grass_tile->texture);
}