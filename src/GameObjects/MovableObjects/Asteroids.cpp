#include "MovableObjects.h"
#include <cstdlib>

Asteroid::Asteroid() : MovableObject(rand() % 100, rand() % 32, FacingUp) {
  settingRandomFacing();
}

void Asteroid::settingRandomFacing() {

  int randomNumber = rand() % 4;
  switch (rand() % 4) {
  case 0:
    setOrientation(FacingUp);
    break;
  case 1:
    setOrientation(FacingDown);
    break;
  case 2:
    setOrientation(FacingRight);
    break;
  case 3:
    setOrientation(FacingLeft);
    break;
  }
}

bigAsteroid::bigAsteroid() : Asteroid() { setIcon('0'); }

std::array<littleAsteroid *, 2> bigAsteroid::splitAsteroid() {
  return {new littleAsteroid(), new littleAsteroid()};
}

littleAsteroid::littleAsteroid() : Asteroid() { setIcon('o'); }
