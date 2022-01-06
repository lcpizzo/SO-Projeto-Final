#ifndef _HORIZONTALCROLLER_
#define _HORIZONTALCROLLER_

#include <vector>
#include <semaphore.h>
#include "raylib.h"

typedef struct HorizontalScroller {
	Vector2 position;
	Vector2 size;
	Vector2 movement;
	Texture2D texture;
	Vector2 speed;
} HorizontalScroller;

void updateVehicle(HorizontalScroller* vehicle);
void updateEnemies(std::vector<HorizontalScroller>* enemies);
void checkCollision(sem_t* sem, bool& end, float x, float y, std::vector<HorizontalScroller>* enemies);

#endif