#ifndef _MANAGER_
#define _MANAGER_

#include <semaphore.h>

#include <vector>

#include "../useHeaders/horizontalScroller.h"
#include "../useHeaders/player.h"
#include "raylib.h"

void gameOver(sem_t *sem, bool *end, bool *top, int *score, std::vector<HorizontalScroller> *enemies, Player *frogg, Texture2D *frogg_end);
void cont(sem_t *sem, bool *end, bool *top, int *score, std::vector<HorizontalScroller> *enemies, Player *frogg, Texture2D *background);

#endif
