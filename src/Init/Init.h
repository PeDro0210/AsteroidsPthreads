#ifndef INITIALIZER
#define INITIALIZER
#include "../GameManager/FunctionManager.h"
#include "../GameObjects/MovableObjects/MovableObjects.h"
#include "../Ui/Ui.h"
#include <cstddef>
#include <cstdlib>
#include <ncurses.h>
#include <pthread.h>
#include <unistd.h>

extern pthread_mutex_t print_mutex;

extern std::vector<MovableObject *> all_objects; // for checking collisions
extern std::vector<Projectile *> projectile_ship1;
extern std::vector<Projectile *> projectile_ship2;
extern std::vector<MovableObject *> objects_to_destroy;
extern std::vector<Asteroid *> asteroids;
extern Ship *ships[2];

// init the ship

void initializeShip();

void initializeAsteroidsNormalMode();

void initializeAsteroidsTwoPlayers();

#endif // !INITIALIZER
