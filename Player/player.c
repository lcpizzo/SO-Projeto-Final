#include "raylib.h"
#include <math.h>

bool end;

enum dir{
    UP=0,
    RIGHT=1,
    DOWN=2,
    LEFT=3
};

typedef struct Player{
    Vector2 position;
    Vector2 size;
    Vector2 movement;
    Texture2D texture;
    int rotation;
} Player;

void updatePlayer(Player *player){
    if (IsKeyPressed(KEY_RIGHT) && player->position.x+player->movement.x < GetScreenWidth()){
        player->position.x += player->movement.x;
        player->rotation = RIGHT;
    }
    if (IsKeyPressed(KEY_LEFT) && player->position.x-player->movement.x > 0){
        player->position.x -= player->movement.x;
        player->rotation = LEFT;
    }
    if (IsKeyPressed(KEY_UP) && player->position.y-player->movement.y > 0){
        player->position.y -= player->movement.y;
        player->rotation = UP;
    }
    if (IsKeyPressed(KEY_DOWN) && player->position.y+player->movement.y < GetScreenHeight()){
        player->position.y += player->movement.y;
        player->rotation = DOWN;
    }
    
    if (player->position.y == floor(player->movement.y*3+player->movement.y/2)) end = true;
    else end = false;
}

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int GRID_CONST_X = 10;
    const int GRID_CONST_Y = 7;

    const int screenWidth = GRID_CONST_X * 85;
    const int screenHeight = GRID_CONST_Y * 85;
    
    const int gridSize_x = screenWidth/GRID_CONST_X;
    const int gridSize_y = screenHeight/GRID_CONST_Y;

    InitWindow(screenWidth, screenHeight, "Projeto SO Final - teste player && scenario");
    
    Texture2D background = LoadTexture("../Designs/Scenario/scenario_without_water_effect.png");
    Texture2D water = LoadTexture("../Designs/Scenario/water_effect.png");
    float water_scrolling = 0.0f;
    
    
    Texture2D frogg_end = LoadTexture("../Designs/Player/frog_jumping.png");
    
    Player frogg;
    frogg.texture = LoadTexture("../Designs/Player/frog.png");
    frogg.movement.x = (float)gridSize_x;
    frogg.movement.y = (float)gridSize_y;
    frogg.position.x = (float)gridSize_x*5 + gridSize_x/2;
    frogg.position.y = (float)gridSize_y*6 + gridSize_y/2;
    frogg.rotation = UP;
    frogg.size.x = frogg.texture.width*0.7f;
    frogg.size.y = frogg.texture.height*0.7f;
    
    end = false;
    
    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        updatePlayer(&frogg);
        
        water_scrolling -= 2.0f;
        
        if(water_scrolling <= -water.width) water_scrolling = 0.0f;
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);
            
            DrawTextureEx(background, (Vector2) {0, 0}, 0.0f, 0.55f, WHITE);
            
            DrawTexturePro(water, 
                                (Rectangle) {0.0f, 0.0f, water.width*2, water.height},
                                (Rectangle) {water_scrolling, screenHeight-water.height/4, water.width*2.0f, water.height*0.5f},
                                (Vector2) {screenWidth/2, screenHeight/2},
                                0.0f, WHITE
                                );
            
            for (int i = 0; i <= screenWidth/gridSize_x; i++) DrawRectangle(gridSize_x*i, 0, 1, screenHeight, SKYBLUE);
            for (int i = 0; i <= screenHeight/gridSize_y; i++) DrawRectangle(0, gridSize_y*i, screenWidth, 1, SKYBLUE);
            
            if(end){
                DrawText("Game Over", screenWidth / 2, 70, 50, DARKGRAY);
                DrawTexturePro(frogg_end,                                               
                            (Rectangle) {0.0f, 0.0f, frogg_end.width, frogg_end.height},
                            (Rectangle) {frogg.position.x,frogg.position.y, frogg_end.width*0.6, frogg_end.height*0.6},    
                            (Vector2) {frogg.size.x/2, frogg.size.y/2},                                     
                            frogg.rotation*90.0f, WHITE);                                                   
            }
            else
                DrawTexturePro(frogg.texture,                                                               //texture
                        (Rectangle) {0.0f, 0.0f, frogg.texture.width, frogg.texture.height},            //Source Rectangle = parte da textura que será usada
                        (Rectangle) {frogg.position.x,frogg.position.y, frogg.size.x, frogg.size.y},    //Destination Rectangle = posição na tela
                        (Vector2) {frogg.size.x/2, frogg.size.y/2},                                     //Origin = ponto de rotação da textura
                        frogg.rotation*90.0f, WHITE);                                                   //Rotation, colour
            
            
            DrawText("move the frogg with arrow keys", 10, 10, 20, DARKGRAY);
            
            DrawText(TextFormat("frogg Position: %f %f", frogg.position.x, frogg.position.y), 10, 30, 20, WHITE);
            DrawText(TextFormat("Mouse Position: %f %f", GetMousePosition().x, GetMousePosition().y), 10, 60, 20, WHITE);
                
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}