#ifndef _PLAYER_
#define _PLAYER_

#include "raylib.h"

typedef struct Player {
  Vector2 position;
  Vector2 size;
  Vector2 movement;
  Texture2D texture;
  int rotation;
  Vector3 collider;
} Player;

bool updatePlayer(Player *player, bool end);

#endif