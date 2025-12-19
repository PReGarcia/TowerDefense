#pragma once
#include "Enemy.h"
#include "Entity.h"

class Projectile : public Entity {
protected:
  int velocidad;
  Enemy *objetivo;

public:
  virtual ~Projectile();
  virtual void mover();
};
