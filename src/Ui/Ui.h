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
};

#endif // !UI
