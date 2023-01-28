#include <stdio.h>
#include "langton.h"
#include "visualiser.h"

cell* cells;

void turn_left(struct ant *ant){
    if(ant->direction  == UP)
        ant->direction = LEFT;
    else if(ant->direction  == DOWN)
        ant->direction = RIGHT;
    else if(ant->direction  == LEFT)
        ant->direction = DOWN;
    else
        ant->direction = UP;
}

void turn_right(struct ant *ant){
    if(ant->direction  == UP){
        ant->direction = RIGHT;
    }
    else if(ant->direction  == DOWN){
        ant->direction = LEFT;
    }
    else if(ant->direction  == LEFT){
        ant->direction = UP;
    }
    else {
        ant->direction = DOWN;
    }
}

void move_forward(struct ant *ant){
    if(ant->direction == UP){
        ant->y -= 1;
    }
    else if(ant->direction == DOWN){
        ant->y += 1;
    }
    else if(ant->direction == LEFT){
        ant->x -= 1;
    }
    else {
        ant->x += 1;
    }
}


void apply_rule(enum colour *colour, struct ant *ant){
    if(*colour == WHITE){
        turn_right(ant);
        *colour = BLACK;
        cells[(max_y*ant->y + ant->x)] = *colour;
    }
    else {
        turn_left(ant);
        *colour = WHITE;
        cells[(max_y*ant->y + ant->x)] = *colour;
    }
}

//void apply_rule_general(colour *colour, ant *ant, rule *rule){}