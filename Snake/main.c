#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include "snake.h"
#include"Food.h"

#define WIDTH 800
#define HEIGHT 600




int main(int argc, char* argv[]) {

    // init sdl
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Erreur SDL INIT failed\n");
        return -1;
    }
    //creer une fenetre avec sdl
    SDL_Window* window = SDL_CreateWindow("Snake Game",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        WIDTH, HEIGHT, SDL_WINDOW_SHOWN);

    if (window == NULL) {
        printf("Erreur creation de la fenetre SDL\n");
        SDL_Quit();
        return -1;
    }

    // Creer le systeme de rendu
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1,
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if (renderer == NULL) {
        printf("Erreur creation rendu SDL");
        SDL_Quit();
        return -1;
    }


   struct Snake snake;
   struct Food food;
    setup(&snake, &food);

    SDL_Event event;

    while (1) {
      //Clear rendu + set color black
     SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
     SDL_RenderClear(renderer);

        while (SDL_PollEvent(&event)) {  // boucle pour lires les events de la fenêtre.
            if (event.type == SDL_QUIT) {
                SDL_DestroyRenderer(renderer); // libère la mémoire.
                SDL_DestroyWindow(window);
                SDL_Quit();
                return 0;
            }
        }
    }

    void snakePhysics(struct Snake* snake){
        for (int i = 0; i <= snake->size - 2; i++) {
            snake->tail[i] = snake->tail[i + 1];
        }
        new_tail = { snake->x, snake->y };
        snake->tail[snake->size - 1] = new_tail;
        switch (snake->direction) {
        case UP:
            snake->y -= SPEED;
            break;
        case DOWN:
            snake->y += SPEED;
            break;
        case LEFT:
            snake->x -= SPEED;
            break;
        case RIGHT:
            snake->x += SPEED;
            break;
        }
    }


   SDL_Rect Square = { x, y, width, height };
   SDL_SetRenderDrawColor(renderer,0, 0, 0, 0);
   SDL_RenderFillRect(renderer, &Square);

   SDL_RenderPresent(renderer);
   SDL_Delay(1);
    }