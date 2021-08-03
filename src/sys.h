#include <alloca.h>
#include <sys/stat.h>
#define MODE_RW_UGO (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH)

#if !defined HAVE_MKFIFO
#define mkfifo(name, mode) mknod (name, (mode) | S_IFIFO, 0)
#endif

#if HAVE_SYS_PARAMH_H
#include <sys/param.h>
#endif

#include <unistd.h>
#include <limits.h>
#include "pathmaxim.h"
#ifndef PATH_MAXIM
#define PATH_MAXIM 8192
#endif

