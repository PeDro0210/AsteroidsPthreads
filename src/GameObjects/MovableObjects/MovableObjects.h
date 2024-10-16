#ifndef MOVABLE_OBJECTS
#define MOVABLE_OBJECTS

#include "../../GameManager/GameManager.h"
#include "../Util/OrientationEnum.h"
#include "ncurses.h"
#include <string>
#include <vector>

class MovableObject {
private:
  int x_pos;
  int y_pos;

  bool destroyed = false;

  Orientation orientation;

  char icon = 'x';

  screenSettings settings;

  // Keep object within grid limits
  void keepOnLimits();

public:
  // Constructor
  MovableObject(int x, int y, Orientation orientation,
                const screenSettings &settings);

  ~MovableObject();

  // For managing the position
  void MoveFoward();
  void MoveBackward();

  // Getter for position
  std::array<int, 2> getPos() const;

  // Setting the object as destroyed
  void destroy();

  // The getter for destroyed status
  bool isDestroyed() const;

  // render the icon
  void render();

  void erase();
};

class Asteroid : public MovableObject {
public:
  // Keeps the movement depending on the orientation
  void keepMovement();
};

class littleAsteroid : public Asteroid {
private:
  char icon = 'o';
};

class bigAsteroid : public Asteroid {
private:
  char icon = '0';

public:
  std::array<littleAsteroid, 2>
  splitAsteroid(); // using std::array instead of vector, because of the size
};

class Projectile : public MovableObject {
private:
  int id;
  /*
   * Icon based on orientation:
   * FacingUp = "|"
   * FacingDown = "|"
   * FacingLeft = "-"
   * FacingRight = "-"
   */
  char icon = '|';

public:
  Projectile(Orientation orientation); // And use the super Constructor
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
  char icon = 'A';
  Orientation orientation = FacingUp;
  int lifes = 3;
  int id;

public:
  Ship(int id);
  // Take life points
  void takeOutLife();

  void addPoints(Asteroid asteroidDestroyed);

  // Rotate counterclockwise
  void goCounterClockWise();

  // Rotate clockwise
  void goClockWise();

  // Create instance of a Projectile
  Projectile fire();
};

#endif // MOVABLE_OBJECTS
