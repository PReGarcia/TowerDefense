#pragma once
#include "../core/Oleadas.h"
#include "../core/PlayerStats.h"
#include "../entities/Enemy.h"
#include "../entities/Tower.h"
#include "../entities/enemies/Goblin.h"
#include "../entities/enemies/Orc.h"
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
  void SpawnEnemy(TipoEnemigo tipo);
};
