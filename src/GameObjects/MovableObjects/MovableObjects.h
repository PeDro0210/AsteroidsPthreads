
#ifndef MOVABLE_OBJECTS
#define MOVABLE_OBJECTS

#include "../Util/OrientationEnum.h"
#include <string>
#include <vector>

class MovableObject {
private:
  int x_pos;
  int y_pos;

  bool destroyed = false;

  Orientation orientation;

  std::string icon;

public:
  // Constructor
  MovableObject(int x, int y);

  // For managing the position
  void moveRight();
  void moveLeft();
  void moveUp();
  void moveDown();

  // Getter for position
  std::vector<int> getPos() const;

  // Setting the object as destroyed
  void destroy();

  // The getter for destroyed status
  bool isDestroyed() const;

  // Keep object within grid limits, assumed 128x128
  void keepOnLimits();

  std::string getIcon() const;
};

class Asteroid : public MovableObject {
private:
  std::string icon = "O";
  Orientation orientation; // Random orientation to be selected

public:
  Asteroid();

  // Keeps the movement depending on the orientation
  void keepMovement();
};

class Ship : public MovableObject {
private:
  /*
   * Icon based on orientation:
   * FacingUp = "A"
   * FacingDown = "V"
   * FacingLeft = "<"
   * FacingRight = ">"
   */
  std::string icon = "A";
  Orientation orientation = FacingUp;

public:
  // Rotate counterclockwise
  void goCounterClockWise();

  // Rotate clockwise
  void goClockWise();
};

#endif // MOVABLE_OBJECTS
