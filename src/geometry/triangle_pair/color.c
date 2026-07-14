#include"triangle_pair.h"

// time : O(1)
// space: O(1)
void	average_tri_coloring(const t_table_fdf *src, size_t index, t_triangle *dst)
{
	int	y;

	if (dst != NULL && src != NULL && index < (src->col - 1) * (src->row - 1))
	{
		y = 0;
		if (src->r != NULL)
			y = (int)(src->r[index] + src->r[index + 1] + src->r[index + src->col] + src->r[index + src->col + 1]);
		dst->r = (unsigned char)f_interval(((float)y) / 4, 0, 255);
		y = 0;
		if (src->g != NULL)
			y = (int)(src->g[index] + src->g[index + 1] + src->g[index + src->col] + src->g[index + src->col + 1]);
		dst->g = (unsigned char)f_interval(((float)y) / 4, 0, 255);
		y = 0;
		if (src->b != NULL)
			y = (int)(src->b[index] + src->b[index + 1] + src->b[index + src->col] + src->b[index + src->col + 1]);
		dst->b = (unsigned char)f_interval(((float)y) / 4, 0, 255);
		y = 0;
		if (src->a != NULL)
			y = (int)(src->a[index] + src->a[index + 1] + src->a[index + src->col] + src->a[index + src->col + 1]);
		dst->a = (unsigned char)f_interval(((float)y) / 4, 0, 255);
	}
}

// time : O(1)
// space: O(1)
void	topleft_tri_coloring(const t_table_fdf *src, size_t index, t_triangle *dst)
{
	if (dst != NULL && src != NULL && index < (src->col - 1) * (src->row - 1))
	{
		dst->r = src->r[index];
		dst->g = src->g[index];
		dst->b = src->b[index];
		dst->a = src->a[index];
	}
}

// time : O(1)
// space: O(1)
unsigned char	get_edge_average_tri_color(const unsigned char *src, t_triangle_arr *dst, size_t col)
{
	int				y;

	if (src == NULL || dst == NULL || dst->capacity < 2 || dst->arr == NULL)
		return (0);
	y = src[(int)f_floor(dst->arr[0].p1[1] * col + dst->arr[0].p1[0])] + src[(int)f_floor(dst->arr[1].p2[1] * col + dst->arr[1].p2[0])];
	return ((unsigned char)f_interval(((float)y) / 2, 0, 255));
}

// time : O(1)
// space: O(1)
void	edge_average_tri_coloring(const t_table_fdf *src, t_triangle_arr *dst)
{
	if (dst != NULL && dst->arr != NULL && dst->capacity > 1 && src != NULL)
	{
		dst->arr[0].r = get_edge_average_tri_color(src->r, dst, src->col);
		dst->arr[1].r = get_edge_average_tri_color(src->r, dst, src->col);
		dst->arr[0].g = get_edge_average_tri_color(src->g, dst, src->col);
		dst->arr[1].g = get_edge_average_tri_color(src->g, dst, src->col);
		dst->arr[0].b = get_edge_average_tri_color(src->b, dst, src->col);
		dst->arr[1].b = get_edge_average_tri_color(src->b, dst, src->col);
		dst->arr[0].a = get_edge_average_tri_color(src->a, dst, src->col);
		dst->arr[1].a = get_edge_average_tri_color(src->a, dst, src->col);
	}
}
