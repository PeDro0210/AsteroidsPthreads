#include "GameManager/FunctionManager.h"
#include "GameObjects/MovableObjects/MovableObjects.h"
#include "Ui/Ui.h"
#include <cstddef>
#include <cstdlib>
#include <ncurses.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t print_mutex;

int scores[2] = {0, 0};
std::vector<MovableObject *> all_objects; // for checking collisions
std::vector<Projectile *> projectile_ship1;
std::vector<MovableObject *> objects_to_destroy;
std::vector<Asteroid *> asteroids;
Ship *debug_ship;
// init the ship

void initializeShip() {
  debug_ship = new Ship(1, 10, 10);
  all_objects.push_back(debug_ship);
}

void initializeAsteroidsNormalMode() {
  for (int i = 0; i <= 3; i++) {
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
  auto *ui_manager = new UiManagers();

  while (true) {
    if (debug_ship->getLife() >= 0) {

      pthread_mutex_lock(&print_mutex);
      ui_manager->gameDisplay();
      ui_manager->scoreDisplay(scores);
      int lifes[2] = {debug_ship->getLife(), 0};
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
void *playerRenderLoop(void *) {
  int lastX = debug_ship->getPos()[0];
  int lastY = debug_ship->getPos()[1];

  while (true) {
    pthread_mutex_lock(&print_mutex);

    // Erase the previous position of the ship
    debug_ship->erase(lastX, lastY);
    debug_ship->render(); // Render the ship at the new position

    // Update the last known position
    lastX = debug_ship->getPos()[0];
    lastY = debug_ship->getPos()[1];

    // Temporary storage for projectiles to remove

    for (Projectile *projectile : projectile_ship1) {
      all_objects.push_back(projectile);
      int lastX_projectile = projectile->getPos()[0];
      int lastY_projectile = projectile->getPos()[1];

      projectile->erase(lastX_projectile,
                        lastY_projectile); // Erase from the previous position
      projectile->MoveFoward();            // Move the projectile forward
      projectile->addingAge();
      projectile->alive();

      if (!projectile->isDestroyed()) {
        projectile->render(); // Render at the new position
      } else {
        objects_to_destroy.push_back(projectile); // Mark for removal
      }
    }

    if (debug_ship->isDestroyed()) {
      debug_ship->takeOutLife();
      debug_ship->unDestroyed();
      if (debug_ship->getLife() <= 0) {
      }
    }

    overlapperChecker(all_objects);
    objectDestroyer(objects_to_destroy, all_objects, projectile_ship1,
                    asteroids);

    refresh();

    pthread_mutex_unlock(&print_mutex);

    usleep(100000);
  }
  return nullptr;
}
void *asteroidsRenderLoop(void *arg) {

  while (true) {

    pthread_mutex_lock(&print_mutex);
    objectDestroyer(objects_to_destroy, all_objects, projectile_ship1,
                    asteroids);
    // DEBUGGING
    for (Asteroid *asteroid : asteroids) {
      int lastX = asteroid->getPos()[0];
      int lastY = asteroid->getPos()[1];

      asteroid->erase(lastX, lastY);
      asteroid->MoveFoward();
      asteroid->render();

      if (asteroid->isDestroyed()) {
        if (bigAsteroid *bigAst = dynamic_cast<bigAsteroid *>(asteroid)) {
          std::array<littleAsteroid *, 2> newAsteroids =
              bigAst->splitAsteroid();
          for (littleAsteroid *little : newAsteroids) {
            asteroids.push_back(little);
            all_objects.push_back(little);
          }
        }
        objects_to_destroy.push_back(asteroid);
      }
    }

    // DEBUGGING
    refresh();
    //* Putting all the code for the logic
    pthread_mutex_unlock(&print_mutex);

    usleep(99999);
  }
  return nullptr;
}

// TODO: only manage the inputs of the ship in here
void *inputPlayer1Loop(void *) {
  // TODO: setting this for multithreading
  while (true) {
    pthread_mutex_lock(&print_mutex);
    char ch = getch();

    if (ch == 'w') {
      debug_ship->lookUp();
    }
    if (ch == 's') {
      debug_ship->lookDown();
    }

    if (ch == 'a') {
      debug_ship->lookLeft();
    }

    if (ch == 'd') {
      debug_ship->lookRight();
    }

    if (ch == 'p') {
      projectile_ship1.push_back(
          debug_ship->fire()); // TODO: see if is in here the issue
    }

    pthread_mutex_unlock(&print_mutex);
    usleep(10000);
  }
  return nullptr;
}
// TODO: only manage the inputs of the ship in here
void *inputPlayer2Loop(void *) {
  while (true) {
    pthread_mutex_lock(&print_mutex);
    char ch = getch();

    pthread_mutex_unlock(&print_mutex);
    usleep(10000);
  }
  return nullptr;
}

// TODO: init all the objects and pass the on the inputLoop
int main() {

  pthread_t player_threads[2];

  pthread_t ui_render_thread, ship_render_thread, asteroid_render_thread;

  // Initialize ncurses
  initscr();
  cbreak();
  noecho();
  timeout(0);

  pthread_mutex_init(&print_mutex, NULL);

  srand(static_cast<unsigned int>(time(0)));
  initializeShip();
  initializeAsteroidsNormalMode();

  all_objects.push_back(debug_ship);

  // TODO: initialize the threads
  pthread_create(&ui_render_thread, NULL, uiRenderLoop, NULL);
  pthread_create(&asteroid_render_thread, NULL, asteroidsRenderLoop,
                 NULL); // FOR DEBUGGING
                        //
  pthread_create(&player_threads[0], NULL, inputPlayer1Loop, NULL);
  pthread_create(&ship_render_thread, NULL, playerRenderLoop, NULL);

  // Create threads for rendering and input

  pthread_join(ui_render_thread, NULL);
  pthread_join(asteroid_render_thread, NULL); // DEBUGGING
  pthread_join(player_threads[0], NULL);
  pthread_join(ship_render_thread, NULL);

  pthread_mutex_destroy(&print_mutex);
  return 0;
}
