#include <stdio.h>
#include "langton.h"
#include "visualiser.h"


struct ant ant = {};
enum colour start_colour;
enum direction d;

int main(int argc, char *argv[]){
    start_visualisation(&ant);
    do{
        visualise_and_advance(&ant);
    }
    while(not_quit());

    end_visualisation();

    return 0;
}