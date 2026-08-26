#include"raster.h"

// time : O(1)
// space: O(1)
int32_t	f_rgba_to_int32(unsigned char r,
	unsigned char g, unsigned char b, unsigned char a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

// time : O(n)
// space: O(1)
void	color_background_mlx(mlx_image_t *dst, int32_t color)
{
	int32_t	i;
	int32_t	j;

	i = 0;
	while (dst != NULL && i < (int32_t)dst->height)
	{
		j = 0;
		while (j < (int32_t)dst->width)
		{
			mlx_put_pixel(dst, j, i, color);
			j += 1;
		}
		i += 1;
	}
}

// time : O(1)
// space: O(1)
int32_t	get_table_rgba_int32(const t_table_fdf *src, size_t index)
{
	int32_t	r;
	int32_t	g;
	int32_t	b;
	int32_t	a;

	if (src == NULL || index >= src->row * src->col)
		return (0);
	r = 0;
	g = 0;
	b = 0;
	a = 0;
	if (src->r != NULL)
		r = (int32_t)src->r[index];
	if (src->g != NULL)
		g = (int32_t)src->g[index];
	if (src->b != NULL)
		b = (int32_t)src->b[index];
	if (src->a != NULL)
		a = (int32_t)src->a[index];
	return (r << 24 | g << 16 | b << 8 | a);
}
