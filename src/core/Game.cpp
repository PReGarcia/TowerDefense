#include "../../include/core/Game.h"
#include <cstdio>

Game::Game() {}

void Game::Actualizar() {
  ActualizarEnemigos();
  ActualizarTorres();
  ActualizarProyectiles();
};

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
  for (int i = 0; i < (int)enemigos.size(); i++) {
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

void Game::ActualizarProyectiles() {
  for (int i = 0; i < (int)proyectiles.size(); i++) {
    Projectile *p = proyectiles[i];

    p->Actualizar();

    if (!p->EstaActivo()) {
      delete p;
      proyectiles.erase(proyectiles.begin() + i);
    }
  }
}

void Game::GestionarInput() {
  if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
    Vector2 raton = GetMousePosition();

    // Convertir pixel a coordenada de rejilla (0, 1, 2...)
    int col = (int)(raton.x / TILE_SIZE);
    int fil = (int)(raton.y / TILE_SIZE);

    // 1. Validar que sea CÉSPED (valor 0 segun tu Map.cpp)
    // y que no hayamos clicado fuera de la pantalla
    if (mapa.GetTipoCasilla(col, fil) == 0) {

      // 2. Validar que NO haya otra torre ahí
      bool ocupado = false;
      for (Tower *t : torres) {
        // Comprobamos si la torre está en esa misma celda
        // (Margen de error pequeño por flotantes)
        int tCol = (int)(t->getX() / TILE_SIZE);
        int tFil = (int)(t->getY() / TILE_SIZE);
        if (tCol == col && tFil == fil) {
          ocupado = true;
          break;
        }
      }

      if (!ocupado) {
        // ¡CONSTRUIR! Centramos la torre en la casilla
        // float centroX = col * TILE_SIZE + TILE_SIZE / 2;
        // float centroY = fil * TILE_SIZE + TILE_SIZE / 2;

        // Aquí añades tu lógica de gastar dinero...
        // torres.push_back(new ArcherTower(centroX, centroY));
      } else {
        printf("¡Ya hay una torre ahí!\n");
      }
    } else {
      printf("No se puede construir en el camino.\n");
    }
  }
}

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
