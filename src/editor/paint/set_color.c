#include"paint.h"

/*
// time : O(1)
// space: O(1)
void	copy_gradient(t_gradient *src, t_gradient *dst)
{
	dst->r1 = src->r1;
	dst->g1 = src->g1;
	dst->b1 = src->b1;
	dst->a1 = src->a1;
	dst->x1 = src->x1;
	dst->r2 = src->r2;
	dst->g2 = src->g2;
	dst->b2 = src->b2;
	dst->a2 = src->a2;
	dst->x2 = src->x2;
}
*/

// https://youtu.be/094y1Z2wpJg?si=78avHdrzF7oMT31w
// time : "might be" O(log(n))
// space: O(1)
e_bool	collatz_coloring(size_t row, size_t col, t_table_fdf *dst)
{
	size_t	j;
	size_t	i;

	if (dst == NULL || row >= dst->row || col >= dst->col)
		return (FALSE);
	j = 0;
	i = f_max((float)row,
			(float)(dst->row - row)) * f_max((float)col,
			(float)(dst->col - col));
	while (i > 1 && j < 10000)
	{
		if (i % 2 == 0)
			i /= 2;
		else
			i = 3 * i + 1;
		j += 1;
	}
	if (j % 2 == 0)
		return (FALSE);
	return (TRUE);
}

// time : O(1)
// space: O(1)
e_bool	is_colored_cell(size_t row, size_t col, t_table_fdf *dst)
{
	if (dst == NULL || row >= dst->row || col >= dst->col)
		return (FALSE);
	if (dst->r != NULL && dst->r[row] != NULL && dst->r[row][col] > 0)
		return (TRUE);
	if (dst->g != NULL && dst->g[row] != NULL && dst->g[row][col] > 0)
		return (TRUE);
	if (dst->b != NULL && dst->b[row] != NULL && dst->b[row][col] > 0)
		return (TRUE);
	if (dst->a != NULL && dst->a[row] != NULL && dst->a[row][col] > 0)
		return (TRUE);
	return (FALSE);
}

// r = (int)f_max((float)row, (float)dst->row - row);
// c = (int)f_max((float)col, (float)dst->col - col);

// I will debugging it later, such that it will looks more similar to
// Wolfarm Math website illustration than Ladder.

// https://mathworld.wolfram.com/GaussianPrime.html
// time : O(n log(log(n)))
// space: O(n)
e_bool	gaussian_prime(size_t row, size_t col, t_table_fdf *dst)
{
	int	r;
	int	c;

	if (row >= dst->row || col >= dst->col)
		return (FALSE);
	r = (int)row - (int)(dst->row / 2);
	c = (int)col - (int)(dst->col / 2);
	if (r == 0 && c == 0)
		return (FALSE);
	if (r != 0 && c != 0 && is_prime((size_t)(r * r + c * c)) == 1)
		return (TRUE);
	if (c == 0 && is_prime((size_t)r) == 1 && r % 4 == 3)
		return (TRUE);
	if (r == 0 && is_prime((size_t)c) == 1 && c % 4 == 3)
		return (TRUE);
	return (FALSE);
}

// time : O(1)
// space: O(1)
e_bool	imaginary_square(size_t row, size_t col, t_table_fdf *dst)
{
	int	r;
	int	c;

	if (dst == NULL || row >= dst->row || col >= dst->col)
		return (FALSE);
	r = (int)row;
	c = (int)col;
	if (((r * r / 4 - c * c / 4) % 2 == 0 && (r * c / 2) % 2 == 1)
		|| ((r * r / 4 - c * c / 4) % 2 == 1 && (r * c / 2) % 2 == 0))
		return (TRUE);
	return (FALSE);
}

// time : O(n)
// space: O(1)
void	set_color_every_cells(
	t_table_fdf *dst,
	e_rgba rgb_type,
	unsigned char new_rgb,
	e_bool(*is_color_target)(size_t row, size_t col, t_table_fdf *dst))
{
	size_t	i;
	size_t	j;

	i = 0;
	while (dst != NULL && i < dst->row)
	{
		j = 0;
		while (j < dst->col)
		{
			if (dst->r != NULL && dst->r[i] != NULL
				&& is_color_target(i, j, dst) == TRUE && rgb_type == RED)
				dst->r[i][j] = new_rgb;
			if (dst->g != NULL && dst->g[i] != NULL
				&& is_color_target(i, j, dst) == TRUE && rgb_type == GREEN)
				dst->g[i][j] = new_rgb;
			if (dst->b != NULL && dst->b[i] != NULL
				&& is_color_target(i, j, dst) == TRUE && rgb_type == BLUE)
				dst->b[i][j] = new_rgb;
			if (dst->a != NULL && dst->a[i] != NULL
				&& is_color_target(i, j, dst) == TRUE && rgb_type == ALPHA)
				dst->a[i][j] = new_rgb;
			j += 1;
		}
		i += 1;
	}
}

/*
typedef enum e_bool e_bool;

enum e_bool
{
	FALSE,
	TRUE
};

typedef enum e_rgba e_rgba;

enum e_rgba
{
	RED,
	GREEN,
	BLUE,
	ALPHA
};
*/