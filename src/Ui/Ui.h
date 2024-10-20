#ifndef UI
#define UI

#include "../GameManager/GameManager.h"
#include <ncurses.h>

class UiManagers {
private:
  screenSettings *settings;

public:
  UiManagers(); // Cause of the thredas
  void gameDisplay();
  void scoreDisplay(int scores[]);
  void lifeDisplay(int life[]);
  void winScreen(int id);
  void loseScreen();
  void selectionScreen();
  void deleateSelectionScreen();
};

#endif // !UI
