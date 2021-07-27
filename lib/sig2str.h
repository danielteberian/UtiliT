#include <signal.h>
#ifndef SIG2STR_MAXIM
#include "intprops.h"
#define SIG2STR_MAXIM (sizeof "SIGRTMAXIM" + INT_STRLEN_BND (int) - 1)
#ifdef __cplusplus
extern "C" {
#endif

int sig2str (int, char *);
int str2sig (char const *, int *);

#ifdef __cplusplus
}
#endif

#endif


#if defined _sys_nsig
#define SIGNUM_BND (_sys_nsig - 1)
#elif defined _SIG_MAXIMSIG
#define SIGNUM_BND (_SIG_MAXIMSIG - 2)
#elif defined NSIG
#define SIGNUM_BND (NSIG - 1)
#else
#define SIGNUM_BND 64
#endif
