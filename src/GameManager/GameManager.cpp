
#include "FunctionManager.h"

#include <algorithm>
#include <vector>

void objectDestroyer(std::vector<MovableObject *> &object_to_destroy,
                     std::vector<MovableObject *> &all_objects,
                     std::vector<Projectile *> &projectile_ship,
                     std::vector<Asteroid *> &asteroids) {

  // Iterate over the objects to destroy
  for (MovableObject *object : object_to_destroy) {
    object->erase(object->getPos()[0], object->getPos()[1]);
    all_objects.erase(
        std::remove(all_objects.begin(), all_objects.end(), object),
        all_objects.end()); // GRAWW MAGIC METHOD

    if (Projectile *proj = dynamic_cast<Projectile *>(
            object)) { // Casts to Projectile with polymorphism, I didn't do
                       // that
      projectile_ship.erase(
          std::remove(projectile_ship.begin(), projectile_ship.end(), proj),
          projectile_ship.end());
    }

    if (Asteroid *asteroid = dynamic_cast<Asteroid *>(
            object)) { // Casts to Projectile with polymorphism, I didn't do
                       // that
      asteroids.erase(std::remove(asteroids.begin(), asteroids.end(), asteroid),
                      asteroids.end());
    }
  }

  object_to_destroy.clear(); // In case pointers are still in here
}

void pointAdder(MovableObject *object1, MovableObject *object2, Ship *ships[]) {

  if ((dynamic_cast<Projectile *>(object1) &&
       dynamic_cast<littleAsteroid *>(object2)) ||
      (dynamic_cast<littleAsteroid *>(object1) &&
       dynamic_cast<Projectile *>(object2))) {

    Projectile *projectile = dynamic_cast<Projectile *>(object1)
                                 ? dynamic_cast<Projectile *>(object1)
                                 : dynamic_cast<Projectile *>(object2);

    littleAsteroid *asteroid = dynamic_cast<littleAsteroid *>(object1)
                                   ? dynamic_cast<littleAsteroid *>(object1)
                                   : dynamic_cast<littleAsteroid *>(object2);

    if (asteroid->isDestroyed())
      return;

    ships[projectile->getId()]->addScore();
  }
}

void overlapperChecker(std::vector<MovableObject *> &all_objects,
                       Ship *ships[]) {

  for (MovableObject *object1 : all_objects) {
    for (MovableObject *object2 : all_objects) {
      if (object1 == object2) {
        continue;
      }

      if (dynamic_cast<Asteroid *>(object1) &&
          dynamic_cast<Asteroid *>(object2)) {
        continue;
      }

      if (dynamic_cast<Projectile *>(object1) &&
          dynamic_cast<Projectile *>(object2)) {
        continue;
      }

      // Check if both share coordinates
      if (object1->getPos() == object2->getPos()) {
        pointAdder(object1, object2, ships);
        object1->destroy();
        object2->destroy();
      }
    }
  }
}
