#include "../../include/entities/Enemy.h"

void Enemy::recibirDanio(int danio) {
  this->hp -= danio;

  if (this->hp <= 0) {
    estaVivo = false;
  }
}

void Enemy::caminar() {
  if (casillaDestino > camino->size()) {
    hacerDanio = true;
  }

  Vector2 destino = camino->at(casillaDestino);

  float distancia = Vector2Distance(Vector2{x, y}, destino);

  if (distancia < velocidad) {
    x = destino.x;
    y = destino.y;
    casillaDestino++;
  } else {
    Vector2 direccion = Vector2Subtract(destino, Vector2{x, y});
    direccion = Vector2Normalize(direccion);

    x += direccion.x * velocidad;
    y += direccion.y * velocidad;
  }
}

void Enemy::morir() { delete this; }
