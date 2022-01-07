#ifndef _PLAYER_
#define _PLAYER_

#include <semaphore.h>

#include "../useHeaders/horizontalScroller.h"
#include "raylib.h"

// Inicializacao do struct do jogador
typedef struct Player {
  Vector2 position;
  Vector2 size;
  Vector2 movement;
  Texture2D texture;
  int rotation;
  Vector3 collider;
} Player;

void updateScore(Player* player, int& score, bool& top);
void updatePlayer(Player* player);

#endif
