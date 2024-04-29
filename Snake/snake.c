#include "snake.h"
#include <SDL.h>


void setup(struct Snake* snake, struct Food* food) {
    snake->x = 100;
    snake->y = 100;
    snake->tail = 20;
    snake->size = 0;
    snake->width = 20;
    snake->direction = 0;
    snake->height = 20;
    foodSetRandomPosition(food);
}


int snakeHitWall(struct Snake* snake) {
    if (snake->x < 0 || snake->y < 0) {
        return 0;
    }
    if (snake->x > 480 || snake->y > 480) {
        return 0;
    }
    return 1;
}

void snakeUpdate(struct SDL_Renderer* renderer, struct Snake* snake) {
    SDL_Rect rect = { snake->x, snake->y, snake->height, snake->width };
    SDL_SetRenderDrawColor(renderer, 80, 80, 80, 255);
    SDL_RenderDrawRect(renderer, &rect);
    SDL_RenderFillRect(renderer, &rect);
    for (int i = 0; i <= snake->size - 1; i++) {
        SDL_SetRenderDrawColor(renderer, 100, 100, 100, 255);
        SDL_Rect new_tail = { snake->tail, snake->tail, snake->height, snake->width };
        SDL_RenderFillRect(renderer, &new_tail);
        SDL_RenderDrawRect(renderer, &new_tail);
    }
}

    void snakeDeath(struct Snake* snake, struct Food* food) {
        if (!snakeHitWall(snake)) {
            free(snake->tail);
            setup(snake, food);
            printf("DEAD\n");
        }
        for (int i = 0; i <= snake->size - 1; i++) {
            int dist = distance(snake->x, snake->y, snake->tail, snake->tail);
            if (dist < 1) {
                free(snake->tail);
                setup(snake, food);
                printf("DEAD\n");
            }
        }
    }

 

        void snakeEat(struct Snake* snake, struct Food* food, int new_tail) {
            double dist = distance(snake->x, snake->y, food->x, food->y);
            if (dist < 1) {
                snake->size += 1;
                foodSetRandomPosition(food);
                struct Tail* temp = (snake->tail, (snake->size * tail);
                if (temp != NULL) {
                    snake->tail = temp;
                    new_tail =  snake->x, snake->y ;
                    snake->tail[snake->size - 1] = new_tail;
                    printf("SUCCESS\n");
                }
                else {
                    printf("GAME OVER\n");
                }
            }
        }