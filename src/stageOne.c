#include "stageOne.h"
#include "board_tile.h"
#include "dirt_tile.h"
#include "grass_tile.h"
#include "player.h"
#include "tree_tile.h"
#include "utils_rpg.h"

static void fillWindowWithGrassTile(struct grass_tile grassTile,
                                    SDL_Renderer *renderer);
static void createDirtPath(struct dirt_tile dirtTile, SDL_Renderer *renderer);
static void createForest(struct tree_tile treeTile, SDL_Renderer *renderer);

void stageOne_executeStageOne(SDL_Window *window, SDL_Renderer *renderer) {
  struct player player;
  player_initializePlayerStruct(&player, renderer);
  struct grass_tile grassTile;
  grass_tile_initializeGrassTile(&grassTile, renderer);
  struct dirt_tile dirtTile;
  dirt_tile_initializeDirtTile(&dirtTile, renderer);
  struct board_tile boardTile;
  board_tile_initializeBoardTile(&boardTile, renderer);
  struct tree_tile treeTile;
  tree_tile_initializeTreeTile(&treeTile, renderer);

  player.sprite.x = 32 * 2;
  player.sprite.y = 32 * 5;

  boardTile.sprite.x = 32 * 10;
  boardTile.sprite.y = 32 * 4;

  while (1) {
    SDL_Event event;
    if (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT)
        break;

      if (event.type == SDL_KEYDOWN) {
        switch (event.key.keysym.scancode) {
        case SDL_SCANCODE_D:
          player_moveRight(&player, 32);
          break;

        case SDL_SCANCODE_A:
          player_moveLeft(&player, 32);
          break;

        case SDL_SCANCODE_W:
          player_moveUp(&player, 32);
          break;

        case SDL_SCANCODE_S:
          player_moveDown(&player, 32);
          break;
        }
      }
    }

    SDL_RenderClear(renderer);

    fillWindowWithGrassTile(grassTile, renderer);
    createDirtPath(dirtTile, renderer);
    board_tile_renderBoardTile(&boardTile, renderer);

    player_renderPlayer(&player, renderer);

    createForest(treeTile, renderer);

    SDL_RenderPresent(renderer);

    SDL_Delay(1000 / 60);
  }

  board_tile_destroyBoardTile(&boardTile);
  dirt_tile_destroyDirtTile(&dirtTile);
  grass_tile_destroyGrassTile(&grassTile);
  tree_tile_destroyTreeTile(&treeTile);
  player_destroyPlayer(&player);
}

static void fillWindowWithGrassTile(struct grass_tile grassTile,
                                    SDL_Renderer *renderer) {
  for (int i = 0; i < WINDOW_WIDTH / 32; i++) {
    grassTile.sprite.x = 32 * i;
    for (int j = 0; j < WINDOW_HEIGHT / 32; j++) {
      grassTile.sprite.y = 32 * j;
      grass_tile_renderGrassTile(&grassTile, renderer);
    }
  }
}

static void createDirtPath(struct dirt_tile dirtTile, SDL_Renderer *renderer) {
  dirtTile.sprite.y = 32 * 5;

  for (int i = 0; i < WINDOW_WIDTH / 32; i++) {
    dirtTile.sprite.x = 32 * i;
    dirt_tile_renderDirtTile(&dirtTile, renderer);
  }

  dirtTile.sprite.y = 32 * 6;

  for (int i = 0; i < WINDOW_WIDTH / 32; i++) {
    dirtTile.sprite.x = 32 * i;
    dirt_tile_renderDirtTile(&dirtTile, renderer);
  }
}

static void createForest(struct tree_tile treeTile, SDL_Renderer *renderer) {
  for (int i = -1; i < WINDOW_WIDTH / 128; i++) {
    treeTile.sprite.x = 128 * i;
    treeTile.sprite.y = -64;
    tree_tile_renderTreeTile(&treeTile, renderer);
  }

  for (int i = -1; i < WINDOW_WIDTH / 78; i++) {
    treeTile.sprite.x = 78 * i;
    treeTile.sprite.y = -32;
    tree_tile_renderTreeTile(&treeTile, renderer);
  }

  for (int i = -1; i < WINDOW_WIDTH / 78; i++) {
    treeTile.sprite.x = 78 * i;
    treeTile.sprite.y = 0;
    tree_tile_renderTreeTile(&treeTile, renderer);
  }

  for (int i = -1; i < WINDOW_WIDTH / 78; i++) {
    treeTile.sprite.x = 78 * i;
    treeTile.sprite.y = 200;
    tree_tile_renderTreeTile(&treeTile, renderer);
  }

  for (int i = -1; i < WINDOW_WIDTH / 78; i++) {
    int yPosition = 200;
    treeTile.sprite.x = 78 * i;

    for (size_t y = 0; y < WINDOW_HEIGHT / 64; y++) {
      treeTile.sprite.y = yPosition;
      tree_tile_renderTreeTile(&treeTile, renderer);

      yPosition += 64;
    }
  }
}