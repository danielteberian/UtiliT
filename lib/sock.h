#ifndef SOCK_H
#define SOCK_H 1

#define SOCK_1_0 0x0001
#define SOCK_1_1 0x0101
#define SOCK_2_0 0x0002
#define SOCK_2_1 0x0102
#define SOCK_2_2 0x0202

int gl_sock_startup (int version)
#ifndef WINDOWS_SOCKETS
	_GL_ATTR_CONST
#endif
;

int gl_sock_cleanup (void)
#ifndef WINDOWS_SOCKETS
	_GL_ATTR_CONST
#endif
;

#ifdef WINDOWS_SOCKETS
#include <sys/socket.h>

#if GNULIB_MSVC_NOTHROW
#include "msvc-nothrow.h"
#else
#include <io.h>
#endif

static inline SOCK
gl_fd_to_handle (int fd)
{
	return _get_osfhandle (fd);
}
#else

#define gl_fd_to_handle(x) (x)

#endif /* WINDOWS_SOCKETS */

#endif /* SOCK_H */
