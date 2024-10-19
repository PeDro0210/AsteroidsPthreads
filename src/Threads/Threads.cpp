#include "Threads.h"

void *uiRenderLoopScreen1(void *arg) {
  UiManagers *ui_manager = static_cast<UiManagers *>(arg);

  while (true) {

    pthread_mutex_lock(&print_mutex);
    ui_manager->gameDisplay();

    int scores[2] = {ships[0]->getScore(), ships[1]->getScore()};
    ui_manager->scoreDisplay(scores); // can't pass it directly, bowhomp

    int lifes[2] = {ships[0]->getLife(), ships[1]->getScore()};
    ui_manager->lifeDisplay(lifes);

    if (ships[0]->getScore() >= 40) {
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
                                      //
    int lifes[2] = {ships[0]->getLife(), ships[1]->getScore()};
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

void *playerRenderLoop(void *arg) {
  // TODO:RECOMMENT
  Ship *ship = static_cast<Ship *>(arg);
  ship->MoveFoward();
  int lastX = ship->getPos()[0];
  int lastY = ship->getPos()[1];

  while (true) {
    pthread_mutex_lock(&print_mutex);

    ship->erase(lastX, lastY);
    ship->render();

    lastX = ship->getPos()[0];
    lastY = ship->getPos()[1];

    std::vector<Projectile *> projectile_ship;

    if (ship->getId() == 0) {
      projectile_ship = projectile_ship1;
    } else {
      projectile_ship = projectile_ship2;
    }

    for (Projectile *projectile : projectile_ship) {

      all_objects.push_back(projectile);
      int lastX_projectile = projectile->getPos()[0];
      int lastY_projectile = projectile->getPos()[1];

      projectile->erase(lastX_projectile, lastY_projectile);
      projectile->MoveFoward();
      projectile->addingAge();
      projectile->alive();

      if (!projectile->isDestroyed()) {
        projectile->render();
      } else {
        objects_to_destroy.push_back(projectile);
      }
    }

    // Handle ship destruction logic
    if (ship->isDestroyed()) {
      ship->takeOutLife();
      ship->unDestroyed();
      all_objects.push_back(ship);
    }

    refresh();

    pthread_mutex_unlock(&print_mutex);

    usleep(100000); // Sleep for 100ms
  }

  return nullptr;
}
void *asteroidsRenderLoop(void *arg) {

  while (true) {

    pthread_mutex_lock(&print_mutex);
    // DEBUGGING
    for (Asteroid *asteroid : asteroids) {

      int lastX = asteroid->getPos()[0];
      int lastY = asteroid->getPos()[1];

      asteroid->erase(lastX, lastY);
      asteroid->MoveFoward();
      asteroid->render();

      if (asteroid->isDestroyed()) {
        if (bigAsteroid *bigAst = dynamic_cast<bigAsteroid *>(
                asteroid)) { // If the asteroid can be cast to a bigAsteroid
                             //
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

    overlapperChecker(all_objects, ships);
    objectDestroyer(objects_to_destroy, all_objects, projectile_ship1,
                    asteroids);

    // DEBUGGING
    refresh();
    //* Putting all the code for the logic
    pthread_mutex_unlock(&print_mutex);

    usleep(99999);
  }
  return nullptr;
}
