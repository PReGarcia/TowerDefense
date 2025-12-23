#pragma once
#include "../core/PlayerStats.h"
#include "../entities/Enemy.h"
#include "../entities/Tower.h"
#include "Map.h"
#include <vector>

class Game {
private:
  Map mapa;
  PlayerStats jugador;

  std::vector<Enemy *> enemigos;
  std::vector<Tower *> torres;

public:
  Game();
  ~Game();

  void Actualizar();
  void Draw();
  void ActualizarTorres();
  void ActualizarEnemigos();
  void GestionarInput();
};
