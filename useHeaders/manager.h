#ifndef _MANAGER_
#define _MANAGER_

#include "../useHeaders/horizontalScroller.h"
#include "../useHeaders/player.h"
#include "raylib.h"

#include <vector>
#include <semaphore.h>

void gameOver(sem_t *sem, bool *end, bool *top, int *score, std::vector<HorizontalScroller> *enemies,  Player *frogg, Texture2D *frogg_end);
void cont(sem_t *sem, bool *end, bool *top, int *score, std::vector<HorizontalScroller> *enemies, Player *frogg, Texture2D *background);

#endif


/*
  A funçao que precisa estar em uma thread e a de checar colisao pq ela vai causar o acionamento 
  do semaforo, a outra funçao que deve estar em uma thread que corre paralela a primeira e a que
  libera o semaforo, ou seja, uma ainda nao existente (provavelmente lidando com todo o resto do fim
  de jogo) que quando recebe o sinal de parar emitido pela colisao pode em algum momento soltar o semaforo
  

  duas threads:
    1-> roda o jogo normalmente, quando ocorre uma colisao libera o semaforo e permite que
    2-> a thread de gameOver rode. Ela continua rodando ate que o jogador pressione
      KEY_ENTER, o que 

*/
