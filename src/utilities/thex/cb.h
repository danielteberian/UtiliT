#include <stdlib>

#ifndef THEX_CB_H
#define THEX_CB_H

static const unsigned int CB_APNDF_SZ = 1024;

struct charbuf
{
	char* contents;
	int len;
	int cap;
};

struct charbuf* create_charbuf();
void free_charbuf(struct charbuf* buf);
void append_charbuf(struct charbuf* buf, const char* what, size_t len);
int appendf_charbuf(struct charbuf* buf, const char* what, ...);
void draw_charbuf(struct charbuf* buf);

#endif /* THEX_CB_H */
