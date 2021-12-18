#include <math.h>
#include <semaphore.h>
#include <unistd.h>

#include <chrono>
#include <thread>

#include "../useHeaders/horizontalScroller.h"
#include "../useHeaders/player.h"
#include "../useHeaders/utils.h"
#include "raylib.h"

bool end;

int main(void) {
  // Initialization
  //--------------------------------------------------------------------------------------
  const int GRID_CONST_X = 10;
  const int GRID_CONST_Y = 7;

  const int screenWidth = GRID_CONST_X * 85;
  const int screenHeight = GRID_CONST_Y * 85;

  const int gridSize_x = screenWidth / GRID_CONST_X;
  const int gridSize_y = screenHeight / GRID_CONST_Y;

  InitWindow(screenWidth, screenHeight, "Projeto SO Final - teste player && scenario");

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
  truck.speed.x = 0.01;
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

  end = false;

  SetTargetFPS(60);  // Set our game to run at 60 frames-per-second
                     //--------------------------------------------------------------------------------------

  // Main game loop
  while (!WindowShouldClose())  // Detect window close button or ESC key
  {
    if (!end) {
      // Update
      //----------------------------------------------------------------------------------
      end = updatePlayer(&frogg, end);
      end = checkCollision(end, frogg.position.x, frogg.position.y, &truck, &redCar, &blueCar, &yellowCar, &yellowCar2);

      updateEnemies(&truck, &redCar, &blueCar, &yellowCar, &yellowCar2);
      end = checkCollision(end, frogg.position.x, frogg.position.y, &truck, &redCar, &blueCar, &yellowCar, &yellowCar2);

      //----------------------------------------------------------------------------------

      // Draw
      //----------------------------------------------------------------------------------
      BeginDrawing();

      ClearBackground(RAYWHITE);

      DrawTextureEx(background, (Vector2){0, 0}, 0.0f, 0.55f, WHITE);

      for (int i = 0; i <= screenWidth / gridSize_x; i++) DrawRectangle(gridSize_x * i, 0, 1, screenHeight, SKYBLUE);
      for (int i = 0; i <= screenHeight / gridSize_y; i++) DrawRectangle(0, gridSize_y * i, screenWidth, 1, SKYBLUE);

      DrawTexturePro(frogg.texture,                                                                // texture
                     (Rectangle){0.0f, 0.0f, frogg.texture.width, frogg.texture.height},           // Source Rectangle = parte da textura que será usada
                     (Rectangle){frogg.position.x, frogg.position.y, frogg.size.x, frogg.size.y},  // Destination Rectangle = posição na tela
                     (Vector2){frogg.size.x / 2, frogg.size.y / 2},                                // Origin = ponto de rotação da textura
                     frogg.rotation * 90.0f, WHITE);                                               // Rotation, colour

      DrawTexturePro(truck.texture,
                     (Rectangle){0.0f, 0.0f, truck.texture.width, truck.texture.height},
                     (Rectangle){truck.position.x, truck.position.y, truck.size.x, truck.size.y},
                     (Vector2){4, 4},
                     UP, WHITE);
      DrawTexturePro(redCar.texture,
                     (Rectangle){0.0f, 0.0f, redCar.texture.width, redCar.texture.height},
                     (Rectangle){redCar.position.x, redCar.position.y, redCar.size.x, redCar.size.y},
                     (Vector2){4, 4},
                     UP, WHITE);
      DrawTexturePro(blueCar.texture,
                     (Rectangle){0.0f, 0.0f, blueCar.texture.width, blueCar.texture.height},
                     (Rectangle){blueCar.position.x, blueCar.position.y, blueCar.size.x, blueCar.size.y},
                     (Vector2){4, 4},
                     UP, WHITE);
      DrawTexturePro(yellowCar.texture,
                     (Rectangle){0.0f, 0.0f, yellowCar.texture.width, yellowCar.texture.height},
                     (Rectangle){yellowCar.position.x, yellowCar.position.y, yellowCar.size.x, yellowCar.size.y},
                     (Vector2){4, 4},
                     UP, WHITE);
      DrawTexturePro(yellowCar2.texture,
                     (Rectangle){0.0f, 0.0f, yellowCar2.texture.width, yellowCar2.texture.height},
                     (Rectangle){yellowCar2.position.x, yellowCar2.position.y, yellowCar2.size.x, yellowCar2.size.y},
                     (Vector2){4, 4},
                     UP, WHITE);

      DrawText("move the frogg with arrow keys", 10, 10, 20, DARKGRAY);

      DrawText(TextFormat("frogg Position: %f %f", frogg.position.x, frogg.position.y), 10, 30, 20, BLACK);
      DrawText(TextFormat("truck Position: %f %f", truck.position.x, truck.position.y), 10, 60, 20, BLACK);
      // DrawText(TextFormat("Mouse Position: %f %f", GetMousePosition().x, GetMousePosition().y), 10, 60, 20, BLACK);
    } else {
      DrawRectangle(0, GetScreenHeight() / 2 - 70, GetScreenWidth(), 70, WHITE);
      DrawText("PRESS [ENTER] TO PLAY AGAIN", GetScreenWidth() / 2 - MeasureText("PRESS [ENTER] TO PLAY AGAIN", 35) / 2, GetScreenHeight() / 2 - 50, 35, DARKGRAY);

      if (IsKeyPressed(KEY_ENTER)) {
        end = false;

        frogg.position.x = (float)gridSize_x * 5 + gridSize_x / 2;
        frogg.position.y = (float)gridSize_y * 6 + gridSize_y / 2;
        frogg.rotation = UP;

        DrawTexturePro(truck.texture,
                       (Rectangle){0.0f, 0.0f, truck.texture.width, truck.texture.height},
                       (Rectangle){truck.position.x, truck.position.y, truck.size.x, truck.size.y},
                       (Vector2){4, 4},
                       UP, WHITE);
        DrawTexturePro(redCar.texture,
                       (Rectangle){0.0f, 0.0f, redCar.texture.width, redCar.texture.height},
                       (Rectangle){redCar.position.x, redCar.position.y, redCar.size.x, redCar.size.y},
                       (Vector2){4, 4},
                       UP, WHITE);
        DrawTexturePro(blueCar.texture,
                       (Rectangle){0.0f, 0.0f, blueCar.texture.width, blueCar.texture.height},
                       (Rectangle){blueCar.position.x, blueCar.position.y, blueCar.size.x, blueCar.size.y},
                       (Vector2){4, 4},
                       UP, WHITE);
        DrawTexturePro(yellowCar.texture,
                       (Rectangle){0.0f, 0.0f, yellowCar.texture.width, yellowCar.texture.height},
                       (Rectangle){yellowCar.position.x, yellowCar.position.y, yellowCar.size.x, yellowCar.size.y},
                       (Vector2){4, 4},
                       UP, WHITE);
        DrawTexturePro(yellowCar2.texture,
                       (Rectangle){0.0f, 0.0f, yellowCar2.texture.width, yellowCar2.texture.height},
                       (Rectangle){yellowCar2.position.x, yellowCar2.position.y, yellowCar2.size.x, yellowCar2.size.y},
                       (Vector2){4, 4},
                       UP, WHITE);
        DrawTexturePro(frogg_end,
                       (Rectangle){0.0f, 0.0f, frogg_end.width, frogg_end.height},
                       (Rectangle){frogg.position.x, frogg.position.y, frogg_end.width * 0.6, frogg_end.height * 0.6},
                       (Vector2){frogg.size.x / 2, frogg.size.y / 2},
                       frogg.rotation * 90.0f, WHITE);
      }
    }
    EndDrawing();
    //----------------------------------------------------------------------------------
  }

  // De-Initialization
  //--------------------------------------------------------------------------------------
  CloseWindow();  // Close window and OpenGL context
  //--------------------------------------------------------------------------------------

  return 0;
}