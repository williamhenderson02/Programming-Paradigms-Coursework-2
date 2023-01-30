#ifndef visualiser_h
#define visualiser_h

#include "langton.h"
#include <stdbool.h>

static int max_x;
static int max_y;

typedef enum colour cell;

void start_visualisation(struct ant* ant);
void visualise_and_advance(struct ant* ant);
void general_visualise_and_advance(struct ant* ant, struct rule* rule);
bool not_quit();
void end_visualisation();
const char* direction_to_s(enum direction d);

#endif
