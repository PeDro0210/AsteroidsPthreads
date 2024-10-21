#include "GameThreads.h"

void *uiRenderLoopScreen1(void *arg) {
  UiManagers *ui_manager = new UiManagers();

  while (true) {

    pthread_mutex_lock(&print_mutex);
    ui_manager->gameDisplay();

    int scores[2] = {ships[0]->getScore(),
                     ships[1]->getScore()}; // pass the score of both
    ui_manager->scoreDisplay(scores);       // can't pass it directly, bowhomp

    int lifes[2] = {ships[0]->getLife(),
                    0}; // Lmao, I typo getScore for the second one, LMAO
    ui_manager->lifeDisplay(lifes);

    if (ships[0]->getScore() >= 60) {
      ui_manager->winScreen(1);
    }
    if (ships[0]->getLife() <= 0) {
      ui_manager->loseScreen();
    }

    refresh();
    pthread_mutex_unlock(&print_mutex);

    usleep(33333);
  }
  return nullptr;
}

void *uiRenderLoopScreen2(void *arg) {
  UiManagers *ui_manager = new UiManagers();

  while (true) {

    pthread_mutex_lock(&print_mutex);
    ui_manager->gameDisplay();

    int scores[2] = {ships[0]->getScore(), ships[1]->getScore()};
    ui_manager->scoreDisplay(scores); // can't pass it directly, bowhomp

    int lifes[2] = {ships[0]->getLife(), ships[1]->getLife()};
    ui_manager->lifeDisplay(lifes);

    if (ships[0]->getScore() >= 60 || ships[1]->getLife() <= 0) {
      ui_manager->winScreen(1);
    }
    if (ships[1]->getScore() >= 60 || ships[0]->getLife() <= 0) {
      ui_manager->winScreen(2);
    }

    refresh();
    pthread_mutex_unlock(&print_mutex);

    usleep(33333);
  }
  return nullptr;
}

// At the end, I did followed DRY
void *playerRenderLoop(void *arg) {
  // TODO:RECOMMENT
  Ship *ship = static_cast<Ship *>(arg);
  /*
   * A bug occured, where the ship didn't spawn on the limits of the screen,
   * and for some reason while not being in the limits the takeOutLife
   * method keept calling itself, so by moving it foward, the ship appears
   * again in the screen with the keepOnLimits method.
   *
   * Fix :D
   */

  ship->MoveFoward();
  int lastX = 0; // need to keep track of the last position,
                 // if not it keeps a trail
  int lastY = 0;

  if (ship != nullptr) {
    int lastX = ship->getPos()[0]; // need to keep track of the last position,
                                   // if not it keeps a trail
    int lastY = ship->getPos()[1];
  }
  while (true) {
    pthread_mutex_lock(&print_mutex);

    if (ship != nullptr) { // just in case LMAO
      ship->erase(lastX, lastY);
      ship->render();

      // get the latest position in the newest iteration
      lastX = ship->getPos()[0];
      lastY = ship->getPos()[1];
      std::vector<Projectile *> projectile_ship;

      // Sees the id of the ship, for pushing the projectiles
      if (ship->getId() == 0) {
        projectile_ship = projectile_ship1;
      } else {
        projectile_ship = projectile_ship2;
      }

      for (Projectile *projectile : projectile_ship) {
        if (projectile != nullptr) {
          all_objects.push_back(projectile);
          int lastX_projectile = projectile->getPos()[0];
          int lastY_projectile = projectile->getPos()[1];

          projectile->erase(lastX_projectile, lastY_projectile);
          projectile->MoveFoward();
          projectile->addingAge();
          projectile->alive(); // makes it older, for dying

          if (!projectile->isDestroyed()) {
            projectile->render();
          } else {
            objects_to_destroy.push_back(projectile);
          }
          refresh();
        }
      }

      /*
       * kinda of a trick in here, by Destroying it, we can go trough most of
       * the rules of the other movableobjects, but it has more chances, soo
       * whenever it destroys, it just takes out a life
       */
      if (ship->isDestroyed()) {
        ship->takeOutLife();
        ship->unDestroyed();
      }

      objectDestroyer(objects_to_destroy, all_objects, projectile_ship,
                      asteroids);

      overlapperChecker(all_objects, ships); // all it's ass function
                                             //
    }
    pthread_mutex_unlock(&print_mutex);
    usleep(33333);
  }

  return nullptr;
}

void *asteroidsRenderLoop(void *arg) {
  int lastX = 0;
  int lastY = 0;

  while (true) {

    pthread_mutex_lock(&print_mutex);
    for (Asteroid *asteroid : asteroids) {

      if (asteroid != nullptr) {
        int lastX = asteroid->getPos()[0]; // both of them are the issue
        int lastY = asteroid->getPos()[1]; // both of them are the issue

        if (!asteroid->isDestroyed()) {
          asteroid->erase(lastX, lastY);
          asteroid->MoveFoward();
          asteroid->render();
          refresh();
        }

        if (asteroid->isDestroyed()) {
          if (bigAsteroid *bigAst = dynamic_cast<bigAsteroid *>(
                  asteroid)) { // If the asteroid can be cast to a bigAsteroid

            std::array<littleAsteroid *, 2> newAsteroids =
                bigAst->splitAsteroid(asteroid->getPos()); // do the split

            for (littleAsteroid *little : newAsteroids) {

              asteroids.push_back(little);
              all_objects.push_back(little);
            }
          }
          objects_to_destroy.push_back(asteroid);
        }
      }
    }
    pthread_mutex_unlock(&print_mutex);

    usleep(99999);
  }
  return nullptr;
}
