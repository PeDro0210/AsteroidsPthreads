#include <cstdlib>

int randomNumberX() {
  return rand() % 100; // for "keeping" it on the grid
}

int randomNumberY() {
  return rand() % 32; // for "keeping" it on the grid
}
