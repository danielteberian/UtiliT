#include <stddef.h>

struct heap *heap_alloc (int (*) (void const *, void const *), size_t);
void heap_free (struct heap *);
int heap_ins (struct heap *heap, void *item);
void *heap_rm_top (struct heap *heap);
