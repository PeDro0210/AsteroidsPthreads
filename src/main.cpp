#include "GameManager/GameManager.h"
#include "GameObjects/MovableObjects/MovableObjects.h"
#include "Ui/Ui.h"
#include <cstddef>
#include <ncurses.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t print_mutex;

int scores[2] = {0, 0};
std::vector<MovableObject> all_objects; // For checking collisions
Ship *debug_ship;                       // Now it can be acces everywhere

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

void *playerRenderLoop(void *) {
  int lastX = debug_ship->getPos()[0];
  int lastY = debug_ship->getPos()[1];

  while (true) {
    pthread_mutex_lock(&print_mutex);

    debug_ship->erase(
        lastX,
        lastY); // Modify the erase method if needed to accept coordinates

    debug_ship->render(); // Render the ship at the new position

    lastX = debug_ship->getPos()[0];
    lastY = debug_ship->getPos()[1];

    refresh();
    pthread_mutex_unlock(&print_mutex);

    usleep(100000);
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
