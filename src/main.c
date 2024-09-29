#include "gamesquare.h"
#include "raylib.h"
#include "player.h"
#include "gameinit.h"

extern struct GameSquare player;

int main(void){
  initGame();
    
  while (!WindowShouldClose()) {
		playerMovement();
		renderPlayer();

  }
  CloseWindow();

  return 0;
}
