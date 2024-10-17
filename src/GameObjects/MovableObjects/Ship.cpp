#include "MovableObjects.h"

Ship::Ship(int id, int x_dis, int y_dis)
    : MovableObject(100 + x_dis, 35 + y_dis, FacingUp), id(id), lifes(3) {
  setIcon('A');
  setOrientation(FacingUp);
}

void Ship::takeOutLife() { lifes--; };

void Ship::goClockWise() {
  switch (orientation) {
  case FacingUp:
    setOrientation(FacingRight);
    setIcon('>');
    break;
  case FacingDown:
    setOrientation(FacingLeft);
    setIcon('<');
    break;
  case FacingLeft:
    setOrientation(FacingUp);
    setIcon('A');
    break;
  case FacingRight:
    setOrientation(FacingDown);
    setIcon('V');
    break;
  }
}

void Ship::goCounterClockWise() {
  switch (orientation) {
  case FacingUp:
    setOrientation(FacingLeft);
    setIcon('<');
    break;
  case FacingDown:
    setOrientation(FacingRight);
    setIcon('>');
    break;
  case FacingLeft:
    setOrientation(FacingDown);
    setIcon('V');
    break;
  case FacingRight:
    setOrientation(FacingUp);
    setIcon('A');
    break;
  }
}
