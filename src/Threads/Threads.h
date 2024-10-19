#ifndef THREADS
#define THREADS

#include "../GameManager/FunctionManager.h"
#include "../GameObjects/MovableObjects/MovableObjects.h"
#include "../Initializer/Initializer.h"
#include "../Ui/Ui.h"
#include <SDL2/SDL.h>
#include <cstdlib>
#include <ncurses.h>
#include <pthread.h>
#include <unistd.h>

void *asteroidsRenderLoop(void *arg);
void *playerRenderLoop(void *arg);
void *uiRenderLoopScreen2(void *arg);
void *uiRenderLoopScreen1(void *arg);

#endif // !THREADS
