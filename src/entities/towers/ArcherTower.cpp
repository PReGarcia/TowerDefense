#include "../../../include/entities/towers/ArcherTower.h"

ArcherTower::ArcherTower(float x, float y)
    : Tower(x, y, LoadTexture("../assets/archerTower.png"), 10, 3, 50, 15) {}

ArcherTower::~ArcherTower() {}
