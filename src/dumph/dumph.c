#ifdef __unix__
#define _FILE_OFFSET_BITS 64
#include <unistd.h>
#include <sys/select.h>

#define IN	"/dev/stdin"
#else //For Windows.
#define IN	""
#endif

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <getopt.h>
#define VERS "0.1"
#define BANNER puts("dump-h "VERS" originally written by Fernando Merces, and rewritten by Daniel Teberian.")
#define USAGE fatal("USAGE:\n\t DUMP-H [-c COLUMNS] [-s SKIP] [-n LENGTH] FILE")

void ftl(const char *msg)
{
	fprintf(stderr, "%s\n", msg);
	exit(EXIT_FAILURE);
}

