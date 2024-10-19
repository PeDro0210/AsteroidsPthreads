#include "GameInputs.h"
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

    if (ch == ' ') {
      projectile_ship1.push_back(
          ship->fire()); // TODO: see if is in here the issue
    }

    pthread_mutex_unlock(&print_mutex);
    usleep(10000);
  }
  return nullptr;
}

void *inputPlayer2Loop(void *arg) {
  Ship *ship = static_cast<Ship *>(arg);
  SDL_Init(SDL_INIT_GAMECONTROLLER); // Initialize SDL for controller input

  SDL_GameController *controller = nullptr;
  if (SDL_NumJoysticks() > 0) {
    controller =
        SDL_GameControllerOpen(0); // Open the first available controller
  }

  if (!controller) {
    mvwprintw(stdscr, 25, 25, "no controller");
    return nullptr;
  }

  while (true) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) { // Poll for events
      if (event.type == SDL_QUIT) {
        SDL_GameControllerClose(controller);
        SDL_Quit();
        return nullptr;
      }

      if (event.type == SDL_CONTROLLERAXISMOTION) {
        // Handle axis motion (e.g., joystick movement)
      }

      if (event.type == SDL_CONTROLLERBUTTONDOWN) {
        switch (event.cbutton.button) {
        case SDL_CONTROLLER_BUTTON_DPAD_UP:
          ship->lookUp();
          break;
        case SDL_CONTROLLER_BUTTON_DPAD_DOWN:
          ship->lookDown();
          break;
        case SDL_CONTROLLER_BUTTON_DPAD_LEFT:
          ship->lookLeft();
          break;
        case SDL_CONTROLLER_BUTTON_DPAD_RIGHT:
          ship->lookRight();
          break;
        case SDL_CONTROLLER_BUTTON_A:
          projectile_ship2.push_back(ship->fire());
          break;
        default:
          break;
        }
      }
    }

    usleep(10000); // Sleep to prevent busy-waiting
  }

  SDL_GameControllerClose(controller);
  SDL_Quit();
  return nullptr;
}
