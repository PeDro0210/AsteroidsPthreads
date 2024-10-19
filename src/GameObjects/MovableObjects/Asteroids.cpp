#include "MovableObjects.h"
#include <cstdlib>

Asteroid::Asteroid(int x, int y) : MovableObject(x, y, FacingUp) {
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

bigAsteroid::bigAsteroid() : Asteroid(rand() % 100, rand() % 32) {
  setIcon('0');
}

std::array<littleAsteroid *, 2>
bigAsteroid::splitAsteroid(std::array<int, 2> position) {
  return {new littleAsteroid(position[0], position[1]),
          new littleAsteroid(position[0], position[1])};
}

littleAsteroid::littleAsteroid(int x, int y) : Asteroid(x, y) { setIcon('o'); }
