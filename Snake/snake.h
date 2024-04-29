#pragma once
#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4
#define SPEED 25


struct Snake {
    int x, y;
    int direction;
    int width, height;
    int size;
    int tail;
    int new_tail;
    int foodSetRandomPosition;
};



struct Game {
    struct Snake* snake;
    int points;
    int alive;
};