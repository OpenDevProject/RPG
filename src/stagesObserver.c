#include "stagesObserver.h"
#include "stageOne.h"

bool runStage(int stageNumber, SDL_Window *window, SDL_Renderer *renderer) {
  switch (stageNumber)
  {
  case 1:
    stageOne_executeStageOne(window, renderer);
    break;
  
  default:
    break;
  }
}