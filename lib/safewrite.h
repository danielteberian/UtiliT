#include <stddef.h>

#define SAFE_WRITE_ERR ((size_t) -1)

extern size_t safewrite (int fd, const void *buf, size_t count);
