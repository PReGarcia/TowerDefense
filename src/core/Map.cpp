#include "../../include/core/Map.h"

Map::Map() {
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      grid[i][j] = 0;
    }
  }

  for (int x = 0; x <= 10; x++)
    grid[2][x] = 1;

  for (int y = 2; y <= 12; y++)
    grid[y][10] = 1;

  for (int x = 10; x < COLS; x++)
    grid[12][x] = 1;

  camino.push_back(Vector2{0, 2 * TILE_SIZE + TILE_SIZE / 2});
  camino.push_back(
      Vector2{10 * TILE_SIZE + TILE_SIZE / 2, 2 * TILE_SIZE + TILE_SIZE / 2});
  camino.push_back(
      Vector2{10 * TILE_SIZE + TILE_SIZE / 2, 12 * TILE_SIZE + TILE_SIZE / 2});
  camino.push_back(Vector2{SCREEN_WIDTH, 12 * TILE_SIZE + TILE_SIZE / 2});
}

void Map::Draw() {
  for (int y = 0; y < ROWS; y++) {
    for (int x = 0; x < COLS; x++) {
      int posX = x * TILE_SIZE;
      int posY = y * TILE_SIZE;

      Color colorDelCuadrado;

      if (grid[y][x] == 0) {
        colorDelCuadrado = DARKGREEN;
      } else {
        colorDelCuadrado = DARKBROWN;
      }

      DrawRectangle(posX, posY, TILE_SIZE, TILE_SIZE, colorDelCuadrado);

      DrawRectangleLines(posX, posY, TILE_SIZE, TILE_SIZE, Fade(BLACK, 0.1f));
    }
  }

  for (Vector2 punto : camino) {
    DrawCircleV(punto, 5, RED);
  }
}

int Map::GetTipoCasilla(int col, int fil) {
  if (col < 0 || col >= COLS || fil < 0 || fil >= ROWS)
    return -1;
  return grid[fil][col];
}

Map::~Map() {};
