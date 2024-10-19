#include "GameThreads/GameThreads.h"
#include "PlayerInputs/PlayerInputs.h"

/*
 * Still some issues, for some reason there's a race condition when you first
 * try to takeout the asteroidsRenderLoop
 *
 * and player 2 doesn't work LMAO, but. I had progress with a library for
 * managing controller inputs
 *
 *
 */

/*
 *TODO: fix the race condition issue
 * fix that when ship2 shoots, it gives player to ship1
 * implement another way for moving ship2, just ship2
 *
 */

int main() {
  pthread_t player_threads[2];
  pthread_t ship_render_thread[2];
  pthread_t ui_render_thread, asteroid_render_thread;

  int selection;

  UiManagers *ui_manager = new UiManagers();

  // Init ncurses
  initscr();
  cbreak();
  noecho();
  timeout(0);
  curs_set(0);
  keypad(stdscr, TRUE);

  pthread_mutex_init(&print_mutex, NULL);

  srand(static_cast<unsigned int>(time(0))); // for random seed
  initializeShip();

  ui_manager->selectionScreen(); // rendering the Selection Screen
  while (true) {                 // Selection option
    char ch = getch();
    if (ch == '1') {
      selection = 1;
      break;
    }

    if (ch == '2') {
      selection = 2;
      break;
    }
  }

  ui_manager->deleateSelectionScreen(); // Autoexplanatory

  // Threads that always will happen
  pthread_create(&asteroid_render_thread, NULL, asteroidsRenderLoop, NULL);
  pthread_create(&ship_render_thread[0], NULL, playerRenderLoop, ships[0]);
  pthread_create(&ship_render_thread[0], NULL, playerRenderLoop, ships[0]);
  pthread_create(&player_threads[0], NULL, inputPlayer1Loop, ships[0]);

  if (selection == 1) { // creating specific threads
    initializeAsteroidsNormalMode();
    pthread_create(&ui_render_thread, NULL, uiRenderLoopScreen1, ui_manager);

  } else if (selection == 2) { // creating specific threads
    initializeAsteroidsTwoPlayers();
    pthread_create(&ui_render_thread, NULL, uiRenderLoopScreen2, ui_manager);

    pthread_create(&player_threads[1], NULL, inputPlayer2Loop, ships[1]);
    pthread_create(&ship_render_thread[1], NULL, playerRenderLoop, ships[1]);

    pthread_join(player_threads[1], NULL);
    pthread_join(ship_render_thread[1], NULL);
  }

  pthread_join(player_threads[0], NULL);
  pthread_join(ship_render_thread[0], NULL);
  pthread_join(ui_render_thread, NULL);
  pthread_join(asteroid_render_thread, NULL);

  pthread_mutex_destroy(&print_mutex);
  delete ui_manager;
  endwin(); // for ncurses
  return 0;
}
