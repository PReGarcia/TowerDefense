#pragma once
#include "../raylib.h"
#include "Entity.h"
#include <vector>

class Enemy : public Entity {
protected:
  int hp, puntoActualIndex, danio, oro;
  float velocidad;
  std::vector<Vector2> *camino; // OBTENER EL CAMINO ASI ES MAS RAPIDO Y COMODO

  Enemy(int hp, float velocidad, std::vector<Vector2> *camino, float x, float y,
        Texture2D textura)
      : Entity(x, y, textura), hp(hp), velocidad(velocidad), camino(camino) {};

public:
  virtual void recibirDanio(int danio);
  virtual void caminar();
  virtual void morir();
};
