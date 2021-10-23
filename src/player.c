#include <player.h>
#include <string.h>
#include "utils_rpg.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

void player_initializePlayerStruct(struct player *player,
                                   SDL_Renderer *renderer) {
  strcpy(player->name, "");

  player->texture =
      IMG_LoadTexture(renderer, "resources/Bandit/Bandit_Idle_1.png");

  SDL_QueryTexture(player->texture, NULL, NULL, &player->sprite.w,
                   &player->sprite.h);

  player->sprite.w *= 2;
  player->sprite.h *= 2;
}

void player_moveRight(struct player *player, int pixelsToMove) {
  player->sprite.x += pixelsToMove;
  if (player->sprite.x > (WINDOW_WIDTH - player->sprite.w))
    player->sprite.x = WINDOW_WIDTH - player->sprite.w;
}

void player_moveLeft(struct player *player, int pixelsToMove) {
  player->sprite.x -= pixelsToMove;
  if (player->sprite.x <= 0)
    player->sprite.x = 0;
}

void player_moveUp(struct player *player, int pixelsToMove) {
  player->sprite.y -= pixelsToMove;
  if (player->sprite.y < 0)
    player->sprite.y = 0;
}

void player_moveDown(struct player *player, int pixelsToMove) {
  player->sprite.y += pixelsToMove;
  if (player->sprite.y > (WINDOW_HEIGHT - player->sprite.h))
    player->sprite.y = WINDOW_HEIGHT - player->sprite.h;
}

void player_renderPlayer(struct player *player, SDL_Renderer *renderer) {
  SDL_RenderCopy(renderer, player->texture, NULL, &player->sprite);
}

void player_destroyPlayer(struct player *player) {
  SDL_DestroyTexture(player->texture);
}