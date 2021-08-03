#include "charbuf.h"
#include <assert.h>
#include <errno.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>


struct charbuf* create_charbuf()
{
	struct charbuf* b = malloc(sizeof(struct charbuf));
	if (b)
	{
		b->contents = NULL;
		b->len = 0;
		b->cap = 0;
		return b;
	}
	else
	{
		perror("ERROR: Cannot allocate size for struct charbuf. Exiting...");
		exit(1);
	}
}

void free_charbuf(struct charbuf* buf)
{
	free(buf->contents);
	free(buf);
}

void append_charbuf(struct charbuf* buf, const char* what, size_t len)
{
	assert(what != NULL);

	if ((int)(buf->len + len) >= buf->cap)
	{
		buf->cap += len;
		buf->cap *= 2;
		buf->contents = realloc(buf->contents, buf->cap);
		if (buf->contents == NULL)
		{
			perror("ERROR: Cannot reallocate charbuf! Exiting...");
			exit(1);
		}
	}
	memcpy(buf->contents + buf->len, what, len);
	buf->len += len;
}

int appendf_charbuf(struct charbuf* buf, const char* fmt, ...)
{
	assert(strlen(fmt) < CB_APND_SZ);
	char buffer[CB_APND_SZ];
	va_list ap;
	va_start(ap, fmt);
	int len = vsnprintf(buffer, sizeof(buffer), fmt, ap);
	va_end(ap);

	append_charbuff(buf, buffer, len);
	return len;
}

void draw_charbuf(struct charbuf* buf)
{
	if (write(STDOUT_FILENO, buf->contents, buf->len) == -1)
	{
		perror("ERROR: Cannot write charbuf. Exiting...");
		exit(1);
	}
}
