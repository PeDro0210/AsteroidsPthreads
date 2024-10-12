#include "GameManager/GameManager.h"
#include "Ui/Ui.h"
#include <ncurses.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t mutex;

int scores[2] = {0, 0};

/* TODO: beside calling all the functions
 * for keeping the score, seeing if objects are overlapping
 */

void *uiRenderLoop(void *arg) {
  auto *screen = (screenSettings *)arg;
  auto *ui_manager = new UiManagers(*screen);

  while (true) {
    pthread_mutex_lock(&mutex);
    clear();
    ui_manager->gameDisplay();
    ui_manager->scoreDisplay(scores);
    //* Putting all the code for the logic
    refresh();
    pthread_mutex_unlock(&mutex);

    usleep(33333);
  }
  return nullptr;
}

void *playerRenderLoop(void *) {
  while (true) {
    pthread_mutex_lock(&mutex);
    clear();
    //* Putting all the code for the logic
    refresh();
    pthread_mutex_unlock(&mutex);

    usleep(33333);
  }
  return nullptr;
}

void *asteroidsRenderLoop(void *) {
  while (true) {
    pthread_mutex_lock(&mutex);
    clear();
    //* Putting all the code for the logic
    refresh();
    pthread_mutex_unlock(&mutex);

    usleep(33333);
  }
  return nullptr;
}

// TODO: only manage the inputs of the ship in here
void *inputPlayer1Loop(void *) {
  while (true) {
    pthread_mutex_lock(&mutex);
    char ch = getch();

    pthread_mutex_unlock(&mutex);
    usleep(10000);
  }
  return nullptr;
}
// TODO: only manage the inputs of the ship in here
void *inputPlayer2Loop(void *) {
  while (true) {
    pthread_mutex_lock(&mutex);
    char ch = getch();

    pthread_mutex_unlock(&mutex);
    usleep(10000);
  }
  return nullptr;
}
// TODO: init all the objects and pass the on the inputLoop
int main() {
  pthread_t player_threads[2];

  pthread_t ui_render_thread, ship_render_thread, asteroid_thread;

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
  timeout(0); // Non-blocking getch()

  // Initialize mutex
  pthread_mutex_init(&mutex, NULL);

  // TODO: initialize the threads
  pthread_create(&ui_render_thread, NULL, uiRenderLoop, screen);

  // Create threads for rendering and input
  pthread_join(ui_render_thread, NULL);

  // Cleanup
  pthread_mutex_destroy(&mutex);
  return 0;
}
