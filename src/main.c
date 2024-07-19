#include "raylib.h"

const int screenWidth = 800;
const int screenHeight = 600;

int posX;
int posY;

const int vel = 250;


struct GameSquare{
  int posX;
  int posY;
  int width;
  int height;
  Color squareColour;
}; 

struct GameSquare player = {screenWidth / 2, screenHeight / 2, 20, 20, WHITE};

void initGame(){
  InitWindow(screenWidth, screenHeight, "testgame");

  SetTargetFPS(60);
}

void render(){
  BeginDrawing();

  ClearBackground(BLACK);

  DrawRectangle(player.posX, player.posY, player.width, player.height, player.squareColour);

  EndDrawing();
}

int main(void){
    initGame();
    
    while (!WindowShouldClose()) 
    {
        render();    

        if (IsKeyDown(KEY_RIGHT)) {
            player.posX += GetFrameTime() * vel;
        } else if (IsKeyDown(KEY_LEFT)) {
            player.posX += GetFrameTime() * -vel;
        } else if (IsKeyDown(KEY_UP)) {
            player.posY += GetFrameTime() * -vel;
        } else if (IsKeyDown(KEY_DOWN)) {
            player.posY += GetFrameTime() * vel;
        }

        if (player.posX <= 0){
            player.posX = 0;
        } else if(player.posX >= screenWidth - player.width){
            player.posX = screenWidth - player.width;
        }
       
        if (player.posY <= 0){
          player.posY = 0;
        } else if (player.posY >= screenHeight - player.height){
          player.posY = screenHeight - player.height;  
        } 
    }
    CloseWindow();

    return 0;
}
