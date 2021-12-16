#include <math.h>

#include <thread>

#include "../useHeaders/horizontalScroller.h"
#include "../useHeaders/player.h"
#include "../useHeaders/utils.h"
#include "raylib.h"

bool end;
bool final;

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

  Texture2D background = LoadTexture("./Designs/Scenario/scenario.png");

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

  // Initialization waterLily
  HorizontalScroller waterLily;
  waterLily.texture = LoadTexture("./Designs/water_lily.png");
  waterLily.movement.x = (float)gridSize_x;
  waterLily.position.x = (float)gridSize_x * 9;
  waterLily.position.y = (float)gridSize_x * 3;
  waterLily.speed.x = 0.02;
  waterLily.size.x = waterLily.texture.width * 0.7f;
  waterLily.size.y = waterLily.texture.height * 0.7f;

  HorizontalScroller truck;
  truck.texture = LoadTexture("./Designs/Enimies/truck.png");
  truck.movement.x = (float)gridSize_x;
  truck.position.x = (float)gridSize_x * 10;
  truck.position.y = (float)gridSize_x * 4;
  truck.speed.x = 0.01;
  truck.size.x = truck.texture.width * 0.7f;
  truck.size.y = truck.texture.height * 0.7f;

  HorizontalScroller redCar;
  redCar.texture = LoadTexture("./Designs/Enimies/red_car.png");
  redCar.movement.x = (float)gridSize_x;
  redCar.position.x = (float)gridSize_x * 10;
  redCar.position.y = (float)gridSize_x * 4;
  redCar.speed.x = 0.03;
  redCar.size.x = redCar.texture.width * 0.7f;
  redCar.size.y = redCar.texture.height * 0.7f;

  end = false;

  SetTargetFPS(60);  // Set our game to run at 60 frames-per-second
                     //--------------------------------------------------------------------------------------

  // Main game loop
  while (!WindowShouldClose())  // Detect window close button or ESC key
  {
    // Update
    //----------------------------------------------------------------------------------
    end = updatePlayer(&frogg, end);
    updateEnemies(final, &waterLily, &truck, &redCar);

    //----------------------------------------------------------------------------------

    // Draw
    //----------------------------------------------------------------------------------
    BeginDrawing();

    ClearBackground(RAYWHITE);

    DrawTextureEx(background, (Vector2){0, 0}, 0.0f, 0.55f, WHITE);

    for (int i = 0; i <= screenWidth / gridSize_x; i++) DrawRectangle(gridSize_x * i, 0, 1, screenHeight, SKYBLUE);
    for (int i = 0; i <= screenHeight / gridSize_y; i++) DrawRectangle(0, gridSize_y * i, screenWidth, 1, SKYBLUE);

    if (end) {
      DrawText("Game Over", screenWidth / 2, 70, 50, DARKGRAY);
      DrawTexturePro(waterLily.texture,
                     (Rectangle){0.0f, 0.0f, waterLily.texture.width, waterLily.texture.height},
                     (Rectangle){waterLily.position.x, waterLily.position.y, waterLily.size.x, waterLily.size.y},
                     (Vector2){9, 3},
                     UP, WHITE);
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
      DrawTexturePro(frogg_end,
                     (Rectangle){0.0f, 0.0f, frogg_end.width, frogg_end.height},
                     (Rectangle){frogg.position.x, frogg.position.y, frogg_end.width * 0.6, frogg_end.height * 0.6},
                     (Vector2){frogg.size.x / 2, frogg.size.y / 2},
                     frogg.rotation * 90.0f, WHITE);
    } else {
      DrawTexturePro(frogg.texture,                                                                // texture
                     (Rectangle){0.0f, 0.0f, frogg.texture.width, frogg.texture.height},           // Source Rectangle = parte da textura que será usada
                     (Rectangle){frogg.position.x, frogg.position.y, frogg.size.x, frogg.size.y},  // Destination Rectangle = posição na tela
                     (Vector2){frogg.size.x / 2, frogg.size.y / 2},                                // Origin = ponto de rotação da textura
                     frogg.rotation * 90.0f, WHITE);                                               // Rotation, colour
      DrawTexturePro(waterLily.texture,
                     (Rectangle){0.0f, 0.0f, waterLily.texture.width, waterLily.texture.height},
                     (Rectangle){waterLily.position.x, waterLily.position.y, waterLily.size.x, waterLily.size.y},
                     (Vector2){9, 3},
                     UP, WHITE);
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
    }

    DrawText("move the frogg with arrow keys", 10, 10, 20, DARKGRAY);

    DrawText(TextFormat("frogg Position: %f %f", frogg.position.x, frogg.position.y), 10, 30, 20, BLACK);
    DrawText(TextFormat("Mouse Position: %f %f", GetMousePosition().x, GetMousePosition().y), 10, 60, 20, BLACK);

    EndDrawing();
    //----------------------------------------------------------------------------------
  }

  // De-Initialization
  //--------------------------------------------------------------------------------------
  CloseWindow();  // Close window and OpenGL context
  //--------------------------------------------------------------------------------------

  return 0;
}