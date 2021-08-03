#ifndef _SYSMON_H
#define _SYSMON_H
#include "def.h"
#include "tp.h"
#include "cursestl.h"
#include "opt.h"
#include "out.h"
#include "in/ret.h"
#include "assist.h"

#ifdef WIN32
#include <windows.h>
#endif

#ifdef __STDC__
#include <stdarg.h>
void dinit(int code, const char *errmsg, ...) FUNCATTR_NORET;
#else

#include <varargs.h>
void dinit(int code, ...) FUNCATTR_NORET;
#endif

#endif /* _SYSMON_H */
