#ifndef UI
#define UI

#include "../GameManager/GameManager.h"
#include <ncurses.h>

class UiManagers {
private:
  screenSettings settings;

public:
  UiManagers(const screenSettings &settings); // Cause of the thredas
  void gameDisplay();
  void scoreDisplay(int scores[]);
};

#endif // !UI
