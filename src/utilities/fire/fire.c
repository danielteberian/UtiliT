#include <ncurses.h>
#include <signal.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#ifdef _WIN32
#include <windows.h>
#endif

#define CELLTP int
#include "gridutil.h"

static int PALETTESIZE;
static int WIDTH, HEIGHT;
static int hrec=0;
static volatile sig_atomic_t sig_caught = 0;

typedef struct cvalstruct{ short r,g,b; } cval;

void flipgrid(ca_grid
