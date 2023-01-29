#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include "langton.h"
#include "visualiser.h"

int g_argc;
char **g_argv;

struct ant ant = {};
enum colour colour;
enum direction d;

int main(int argc, char *argv[]){
    g_argc = argc;
    g_argv = argv;
    int i = 0;
    char temp;

    if(g_argc < 2){
    start_visualisation(&ant);
    do{
        for(int i = 0; i < 100; i++){
        visualise_and_advance(&ant);
        }
    }
    while(not_quit());  

    end_visualisation();
    }
    else if(g_argc > 2){
        printf("Too many arguments given. The program should be invoked as './ant {rule}");
    }
    else{
        char *rule = g_argv[1];
        for(int i = 0; i < strlen(rule); i++){
            if(rule[i]!= 'l' && rule[i] != 'L' && rule[i] != 'r' && rule[i] != 'R'){
            printf("{rule} must only include 'L' and 'R'");
            return 0;
            }
            else{
                while (rule[i]) {
                temp = rule[i];
                rule[i] = toupper(temp);
                i++;
    }
            }

        }
        start_visualisation(&ant);
    do{
        for(int i = 0; i < 100; i++){
        visualise_and_advance(&ant);
        }
    }
    while(not_quit());  

    end_visualisation();
    }
    return 0;
}