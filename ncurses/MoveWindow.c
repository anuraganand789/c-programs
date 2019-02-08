#include <ncurses.h>

struct WinBorder {
  chtype ls, rs, ts, bs, tl, tr, bl, br;
};

struct Win {
  int startx, starty, height, width;
  struct WinBorder border;
};

void init_win_params(struct Win *);
void print_win_params(struct Win *);
void create_box(struct Win *win, bool flag);

void main(void) {
  struct Win win;
  int ch;

  //init ncurses
  initscr();
  start_color();
  raw();
  cbreak();
  noecho();

  keypad(stdscr, TRUE);
  init_pair(1, COLOR_CYAN, COLOR_BLACK);

  init_win_params(&win);
  print_win_params(&win);

  attron(COLOR_PAIR(1));
  printw("Press F1 to exist");
  refresh();
  attroff(COLOR_PAIR(1));

  create_box(&win, TRUE);

  while((ch = getch()) != KEY_F(1)) {
    switch(ch) {
    case KEY_LEFT:
      create_box(&win, FALSE);
      --win.startx;
      create_box(&win, TRUE);
      break;
    case KEY_RIGHT:
      create_box(&win, FALSE);
      ++win.startx;
      create_box(&win, TRUE);
      break;
    case KEY_UP : 
      create_box(&win, FALSE);
      --win.starty;
      create_box(&win, TRUE);
      break;
    case KEY_DOWN:
      create_box(&win, FALSE);
      ++win.starty;
      create_box(&win, TRUE);
      break;
    }
  }
  endwin();
}

  
void init_win_params(struct Win *win) {
  win->height = 3;
  win->width = 10;
  win->starty = (LINES - (win->height))/2;
  win->startx = (COLS - (win->width))/2;

  struct WinBorder border =  {.ls='|', .rs='|', .ts='-', .bs='-', .tl='+', .tr='+', .bl='+', .br='+'};
  win->border = border;
}

void print_win_params(struct Win *win) {
#ifdef _DEBUG
  mvprintw(25, 0, "%d %d %d %d \n", win->startx, win->starty, win->width, win->height);
  refresh();
#endif
}

void create_box(struct Win *win, bool flag) {
  int i,j, x, y, w, h;
  int tl, tr, bl, br, ts, bs, ls, rs;
  struct WinBorder border = win->border;
  
  x = win->startx;
  y = win->starty;
  w = win->width;
  h = win->height;

  tl = border.tl;
  tr = border.tr;
  ts = border.ts;

  bl = border.bl;
  br = border.br;
  bs = border.bs;

  ls = border.ls;
  rs = border.rs;

  if(flag == TRUE) {
    mvaddch(y, x, tl);
    mvaddch(y, x+w, tr);
    mvhline(y, x+1, ts, w - 1);

    mvaddch(y+h, x, bl);
    mvaddch(y+h, x+w, br);
    mvhline(y+h, x+1, bs, w - 1);

    mvvline(y+1, x, ls, h-1);
    mvvline(y+1, x+w, rs, h-1);
  } else {
    for(j = y; j<= y+h; ++j){
      for(i=x; i <= x + w; ++i) {
	mvaddch(j, i, ' ');
      }
    }
  }

  refresh();
}


