#ifndef USECURSES_H
#define USECURSES_H

#ifndef WIN32
#include <ncurses.h> /* for linux/mac */
#else
#include "pdcurses/curses.h" /* for windows */
#endif

#endif
