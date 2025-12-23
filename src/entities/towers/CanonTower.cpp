#include "../../../include/entities/towers/CanonTower.h"

CanonTower::CanonTower(float x, float y)
    : Tower(x, y, LoadTexture("../../../assets/canonTower.png"), 25, 6, 70,
            10) {};

CanonTower::~CanonTower() {}
