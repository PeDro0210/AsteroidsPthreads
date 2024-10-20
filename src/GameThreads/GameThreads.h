#ifndef GAME_THREADS
#define GAME_THREADS

#include "../Init/Init.h"
#include "pthread.h"

void *uiRenderLoopScreen1(void *arg);
void *uiRenderLoopScreen2(void *arg);

void *playerRenderLoop(void *arg);

void *asteroidsRenderLoop(void *arg);

#endif // !GAME_THREADS
