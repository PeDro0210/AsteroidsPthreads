#include "GameManager/FunctionManager.h"
#include "GameObjects/MovableObjects/MovableObjects.h"
#include "Ui/Ui.h"
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
    ships[i] = new Ship(i, 0, 0);
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

void *uiRenderLoop(void *arg) {
  UiManagers *ui_manager = new UiManagers();

  while (true) {
    if (ships[0]->getLife() >= 0) {

      pthread_mutex_lock(&print_mutex);
      ui_manager->gameDisplay();
      int scores[2] = {ships[0]->getScore(), ships[1]->getScore()};
      ui_manager->scoreDisplay(scores); // can't pass it directly, bowhomp
      int lifes[2] = {ships[0]->getLife(), ships[1]->getScore()};
      ui_manager->lifeDisplay(lifes);
      //* Putting all the code for the logic
      refresh();
      pthread_mutex_unlock(&print_mutex);
    }

    usleep(33333);
  }
  return nullptr;
}

// f*** DRY, I'll do the same for player 2
void *playerRenderLoop(void *arg) {
  // TODO:RECOMMENT
  Ship *ship = static_cast<Ship *>(arg);
  ship->MoveFoward();
  int lastX = ship->getPos()[0];
  int lastY = ship->getPos()[1];

  while (true) {
    pthread_mutex_lock(&print_mutex);

    // Erase the previous position of the ship
    ship->erase(lastX, lastY);
    ship->render(); // Render the ship at the new position

    // Update the last known position
    lastX = ship->getPos()[0];
    lastY = ship->getPos()[1];

    std::vector<Projectile *> projectile_ship;

    if (ship->getId() == 0) {
      projectile_ship = projectile_ship1;
    } else {
      projectile_ship = projectile_ship2;
    }
    // Handle projectiles
    for (Projectile *projectile : projectile_ship) {
      all_objects.push_back(projectile);
      int lastX_projectile = projectile->getPos()[0];
      int lastY_projectile = projectile->getPos()[1];

      projectile->erase(lastX_projectile,
                        lastY_projectile); // Erase old position
      projectile->MoveFoward();            // Move forward
      projectile->addingAge();
      projectile->alive();

      if (!projectile->isDestroyed()) {
        projectile->render(); // Render at new position
      } else {
        objects_to_destroy.push_back(projectile); // Mark for removal
      }
    }

    // Handle ship destruction logic
    if (ship->isDestroyed()) {
      ship->takeOutLife();
      ship->unDestroyed();
      all_objects.push_back(ship);
      if (ship->getLife() <= 0) {
        // Handle game-over logic if necessary
      }
    }

    overlapperChecker(all_objects, ships);
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

    if (ch == '\n') { // enter key, lmao. Clever way of asking for inputs
      projectile_ship2.push_back(ship->fire());
    }

    pthread_mutex_unlock(&print_mutex);
    usleep(10000);
  }
  return nullptr;
}

int main() {

  pthread_t player_threads[2];
  pthread_t ship_render_thread[2];

  pthread_t ui_render_thread, asteroid_render_thread;

  // Initialize ncurses
  initscr();
  cbreak();
  noecho();
  timeout(0);
  keypad(stdscr, TRUE);

  pthread_mutex_init(&print_mutex, NULL);

  srand(static_cast<unsigned int>(time(0))); // for the random
  initializeShip();
  initializeAsteroidsNormalMode();

  // TODO: initialize the threads
  pthread_create(&ui_render_thread, NULL, uiRenderLoop, NULL);
  pthread_create(&asteroid_render_thread, NULL, asteroidsRenderLoop,
                 NULL); // FOR DEBUGGING
                        //
  pthread_create(&player_threads[0], NULL, inputPlayer1Loop, ships[0]);

  pthread_create(&ship_render_thread[0], NULL, playerRenderLoop, ships[0]);

  // Create threads for rendering and input

  pthread_join(ui_render_thread, NULL);
  pthread_join(asteroid_render_thread, NULL); // DEBUGGING
  pthread_join(player_threads[0], NULL);
  pthread_join(ship_render_thread[0], NULL);

  pthread_mutex_destroy(&print_mutex);
  return 0;
}
