#include"view.h"

// time : O(1)
// space: O(1)
int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

// time : O(1)
// space: O(1)
int32_t	ft_table_pixel(const t_table_fdf *src, size_t index)
{
	int32_t	r;
	int32_t	g;
	int32_t	b;
	int32_t	a;

	if (src == NULL || index >= src->row * src->col)
		return (0);
	r = 0;
	if (src->r != NULL)
		r = (int32_t)src->r[index];
	g = 0;
	if (src->g != NULL)
		g = (int32_t)src->g[index];
	b = 0;
	if (src->b != NULL)
		b = (int32_t)src->b[index];
	a = 0;
	if (src->a != NULL)
		a = (int32_t)src->a[index];
	return (ft_pixel(r, g, b, a));
}

// time : O(n)
// space: O(1)
void	paint_table_on_image(const t_table_fdf *src, mlx_image_t *img)
{
	size_t		i;
	uint32_t	color;

	i = 0;
	while (src != NULL && img != NULL
		&& img->height == src->row
		&& img->width == src->col
		&& i < src->col * src->row)
	{
		color = ft_table_pixel(src, i);
		mlx_put_pixel(img, i % src->col, i / src->col, color);
		i += 1;
	}
}

// time : O(n)
// space: O(n)
t_table_fdf	scale_window_dimension_fdf(const t_table_fdf *src)
{
	if (src == NULL || src->row * src->col == 0)
	{
		write(1, "Warning: The input data is empty.\n", 35);
		return (init_table_fdf(0, 0, false));
	}
	if (src->row > 810 || src->col > 1440)
	{
		write(1, "Warning: The input data contains "
			"rows and/or columns more than 1440 x 810 "
			"(window size).\nsrc->row = ", 101);
		ft_putnbr_fd(src->row, 1, "0123456789", 1);
		write(1, "\nsrc->col = ", 13);
		ft_putnbr_fd(src->col, 1, "0123456789", 1);
		write(1, "\n", 1);
		return (*src);
	}
	if (src->row >= src->col)
		return (scale_dimension_fdf(
			src, 810 / src->row, 810 / src->row));
	return (scale_dimension_fdf(
		src, 1140 / src->col, 1140 / src->col));
}
