#include "GameManager/GameManager.h"
#include "GameObjects/MovableObjects/MovableObjects.h"
#include "Ui/Ui.h"
#include <ncurses.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t print_mutex;

int scores[2] = {0, 0};

/* TODO: beside calling all the functions
 * for keeping the score, seeing if objects are overlapping
 */

void *uiRenderLoop(void *arg) {
  auto *screen = (screenSettings *)arg;
  auto *ui_manager = new UiManagers(*screen);

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
  auto *screen = (screenSettings *)arg; // DEBUGGING
  MovableObject *debug_object =
      new MovableObject(screen->startX + 15, screen->startY + 15, FacingLeft,
                        *screen); // DEBUGGING

  while (true) {

    // TODO: use barrier when the overlapping function is done
    pthread_mutex_lock(&print_mutex);
    // DEBUGGING
    debug_object->erase();
    debug_object->MoveBackward();
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

  // seeing screen data
  int termHeight, termWidth;
  getmaxyx(stdscr, termHeight, termWidth);

  int boxHeight = 32, boxWidth = 64;
  int startY = (75 + termHeight - boxHeight) / 2; // hehe, I love magic numbers
  int startX = (200 + termWidth - boxWidth) / 2;

  // put the instance of the screenSetting in here and pass it to the renderLoop
  auto *screen = new screenSettings(startX, startY, boxWidth,
                                    boxHeight); // okay, thanks LLMS for this

  // Initialize ncurses
  initscr();
  cbreak();
  noecho();
  timeout(0);

  pthread_mutex_init(&print_mutex, NULL);

  // TODO: initialize the threads
  pthread_create(&ui_render_thread, NULL, uiRenderLoop, screen);
  pthread_create(&asteroid_render_thread, NULL, asteroidsRenderLoop,
                 screen); // FOR DEBUGGING

  // Create threads for rendering and input

  pthread_join(ui_render_thread, NULL);
  pthread_join(asteroid_render_thread, NULL); // DEBUGGING

  pthread_mutex_destroy(&print_mutex);
  return 0;
}
