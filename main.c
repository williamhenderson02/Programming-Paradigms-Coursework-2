// header files and libraries to be included
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include "langton.h"
#include "visualiser.h"

// creating global instances for command line input arguments
int global_argc;
char **global_argv;

// initialising an ant, colours, direction and rule
struct ant ant = {};
enum colour colour;
enum direction d;
struct rule rule = {};

// Main function to control the flow of the enitre system
/* This takes arguments argc and argv which are the number of command line arguments
and list of command line arguments respectively */
int main(int argc, char *argv[]) {
    // setting globals
    global_argc = argc;
    global_argv = argv;

    // initialising index variable
    int i;

    // Checks the number of command line arguments
    if (global_argc < 2) {
    // if the basic variant is used the visualisation is started
    start_visualisation(&ant);

    // while the user does not quit the simulation is ran
    do {
        for (i = 0; i < 100; i++) {
        visualise_and_advance(&ant);
        }
    }
    while (not_quit());

    // simulation ended when user quits
    end_visualisation();

    // checks number of command line arguments
    } else if (global_argc > 2) {
        // if more too many arguments passed an error is thrown
        printf("Too many arguments given."
                " The program should be invoked as './ant {rule} ");

    // otherwise the advanced variant is simulated
    } else {
        // user entered rule is iterated through
        char *input = global_argv[1];
        for (int i = 0; i < strlen(input); i++) {
            // if the rule includes incorrect letters an error is thrown
            if (input[i]!= 'l' && input[i] != 'L' && input[i] != 'r' &&
            input[i] != 'R') {
                printf("{rule} must only include 'L' and 'R' ");
                return 0;
            }
        }
        // otherwise the rule is converted to uppercase
        for (int i = 0; i < strlen(input); i++) {
        input[i] = toupper(input[i]);
        }

    // user input set as rule in struct
    rule.rules = input;
    rule.states = strlen(input);

    // advanced variation started
    start_visualisation(&ant);

    // advanced variation simulated while user does not quit
    do {
        //for (i = 0; i < 100; i++) {
            general_visualise_and_advance(&ant, &rule);
        //}
    }
    while (not_quit());

    // when user quits simulation ends
    end_visualisation();
    }

    // normal 0 return at end of main function
    return 0;
}
