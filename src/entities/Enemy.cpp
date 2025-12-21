#include "../../include/entities/Enemy.h"
#include <vector>

Enemy::Enemy(int hp, float velocidad, std::vector<Vector2> *camino, float x,
             float y, Texture2D textura)
    : Entity(x, y, textura) {
  this->hp = hp;
  this->velocidad = velocidad;
  this->camino = camino;
}

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

  Vector2 nuevaPosicion = calcularMovimiento({x, y}, destino, velocidad);

  x = nuevaPosicion.x;
  y = nuevaPosicion.y;
}

void Enemy::morir() { delete this; }
