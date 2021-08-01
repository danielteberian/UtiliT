#ifndef _PRGNAME_H
#define _PRGNAME_H

#ifdef __cplusplus
extern "C" {
#endif


extern const char *prog_name;

extern void prog_name_set (const char *argv0);

#if ENABLE_RELOCATABLE
extern void prog_name_and_installdir_set (const char *argv0,
					  const char *orig_installpfx,
					  const char *orig_installdir);

#undef prog_name_set
#define prog_name_set(ARG0) \
	prog_name_and_installdir_set (ARG0, INSTALLPREFIX, INSTALLDIR)

extern char *get_prog_name (void);
#endif
#ifdef __cplusplus
}
#endif

#endif /* _PRGNAME_H */
