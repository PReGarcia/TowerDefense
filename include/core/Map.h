#pragma once
#include "../Constants.h"
#include "../raylib.h"
#include <vector>

class Map {
private:
  int grid[ROWS][COLS];
  std::vector<Vector2> camino;

public:
  Map();
  void Draw();
  std::vector<Vector2> *GetCaminoPtr() { return &camino; };
  int GetTamCamino() const { return camino.size(); }
  int GetTipoCasilla(int col, int fil);
  ~Map();
};
