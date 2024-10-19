#ifndef GLOBAL_VARIABLES
#define GLOBAL_VARIABLES
#include "../GameObjects/MovableObjects/MovableObjects.h"
#include <SDL2/SDL.h>
#include <cstdlib>
#include <ncurses.h>
#include <pthread.h>
#include <unistd.h>

extern std::vector<Projectile *> projectile_ship1;
extern std::vector<Projectile *> projectile_ship2;
extern pthread_mutex_t print_mutex;
extern Ship *ships[2];
extern std::vector<MovableObject *> all_objects; // for checking collisions
extern std::vector<MovableObject *> objects_to_destroy;
extern std::vector<Asteroid *> asteroids;

void initializeShip();
void initializeAsteroidsNormalMode();
void initializeAsteroidsTwoPlayers();

#endif // !GLOBAL_VARIABLES
