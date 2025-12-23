#include "../include/Constants.h"
#include "../include/core/Game.h"
#include "../include/core/Map.h"
#include "../include/raylib.h"

int main(int argc, char *argv[]) {
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Tower Defense C++");
  SetTargetFPS(FPS);

  Map mapa;
  Game *game = new Game();
  game->SpawnEnemy(GOBLIN);
  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    game->Actualizar();
    EndDrawing();
  }

  CloseWindow();

  return 0;
}
