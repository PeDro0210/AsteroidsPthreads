#include "PlayerInputs.h"

void *inputPlayer1Loop(void *arg) {
  Ship *ship = static_cast<Ship *>(arg);
  while (true) {
    pthread_mutex_lock(&print_mutex);
    char ch = getch();

    if (ch == 'w') {
      ship->lookUp();
    }
    if (ch == 's') {
      ship->lookDown();
    }

    if (ch == 'a') {
      ship->lookLeft();
    }

    if (ch == 'd') {
      ship->lookRight();
    }

    if (ch == 'e') {
      projectile_ship1.push_back(ship->fire());
    }

    pthread_mutex_unlock(&print_mutex);
    usleep(10000);
  }
  return nullptr;
}

void *inputPlayer2Loop(void *arg) {
  // TODO: this needs to be change somehow, for accepting multiple inputs
  Ship *ship = static_cast<Ship *>(arg);
  while (true) {
    pthread_mutex_lock(&print_mutex);
    char ch = getch();

    if (ch == 'i') {
      ship->lookUp();
    }
    if (ch == 'k') {
      ship->lookDown();
    }

    if (ch == 'j') {
      ship->lookLeft();
    }

    if (ch == 'l') {
      ship->lookRight();
    }

    if (ch == 'o') { // This shitty asf, why not an enum for enter
      projectile_ship2.push_back(ship->fire());
    }

    pthread_mutex_unlock(&print_mutex);
    usleep(10000);
  }
  return nullptr;
}
