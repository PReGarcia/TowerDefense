#pragma once
#include "../Constants.h"
#include "../raylib.h"
#include "../raymath.h"

class Entity {
protected:
  float x, y;
  Texture2D textura;

  Entity(float x, float y, Texture2D textura) : x(x), y(y), textura(textura) {}

public:
  virtual void Dibujar();
  virtual Vector2 calcularMovimiento(Vector2 posicion, Vector2 destino,
                                     float velocidad);
  float getX() { return x; }
  float getY() { return y; }
  virtual ~Entity();
};
