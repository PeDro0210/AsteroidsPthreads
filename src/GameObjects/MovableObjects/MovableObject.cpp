#include "../../Ui/Util/ScreenSettingsInit.h"
#include "MovableObjects.h"
#include <array>

MovableObject::MovableObject(int x, int y, Orientation orientation)
    : x_pos(x), y_pos(y), orientation(orientation), settings(settingsSetup()) {}

// This is pure magic, like no need to explain okay :D
void MovableObject::keepOnLimits() {
  if (x_pos < settings->startX + 1) {
    x_pos = settings->startX + settings->boxWidth - 2;
  } else if (x_pos >= settings->startX + settings->boxWidth - 1) {
    x_pos = settings->startX + 2;
  }

  if (y_pos < settings->startY + 1) {
    y_pos = settings->startY + settings->boxHeight - 2;
  } else if (y_pos >= settings->startY + settings->boxHeight - 1) {
    y_pos = settings->startY + 2;
  }
}

void MovableObject::setIcon(char new_icon) { icon = new_icon; }

void MovableObject::setOrientation(Orientation new_orientation) {
  orientation = new_orientation;
}

void MovableObject::MoveFoward() {
  switch (orientation) {
  case FacingUp:
    y_pos--;
    break;
  case FacingDown:
    y_pos++;
    break;
  case FacingLeft:
    x_pos--;
    break;
  case FacingRight:
    x_pos++;
    break;
  }
  keepOnLimits();
}
void MovableObject::unDestroyed() { destroyed = false; }

void MovableObject::destroy() { destroyed = true; }

void MovableObject::render() { mvwprintw(stdscr, y_pos, x_pos, "%c", icon); }

void MovableObject::erase(int latest_x, int latest_y) {
  mvaddch(latest_y, latest_x, ' ');
}

std::array<int, 2> MovableObject::getPos() { return {x_pos, y_pos}; }

Orientation MovableObject::getOrientation() { return orientation; }

bool MovableObject::isDestroyed() { return destroyed; }
