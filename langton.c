#include <stdio.h>
#include "langton.h"

//enum direction { UP, DOWN, LEFT, RIGHT };

int main(){
    //printf("x = %d y = %d direction = %d", ant1.x, ant1.y, ant1.direction);
    struct ant ant1 = {10,15,RIGHT};
    turn_left(&ant1);
    turn_right(&ant1);
    move_forward(&ant1);
    return 0;
}

void turn_left(struct ant *ant){
    printf("direction = %d\n",ant->direction);
    if(ant->direction  == 0)
        ant->direction = 2;
    else if(ant->direction  == 1)
        ant->direction = 3;
    else if(ant->direction  == 2)
        ant->direction = 1;
    else
        ant->direction = 0;
    printf("direction = %d\n", ant->direction);
}

void turn_right(struct ant *ant){
    printf("direction = %d\n",ant->direction);
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
    printf("direction = %d\n", ant->direction);
}

void move_forward(struct ant *ant){
    printf("x = %d y = %d\n", ant->x, ant->y);
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
    printf("x = %d y = %d\n", ant->x, ant->y);
}

/*
void apply_rule_general(colour *colour, ant *ant, rule *rule){

}

void apply_rule(colour *colour, struct ant1 *ant){

}
*/