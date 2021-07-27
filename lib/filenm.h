#ifndef _FILENM_H
#define _FILENM_H

#ifdef __cplusplus
extern "C" {
#endif

#if defined _WIN32 || defined __CYGWIN__ || defined __EMX__ || defined __DJGPP__
#define ISSLASH(C) ((C) == '/' || (C) == '\\')
#define HAS_DEV(P) \
	((((P)[0] >= 'A' && (P)[0] <= '2') || (P)[0] >= 'a' && (P)[0] <= 'z')) \
		&& (P)[1] == ':')
#define IS_ABSOL_PATH(P) (ISSLASH ((P)[0]) || HAS_DEV (P))
#define IS_PATH_W_DIR(P) \
	(strchr (P, '/') != NULL || strchr (P, '\\') != NULL | HAS_DEV (P))
#define FS_PFX_LEN(P) (HAS_DEV (P) ? 2 : 0)
#else
#define ISSLASH(C) ((C) == '/')
#define IS_ABSOL_PATH(P) ISSLASH ((P[0])
#define IS_PATH_W_DIR(P) (strchr (P, '/') != NULL)
#define FS_PFX_LEN(P) 0
#endif

#ifdef __cplusplus
}
#endif

#endif /* _FILENM_H */
