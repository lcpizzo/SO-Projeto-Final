#include "../useHeaders/manager.h"

#include <semaphore.h>
#include <unistd.h>

#include <iostream>
#include <thread>
#include <typeinfo>
#include <vector>

#include "../useHeaders/horizontalScroller.h"
#include "../useHeaders/player.h"
#include "../useHeaders/utils.h"
#include "raylib.h"

// Funcao principal do jogo em execucao, realizando funcoes e desenhos do jogador e 'inimigos'
void cont(sem_t *sem, bool *end, bool *top, int *score, std::vector<HorizontalScroller> *enemies, Player *frogg, Texture2D *background) {
  if (!*end) {
    // Realiza o movimento do jogador
    updatePlayer(frogg);

    // Realiza o movimento dos 'inimigos'
    updateEnemies(enemies);

    // Verifica e realiza a colisao do jogador com os 'inimigos'
    checkCollision(*end, frogg->position.x, frogg->position.y, enemies);

    // Quando ha uma colisao do jogador com um 'inimigo', o jogo finaliza pelo semaforo
    //  o semaforo a principicio e desbloqueado para liberar a thread de fim de jogo que
    //  foi bloqueada, e na linha abaixo o semaforo e bloqueado nessa thread, impedindo que o jogo continue
    //  ate que a thread de fim de jogo reinicie todos os objetos para a posicao inicial
    if (*end) {
      sem_post(sem);  // Realiza o desbloqueio do semaforo
      sem_wait(sem);  // Realiza o bloqueio do semaforo
    }

    // Funcao para a aumento do placar quando o jogador atinge as extremidades do jogo
    updateScore(frogg, *score, *top);

    ClearBackground(RAYWHITE);

    // Realiza o desenho do cenario, jogador e 'inimigos'
    DrawTextureEx(*background, (Vector2){0, 0}, 0.0f, 0.55f, WHITE);

    DrawTexturePro(frogg->texture,                                                                   // texture
                   (Rectangle){0.0f, 0.0f, frogg->texture.width, frogg->texture.height},             // Source Rectangle = parte da textura que sera usada
                   (Rectangle){frogg->position.x, frogg->position.y, frogg->size.x, frogg->size.y},  // Destination Rectangle = posicao na tela
                   (Vector2){frogg->size.x / 2, frogg->size.y / 2},                                  // Origin = ponto de rotacao da textura
                   frogg->rotation * 90.0f, WHITE);                                                  // Rotation, colour

    for (int i = 0; i <= enemies->size(); i++) {
      DrawTexturePro((*enemies)[i].texture,
                     (Rectangle){0.0f, 0.0f, (*enemies)[i].texture.width, (*enemies)[i].texture.height},
                     (Rectangle){(*enemies)[i].position.x, (*enemies)[i].position.y, (*enemies)[i].size.x, (*enemies)[i].size.y},
                     (Vector2){4, 4},
                     UP, WHITE);
    }

    DrawText(TextFormat("Score: %d", *score * 100), 10, 10, 50, WHITE);

    // Quando o jogo finaliza, desenha uma faixa de 'Game Over'
    if (*end) {
      DrawRectangle(0, GetScreenHeight() / 2 - 70, GetScreenWidth(), 70, WHITE);
      DrawText("GAME OVER", GetScreenWidth() / 2 - MeasureText("GAME OVER", 35) / 2, GetScreenHeight() / 2 - 50, 35, DARKGRAY);
    }
  }
}

// Funcao principal do jogo em estado de 'Game Over', reinicializando as variaveis e desenhos
void gameOver(sem_t *sem, bool *end, bool *top, int *score, std::vector<HorizontalScroller> *enemies, Player *frogg, Texture2D *frogg_end) {
  if (*end) {
    // caso o jogo seja encerrado com uma colisao entre o jogador e um 'inimigo', essa thread e pausada ate que as imagens do jogo sejaa atualizadas
    // uma ultima vez, e entao o jogo recomeca com todas as variaveis com seus valores iniciais
    sem_wait(sem);
    DrawRectangle(0, GetScreenHeight() / 2 - 70, GetScreenWidth(), 70, WHITE);
    DrawText("GAME OVER", GetScreenWidth() / 2 - MeasureText("GAME OVER", 35) / 2, GetScreenHeight() / 2 - 50, 35, DARKGRAY);
    sleep(2);

    *top = true;
    *score = 0;
    *end = false;

    frogg->position.x = (float)frogg->movement.x * 5 + frogg->movement.x / 2;
    frogg->position.y = (float)frogg->movement.y * 6 + frogg->movement.y / 2;
    frogg->rotation = UP;

    // Realiza o desenho do jogador "morto"
    DrawTexturePro(*frogg_end,
                   (Rectangle){0.0f, 0.0f, frogg_end->width, frogg_end->height},
                   (Rectangle){frogg->position.x, frogg->position.y, frogg_end->width * 0.6, frogg_end->height * 0.6},
                   (Vector2){frogg->size.x / 2, frogg->size.y / 2},
                   frogg->rotation * 90.0f, WHITE);

    // quando essa thread termina de ser executada ela libera a thread de continuacao do jogo que ficou bloqueada
    sem_post(sem);
  }
}
