#ifndef THEXEDIT_H
#define THEXEDIT_H
#include "cb.h"
#include <stdbool.h>

enum edit_md
{
	MD_APPEND	= 1 << 0,
	MD_APPEND_ASCII = 1 << 1,
	MD_REPL_ASCII	= 1 << 2,
	MD_NORM		= 1 << 3,
	MD_INS		= 1 << 4,
	MD_INS_ASCII	= 1 << 5,
	MD_REPL		= 1 << 6,
	MD_CMD		= 1 << 7,
	MD_SEARCH	= 1 << 8,
};

enum searchdir
{
	SEARCHFWD,
	SEARCHBWD,
};

enum statsev
{
	STATINFO,
	STATWARN,
	STATERR,
};

#define INBUFSIZE 80

struct edit
{
	int octperlin;
	int grping;
	int ln;
	int crsr_x;
	int crsr_y;
	int scr_r;
	int scr_c;

	enum edit_md md;

	bool	dirt;
	char*	filenm;
	char*	cont;
	unsigned int contlen;

	enum statsev statsev;
	char	statmsg[120];

	char inbuf[INBUFSIZE];
	int inbuff_idx;
	char searchstr[INBUFSIZE];
	struct actls* undols;
};

struct edit* init_edit();


