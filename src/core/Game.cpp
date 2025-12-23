#include "../../include/core/Game.h"

Game::Game() {}

void Game::Actualizar() { ActualizarEnemigos(); };

void Game::Draw() {
  mapa.Draw();

  for (auto e : enemigos) {
    e->Dibujar();
  }

  for (auto t : torres) {
    t->Dibujar();
  }
}

void Game::ActualizarTorres() {
  for (auto t : torres)
    t->atacar(enemigos);
}

void Game::ActualizarEnemigos() {
  for (int i = 0; i < enemigos.size(); i++) {
    Enemy *e = enemigos[i];

    e->caminar();

    if (!e->estaVivo()) {
      if (e->hacerDanio()) {
        jugador.vida -= e->getDanio();
      } else {
        jugador.oro += e->getOro();
      }

      delete e;
      enemigos.erase(enemigos.begin() + i);
    }
  }
}

void Game::GestionarInput() {}

void Game::SpawnEnemy(TipoEnemigo tipo) {
  Vector2 salida = mapa.GetCaminoPtr()->at(0);
  Enemy *nuevoEnemigo = nullptr;

  switch (tipo) {
  case GOBLIN:
    nuevoEnemigo = new Goblin(mapa.GetCaminoPtr(), salida.x, salida.y);
    break;
  case ORC:
    nuevoEnemigo = new Orc(mapa.GetCaminoPtr(), salida.x, salida.y);
  }

  if (nuevoEnemigo != nullptr) {
    enemigos.push_back(nuevoEnemigo);
  }
}

Game::~Game() {};
