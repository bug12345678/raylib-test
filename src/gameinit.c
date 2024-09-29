#include "raylib.h"

const int screenWidth = 800;
const int screenHeight = 600;

void initGame(){
  InitWindow(screenWidth, screenHeight, "testgame");

  SetTargetFPS(60);
}
