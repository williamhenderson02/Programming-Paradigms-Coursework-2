// header files and libraries to be included
#include <stdio.h>
#include "langton.h"
#include "visualiser.h"

// function to make the ant turn left
void turn_left(struct ant *ant) {
    // ant direction changed 90 degrees anti-clockwise
    if (ant->direction  == UP) {
        ant->direction = LEFT;
    } else if (ant->direction  == DOWN) {
        ant->direction = RIGHT;
    } else if (ant->direction  == LEFT) {
        ant->direction = DOWN;
    } else {
        ant->direction = UP;
    }
}

// function to make the ant turn right
void turn_right(struct ant *ant) {
    // ant direction changed 90 degrees clockwise
    if (ant->direction  == UP) {
        ant->direction = RIGHT;
    } else if (ant->direction  == DOWN) {
        ant->direction = LEFT;
    } else if (ant->direction  == LEFT) {
        ant->direction = UP;
    } else {
        ant->direction = DOWN;
    }
}

// function to move the ant forward
void move_forward(struct ant *ant) {
    // update the ant's x and y position based on current direction
    if (ant->direction == UP) {
        ant->y -= 1;
    } else if (ant->direction == DOWN) {
        ant->y += 1;
    } else if (ant->direction == LEFT) {
        ant->x -= 1;
    } else {
        ant->x += 1;
    }
}

// function to apply rule to ant
void apply_rule(enum colour *colour, struct ant *ant) {
    // checks colour of cell ant currently on, turns and flips colour
    if (*colour == A) {
        turn_right(ant);
        *colour = B;
    } else {
        turn_left(ant);
        *colour = A;
    }
}

// function to apply advanced variant to ant
void apply_rule_general(enum colour *colour, struct ant *ant, struct rule *rule) {
    // set the index as the number that the colour is poining to in enum colour
    int index = *colour;

    // index rules to find turn decision of current state
    if (rule->rules[index] == 'R') {
        turn_right(ant);
    } else {
        turn_left(ant);
    }
    // if the ant is at the last state return to first state
    if (index == (rule->states) - 1) {
            *colour = 0;
    // otherwise set ant to next state
    } else {
            *colour += 1;
    }
}
