#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>
#ifndef SNAKE_FOOD_H
#define SNAKE_FOOD_H

struct Food {
    int x, y;
};

void foodUpdate(SDL_Renderer* renderer, struct Food* food) {
    SDL_Rect rect = { food->x, food->y, 20, 20 };
    SDL_SetRenderDrawColor(renderer, 207, 52, 85, 255);
    SDL_RenderFillRect(renderer, &rect);
    SDL_RenderDrawRect(renderer, &rect);
}


#endif //SNAKE_FOOD_H