#include <math.h>
#include <semaphore.h>
#include <stdlib.h>
#include <unistd.h>

#include <thread>
#include <vector>

#include "../useHeaders/horizontalScroller.h"
#include "../useHeaders/manager.h"
#include "../useHeaders/player.h"
#include "../useHeaders/utils.h"
#include "raylib.h"

int main(void) {
  // Inicializacao de variaveis
  const int GRID_CONST_X = 10;
  const int GRID_CONST_Y = 7;

  const int screenWidth = GRID_CONST_X * 85;
  const int screenHeight = GRID_CONST_Y * 85;

  const int gridSize_x = screenWidth / GRID_CONST_X;
  const int gridSize_y = screenHeight / GRID_CONST_Y;

  // Inicializa a janela do jogo com os tamanhos ja definidos
  InitWindow(screenWidth, screenHeight, "SOgger");

  GameScreen currentScreen = TITLE;

  Texture2D background = LoadTexture("./Designs/Scenario/new_scenario.png");

  Texture2D frogg_end = LoadTexture("./Designs/Player/frog_jumping.png");

  // Inicializacao e atribuicao dos valores para o 'personagem' e 'inimigos'
  Player frogg;
  frogg.texture = LoadTexture("./Designs/Player/frog.png");
  frogg.movement.x = (float)gridSize_x;
  frogg.movement.y = (float)gridSize_y;
  frogg.position.x = (float)gridSize_x * 5 + gridSize_x / 2;
  frogg.position.y = (float)gridSize_y * 6 + gridSize_y / 2;
  frogg.rotation = UP;
  frogg.size.x = frogg.texture.width * 0.7f;
  frogg.size.y = frogg.texture.height * 0.7f;

  HorizontalScroller truck;
  truck.texture = LoadTexture("./Designs/Enimies/truck.png");
  truck.movement.x = (float)gridSize_x;
  truck.position.x = (float)gridSize_x * 10;
  truck.position.y = (float)gridSize_y * 4;
  truck.speed.x = 0.025;
  truck.size.x = truck.texture.width * 0.7f;
  truck.size.y = truck.texture.height * 0.7f;

  HorizontalScroller redCar;
  redCar.texture = LoadTexture("./Designs/Enimies/red_car.png");
  redCar.movement.x = (float)gridSize_x;
  redCar.position.x = (float)gridSize_x * 10;
  redCar.position.y = (float)gridSize_y * 1;
  redCar.speed.x = 0.03;
  redCar.size.x = redCar.texture.width * 0.7f;
  redCar.size.y = redCar.texture.height * 0.7f;

  HorizontalScroller blueCar;
  blueCar.texture = LoadTexture("./Designs/Enimies/blue_car.png");
  blueCar.movement.x = (float)gridSize_x;
  blueCar.position.x = (float)gridSize_x * 10;
  blueCar.position.y = (float)gridSize_y * 3;
  blueCar.speed.x = 0.037;
  blueCar.size.x = blueCar.texture.width * 0.7f;
  blueCar.size.y = blueCar.texture.height * 0.7f;

  HorizontalScroller yellowCar;
  yellowCar.texture = LoadTexture("./Designs/Enimies/yellow_car.png");
  yellowCar.movement.x = (float)gridSize_x;
  yellowCar.position.x = (float)gridSize_x * 10;
  yellowCar.position.y = (float)gridSize_y * 5;
  yellowCar.speed.x = 0.047;
  yellowCar.size.x = yellowCar.texture.width * 0.7f;
  yellowCar.size.y = yellowCar.texture.height * 0.7f;

  HorizontalScroller truck2;
  truck2.texture = LoadTexture("./Designs/Enimies/truck.png");
  truck2.movement.x = (float)gridSize_x;
  truck2.position.x = (float)gridSize_x * 10;
  truck2.position.y = (float)gridSize_y * 2;
  truck2.speed.x = 0.027;
  truck2.size.x = truck2.texture.width * 0.7f;
  truck2.size.y = truck2.texture.height * 0.7f;

  // Insere os 'inimigos' em um vetor para facilitar a manipulacao
  std::vector<HorizontalScroller> enemies;
  enemies.push_back(truck);
  enemies.push_back(redCar);
  enemies.push_back(blueCar);
  enemies.push_back(yellowCar);
  enemies.push_back(truck2);

  int score = 0;
  double prev_score = score;
  bool top = true;
  bool end = false;

  // Inicializacao do semaforo
  sem_t sem;
  sem_init(&sem, 0, 1);

  // Inicializa o jogo a 60 frames por segundo
  SetTargetFPS(60);

  // Principal loop do jogo
  while (!WindowShouldClose())  // Detecta o fechamento da janela (ou pela tecla ESC)
  {
    BeginDrawing();

    // 2 telas do jogo:
    // TITLE: Primeira tela com titulo e instrucoes do jogo
    // GAMEPLAY: Tela principal do jogo em execucao
    switch (currentScreen) {
      case TITLE: {
        // Textos da tela TITLE
        DrawRectangle(0, 0, screenWidth, screenHeight, GREEN);
        DrawText("SOgger", 120, 20, 40, DARKGREEN);
        DrawText("SO + Frogger game", 120, 70, 30, DARKGREEN);
        DrawText("Use as setinhas [<-][^][v][->] para controlar o sapo.", 120, 220, 20, BLACK);
        DrawText("Desvie dos ve??culos e tente chegar at?? o final da avenida.\nChegando l??, retorne para o in??cio e ganhe pontos!\nSe voc?? morrer, espere 2 segundos para reiniciar o jogo.",
                 120, 250, 20, BLACK);
        DrawText("Pressione [ENTER] para jogar!", 120, 420, 30, BLACK);

        // Alterna para a tela GAMEPLAY quando pressionada a tecla ENTER
        if (IsKeyPressed(KEY_ENTER))
          currentScreen = GAMEPLAY;

      } break;

      case GAMEPLAY: {
        prev_score = score;

        /*
         Inicializacao das 2 threads do jogo
         threadCont: thread que chama a funcao cont(), que executa as principais funcoes do jogo
         threadGameOver: thread que chama a funcao gameover(), que executa as funcoes quando o personagem morre e o jogo finaliza e recomeca

         apesar das duas threads ocorrerem simultaneamente, a thread de fim de jogo apenas realiza a parada se uma colisao e consequentemente
            o fim de jogo for desencadeado, caso contrario ela comeca e termina sem fazer nada alem de checar se o jogo acabou
            enquanto a thread cont realiza todas as funcoes de mudanca de posicao dos objetos, atualizar o score e checar a colisao
        */
        std::thread threadCont(cont, &sem, &end, &top, &score, &enemies, &frogg, &background);
        std::thread threadGameOver(gameOver, &sem, &end, &top, &score, &enemies, &frogg, &frogg_end);

        // Espera para que a threadCont finalize
        threadCont.join();
        // Espera para que a threadGameOver finalize
        threadGameOver.join();

        // Aumenta a velocidade dos 'inimigos' conforme o jogador ganha mais pontos
        if (score != prev_score) {
          enemies[0].speed.x += 0.01;
          enemies[1].speed.x += 0.01;
          enemies[2].speed.x += 0.01;
          enemies[3].speed.x += 0.01;
          enemies[4].speed.x += 0.01;
        }

        // Retorna a velocidade inicial dos 'inimigos' quando o jogador morre
        if (score == 0) {
          enemies[0].speed.x = 0.025;
          enemies[1].speed.x = 0.03;
          enemies[2].speed.x = 0.037;
          enemies[3].speed.x = 0.047;
          enemies[4].speed.x = 0.027;
        }
      } break;

      default:
        break;
    }
    EndDrawing();
  }

  CloseWindow();

  // Finaliza o semaforo
  sem_destroy(&sem);
  return 0;
}