#ifndef _HORIZONTALCROLLER_
#define _HORIZONTALCROLLER_

#include "raylib.h"

typedef struct HorizontalScroller {
  Vector2 position;
  Vector2 size;
  Vector2 movement;
  Texture2D texture;
  Vector2 speed;
} HorizontalScroller;

void updateEnemies(HorizontalScroller *truck, HorizontalScroller *redCar, HorizontalScroller *blueCar, HorizontalScroller *yellowCar, HorizontalScroller *yellowCar2);
bool checkCollision(bool end, float x, float y, HorizontalScroller *truck, HorizontalScroller *redCar, HorizontalScroller *blueCar, HorizontalScroller *yellowCar, HorizontalScroller *yellowCar2);

#endif