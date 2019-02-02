#include <ncurses.h>

void main() {

  int ch;

  initscr();
  raw();
  keypad(stdscr, TRUE);
  noecho();

  printw("Type charachter ... \n");

  ch = getch();

  if(ch == KEY_F(1)) {
    printw("F1 Key is pressed ... Loser .");
  } else {
    printw("The pressed key is -> ");
    attron(A_BOLD);
    printw("%c \n", ch);
    attroff(A_BOLD);
  }

  refresh();
  getch();
  endwin();
  
}
