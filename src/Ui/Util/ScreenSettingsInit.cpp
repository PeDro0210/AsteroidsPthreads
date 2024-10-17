#include "ScreenSettingsInit.h"

struct screenSettings *settingsSetup() {
  // Get terminal dimensions
  int termHeight, termWidth;
  getmaxyx(stdscr, termHeight, termWidth);

  // Box dimensions and positioning
  int boxHeight = 32, boxWidth = 64;
  int startY = (termHeight - boxHeight) / 2;
  int startX = (termWidth - boxWidth) / 2;

  // Allocate memory for screenSettings and return the pointer
  return new struct screenSettings(startX, startY, boxWidth, boxHeight);
}
