#ifndef GAME_MANAGER
#define GAME_MANAGER

#include "../GameObjects/MovableObjects/MovableObjects.h"
#include <vector>

struct screenSettings {
  int startX;
  int startY;
  int boxWidth;
  int boxHeight;

  screenSettings(int x, int y, int width, int height)
      : startX(x), startY(y), boxWidth(width), boxHeight(height) {}
};

void overlappingChecker(
    std::vector<MovableObject> objects); // PointSetter will be called in here

void pointSetters(int id);

void firstMode();

void secondMode();

#endif // GAME_MANAGER
