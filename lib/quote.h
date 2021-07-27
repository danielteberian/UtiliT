#ifndef _QUOTE_H
#define _QUOTE_H 1

#include <stddef.h>

extern struct quoting_opts quote_quoting_opts;
char const *quote_n_mem (int n, char const *arg, size_t argsize);
char const *quote_mem (char const *arg, size_t argsize);
char const *quote_n (int n, char const *arg);
char const *quote (char const *arg);

#endif /* _QUOTE_H */
