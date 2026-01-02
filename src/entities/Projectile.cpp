#include "../../include/entities/Projectile.h"

Projectile::Projectile(float x, float y, Texture2D textura, float velocidad,
                       Enemy *objetivo)
    : Entity(x, y, textura) {
  this->velocidad = velocidad;
  this->objetivo = objetivo;
}

bool Projectile::Actualizar() {
  if (!activo)
    return false;

  if (!objetivo->estaVivo()) {
    activo = false;
    return false;
  }

  Vector2 posicionObjetivo = {objetivo->getX(), objetivo->getY()};

  if (Vector2Distance({x, y}, posicionObjetivo) < velocidad) {
    objetivo->recibirDanio(this->danio);
    activo = false;
    return true;
  }

  Vector2 nuevaPosicion =
      Entity::calcularMovimiento({x, y}, posicionObjetivo, velocidad);

  x = nuevaPosicion.x;
  y = nuevaPosicion.y;

  return false;
}

Projectile::~Projectile() {}
