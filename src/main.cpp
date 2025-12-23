#include "../include/Constants.h"
#include "../include/core/Map.h"
#include "../include/raylib.h"

int main(int argc, char *argv[]) {
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Tower Defense C++");
  SetTargetFPS(FPS);

  Map mapa;
  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    mapa.Draw();
    EndDrawing();
  }

  CloseWindow();

  return 0;
}
