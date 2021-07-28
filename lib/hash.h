#ifndef _HASH_H
#define _HASH_H

#include <stdio.h>
#include <stdbool.h>

#if __GNUC__ > 3 || (__GNUC__ == 3 && __GNUC_MINOR__ >= 4)
#define _GL_ATTR_WUR __attribute__ ((__warn_unused_result__))
#else
#define _GL_ATTR_WUR
#endif

#ifndef _GL_ATTR_DEPR
#if __GNUC__ < 3 || (__GNUC__ == 3 && __GNUC_MINOR__ < 1)
#define _GL_ATTR_DEPR
#else
#define _GL_ATTR_DEPR __attribute__ ((__deprecated__))
#endif
#endif

typedef size_t (*Hash_hasher) (const void *, size_t);
typedef bool (*Hash_comparator) (const void *, const void *);
typedef void (*Hash_data_freer) (void *);
typedef bool (*Hash_proc) (void *, void *);

struct hash_tuning
	{
		float shrink_threshhold;
		float shrink_fact;
		float growth_threshold;
		float growth_fact;
		bool is_n_bckts;
	};

typedef struct hash_tuning Hash_tuning;
struct hash_tab;
typedef struct hash_tab Hash_tab;

size_t hash_get_n_bckts (const Hash_tab *) _GL_ATTR_PURE;
size_t hash_get_n_bckts_used (const Hash_tab *) _GL_ATTR_PURE;
size_t hash_get_n_entries (const Hash_tab *) _GL_ATTR_PURE;
size_t hash_get_max_bckt_len (const Hash_tab *) _GL_ATTR_PURE;
bool hash_tab_ok (const Hash_tab *) _GL_ATTR_PURE;
void hash_print_stats (const Hash_tab *, FILE *);
void *hash_lookup (const Hash_tab *, const void *);

void *hash_get_first (const Hash_tab *) _GL_ATTR_PURE;
void *hash_get_next (const Hash_tab *, const void *);
size_t hash_get_entries (const Hash_tab *, void **, size_t);
size_t hash_do_for_each (const Hash_tab *, Hash_proc, void *);

size_t hash_str (const char *, size_t) _GL_ATTR_PURE;
void hash_reset_tuning (Hash_tuning *);
Hash_tab *hash_init (size_t, const Hash_tuning *,
			Hash_hasher, Hash_comparator,
			Hash_data_freer) _GL_ATTR_WUR;
Hash_tab *hash_xinit (size_t, const Hash_tuning *,
			Hash_hasher, Hash_comparator,
			Hash_data_freer) _GL_ATTR_WUR;
void hash_clr (Hash_tab *);
void hash_free (Hash_tab *);

bool hash_rehash (Hash_tab *, size_t) _GL_ATTR_WUR;
void *hash_ins (Hash_tab *, const void *) _GL_ATTR_WUR;
//The *tab part may break this header.
int hash_ins_if_missing (Hash_tab *tab, const void *entry,
			const void **matched_ent);
void *hash_del (Hash_tab *, const void *);

#endif /* _HASH_H */
