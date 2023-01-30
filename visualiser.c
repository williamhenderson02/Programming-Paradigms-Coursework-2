// header files and libraries to be included
#include <curses.h>
#include <locale.h>
#include <stdlib.h>
#include "visualiser.h"
#include "langton.h"

// macro to find position of ant
#define cell_at(y, x) (cells[(max_x * y) + x])

// function like macro to find position of ant
#define cell_under_ant cell_at(ant->y, ant->x)

// global variable for command line arguments from main.c
extern int global_argc;
extern char **global_argv;

// cell pointer to cells
cell *cells;

/* cell_at function which returns the address of 
the cell the ant is currently at */

// function to start visualisation
void start_visualisation(struct ant* ant) {
  // initialise screen
  setlocale(LC_ALL, "");
  initscr();
  curs_set(FALSE);
  max_x = getmaxx(stdscr);
  max_y = getmaxy(stdscr);

  // allocate memory for cells
  cells = calloc(max_y*max_x, sizeof(cell));

  // set attributes for ant
  ant->x = max_x/2;
  ant->y = max_y/2;
  ant->direction = RIGHT;
}

// function to visualise the ant's behaviour
void visualise_and_advance(struct ant* ant) {
  /* Draw cells and ant */
  // for each cell check if the ant is at that cell
  for (int y=0; y < max_y; y++) {
     for (int x=0; x < max_x; x++) {
         // print cell colour to screen
         mvprintw(y, x,
            ant_is_at(y, x)
               // if ant is at current cell put ant direction on that cell
               ? direction_to_s(ant->direction)
               // if pointer to cell is white display white
               : cell_at(y, x)
                  ? "█"
                  // otherwise display black
                  : " ");
      }
  }
  refresh();

  /* Advance to next step */
  apply_rule(&cell_under_ant, ant);

  // torus implemenation
  /* check if ant position is higher than max or lower 
  than min and move it accordingly */
  if (ant->x < 0) {
  ant->x = max_x - 1;
  }

  if (ant->y < 0) {
      ant->y = max_y - 1;
  }

  if (ant->x == max_x) {
      ant->x = 0;
  }

  if (ant->y == max_y) {
      ant->y = 0;
  }

  // call function to move ant forward
  move_forward(ant);
}

// function to visualise the n-state ant's behaviour
void general_visualise_and_advance(struct ant* ant, struct rule* rule) {
  /* Draw cells and ant */
  // for each cell check if the ant is at that cell
  for (int y=0; y < max_y; y++) {
     for (int x=0; x < max_x; x++) {
         // print cell colour to screen
         mvprintw(y, x,
            ant_is_at(y, x)
               // if ant is at current cell put ant direction on that cell
               ? direction_to_s(ant->direction)
               // ternary operator cases for each possible cell state
               // display corresponding state om screen
               : cell_at(y, x) == A
                  ? "A"
               : cell_at(y, x) == B
                  ? "B"
               : cell_at(y, x) == C
                  ? "C"
               : cell_at(y, x) == D
                  ? "D"
               : cell_at(y, x) == E
                  ? "E"
               : cell_at(y, x) == F
                  ? "F"
               : cell_at(y, x) == G
                  ? "G"
               : cell_at(y, x) == H
                  ? "H"
               : cell_at(y, x) == I
                  ? "I"
               : cell_at(y, x) == J
                  ? "J"
               : cell_at(y, x) == K
                  ? "K"
               : cell_at(y, x) == L
                  ? "L"
               : cell_at(y, x) == M
                  ? "M"
               : cell_at(y, x) == N
                  ? "N"
               : cell_at(y, x) == O
                  ? "O"
               : cell_at(y, x) == P
                  ? "P"
               : cell_at(y, x) == Q
                  ? "Q"
               : cell_at(y, x) == R
                  ? "R"
               : cell_at(y, x) == S
                  ? "S"
               : cell_at(y, x) == T
                  ? "T"
               : cell_at(y, x) == U
                  ? "U"
               : cell_at(y, x) == V
                  ? "V"
               : cell_at(y, x) == W
                  ? "W"
               : cell_at(y, x) == X
                  ? "X"
               :cell_at(y, x) == Y
                  ? "Y"
               // otherwise display Z
                  : "Z");
      }
  }
  refresh();

  /* Advance to next step */
  apply_rule_general(&cell_under_ant, ant, rule);

  // torus implemenation
  /* check if ant position is higher than max or lower 
  than min and move it accordingly */
  if (ant->x < 0) {
  ant->x = max_x - 1;
  }

  if (ant->y < 0) {
      ant->y = max_y - 1;
  }

  if (ant->x == max_x) {
      ant->x = 0;
  }

  if (ant->y == max_y) {
      ant->y = 0;
  }

  // call function to move ant forward
  move_forward(ant);
}

// Check if the user has input "q" to quit
bool not_quit() {
  return 'q' != getch();
}

// function to end visualisation
void end_visualisation() {
  // ree memory allocated for cells and close window
  free(cells);
  cells = NULL;
  endwin();
}

// function to get symbol corresponding to ant direction
const char* direction_to_s(enum direction d) {
  return UP   == d ? "^" :
          DOWN == d ? "v" :
          LEFT == d ? "<" :
          /* else */  ">" ;
}
