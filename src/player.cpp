#include "../useHeaders/player.h"

#include <iostream>
#include <math.h>

#include "../useHeaders/utils.h"
#include "raylib.h"

void updateScore(Player* player, int& score, bool& top) {
    if (floor(player->position.y) == floor(player->movement.y / 2) && top) {
        score += 1;
        top = false;
    }

    if (floor(player->position.y) == floor(player->movement.y * 6 + player->movement.y / 2) && !top) {
        score += 1;
        top = true;
    }
}

void updatePlayer(Player* player) {
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
}
