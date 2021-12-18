#include "../useHeaders/player.h"

#include <math.h>

#include "../useHeaders/utils.h"
#include "raylib.h"

bool updatePlayer(Player* player, bool end) {
  if (IsKeyPressed(KEY_RIGHT) && player->position.x + player->movement.x < GetScreenWidth()) {
    player->position.x += player->movement.x;
    player->rotation = RIGHT;
  }
  if (IsKeyPressed(KEY_LEFT) && player->position.x - player->movement.x > 0) {
    player->position.x -= player->movement.x;
    player->rotation = LEFT;
  }
  if (IsKeyPressed(KEY_UP) && player->position.y - player->movement.y > 0) {
    player->position.y -= player->movement.y;
    player->rotation = UP;
  }
  if (IsKeyPressed(KEY_DOWN) && player->position.y + player->movement.y < GetScreenHeight()) {
    player->position.y += player->movement.y;
    player->rotation = DOWN;
  }

  // if (player->position.y == floor(player->movement.y * 3 + player->movement.y / 2))
  //   end = true;
  // else
  //   end = false;

  return end;
}