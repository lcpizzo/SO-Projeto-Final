#ifndef _HORIZONTALCROLLER_
#define _HORIZONTALCROLLER_

#include <vector>

#include "raylib.h"

typedef struct HorizontalScroller {
  Vector2 position;
  Vector2 size;
  Vector2 movement;
  Texture2D texture;
  Vector2 speed;
} HorizontalScroller;

void updateEnemies(std::vector<HorizontalScroller> *enemies);
bool checkCollision(bool end, float x, float y, std::vector<HorizontalScroller> *enemies);

#endif