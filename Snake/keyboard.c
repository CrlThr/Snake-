#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include "snake.h"


int keyboard(struct Snake * snake) {
    const Uint8* state = SDL_GetKeyboardState(NULL);
    if (state[SDL_SCANCODE_UP] && snake->direction != DOWN) {
        snake->direction = UP;
    }
    if (state[SDL_SCANCODE_DOWN] && snake->direction != UP) {
        snake->direction = DOWN;
    }
    if (state[SDL_SCANCODE_LEFT] && snake->direction != RIGHT) {
        snake->direction = LEFT;
    }
    if (state[SDL_SCANCODE_RIGHT] && snake->direction != LEFT) {
        snake->direction = RIGHT;
    }
}