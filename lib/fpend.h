#include <stddef.h>
#include <stdio.h>
#if HAVE_STDIO_EXT_H
#include <stdio_ext.h>
#endif

#if !HAVE_DECL__FPENDING
size_t __fpending (FILE *) _GL_ATTR_PURE;
#endif
