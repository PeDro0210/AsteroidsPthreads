#include "Ui.h"
#include "Util/ScreenSettingsInit.h"
#include <cstdlib>
#include <ncurses.h>
#include <unistd.h>

UiManagers::UiManagers() : settings(settingsSetup()) {}

void UiManagers::gameDisplay() {

  // making horizontal line
  for (int x = 0; x < settings->boxWidth; ++x) {
    mvwprintw(stdscr, settings->startY, settings->startX + x, "-");
    mvwprintw(stdscr, settings->startY + settings->boxHeight - 1,
              settings->startX + x, "-");
  }

  // Making vertical lines
  for (int y = 0; y < settings->boxHeight; ++y) {
    mvwprintw(stdscr, settings->startY + y, settings->startX, "|");
    mvwprintw(stdscr, settings->startY + y,
              settings->startX + settings->boxWidth - 1, "|");
  }

  // Making Corners
  mvwprintw(stdscr, settings->startY, settings->startX, "+");
  mvwprintw(stdscr, settings->startY, settings->startX + settings->boxWidth - 1,
            "+");
  mvwprintw(stdscr, settings->startY + settings->boxHeight - 1,
            settings->startX, "+");
  mvwprintw(stdscr, settings->startY + settings->boxHeight - 1,
            settings->startX + settings->boxWidth - 1, "+");
}

void UiManagers::scoreDisplay(int scores[]) {
  for (int i = 0; i < 2; i++) {
    mvwprintw(stdscr, settings->startY - 2 + i, settings->startX,
              "Score %d: %d", i + 1, scores[i]);
  }
}

void UiManagers::lifeDisplay(int life[]) {
  for (int i = 0; i < 2; i++) { // 1 is for debugging purposes
    mvwprintw(stdscr, settings->startY - 2 + i, settings->startX + 20,
              "Life %d: %d", i + 1, life[i]);
  }
}

void UiManagers::winScreen(int id) {
  clear(); // Clear the screen

  mvwprintw(stdscr, settings->startY + 10, settings->startX + 22,
            "PLAYER %d WINS", id);
  mvwprintw(stdscr, settings->startY + 11, settings->startX + 20,
            "PRESS ESC TO EXIT");
  int ch;
  while (true) {
    ch = getch();
    if (ch == 27) {
      endwin();
      exit(0);
    }
  }
}

void UiManagers::loseScreen() {
  clear(); // Clear the screen

  mvwprintw(stdscr, settings->startY + 10, settings->startX + 22, "YOU LOSE");
  mvwprintw(stdscr, settings->startY + 11, settings->startX + 20,
            "PRESS ESC TO EXIT");
  int ch;
  while (true) {
    ch = getch();
    if (ch == 27) {
      endwin();
      exit(0);
    }
  }
}
