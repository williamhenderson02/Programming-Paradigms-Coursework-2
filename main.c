#include <stdio.h>
#include "langton.h"
#include "visualiser.h"


struct ant ant1 = {10,15,RIGHT};
enum colour start_colour = WHITE;

int main (){
    printf("Hello \n");
    apply_rule(&start_colour, &ant1);
    return 0;
}