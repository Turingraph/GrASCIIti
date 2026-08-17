#include"line.h"

// time : O(n)
// space: O(1)
void	draw_pixel_art_unit(t_table_fdf *dst,
	t_ink ink, t_complex start, t_complex end)
{
	t_line		square;
	t_boundary	boundary;

	if (dst != NULL)
	{
		boundary = get_all_area(dst->row, dst->col);
		square = init_float_line(start, end, boundary.sub_area);
		draw_rectangle_uchar(dst, square, boundary.sub_area, ink);
	}
}

// time : O(1)
// space: O(1)
t_ink	define_ink(const t_table_fdf *src, e_rgba channel, size_t index)
{
	t_ink	ink;

	ink.thickness = 0;
	ink.channel = channel;
	ink.color = 0;
	if (src != NULL && index < src->col * src->row
		&& channel == RED && src->r != NULL)
		ink.color = src->r[index];
	if (src != NULL && index < src->col * src->row
		&& channel == GREEN && src->g != NULL)
		ink.color = src->g[index];
	if (src != NULL && index < src->col * src->row
		&& channel == BLUE && src->b != NULL)
		ink.color = src->b[index];
	if (src != NULL && index < src->col * src->row
		&& channel == ALPHA && src->a != NULL)
		ink.color = src->a[index];
	return (ink);
}

// time : O(n)
// space: O(1)
void	draw_pixel_art(t_table_fdf *dst, const t_table_fdf *src, float zoom)
{
	size_t		i;
	size_t		j;
	t_complex	start;
	t_complex	end;

	i = 0;
	while (dst != NULL && src != NULL && i < src->row)
	{
		j = 0;
		while (j < src->col)
		{
			start.re = zoom * (float)j / (float)src->col;
			start.im = zoom * (float)i / (float)src->row;
			end.re = zoom * (float)(j + 1) / (float)src->col;
			end.im = zoom * (float)(i + 1) / (float)src->row;
			draw_pixel_art_unit(
				dst, define_ink(src, RED, i * src->col + j),
				start, end);
			draw_pixel_art_unit(
				dst, define_ink(src, GREEN, i * src->col + j),
				start, end);
			draw_pixel_art_unit(
				dst, define_ink(src, BLUE, i * src->col + j),
				start, end);
			draw_pixel_art_unit(
				dst, define_ink(src, ALPHA, i * src->col + j),
				start, end);
			j += 1;
		}
		i += 1;
	}
}