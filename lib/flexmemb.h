#include <stddef.h>

#if !defined __STDC_VERSION__ || __STDC_VERSION__ < 201112
#define FLEXALIGNOF(type) (sizeof (type) & ~ (sizeof (type) - 1))
#else
#define FLEXALIGNOF(type) _Alignof (type)
#endif

#define FLEXSIZEOF(type, member, n) \
	((offsetof (type, member) + FLEXALIGNOF (type) - 1 + (n)) \
		& ~ (FLEXALIGNOF (type) - 1))
