#include <stdbool.h>
#include "fts.h"

FTS *
xfts_open (char * const *, int opts,
		int (*) (const FTSENT **, const FTSENT **));
bool

cycle_warn_req (FTS const *fts, FTSENT const *ent)
	_GL_ATTR_PURE;
