#ifndef _LONG_OPTS_H
#define _LONG_OPTS_H 1

#include <stdbool.h>

void parse_long_opts (int _argc,
			char **_argv,
			const char *_cmd_name,
			const char *_pkg,
			const char *_vers,
			void (*_usage) (int),
			...);

void parse_gnu_std_opts_only (int argc,
				char **argv,
				const char *cmd_name,
				const char *pkg,
				const char *vers,
				bool scan_all,
				void (*usage_func) (int)
				...);

#endif /* _LONG_OPTS_H */
