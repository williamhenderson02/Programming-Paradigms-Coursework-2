#include <curses.h>
#include <locale.h>
#include <stdlib.h>
#include "visualiser.h"
#include "langton.h"

#define cell_under_ant cell_at(ant->y, ant->x)

cell *cells;

cell* cell_at(int y, int x)
{
  return &cells[(max_y*y) + x];
}


void start_visualisation(struct ant* ant) {
  setlocale(LC_ALL, "");

   initscr();
   curs_set(FALSE); 
   max_x = getmaxx(stdscr);
   max_y = getmaxy(stdscr);
   cells = calloc(max_y*max_x, sizeof(cell));
   ant->x = max_x/2;
   ant->y = max_y/2;
   ant->direction = RIGHT;
}

void visualise_and_advance(struct ant* ant) {
      /* Draw cells and ant */
      
      for (int y=0; y<max_y; y++)
      {
         for (int x=0; x<max_x; x++)
         {
            mvprintw(y,x,
               ant_is_at(y,x)
                 ? direction_to_s(ant->direction)
                 : cell_at(y,x)
                    ? "█"
                    : " "
            );
         }
      }
      refresh();
      
      /* Advance to next step */
      apply_rule(cell_under_ant, ant);
      move_forward(ant);

       if(ant->x < 0){
         ant->x = max_x - 1;
      }

      if(ant->y < 0){
         ant->y = max_y - 1;
      }

      if(ant->x == max_x){
         ant->x = 0;
      }

      if(ant->y == max_y){
         ant->y = 0;
      }
}

// Check if the user has input "q" to quit
bool not_quit() {
   return 'q' != getch();
}

void end_visualisation() {
   free(cells);
   endwin();
}

const char* direction_to_s(enum direction d) {
   return UP   == d ? "^" :
          DOWN == d ? "v" :
          LEFT == d ? "<" :
          /* else */  ">" ;
}

