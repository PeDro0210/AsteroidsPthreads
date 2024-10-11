#include <ncurses.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t mutex;
int ballxPosition = 10;
int ballyPosition = 10;

/* TODO: manage the printing of each object, beside calling all the functions
 * for keeping the score, seeing if objects are overlapping
 */

void *renderLoop(void *) {
  while (true) {
    usleep(33333); // 30 fps, ~33ms per frame
  }
  return nullptr;
}

// TODO: only manage the inputs of the ship in here
void *inputLoop(void *) {
  while (true) {
    pthread_mutex_lock(&mutex);
    pthread_mutex_unlock(&mutex);
    usleep(10000); // Add a small delay to make movement smoother
  }
  return nullptr;
}

// TODO: init all the objects and pass the on the inputLoop
int main() {
  pthread_t renderThread, inputThread;

  // Initialize ncurses
  initscr();
  cbreak();
  noecho();
  timeout(0); // Non-blocking getch()

  // Initialize mutex
  pthread_mutex_init(&mutex, nullptr);

  // Create threads for rendering and input
  pthread_create(&renderThread, nullptr, renderLoop, nullptr);
  pthread_create(&inputThread, nullptr, inputLoop, nullptr);

  pthread_join(inputThread, nullptr);
  pthread_join(renderThread, nullptr);

  // Cleanup
  pthread_mutex_destroy(&mutex);
  return 0;
}
