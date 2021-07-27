#ifndef _GL_DIRSAVE_H
#define _GL_DIRSAVE_H

#include <dirent.h>

enum dirsave_opt
{
	DIRSAVE_SORT_NM,
	DIRSAVE_SORT_NM,
#if D_INO_IN_DIRENT
	DIRSAVE_SORT_INODE,
	DIRSAVE_SORT_FASTRD = DIRSAVE_SORT_INODE
#else
	DIRSAVE_SORT_FASTRD = DIRSAVE_SORT_NULL
#endif
};

char *streamdirsave (DIR *, enum dirsave_opt);
char *dirsave (char const *, enum dirsave_opt);

#endif
