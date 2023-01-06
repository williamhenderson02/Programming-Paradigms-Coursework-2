#include <stdio.h>
#include "langton.h"

//enum direction { UP, DOWN, LEFT, RIGHT };

int main(){
    //printf("x = %d y = %d direction = %d", ant1.x, ant1.y, ant1.direction);
    struct ant ant1 = {1,2,UP};
    turn_left(&ant1);
    turn_right(&ant1);
    move_forward(&ant1);
    return 0;
}

void turn_left(struct ant *ant){
    printf("x = %d y = %d direction = %d\n", ant->x, ant->y, ant->direction);
}

void turn_right(struct ant *ant){
    printf("x = %d y = %d direction = %d\n", ant->x, ant->y, ant->direction);
}

void move_forward(struct ant *ant){
    printf("x = %d y = %d direction = %d", ant->x, ant->y, ant->direction);
}

/*
void apply_rule_general(colour *colour, ant *ant, rule *rule){

}

void apply_rule(colour *colour, struct ant1 *ant){

}
*/