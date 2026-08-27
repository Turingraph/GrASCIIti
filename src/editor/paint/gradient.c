#include"paint.h"

// time : O(1)
// space: O(1)
unsigned char	get_rgba_input(e_rgba rgba_type, t_rgba src)
{
	if (rgba_type == RED)
		return (src.r);
	if (rgba_type == GREEN)
		return (src.g);
	if (rgba_type == BLUE)
		return (src.b);
	if (rgba_type == ALPHA)
		return (src.a);
	return (0);
}

// time : O(1)
// space: O(1)
unsigned char	gradient_smooth(e_rgba rgba_type, t_gradient gradient_input, int input_threshold)
{
	float	y;
	float	dx;
	float	dy;
	float	y1;
	float	y2;

	if (gradient_input.input_start == gradient_input.input_end)
		return (get_rgba_input(rgba_type, gradient_input.rgba_start));
	y1 = (float)(get_rgba_input(rgba_type, gradient_input.rgba_start));
	y2 = (float)(get_rgba_input(rgba_type, gradient_input.rgba_end));
	dx = (float)(gradient_input.input_end - gradient_input.input_start);
	dy = (float)(y2 - y1);
	y = (((float)(input_threshold - gradient_input.input_start)) / dx) * dy + y1;
	return ((unsigned char)f_interval(f_round(y), 0, 255));
}

// time : O(1)
// space: O(1)
int	get_gradient_input(const t_table_fdf *src, e_7cell_channels mode, size_t index)
{
	if (src == NULL)
		return (-3);
	if (index >= src->row * src->col)
		return (-2);
	if (mode == D7_RED && src->r != NULL)
		return ((int)src->r[index]);
	if (mode == D7_GREEN && src->g != NULL)
		return ((int)src->g[index]);
	if (mode == D7_BLUE && src->b != NULL)
		return ((int)src->b[index]);
	if (mode == D7_ALPHA && src->a != NULL)
		return ((int)src->a[index]);
	if (mode == D7_ROW)
		return ((int)(index / src->col));
	if (mode == D7_COL)
		return ((int)(index % src->col));
	if (mode == D7_HEIGHT && src->arr != NULL)
		return ((int)src->arr[index]);
	return (-1);
}

// time : O(1)
// space: O(1)
unsigned char	update_cell_color(unsigned char alpha, bool is_overwrite,
	unsigned char dst, unsigned char new_color)
{
	float	dc;

	if (is_overwrite == true)
		return (new_color);
	dc = (float)dst - (float)new_color;
	if (dc < 0)
		dc *= -1;
	return ((unsigned char)f_interval(f_round(((dc * alpha) + (new_color * (255 - alpha))) / 255.0), 0, 255));
}

/**
 * Apply a color gradient to cells within an input range.
 *
 * time/space: O(n) / O(1)
 *
 * status: public api
 *
 * @param dst FDF table to modify
 * @param gradient_input gradient definition
 * @param is_overwrite replace existing colors instead of blending
 */
void	color_cells_gradient(t_table_fdf *dst,
	t_gradient gradient_input, bool is_overwrite)
{
	size_t			i;
	int				threshold;
	unsigned char	alpha;

	i = 0;
	while (dst != NULL && i < dst->row * dst->col && dst->arr != NULL)
	{
		threshold = get_gradient_input((const t_table_fdf *)dst, gradient_input.cell_channel, i);
		alpha = 0;
		if (dst->a != NULL && is_overwrite == false)
			alpha = dst->a[i];
		if (gradient_input.input_start <= threshold && threshold <= gradient_input.input_end)
		{
			if (is_overwrite == true && dst->a != NULL)
				dst->a[i] = gradient_smooth(ALPHA, gradient_input, threshold);
			if (dst->r != NULL)
				dst->r[i] = update_cell_color(alpha, is_overwrite, dst->r[i],
					gradient_smooth(RED, gradient_input, threshold));
			if (dst->g != NULL)
				dst->g[i] = update_cell_color(alpha, is_overwrite, dst->g[i],
					gradient_smooth(GREEN, gradient_input, threshold));
			if (dst->b != NULL)
				dst->b[i] = update_cell_color(alpha, is_overwrite, dst->b[i],
					gradient_smooth(BLUE, gradient_input, threshold));
		}
		i += 1;
	}
}
