#include <stdio.h>
#include "langton.h"
#include "visualiser.h"


struct ant ant1 = {};
enum colour start_colour;
enum direction d;

int main (){
    do{
        start_visualisation(&ant1);
        visualise_and_advance(&ant1);
    }
    while(not_quit());
    
    return 0;
}