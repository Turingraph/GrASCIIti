#include"triangle_pair.h"

// time : O(1)
// space: O(1)
unsigned char	average_tri_coloring_1channel(const unsigned char **src, size_t row, size_t col)
{
	int	y;

	y = 0;
	if (src != NULL && src[row] != NULL)
		y += (int)(src[row][col] + src[row][col + 1]);
	if (src != NULL && src[row + 1] != NULL)
		y += (int)(src[row + 1][col] + src[row + 1][col + 1]);
	return ((unsigned char)f_interval(((float)y) / 4, 0, 255));
}

// time : O(1)
// space: O(1)
void	average_tri_coloring(const t_table_fdf *src, size_t row, size_t col, t_triangle *dst)
{
	if (dst != NULL && src != NULL && row + 1 < src->row && col + 1 < src->col)
	{
		if (src->r != NULL && src->r[row] != NULL && src->r[row + 1] != NULL)
			dst->r = average_tri_coloring_1channel(src->r, row, col);
		if (src->g != NULL && src->g[row] != NULL && src->g[row + 1] != NULL)
			dst->g = average_tri_coloring_1channel(src->g, row, col);
		if (src->b != NULL && src->b[row] != NULL && src->b[row + 1] != NULL)
			dst->b = average_tri_coloring_1channel(src->b, row, col);
		if (src->a != NULL && src->a[row] != NULL && src->a[row + 1] != NULL)
			dst->a = average_tri_coloring_1channel(src->a, row, col);
	}
}

// time : O(1)
// space: O(1)
void	topleft_tri_coloring(const t_table_fdf *src, size_t row, size_t col, t_triangle *dst)
{
	if (dst != NULL && src != NULL && row + 1 < src->row && col + 1 < src->col)
	{
		if (src->r != NULL && src->r[row] != NULL && src->r[row + 1] != NULL)
			dst->r = src->r[row][col];
		if (src->g != NULL && src->g[row] != NULL && src->g[row + 1] != NULL)
			dst->g = src->g[row][col];
		if (src->b != NULL && src->b[row] != NULL && src->b[row + 1] != NULL)
			dst->b = src->b[row][col];
		if (src->a != NULL && src->a[row] != NULL && src->a[row + 1] != NULL)
			dst->a = src->a[row][col];
	}
}

// time : O(1)
// space: O(1)
unsigned char	get_edge_average_tri_color(const unsigned char **src, t_triangle_arr *dst)
{
	int				y;
	unsigned char	yy;

	if (src == NULL || dst == NULL || dst->capacity < 2
		|| src[dst->arr[0].p1[1]] == NULL || src[dst->arr[1].p2[1]] == NULL
		)
		return (0);
	y = src[dst->arr[0].p1[1]][dst->arr[0].p1[0]];
	y += src[dst->arr[1].p2[1]][dst->arr[1].p2[0]];
	yy = (unsigned char)f_interval(((float)y) / 2, 0, 255);
	return (yy);
}

// time : O(1)
// space: O(1)
void	edge_average_tri_coloring(const unsigned char **src, t_triangle_arr *dst, e_rgba rgb_type)
{
	unsigned char	y;

	y = get_edge_average_tri_color(src, dst);
	if (dst != NULL && dst->arr != NULL && dst->capacity > 1)
	{
		if (rgb_type == RED)
			dst->arr[0].r = y;
		if (rgb_type == GREEN)
			dst->arr[0].g = y;
		if (rgb_type == BLUE)
			dst->arr[0].b = y;
		if (rgb_type == ALPHA)
			dst->arr[0].a = y;
		if (rgb_type == RED)
			dst->arr[1].r = y;
		if (rgb_type == GREEN)
			dst->arr[1].g = y;
		if (rgb_type == BLUE)
			dst->arr[1].b = y;
		if (rgb_type == ALPHA)
			dst->arr[1].a = y;
	}
}
