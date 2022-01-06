#ifndef _PLAYER_
#define _PLAYER_

#include "../useHeaders/horizontalScroller.h"
#include "raylib.h"

#include <semaphore.h>

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
//void gameOver(sem_t *sem, bool *end, bool *top, int *score, HorizontalScroller *truck, HorizontalScroller *redCar, HorizontalScroller *blueCar,  HorizontalScroller *yellowCar, HorizontalScroller *yellowCar2,  Player *frogg, Texture2D *frogg_end);
//void cont(sem_t *sem, bool *end, bool *top, int *score, HorizontalScroller *truck, HorizontalScroller *redCar, HorizontalScroller *blueCar, HorizontalScroller *yellowCar, HorizontalScroller *yellowCar2, Player *frogg);

#endif


/*
  A funçao que precisa estar em uma thread e a de checar colisao pq ela vai causar o acionamento
  do semaforo, a outra funçao que deve estar em uma thread que corre paralela a primeira e a que
  libera o semaforo, ou seja, uma ainda nao existente (provavelmente lidando com todo o resto do fim
  de jogo) que quando recebe o sinal de parar emitido pela colisao pode em algum momento soltar o semaforo

*/