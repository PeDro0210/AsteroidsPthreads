#include "../../Ui/Util/ScreenSettingsInit.h"
#include "MovableObjects.h"

MovableObject::MovableObject(int x, int y, Orientation orientation)
    : x_pos(x), y_pos(y), orientation(orientation), settings(settingsSetup()) {}

MovableObject::~MovableObject() {}

void MovableObject::keepOnLimits() {
  if (x_pos < settings->startX) {
    x_pos = settings->startX + settings->boxWidth - 1;
  } else if (x_pos >= settings->startX + settings->boxWidth) {
    x_pos = settings->startX;
  }

  if (y_pos < settings->startY) {
    y_pos = settings->startY + settings->boxHeight - 1;
  } else if (y_pos >= settings->startY + settings->boxHeight) {
    y_pos = settings->startY;
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

void MovableObject::destroy() { destroyed = true; }

void MovableObject::render() { mvwprintw(stdscr, y_pos, x_pos, "%c", icon); }

void MovableObject::erase(int latest_x, int latest_y) {
  mvaddch(latest_y, latest_x, ' ');
}

std::array<int, 2> MovableObject::getPos() { return {x_pos, y_pos}; }

Orientation MovableObject::getOrientation() { return orientation; }
