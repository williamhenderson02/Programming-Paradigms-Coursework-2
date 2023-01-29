#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include "langton.h"
#include "visualiser.h"

int global_argc;
char **global_argv;

struct ant ant = {};
enum colour colour;
enum direction d;
struct rule rule = {};

int main(int argc, char *argv[]) {
    global_argc = argc;
    global_argv = argv;
    int i;
    char temp;

    if (global_argc < 2) {
    start_visualisation(&ant);
    do {
        for (i = 0; i < 100; i++) {
        visualise_and_advance(&ant);
        }
    }
    while (not_quit());

    end_visualisation();
    } else if (global_argc > 2) {
        printf("Too many arguments given."
                " The program should be invoked as './ant {rule}");
    } else {
        char *input = global_argv[1];
        for (int i = 0; i < strlen(input); i++) {
            if (input[i]!= 'l' && input[i] != 'L' && input[i] != 'r' &&
            input[i] != 'R') {
                printf("{rule} must only include 'L' and 'R'");
                return 0;
            } else {
                while (input[i]) {
                    temp = input[i];
                    input[i] = toupper(temp);
                    i++;
                }
            }
        }
        rule.rules = input;
        start_visualisation(&ant);
    do {
        for (i = 0; i < 100; i++) {
            visualise_and_advance(&ant);
        }
    }
    while (not_quit());

    end_visualisation();
    }
    return 0;
}
