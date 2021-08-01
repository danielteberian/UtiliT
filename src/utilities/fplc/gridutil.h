#ifndef GRIDUTIL_H
#define GRIDUTIL_H

#ifndef CELLTP
#error CELLTP cannot be used unless it has been defined in gridutil.h
#endif

#include <stdlib.h>

#define MINIM(X, Y)	((X) < (Y) ? (X) : (Y))
#define MAXIM(X, Y)	((X) > (Y) ? (X) : (Y))
#define CLAMP(X, A, B) (MAXIM((A), MINIM((X), (B))))
#define IDX(GRID, R, C) ((GRID->data)[(R) * (GRID->cols) + (C)])

typedef struct cagrid
{
	CELLTP* data;
	int rows, cols;
} cagrid;

cagrid* grid_new(size_t rows, size_t cols)
{
	cagrid* out = malloc(sizeof(cagrid));
	out->data = calloc(rows * cols, sizeof(CELLTP));
	out->rows = rows;
	out->cols = cols;
	return out;
}

void grid_free(cagrid* grid)
{
	free(grid->data);
	free(grid);
}

void grid_copy(cagrid* dest, cagrid* src, const size_t rows, const size_t cols)
{
	for(size_t i = 0; i < rows; i++)
	{
		for(size_t j = 0; j < cols; j++)
		{
			IDX(dest, i, j) = IDX(src, i, j);
		}
	}
}

void grid_resize_custom(cagrid** grid, size_t r_old, size_t c_old, size_t r_new, size_t c_new,
	void (*copyfunc)(cagrid*, cagrid*, const size_t, const size_t) )
{
	cagrid* resized = grid_new(r_new, c_new);
	size_t row_cplim = MINIM(r_old, r_new);
	size_t col_cplim = MINIM(c_old, c_new);
	copyfunc(resized, *grid, row_cplim, col_cplim);
	grid_free(*grid);
	*grid = resized;
}

void grid_resize(cagrid** grid, size_t r_old, size_t c_old, size_t r_new, size_t c_new)
{
	grid_resize_custom(grid, r_old, c_old, r_new, c_new, &grid_copy);
}

#endif /* GRIDUTIL_H */
