#ifdef __unix__
#define _FILE_OFFSET_BITS 64
#include <unistd.h>
#include <sys/select.h>

#define IN	"/dev/stdin"
#else
#define IN	""
#endif /* __unix__ */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include <ctype.h>
#include <getopt.h>

#define VERS "0.1"
#define BANNER puts("dumph "VERS" ")
#define USAGE fatal("Usage:\n\dumph [-c COLUMNS] [-s SKIP] [-n LENGTH] FILE")

void fatal(const char *msg)
{
	fprintf(stderr, "%s\n", msg);
	exit(EXIT_FAILURE);
}

bool available_in(void)
{
#ifdef __unix__
	FILE * in;
	bool available;
	struct timeval tv;
	fd_set fds;
	tv.tv_sec = 0;
	tv.tv_usec = 0;

	if (!(in = fopen ("/dev/stdin", "rb")))
		fatal ("CHECKING STD INPUT");

	FD_ZERO (&fds);
	FD_SET (fileno (in), &fds);
	select ((fileno (in) + 1), &fds, NULL, NULL, &tv);
	available = FD_ISSET (fileno (in), &fds);

	fclose (in);

	return available;
#else
	return false;
#endif /* __unix__ */
}

int get_spc(int bread, int cols)
{
	int spc = 0;
	if (bread < cols)
	{
		spc = cols*3 - bread*3 + 1;
		if (bread < (cols/2))
			spc += 1;
	}
	return spc;
}

int main(int argc, char *argv[])
{
	FILE *file = NULL;
	unsigned char *buff, *ascii;
	register unsigned int i;
	size_t cols;
	unsigned long int bread, sk, len, adrs;
	int c;
	bool in = false;

	bread = sk = len = adrs = cols = 0;

	in = available_in();
	if (argc < 2)
	{
		if(!in)
			USAGE;
	}
	if(!in && (strstr (argv [argc-2], "-")))
		USAGE;

	while ((c = getopt (argc, argv, "c:s:n:vh")) != -1)
	{
		switch(c)
		{
			case 'c':
				cols = (size_t) strtoul(optarg, NULL, 0); break;
			case 's':
				sk = (long) strtoul(optarg, NULL, 0); break;
			case 'n':
				len = strtoul(optarg, NULL, 0); break;
			case 'v':
				BANNER; exit(0);
			case 'h':
				USAGE;
			default:
				USAGE;
		}
	}
	if(!cols)
		cols = 16;

	if(!(file = fopen ((in ? IN : argv[argc-1]), "rb")))
		fatal("ERROR: FILE NOT FOUND/FILE UNREADABLE.");

	if(!in)
	{
		fseek (file, 0, SEEK_END);
		if(!ftell (file))
		{
			fatal("ERROR: SPECIFIED FILE IS EMPTY.");
		}
		rewind(file);
	}

	for ( ;sk > 0; sk --)
	{
		if(fgetc (file) == EOF)
			fatal("ERROR: SKIPPING TOO FREQUENTLY.");
	}

	buff = (unsigned char *) calloc (1, sizeof(unsigned char) * cols);
	ascii = (unsigned char *) calloc (1, (sizeof(unsigned char) * cols) + 1);

	if(!buff || !ascii)
		fatal("ERROR: MEMORY SHORTAGE.");
	do
	{
		bread = (int) fread(buff, sizeof(char), cols, file);

		for(i=0; i<bread; i++)
		{
			if(!i)
				printf("%08lx  ", i+adrs+sk);
			*(ascii+i) = isprint(*(buff+i)) ? *(buff+i) : '.';
			printf("%02x%*c", (unsigned int) *(buff+i), (i+1 == cols/2) ? 2 : 1, ' ');
			*(ascii+bread) = '\0';

			if(i == bread-1)
				printf("%*c|%s|\n", get_spc(bread, cols), ' ', ascii);
		}
		adrs += bread;
		if(len && (adrs >= len))
			break;
	}
	while (bread);

	free(buff);
	free(ascii);
	free(file);
	return 0;
}
