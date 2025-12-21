#pragma once
#include "../raylib.h"
#include "Enemy.h"
#include "Entity.h"

class Tower : public Entity {
protected:
  int danio, cd, coste, rango;

public:
  Tower(float x, float y, Texture2D textura, int danio, int cd, int coste,
        int rango);

  virtual void atacar(Enemy *objetivo);
  virtual void vender();
  virtual ~Tower();
};
