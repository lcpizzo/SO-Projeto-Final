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

void updateEnemies(HorizontalScroller *waterLily, HorizontalScroller *truck, HorizontalScroller *redCar, HorizontalScroller *blueCar, HorizontalScroller *yellowCar);

#endif