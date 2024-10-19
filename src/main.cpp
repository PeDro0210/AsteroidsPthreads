#include "GameThreads/GameThreads.h"
#include "PlayerInputs/PlayerInputs.h"

int main() {
  pthread_t player_threads[2];
  pthread_t ship_render_thread[2];
  pthread_t ui_render_thread, asteroid_render_thread;

  int selection = 0; // Initialize selection

  UiManagers *ui_manager = new UiManagers();

  // Initialize ncurses
  initscr();
  cbreak();
  noecho();
  timeout(0);
  curs_set(0); // Hide cursor
  keypad(stdscr, TRUE);

  pthread_mutex_init(&print_mutex, NULL);

  srand(static_cast<unsigned int>(time(0))); // for random seed
  initializeShip();

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
