#ifndef GAME_MANAGER // can't touch this, all everything breaks LMAO
#define GAME_MANAGER

struct screenSettings {
  int startX;
  int startY;
  int boxWidth;
  int boxHeight;

  screenSettings(int x, int y, int width, int height)
      : startX(x), startY(y), boxWidth(width), boxHeight(height) {}
};

#endif // GAME_MANAGER
