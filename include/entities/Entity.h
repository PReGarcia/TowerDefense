#pragma once
#include "../raylib.h"
#include "../raymath.h"

class Entity {
protected:
  float x, y;
  Texture2D textura;

  Entity(float x, float y, Texture2D textura) : x(x), y(y), textura(textura) {}

public:
  virtual void Actualizar() = 0;
  virtual void Dibujar() = 0;
  virtual Vector2 calcularMovimiento(Vector2 posicion, Vector2 destino,
                                     float velocidad);
  float getX() { return x; }
  float getY() { return y; }
  virtual ~Entity();
};
