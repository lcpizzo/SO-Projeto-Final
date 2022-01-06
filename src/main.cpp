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

typedef enum GameScreen {
  TITLE = 0,
  GAMEPLAY = 1
} GameScreen;

int main(void) {
  // Initialization
  //--------------------------------------------------------------------------------------
  const int GRID_CONST_X = 10;
  const int GRID_CONST_Y = 7;

  const int screenWidth = GRID_CONST_X * 85;
  const int screenHeight = GRID_CONST_Y * 85;

  const int gridSize_x = screenWidth / GRID_CONST_X;
  const int gridSize_y = screenHeight / GRID_CONST_Y;

  InitWindow(screenWidth, screenHeight, "SOgger");

  GameScreen currentScreen = TITLE;

  Texture2D background = LoadTexture("./Designs/Scenario/new_scenario.png");

  Texture2D frogg_end = LoadTexture("./Designs/Player/frog_jumping.png");

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
  blueCar.position.y = (float)gridSize_y * 2;
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

  HorizontalScroller yellowCar2;
  yellowCar2.texture = LoadTexture("./Designs/Enimies/yellow_car.png");
  yellowCar2.movement.x = (float)gridSize_x;
  yellowCar2.position.x = (float)gridSize_x * 10;
  yellowCar2.position.y = (float)gridSize_y * 3;
  yellowCar2.speed.x = 0.057;
  yellowCar2.size.x = yellowCar2.texture.width * 0.7f;
  yellowCar2.size.y = yellowCar2.texture.height * 0.7f;

  std::vector<HorizontalScroller> enemies;
  enemies.push_back(truck);
  enemies.push_back(redCar);
  enemies.push_back(blueCar);
  enemies.push_back(yellowCar);
  enemies.push_back(yellowCar2);

  int score = 0;
  double prev_score = score;
  bool top = true;
  bool end = false;

  sem_t sem;
  sem_init(&sem, 0, 1);

  SetTargetFPS(60);  // Set our game to run at 60 frames-per-second
                     //--------------------------------------------------------------------------------------

  // Main game loop
  while (!WindowShouldClose())  // Detect window close button or ESC key
  {
    BeginDrawing();

    switch (currentScreen) {
      case TITLE: {
        DrawRectangle(0, 0, screenWidth, screenHeight, GREEN);
        DrawText("SOgger", 120, 20, 40, DARKGREEN);
        DrawText("SO + Frogger game", 120, 70, 30, DARKGREEN);
        DrawText("Use as setinhas [<-][^][v][->] para controlar o sapo", 120, 220, 20, BLACK);
        DrawText("Desvie dos veículos e tente chegar até o final da avenida.\nChegando lá, retorne para o início e ganhe pontos!",
                 120, 250, 20, BLACK);
        DrawText("Pressione [ENTER] para jogar!", 120, 420, 30, BLACK);
        if (IsKeyPressed(KEY_ENTER))
          currentScreen = GAMEPLAY;
      } break;

      case GAMEPLAY: {
        prev_score = score;
        std::thread threadCont(cont, &sem, &end, &top, &score, &enemies, &frogg, &background);
        std::thread threadGameOver(gameOver, &sem, &end, &top, &score, &enemies, &frogg, &frogg_end);

        threadCont.join();
        threadGameOver.join();

        if (score != prev_score) {
          enemies[0].speed.x = 0.01 + score * (rand() % 30) / 100;
          enemies[1].speed.x = 0.03 + score * (rand() % 30) / 100;
          enemies[2].speed.x = 0.037 + score * (rand() % 30) / 100;
          enemies[3].speed.x = 0.047 + score * (rand() % 30) / 100;
          enemies[4].speed.x = 0.057 + score * (rand() % 30) / 100;
        }
      } break;

      default:
        break;
    }
    EndDrawing();
  }

  // De-Initialization
  //--------------------------------------------------------------------------------------
  CloseWindow();  // Close window and OpenGL context
  sem_destroy(&sem);
  //--------------------------------------------------------------------------------------
  return 0;
}