#ifndef MOVABLE_OBJECTS
#define MOVABLE_OBJECTS
#pragma once
#include "../../GameManager/GameManager.h"
#include "../Util/OrientationEnum.h"
#include "ncurses.h"
#include <string>
#include <vector>

class MovableObject {
protected:
  char icon = 'x';
  Orientation orientation;
  int x_pos;
  int y_pos;
  bool destroyed = false;

private:
  screenSettings *settings;

  // Keep object within grid limits
  void keepOnLimits();

public:
  // Constructor
  MovableObject(int x, int y, Orientation orientation);

  ~MovableObject();

  // For managing the position
  void MoveFoward();

  void setIcon(char new_icon);
  void setOrientation(Orientation new_orientation);

  // Getter for position
  std::array<int, 2> getPos();

  Orientation getOrientation();

  // Setting the object as destroyed
  void destroy();

  // The getter for destroyed status
  bool isDestroyed() const;

  // render the icon
  void render();

  void erase(int latest_x, int latest_y);
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
  float life_time = 5.0f;
  float age = 0;

public:
  Projectile(int id, Orientation orientation, int x_pos,
             int y_pos); // And use the super Constructor
  void addingAge();

  bool alive();
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
  Ship(int id, int x_dis, int y_dis);
  // Take life points
  void takeOutLife();

  void lookUp();

  void lookDown();

  void lookLeft();

  void lookRight();

  // Create instance of a Projectile
  Projectile *fire();
};

#endif // MOVABLE_OBJECTS
