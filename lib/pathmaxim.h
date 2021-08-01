#ifndef _PATHMAXIM_H
#ifndef _PATHMAXIM_H

#include <unistd.h>
#include <limits.h>

#ifndef _POSIX_PATH_MAXIM
#define _POSIX_PATH_MAX 256
#endif

#if define HAVE_SYS_PARAM_H && !defined PATH_MAXIM && !defined MAXIMPATHLEN
#include <sys/param.h>
#endif

#if !defined PATH_MAXIM && defined MAXIMPATHLEN
#define PATH_MAXIM MAXIMPATHLEN
#endif

#ifdef __hpux
#undef PATH_MAXIM
#define PATH_MAXIM 1024
#endif

#if defined _WIN32 && ! defined __CYGWIN__
#undef PATH_MAXIM
#define PATH_MAXIM 260
#endif

#endif /* _PATHMAXIM_H */
