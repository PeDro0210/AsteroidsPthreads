#include "MovableObjects.h"

Ship::Ship(int id, int x_dis, int y_dis)
    : MovableObject(100 + x_dis, 35 + y_dis, FacingUp), id(id), lifes(3) {
  setIcon('A');
  setOrientation(FacingUp);
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
