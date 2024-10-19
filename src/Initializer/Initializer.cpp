#include "Initializer.h"

std::vector<Projectile *> projectile_ship1;
std::vector<Projectile *> projectile_ship2;
pthread_mutex_t print_mutex;
Ship *ships[2];
std::vector<MovableObject *> all_objects; // for checking collisions
std::vector<MovableObject *> objects_to_destroy;
std::vector<Asteroid *> asteroids;

void initializeShip() {
  for (int i = 0; i <= 1; i++) {
    ships[i] = new Ship(i, i * 5, i * 5);
    all_objects.push_back(ships[i]);
  }
}

void initializeAsteroidsNormalMode() {
  for (int i = 0; i <= 2; i++) {
    bigAsteroid *asteroid = new bigAsteroid();
    all_objects.push_back(asteroid);
    asteroids.push_back(asteroid);
  }
}

void initializeAsteroidsTwoPlayers() {
  for (int i = 0; i <= 5; i++) {
    bigAsteroid *asteroid = new bigAsteroid();
    all_objects.push_back(asteroid);
    asteroids.push_back(asteroid);
  }
}
