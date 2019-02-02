#include <ncurses.h>
#include <unistd.h>
#include <string.h>

#define DELAY 300000

int main(int argc, char **argv) {
  int x =0;
  int y=0;
  int maxX=0;
  int maxY=0;
  int nextX=0;
  int direction=5;

  char *word = "Jai Shree Ram!!!";
  int wordLength = strlen(word);
  
  //init ncursor screen
  initscr();

  //turn off echo
  noecho();

  //turn of cursor displat
  curs_set(FALSE);

  //get the max-x and max-y coordinates
  getmaxyx(stdscr, maxY, maxX);
  //Here we are reducing the maximum
  //value of X-axis. Because, the word will go out of the
  //screen
  maxX -= wordLength;
  
  while(1) {
    clear();
    mvprintw(y, x, word);
    refresh();
    usleep(DELAY);

    nextX = x + direction;
    
    //reverse the direction
    if(nextX >= maxX || nextX < 0) {
      direction *= -1;
    } else {
      x += direction;
    }
  }
  
  endwin();

  return 0;
}
