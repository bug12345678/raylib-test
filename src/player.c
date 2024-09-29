#include "raylib.h"
#include "gamesquare.h" 
#include "gameinit.h"
#include "render.h"

extern const int screenHeight;
extern const int screenWidth;

const int vel = 250;

struct GameSquare player = {400, 300, 20, 20, WHITE};

void playerMovement(){
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

void renderPlayer(){
	render(player.posX, player.posY, player.width, player.height, player.squareColour);
}