#include "MovableObjects.h"

Projectile::Projectile(int id, Orientation orientation, int x_pos, int y_pos)
    : MovableObject(x_pos, y_pos, orientation) {
  switch (orientation) {
  case FacingUp:
    setIcon('|');
    break;
  case FacingDown:
    setIcon('|');
    break;
  case FacingLeft:
    setIcon('-');
    break;
  case FacingRight:
    setIcon('-');
    break;
  }
}

void Projectile::addingAge() {
  float delta_time = 1.0f / 2.0f;
  age += delta_time;
}

void Projectile::alive() {
  if (age >= life_time) {
    destroy();
  }
};

int Projectile::getId() { return id; }
