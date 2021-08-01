#ifndef READTKN_H
#define READTKN_H

#include <stdio.h>

struct tknbuf
{
	size_t size;
	char *buf;
};

typedef struct tknbuf tkn_buf;

void tknbuf_init (tkn_buf *tknbuf);

size_t
	readtkn (FILE *stream, const char *delim, size_t n_delim,
		tkn_buf *tknbuf;

size_t
	readtkns (FILE *stream, size_t proj_n_tkn,
	const char *delim, size_t n_delim,
	char ***tkn_out, size_t **tkn_len);

#endif /* READTKN_H */
