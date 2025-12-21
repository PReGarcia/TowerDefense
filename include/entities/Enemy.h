#pragma once
#include "../raylib.h"
#include "../raymath.h"
#include "Entity.h"
#include <vector>

class Enemy : public Entity {
protected:
  int hp, casillaDestino, danio, oro;
  float velocidad;
  std::vector<Vector2> *camino; // OBTENER EL CAMINO ASI ES MAS RAPIDO Y COMODO
  bool hacerDanio, estaVivo;

  Enemy(int hp, float velocidad, std::vector<Vector2> *camino, float x, float y,
        Texture2D textura);

public:
  virtual void recibirDanio(int danio);
  virtual void caminar();
  virtual void morir();
  virtual ~Enemy();
};
