#include "../../include/core/Game.h"

void Game::Actualizar() {};

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

Game::~Game() {};
