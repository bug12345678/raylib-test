#include "/home/fjodor/devel/raylib-test/_deps/raylib-src/src/raylib.h"

typedef struct{
  float x;
  float y;
  int width;
  int height;
} entity;

const int width = 800;
const int height = 600;
const char *title = "Test";
Camera2D camera = { 0 };
entity player = {(float)width / 2.0f, (float)height / 2.0f, 50, 50};

void GameInit()
{
  InitWindow(width, height, title);
  SetTargetFPS(60);
}

void GamePlayerMove()
{
  if(IsKeyDown(KEY_LEFT)){
    player.x -= 100.0f * GetFrameTime();
    }
  if(IsKeyDown(KEY_RIGHT)){
    player.x += 100.0f * GetFrameTime();
    }
  }    

void GameCamera()
{
  camera.target = (Vector2){player.x, player.y};
  BeginMode2D(camera);
  DrawRectangle((int)player.x, (int)player.y, player.width, player.height, RED);
  EndMode2D();
}

void GameRender()
{
  BeginDrawing();
  ClearBackground(WHITE);
  GameCamera();
  EndDrawing();
}

void GameLoop()
{
  while(!WindowShouldClose()){
    GameCamera();
    GamePlayerMove();
    GameRender();
  }
}

void GameEnd()
{
  CloseWindow();
}

int main()
{
  camera.target = (Vector2){player.x, player.y};
  camera.offset = (Vector2){(float)width / 2.0f, (float)height/ 2.0f};
  camera.zoom = 1;
  camera.rotation = 0;

  GameInit();
  GameLoop();
  GameEnd();
  return 0;
}
