#include "GameManager/FunctionManager.h"
#include "GameObjects/MovableObjects/MovableObjects.h"
#include "Ui/Ui.h"
#include <SDL2/SDL.h>
#include <cstddef>
#include <cstdlib>
#include <ncurses.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t print_mutex;

std::vector<MovableObject *> all_objects; // for checking collisions
std::vector<Projectile *> projectile_ship1;
std::vector<Projectile *> projectile_ship2;
std::vector<MovableObject *> objects_to_destroy;
std::vector<Asteroid *> asteroids;
Ship *ships[2];
// init the ship

void initializeShip() {
  for (int i = 0; i <= 1; i++) {
    ships[i] = new Ship(i, i * 5, i * 5);
    all_objects.push_back(ships[i]);
  }
}

void initializeAsteroidsNormalMode() {
  for (int i = 0; i <= 2; i++) {
    bigAsteroid *asteroid = new bigAsteroid();
    all_objects.push_back(asteroid);
    asteroids.push_back(asteroid);
  }
}

void initializeAsteroidsTwoPlayers() {
  for (int i = 0; i <= 5; i++) {
    bigAsteroid *asteroid = new bigAsteroid();
    all_objects.push_back(asteroid);
    asteroids.push_back(asteroid);
  }
}

void *uiRenderLoopScreen1(void *arg) {
  UiManagers *ui_manager = static_cast<UiManagers *>(arg);

  while (true) {

    pthread_mutex_lock(&print_mutex);
    ui_manager->gameDisplay();

    int scores[2] = {ships[0]->getScore(), ships[1]->getScore()};
    ui_manager->scoreDisplay(scores); // can't pass it directly, bowhomp

    int lifes[2] = {ships[0]->getLife(), ships[1]->getScore()};
    ui_manager->lifeDisplay(lifes);

    if (ships[0]->getScore() >= 40) {
      ui_manager->winScreen(1);
    }
    if (ships[0]->getLife() <= 0) {
      ui_manager->loseScreen();
    }

    refresh();
    pthread_mutex_unlock(&print_mutex);

    usleep(33333);
  }
  return nullptr;
}

void *uiRenderLoopScreen2(void *arg) {
  UiManagers *ui_manager = new UiManagers();

  while (true) {

    pthread_mutex_lock(&print_mutex);
    ui_manager->gameDisplay();

    int scores[2] = {ships[0]->getScore(), ships[1]->getScore()};
    ui_manager->scoreDisplay(scores); // can't pass it directly, bowhomp
                                      //
    int lifes[2] = {ships[0]->getLife(), ships[1]->getScore()};
    ui_manager->lifeDisplay(lifes);

    if (ships[0]->getScore() >= 60 || ships[1]->getLife() <= 0) {
      ui_manager->winScreen(1);
    }
    if (ships[1]->getScore() >= 60 || ships[0]->getLife() <= 0) {
      ui_manager->winScreen(2);
    }

    refresh();
    pthread_mutex_unlock(&print_mutex);

    usleep(33333);
  }
  return nullptr;
}

void *playerRenderLoop(void *arg) {
  // TODO:RECOMMENT
  Ship *ship = static_cast<Ship *>(arg);
  ship->MoveFoward();
  int lastX = ship->getPos()[0];
  int lastY = ship->getPos()[1];

  while (true) {
    pthread_mutex_lock(&print_mutex);

    ship->erase(lastX, lastY);
    ship->render();

    lastX = ship->getPos()[0];
    lastY = ship->getPos()[1];

    std::vector<Projectile *> projectile_ship;

    if (ship->getId() == 0) {
      projectile_ship = projectile_ship1;
    } else {
      projectile_ship = projectile_ship2;
    }

    for (Projectile *projectile : projectile_ship) {

      all_objects.push_back(projectile);
      int lastX_projectile = projectile->getPos()[0];
      int lastY_projectile = projectile->getPos()[1];

      projectile->erase(lastX_projectile, lastY_projectile);
      projectile->MoveFoward();
      projectile->addingAge();
      projectile->alive();

      if (!projectile->isDestroyed()) {
        projectile->render();
      } else {
        objects_to_destroy.push_back(projectile);
      }
    }

    // Handle ship destruction logic
    if (ship->isDestroyed()) {
      ship->takeOutLife();
      ship->unDestroyed();
      all_objects.push_back(ship);
    }

    refresh();

    pthread_mutex_unlock(&print_mutex);

    usleep(100000); // Sleep for 100ms
  }

  return nullptr;
}
void *asteroidsRenderLoop(void *arg) {

  while (true) {

    pthread_mutex_lock(&print_mutex);
    // DEBUGGING
    for (Asteroid *asteroid : asteroids) {

      int lastX = asteroid->getPos()[0];
      int lastY = asteroid->getPos()[1];

      asteroid->erase(lastX, lastY);
      asteroid->MoveFoward();
      asteroid->render();

      if (asteroid->isDestroyed()) {
        if (bigAsteroid *bigAst = dynamic_cast<bigAsteroid *>(
                asteroid)) { // If the asteroid can be cast to a bigAsteroid
                             //
          std::array<littleAsteroid *, 2> newAsteroids =
              bigAst->splitAsteroid(asteroid->getPos()); // do the split

          for (littleAsteroid *little : newAsteroids) {

            asteroids.push_back(little);
            all_objects.push_back(little);
          }
        }
        objects_to_destroy.push_back(asteroid);
      }
    }

    overlapperChecker(all_objects, ships);
    objectDestroyer(objects_to_destroy, all_objects, projectile_ship1,
                    asteroids);

    // DEBUGGING
    refresh();
    //* Putting all the code for the logic
    pthread_mutex_unlock(&print_mutex);

    usleep(99999);
  }
  return nullptr;
}

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

int main() {
  pthread_t player_threads[2];
  pthread_t ship_render_thread[2];
  pthread_t ui_render_thread, asteroid_render_thread;

  int selection = 0; // Initialize selection
  // Initialize ncurses
  initscr();
  cbreak();
  noecho();
  timeout(0);
  keypad(stdscr, TRUE);
  nodelay(stdscr, TRUE);
  pthread_mutex_init(&print_mutex, NULL);

  srand(static_cast<unsigned int>(time(0))); // for random seed
  initializeShip();

  UiManagers *ui_manager = new UiManagers();

  while (true) {
    char ch = getch();
    if (ch == '1') {
      selection = 1;
      break;
    }

    if (ch == '2') {
      selection = 2;
      break;
    }

    ui_manager->selectionScreen();
  }

  ui_manager->deleateSelectionScreen();

  // After obtaining selection, initialize game modes based on the selection
  if (selection == 1) {
    initializeAsteroidsNormalMode();
    pthread_create(&ui_render_thread, NULL, uiRenderLoopScreen1, ui_manager);
    pthread_create(&asteroid_render_thread, NULL, asteroidsRenderLoop, NULL);
    pthread_create(&player_threads[0], NULL, inputPlayer1Loop, ships[0]);
    pthread_create(&ship_render_thread[0], NULL, playerRenderLoop, ships[0]);

    pthread_join(ui_render_thread, NULL);
    pthread_join(asteroid_render_thread, NULL);
    pthread_join(player_threads[0], NULL);
    pthread_join(ship_render_thread[0], NULL);
  } else if (selection == 2) {
    initializeAsteroidsTwoPlayers();
    pthread_create(&ui_render_thread, NULL, uiRenderLoopScreen1, ui_manager);
    pthread_create(&asteroid_render_thread, NULL, asteroidsRenderLoop, NULL);
    pthread_create(&player_threads[0], NULL, inputPlayer1Loop, ships[0]);
    pthread_create(&ship_render_thread[0], NULL, playerRenderLoop, ships[0]);
    pthread_create(&player_threads[1], NULL, inputPlayer2Loop, ships[1]);
    pthread_create(&ship_render_thread[1], NULL, playerRenderLoop, ships[1]);

    pthread_join(ui_render_thread, NULL);
    pthread_join(asteroid_render_thread, NULL);
    pthread_join(player_threads[0], NULL);
    pthread_join(ship_render_thread[0], NULL);
    pthread_join(player_threads[1], NULL);
    pthread_join(ship_render_thread[1], NULL);
  }

  pthread_mutex_destroy(&print_mutex);
  delete ui_manager; // Clean up allocated memory
  endwin();          // End ncurses properly
  return 0;
}
