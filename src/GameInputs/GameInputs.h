#ifndef GAME_INPUTS
#define GAME_INPUTS

#include "../GameObjects/MovableObjects/MovableObjects.h"
#include "../Initializer/Initializer.h"
#include <SDL2/SDL.h>
#include <cstdlib>
#include <ncurses.h>
#include <pthread.h>
#include <unistd.h>

void *inputPlayer1Loop(void *arg);
void *inputPlayer2Loop(void *arg);

#endif // GAME_INPUTS
