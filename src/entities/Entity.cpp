#include "../../include/entities/Entity.h"

Vector2 Entity::calcularMovimiento(Vector2 posicion, Vector2 destino,
                                   float velocidad) {
  float delta = GetFrameTime();
  float paso = velocidad * delta;

  float distancia = Vector2Distance(destino, posicion);
  if (distancia <= paso) {
    return {destino.x, destino.y};
  } else {
    Vector2 direccion = Vector2Normalize(Vector2Subtract(destino, posicion));
    return {posicion.x + (direccion.x * paso),
            posicion.y + (direccion.y * paso)};
  }
}

void Entity::Dibujar() {
  DrawTexture(textura, x, y, WHITE);
  // Para debug
  //  DrawRectangle(x, y , textura.width, textura.height, RED);
}

Entity::~Entity() {}
