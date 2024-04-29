#include "Food.h"

void foodSetRandomPosition(struct Food* food) {
    srand(time(NULL));
    int random_height = (rand() % 480);
    int random_width = (rand() % 480);
    int height_reminder = random_height % 25;
    int width_reminder = random_width % 25;
    food->x = random_height - height_reminder;
    food->y = random_width - width_reminder;
    printf("food->x %d\n", food->x);
    printf("food->y %d\n", food->y);
}