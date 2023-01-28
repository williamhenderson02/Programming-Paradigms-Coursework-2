#include <stdio.h>
#include "langton.h"
#include "visualiser.h"


struct ant ant = {};
enum colour colour;
enum direction d;

int main(int argc, char *argv[]){
    start_visualisation(&ant);
    int i;
    do{
        for(i = 0; i < 10000; i++){
        visualise_and_advance(&ant);
        }
    }
    while(not_quit());  

    end_visualisation();

    return 0;
}