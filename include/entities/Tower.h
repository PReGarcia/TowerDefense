#pragma once
#include "../raylib.h"
#include "Enemy.h"
#include "Entity.h"
#include <vector>

class Tower : public Entity {
protected:
  int danio, cd, coste, rango;

public:
  Tower(float x, float y, Texture2D textura, int danio, int cd, int coste,
        int rango);

  virtual void atacar(const std::vector<Enemy *> &objetivo);
  virtual int vender();
  virtual ~Tower();
};
