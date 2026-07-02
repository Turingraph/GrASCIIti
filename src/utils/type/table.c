#include"type.h"

// time : O(1)
// space: O(1)
unsigned char	**choose_rgb_channel(const t_table_fdf *src, e_rgba rgb_type, size_t row)
{
	if (src == NULL)
		return (NULL);
	if (rgb_type == RED && src->r != NULL && src->r[row] != NULL)
		return (src->r);
	if (rgb_type == GREEN && src->g != NULL && src->g[row] != NULL)
		return (src->g);
	if (rgb_type == BLUE && src->b != NULL && src->b[row] != NULL)
		return (src->b);
	if (rgb_type == ALPHA && src->a != NULL && src->a[row] != NULL)
		return (src->a);
	return (NULL);
}

// time : O(1)
// space: O(1)
void	**choose_5cell_channel(const t_table_fdf *src, e_5cell_channels channel, size_t row)
{
	if (src == NULL)
		return (NULL);
	if (channel == D5_RED && src->r != NULL && src->r[row] != NULL)
		return ((void **)src->r);
	if (channel == D5_GREEN && src->g != NULL && src->g[row] != NULL)
		return ((void **)src->g);
	if (channel == D5_BLUE && src->b != NULL && src->b[row] != NULL)
		return ((void **)src->b);
	if (channel == D5_ALPHA && src->a != NULL && src->a[row] != NULL)
		return ((void **)src->a);
	if (channel ==D5_HEIGHT && src->arr != NULL && src->arr[row] != NULL)
		return ((void **)src->arr);
	return (NULL);
}

// time : O(1)
// space: O(1)
e_bool	is_rgbah_table_not_null(const t_table_fdf *src, size_t row)
{
	if (src == NULL)
		return (FALSE);
	if (src->arr != NULL && src->arr[row] != NULL
		&& src->r != NULL && src->r[row] != NULL
		&& src->g != NULL && src->g[row] != NULL
		&& src->b != NULL && src->b[row] != NULL
		&& src->a != NULL && src->a[row] != NULL)
		return (TRUE);
	return (FALSE);
}

// time : O(1)
// space: O(1)
t_complex	get_table_fdf_coordinate(size_t row, size_t col, const t_table_fdf *dst)
{
	t_complex	y;

	if (dst == NULL || row >= dst->row || col >= dst->col)
		return (FALSE);
	y.re = f_floor((float)row - (float)dst->origin_x);
	y.im = f_floor((float)dst->origin_y - (float)col);
	return (y);
}

// time : O(1)
// space: O(1)
e_bool	is_default_rgba(const unsigned char **r, const unsigned char **g,
	const unsigned char **b, const unsigned char **a)
{
	e_bool	default_r;
	e_bool	default_g;
	e_bool	default_b;
	e_bool	default_a;

	default_r = FALSE;
	if (r == NULL || *r == NULL || **r == 0)
		default_r = TRUE;
	default_g = FALSE;
	if (g == NULL || *g == NULL || **g == 0)
		default_g = TRUE;
	default_b = FALSE;
	if (b == NULL || *b == NULL || **b == 0)
		default_b = TRUE;
	default_a = FALSE;
	if (a == NULL || *a == NULL || **a == 0)
		default_a = TRUE;
	if (default_r == TRUE && default_g == TRUE
		&& default_b == TRUE && default_a == TRUE)
		return (TRUE);
	return (FALSE);
}
