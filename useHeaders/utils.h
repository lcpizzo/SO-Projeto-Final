#ifndef _UTILS_
#define _UTILS_

#include "raylib.h"

// Enum para a movimentacao do jogador
enum dir {
  UP = 0,
  RIGHT = 1,
  DOWN = 2,
  LEFT = 3
};

// Enum para as telas do jogo
enum GameScreen {
  TITLE = 0,
  GAMEPLAY = 1
};

#endif