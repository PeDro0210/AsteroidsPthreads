#ifndef FUNCTIONMANAGER
#define FUNCTIONMANAGER

#include "../GameObjects/MovableObjects/MovableObjects.h"
#include <algorithm>
void pointSetters(int id);

void firstMode();

void secondMode();

void objectDestroyer(
    std::vector<MovableObject *>
        &object_to_destroy, // need to be pass as reference, for deleating the
                            // objects
    std::vector<MovableObject *> &all_objects,
    std::vector<Projectile *> &projectile,
    std::vector<Asteroid *> &asteroids); // Passint any projectile ship
                                         // is bad design, but fuck it

void overlapperChecker(
    std::vector<MovableObject *>
        &all_objects); // needs to be pass as reference, for managing vectors

#endif // !FUNCTIONMANAGER
