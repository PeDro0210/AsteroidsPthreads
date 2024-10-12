#ifndef UI
#define UI

#include "../GameManager/GameManager.h"
#include <ncurses.h>
// TODO: pass screenSettings
class UiManagers {
private:
  screenSettings settings;

public:
  UiManagers(const screenSettings &settings);
  void gameDisplay();
  void scoreDisplay(int scores[]);
};

#endif // !UI
