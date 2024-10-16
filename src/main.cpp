#include "GameObjects/MovableObjects/MovableObjects.h"
#include "Ui/Ui.h"
#include <cstddef>
#include <ncurses.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t print_mutex;

int scores[2] = {0, 0};
std::vector<MovableObject *> all_objects; // For checking collisions
Ship *debug_ship;                         // Now it can be acces everywhere
std::vector<Projectile *> projectile_ship1;

// Initialize the global ship
void initializeShip() { debug_ship = new Ship(1, 10, 10); }

/* TODO: beside calling all the functions
 * for keeping the score, seeing if objects are overlapping
 */

void *uiRenderLoop(void *arg) {
  auto *ui_manager = new UiManagers();

  while (true) {
    pthread_mutex_lock(&print_mutex);
    ui_manager->gameDisplay();
    ui_manager->scoreDisplay(scores);
    //* Putting all the code for the logic
    refresh();
    pthread_mutex_unlock(&print_mutex);

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
    std::vector<Projectile *> projectilesToRemove;

    for (Projectile *projectile : projectile_ship1) {
      all_objects.push_back(projectile);
      int lastX_projectile = projectile->getPos()[0];
      int lastY_projectile = projectile->getPos()[1];

      projectile->erase(lastX_projectile,
                        lastY_projectile); // Erase from the previous position
      projectile->MoveFoward();            // Move the projectile forward
      projectile->addingAge();

      if (projectile->alive()) {
        projectile->render(); // Render at the new position
      } else {
        projectilesToRemove.push_back(projectile); // Mark for removal
      }
    }

    for (Projectile *projectile : projectilesToRemove) {
      delete projectile; // Free memory if dynamically allocated

      all_objects.erase(
          std::remove(all_objects.begin(), all_objects.end(), projectile),
          all_objects
              .end()); // idunno, someone gave me this method. Not saying names

      projectile_ship1.erase(std::remove(projectile_ship1.begin(),
                                         projectile_ship1.end(), projectile),
                             projectile_ship1.end());
    }

    refresh(); // Refresh the display

    pthread_mutex_unlock(&print_mutex); // Unlock the mutex

    usleep(100000); // Sleep for 100 milliseconds
  }
  return nullptr;
}
void *asteroidsRenderLoop(void *arg) {

  while (true) {

    // TODO: use barrier when the overlapping function is done
    pthread_mutex_lock(&print_mutex);
    // DEBUGGING
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

  initializeShip();

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
