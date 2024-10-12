#ifndef MOVABLE_OBJECTS
#define MOVABLE_OBJECTS

#include "../Util/OrientationEnum.h"
#include <string>
#include <vector>

class MovableObject {
private:
  // TODO: add limitations as properties;

  int x_pos;
  int y_pos;

  bool destroyed = false;

  Orientation orientation;

  std::string icon;

  // Keep object within grid limits
  void keepOnLimits();

public:
  // Constructor
  MovableObject(int x, int y, Orientation orientation);

  ~MovableObject();

  // For managing the position
  void MoveFoward();
  void MoveBackward();

  // Getter for position
  std::vector<int> getPos() const;

  // Setting the object as destroyed
  void destroy();

  // The getter for destroyed status
  bool isDestroyed() const;

  std::string render();
};

class Asteroid : public MovableObject {
public:
  Asteroid();

  // Keeps the movement depending on the orientation
  void keepMovement();
};

class littleAsteroid : public Asteroid {
private:
  std::string icon = "o";
};

class bigAsteroid : public Asteroid {
private:
  std::string icon = "0";

public:
  void splitAsteroid();
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
  int lifes = 3;

public:
  Ship();
  // Take life points
  void takeOutLife();

  void addPoints(Asteroid asteroidDestroyed);

  // Rotate counterclockwise
  void goCounterClockWise();

  // Rotate clockwise
  void goClockWise();

  // Create instance of a Projectile
  void fire();
};

class Projectile : public MovableObject {
private:
  int id;

public:
  Projectile(Orientation orientation);
  void keepMovement();
};

#endif // MOVABLE_OBJECTS
