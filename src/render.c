#include "raylib.h"

void render(int posX,int posY,int width,int height,Color colour){
  BeginDrawing();

  ClearBackground(BLACK);

  DrawRectangle(posX, posY, width, height, colour);

  EndDrawing();
}