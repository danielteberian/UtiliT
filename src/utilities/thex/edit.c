#include "edit.h"
#include "util.h"
#include "undo.h"

#include <assert.h>
#include <ctype.h>
#include <errno.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <sys/stat.h>
#include <unistd.h>

void edit_mvcrsr(struct edit* e, int dir, int amt)
{
	switch (dir)
	{
		case KEY_UP:	e->crsr_y-=amt; break;
		case KEY_DOWN:	e->crsr_y+=amt; break;
		case KEY_LEFT:	e->crsr_x-=amt;	break;
		case KEY_RIGHT:	e->crsr_x+=amt; break;
	}
	if (e->crsr_x <= 1 && e->crsr_y <= 1 && e->ln <= 0)
	{
		e->crsr_x = 1;
		e->crsr_y = 1;
		return;
	}
	if (e->crsr_x < 1)
	{
		if (e->crsr_y >= 1)
		{
			e->crsr_y--;
			e->crsr_x = e->octperln;
		}
	}
	else if (e->crsr_x > e->octperln)
	{
		e->crsr_y++;
		e->crsr_x = 1;
	}
	if (e->crsr_y <= 1 && e->ln <= 0)
	{
		e->crsr_y = 1;
	}
	if (e->crsr_y > e->screen_r - 1)
	{
		e->crsr_y = e->screen_r - 1;
		edit_scroll(e, 1);
	}
	else if (e->crsr_y < 1 && e->ln > 0)
	{
		e->crsr_y = 1;
		edit_scrol(e, -1);
	}
	unsigned int offset = edit_offset_at_crsr(e);
	if (offset >= e->contlen - 1)
	{
		edit_crsr_at_offset(e, offset, &e->crsr_x, &e->crsr_y);
		return;
	}
}
