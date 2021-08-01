#if !defined FSUSG_H
#define FSUSG_H

#include <stdint.h>
#include <stdbool.h>

struct fsusg
{
	uintmax_t fsu_blksize;
	uintmax_t fsu_blk;
	uintmax_t fsu_bfree;
	uintmax_t fsu_bavail;
	bool fsu_bavail_top_bit_set;
	uintmax_t fsu_files;
	uintmax_t fsu_ffree;
};

int getfsusg (char const *file, char const *disk, struct fsusg *fsp);

#endif
