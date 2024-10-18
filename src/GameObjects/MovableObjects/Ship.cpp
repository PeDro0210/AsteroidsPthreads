#include "MovableObjects.h"

Ship::Ship(int id, int x_dis, int y_dis)
    : MovableObject(100 + x_dis, 35 + y_dis, FacingUp), id(id), lifes(3) {
  setIcon('A');
}

void Ship::takeOutLife() { lifes--; };

void Ship::lookUp() {
  setIcon('A');
  setOrientation(FacingUp);
  MoveFoward();
}

void Ship::lookDown() {
  setIcon('V');
  setOrientation(FacingDown);
  MoveFoward();
}

void Ship::lookRight() {
  setIcon('>');
  setOrientation(FacingRight);
  MoveFoward();
}

void Ship::lookLeft() {
  setIcon('<');
  setOrientation(FacingLeft);
  MoveFoward();
}

// TODO: fix this, to follow the order of the orietantion as told
Projectile *Ship::fire() {
  switch (getOrientation()) {
  case FacingUp:
    return new Projectile(id, FacingUp, x_pos, y_pos - 2);
  case FacingDown:
    return new Projectile(id, FacingDown, x_pos, y_pos + 2);
  case FacingLeft:
    return new Projectile(id, FacingLeft, x_pos - 2, y_pos);
  case FacingRight:
    return new Projectile(id, FacingRight, x_pos + 2, y_pos);
  }

  // return nullptr; // this was a savior for some reason
}
