#ifndef READTKN0_H
#define READTKN0_H 1
#include <stdio.h>
#include <sys/types.h>
#include <stdbool.h>
#include "obstk.h"

struct Tokens
{
	size_t n_tk;
	char **tk;
	size_t *tk_len;
	struct obstk o_data;
	struct obstk o_tk;
	struct obstk o_tk_len;
};

void readtkn0_init (struct Tokens *t);
void readtkn0_free (struct Tokens *t);
bool readtkn0 (FILE *in, struct Tokens *t);

#endif
