#include "ScreenSettingsInit.h"

struct screenSettings *settingsSetup() {
  int termHeight, termWidth;
  getmaxyx(stdscr, termHeight, termWidth);

  // Dimensions of the imaginry box
  int boxHeight = 32, boxWidth = 64;
  int startY = (termHeight - boxHeight) / 2;
  int startX = (termWidth - boxWidth) / 2;

  return new struct screenSettings(startX, startY, boxWidth,
                                   boxHeight); // GRAWWW POINTERS, GRAWW
}
