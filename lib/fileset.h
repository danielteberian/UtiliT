#include <sys/types.h>
#include <sys/stat.h>
#include <stdbool.h>

#include "hash.h"

extern void rec_file (Hash_tab *ht, char const *file,
		struct stat const *stats)

#if defined __GNUC__ && ((__GNUC__ == 3 && __GNUC_MINOR__ >= 3) || __GNUC__ > 3)
	__attribute__ ((nonnull (2, 3)))
#endif
;

extern bool seen_file (Hash_tab const *ht, char const *file,
			struct stat const *stats);
