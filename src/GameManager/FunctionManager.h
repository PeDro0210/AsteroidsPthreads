#ifndef FUNCTIONMANAGER
#define FUNCTIONMANAGER

#include "../GameObjects/MovableObjects/MovableObjects.h"
#include <algorithm>

void firstMode();

void secondMode();

void objectDestroyer(
    std::vector<MovableObject *>
        &object_to_destroy, // need to be pass as reference,
                            // for deleating the objects
    std::vector<MovableObject *> &all_objects,
    std::vector<Projectile *> &projectile,
    std::vector<Asteroid *> &asteroid); // Passint any projectile ship
                                        // is bad design, but fuck it
                                        //

void overlapperChecker(
    std::vector<MovableObject *> &all_objects,
    Ship *ships[]); // needs to be pass as reference, for managing vectors

#endif // !FUNCTIONMANAGER
