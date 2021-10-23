#include "tree_tile.h"

#include <SDL2/SDL_image.h>

void tree_tile_initializeTreeTile(struct tree_tile *tree_tile,
                                    SDL_Renderer *renderer) {
  tree_tile->sprite.w = 128;
  tree_tile->sprite.h = 128;

  tree_tile->spriteImagePosition.x = 16 * 15;
  tree_tile->spriteImagePosition.y = 16 * 5;
  tree_tile->spriteImagePosition.w = 16 * 5;
  tree_tile->spriteImagePosition.h = 16 * 6;

  tree_tile->texture = IMG_LoadTexture(renderer, "resources/tf_jungle_tileset.png");
}

void tree_tile_renderTreeTile(struct tree_tile *tree_tile, SDL_Renderer *renderer) {
  SDL_RenderCopy(renderer, tree_tile->texture, &tree_tile->spriteImagePosition,
                 &tree_tile->sprite);
}

void tree_tile_destroyTreeTile(struct tree_tile *tree_tile) {
  SDL_DestroyTexture(tree_tile->texture);
}