#pragma once
#include "Enemy.h"
#include "Entity.h"

class Projectile : public Entity {
protected:
  float velocidad;
  Enemy *objetivo;

public:
  Projectile(float x, float y, Texture2D textura, float velocidad,
             Enemy *objetivo);
  virtual void mover();
  virtual ~Projectile();
};
