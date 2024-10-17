#include "GameManager/GameManager.h"
#include "GameObjects/MovableObjects/MovableObjects.h"
#include "Ui/Ui.h"
#include <ncurses.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t print_mutex;

int scores[2] = {0, 0};
std::vector<MovableObject> all_objects; // For checking collisions

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
  while (true) {
    pthread_mutex_lock(&print_mutex);
    //* Putting all the code for the logic
    refresh();
    pthread_mutex_unlock(&print_mutex);

    usleep(99999);
  }
  return nullptr;
}

void *asteroidsRenderLoop(void *arg) {
  MovableObject *debug_object = new MovableObject(100, 100, FacingUp);

  while (true) {

    // TODO: use barrier when the overlapping function is done
    pthread_mutex_lock(&print_mutex);
    // DEBUGGING
    debug_object->erase();
    debug_object->MoveFoward();
    debug_object->render();
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
  while (true) {
    pthread_mutex_lock(&print_mutex);
    char ch = getch();

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

  // TODO: initialize the threads
  pthread_create(&ui_render_thread, NULL, uiRenderLoop, NULL);
  pthread_create(&asteroid_render_thread, NULL, asteroidsRenderLoop,
                 NULL); // FOR DEBUGGING

  // Create threads for rendering and input

  pthread_join(ui_render_thread, NULL);
  pthread_join(asteroid_render_thread, NULL); // DEBUGGING

  pthread_mutex_destroy(&print_mutex);
  return 0;
}
