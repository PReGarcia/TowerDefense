#include "../../include/entities/Enemy.h"

void Enemy::recibirDanio(int danio) {
  this->hp -= danio;

  if (this->hp <= 0) {
    morir();
  }
}

void Enemy::morir() {}
