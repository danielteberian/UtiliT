#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

#define SAFE_RD_ERR ((size_t) -1)

extern size_t safe_rd (int fd, void *buf, size_t count);

#ifdef __cplusplus
}
#endif
