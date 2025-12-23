#pragma once
#include "../Constants.h"
#include "../raylib.h"
#include <vector>

class Map {
private:
  int grid[ROWS][COLS];
  std::vector<Vector2> camino;

public:
  Map();       // Diseño del mapa
  void Draw(); // Dibuja el mapa

  std::vector<Vector2> GetCamino(int index) const { return camino; };
  // PUNTOS DEL CAMINO UNO A UNO ES MAS SEGURO
  int GetTamCamino() const { return camino.size(); }
  ~Map();
};
