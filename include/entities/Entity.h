#pragma once
#include "../raylib.h"

class Entity {
protected:
  float x, y;
  Texture2D textura;

  Entity(float x, float y, Texture2D textura) : x(x), y(y), textura(textura) {}

public:
  virtual void Actualizar() = 0;
  virtual void Dibujar() = 0;
};
