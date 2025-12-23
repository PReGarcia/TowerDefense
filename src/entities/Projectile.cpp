#include "../../include/entities/Projectile.h"

Projectile::Projectile(float x, float y, Texture2D textura, float velocidad,
                       Enemy *objetivo)
    : Entity(x, y, textura) {
  this->velocidad = velocidad;
  this->objetivo = objetivo;
}

void Projectile::mover() {
  // Logica de golpeo
  Vector2 nuevaPosicion = Entity::calcularMovimiento(
      {x, y}, {objetivo->getX(), objetivo->getY()}, velocidad);

  x = nuevaPosicion.x;
  y = nuevaPosicion.y;
}

Projectile::~Projectile() {}
