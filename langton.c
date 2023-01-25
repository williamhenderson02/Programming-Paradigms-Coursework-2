#include <stdio.h>
#include "langton.h"

/*struct ant ant1 = {10,15,RIGHT};
enum colour start_colour = WHITE;

int main(){
    //turn_left(&ant1);
    //turn_right(&ant1);
    //move_forward(&ant1);
    apply_rule(&start_colour, &ant1);
    return 0;
}*/

void turn_left(struct ant *ant){
    //printf("direction = %d\n",ant->direction);
    if(ant->direction  == 0)
        ant->direction = 2;
    else if(ant->direction  == 1)
        ant->direction = 3;
    else if(ant->direction  == 2)
        ant->direction = 1;
    else
        ant->direction = 0;
    //printf("direction = %d\n", ant->direction);
}

void turn_right(struct ant *ant){
    //printf("direction = %d\n",ant->direction);
    if(ant->direction  == 0){
        ant->direction = 3;
    }
    else if(ant->direction  == 1){
        ant->direction = 2;
    }
    else if(ant->direction  == 2){
        ant->direction = 0;
    }
    else {
        ant->direction = 1;
    }
    //printf("direction = %d\n", ant->direction);
}

void move_forward(struct ant *ant){
    //printf("x = %d y = %d\n", ant->x, ant->y);
    if(ant->direction == 0){
        ant->y += 1;
    }
    else if(ant->direction == 1){
        ant->y -= 1;
    }
    else if(ant->direction == 2){
        ant->x -= 1;
    }
    else {
        ant->x += 1;
    }
    //printf("x = %d y = %d\n", ant->x, ant->y);
}


void apply_rule(enum colour *colour, struct ant *ant){
    //printf("colour = %d\n", *colour);
    if(*colour == 0){
        *colour = 1;
        turn_left(ant);
        move_forward(ant);
    }
    else {
        *colour = 0;
        turn_right(ant);
        move_forward(ant);
    }
    //printf("switched colour = %d\n", *colour);
}

//void apply_rule_general(colour *colour, ant *ant, rule *rule){}