#include "raylib.h"

bool end;

enum dir{
    UP=0,
    RIGHT=1,
    DOWN=2,
    LEFT=3
};

typedef struct Player{
    Vector2 position_r;
    Vector2 position_v;
    Vector2 movement;
    Texture2D texture;
    int rotation;
} Player;

void updatePlayer(Player *player){
    if (IsKeyPressed(KEY_RIGHT) && player->position_r.x+player->movement.x < GetScreenWidth()){
        player->position_r.x += player->movement.x;
        player->rotation = RIGHT;
        player->position_v.x = player->position_r.x + player->movement.x;
        player->position_v.y = player->position_r.y;
    }
    if (IsKeyPressed(KEY_LEFT) && player->position_r.x-player->movement.x > 0){
        player->position_r.x -= player->movement.x;
        player->rotation = LEFT;
        player->position_v.x = player->position_r.x;
        player->position_v.y = player->position_r.y + player->movement.y;
    }
    if (IsKeyPressed(KEY_UP) && player->position_r.y-player->movement.y > 0){
        player->position_r.y -= player->movement.y;
        player->rotation = UP;
        player->position_v = player->position_r;
    }
    if (IsKeyPressed(KEY_DOWN) && player->position_r.y+player->movement.y < GetScreenHeight()){
        player->position_r.y += player->movement.y;
        player->rotation = DOWN;
        player->position_v.x = player->position_r.x + player->movement.x;
        player->position_v.y = player->position_r.y + player->movement.y;
    }
    
    if (player->position_r.y == player->movement.y*3) end = true;
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
    
    Texture2D background = LoadTexture("../Designs/Scenario/scenario_prototype_3.png");
    
    Texture2D frogg_end = LoadTexture("../Designs/Player/frog_jumping_prototype.png");
    
    Player frogg;
    frogg.texture = LoadTexture("../Designs/Player/frog_prototype.png");
    frogg.movement.x = (float)gridSize_x;
    frogg.movement.y = (float)gridSize_y;
    frogg.position_r.x = (float)gridSize_x*5;
    frogg.position_r.y = (float)gridSize_y*6;
    frogg.position_v = frogg.position_r;
    frogg.rotation = UP;
    
    end = false;
    
    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        updatePlayer(&frogg);
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);
            
            DrawTextureEx(background, (Vector2) {0, 0}, 0.0f, 0.55f, WHITE);
            
            for (int i = 0; i <= screenWidth/gridSize_x; i++) DrawRectangle(gridSize_x*i, 0, 1, screenHeight, SKYBLUE);
            for (int i = 0; i <= screenHeight/gridSize_y; i++) DrawRectangle(0, gridSize_y*i, screenWidth, 1, SKYBLUE);
            
            if(end){
                DrawText("Game Over", screenWidth / 2, 70, 50, DARKGRAY);
                DrawTextureEx(frogg_end, frogg.position_v, frogg.rotation*90, 0.7, WHITE);
            }
            else
                DrawTextureEx(frogg.texture, frogg.position_v, frogg.rotation*90, 0.7, WHITE);


            DrawText("move the frogg with arrow keys", 10, 10, 20, DARKGRAY);
            
            DrawText(TextFormat("frogg Position real: %f %f", frogg.position_r.x, frogg.position_r.y), 10, 30, 20, WHITE);
            DrawText(TextFormat("frogg Position virtual: %f %f", frogg.position_v.x, frogg.position_v.y), 10, 60, 20, WHITE);
            DrawText(TextFormat("Mouse Position: %f %f", GetMousePosition().x, GetMousePosition().y), 10, 90, 20, WHITE);

            
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}