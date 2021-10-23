#ifndef PLAYER_H
#define PLAYER_H

#define PLAYER_NAME_SIZE 100

#include <SDL2/SDL.h>

struct player {
  char name[PLAYER_NAME_SIZE];
  SDL_Rect sprite;
  SDL_Texture *texture;
};

void player_initializePlayerStruct(struct player *player, SDL_Renderer *renderer);
void player_moveRight(struct player *player, int pixelsToMove);
void player_moveLeft(struct player *player, int pixelsToMove);
void player_moveUp(struct player *player, int pixelsToMove);
void player_moveDown(struct player *player, int pixelsToMove);
void player_renderPlayer(struct player *player, SDL_Renderer *renderer);
void player_destroyPlayer(struct player *player);

#endif