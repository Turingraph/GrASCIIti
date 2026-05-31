#include"paint.h"

// time : O(1)
// space: O(1)
void	mixing_over_rgb(unsigned char *color, t_gradient *rgb, size_t ratio, char rgb_type)
{
	if (ratio < rgb->x1 && rgb_type == 'r')
		*color = rgb->r1;
	if (ratio < rgb->x1 && rgb_type == 'g')
		*color = rgb->g1;
	if (ratio < rgb->x1 && rgb_type == 'b')
		*color = rgb->b1;
	if (ratio < rgb->x1 && rgb_type == 'a')
		*color = rgb->a1;
	if (ratio > rgb->x1 && rgb_type == 'r')
		*color = rgb->r1;
	if (ratio > rgb->x1 && rgb_type == 'g')
		*color = rgb->g1;
	if (ratio > rgb->x1 && rgb_type == 'b')
		*color = rgb->b1;
	if (ratio > rgb->x1 && rgb_type == 'a')
		*color = rgb->a1;
}

/*
ratio == a => r1
ratio == b => r2

f:x1 = y1
f:x2 = y2

(y2 - y1) * (z - x1) / (x2 - x1)
(y2 - y1) * (x1 - x1) / (x2 - x1) + y1 = y1
(y2 - y1) * (x2 - x1) / (x2 - x1) + y1 = (y2 - y1) + y1 = y2
*/

// time : O(1)
// space: O(1)
void	mixing_rgb(unsigned char *color, t_gradient *rgb, size_t ratio, char rgb_type)
{
	float	mix_rgb;
	float	delta;

	if (rgb_type == 'r')
		delta = (float)f_floor(rgb->r2 - rgb->r1);
	if (rgb_type == 'g')
		delta = (float)f_floor(rgb->g2 - rgb->g1);
	if (rgb_type == 'b')
		delta = (float)f_floor(rgb->b2 - rgb->b1);
	if (rgb_type == 'a')
		delta = (float)f_floor(rgb->a2 - rgb->a1);
	mix_rgb = f_floor(ratio - (size_t)(rgb->x1)) * delta / f_floor(rgb->x2 - rgb->x1);
	if (ratio >= (size_t)rgb->x1 && ratio <= (size_t)rgb->x2)
		*color = (unsigned char)f_floor(mix_rgb);
	else
		mixing_over_rgb(color, rgb, ratio, rgb_type);
}

// time : O(n)
// space: O(1)
void	paint_gradient_fdf(t_table_fdf *table, t_gradient *rgb, char dim)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (table != NULL && rgb != NULL && i < table->row)
	{
		j = 0;
		while (j < table->col)
		{
			if ((dim == 0 && rgb->x1 <= (int)i && (int)i <= rgb->x2)
				|| (dim == 1 && rgb->x1 <= (int)j && (int)j <= rgb->x2)
				|| (dim == 2 && rgb->x1 <= table->arr[i][j] && table->arr[i][j] <= rgb->x2))
			{
				mixing_rgb(table->r[i] + j, rgb, (size_t)i, 'r');
				mixing_rgb(table->g[i] + j, rgb, (size_t)i, 'g');
				mixing_rgb(table->b[i] + j, rgb, (size_t)i, 'b');
				mixing_rgb(table->a[i] + j, rgb, (size_t)i, 'a');
			}
			j += 1;
		}
		i += 1;
	}
}

// time : O(n)
// space: O(1)
void	reset_gradient_fdf(t_table_fdf *table)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (table != NULL && i < table->row)
	{
		j = 0;
		while (j < table->col)
		{
			table->r[i][j] = (unsigned char)0;
			table->g[i][j] = (unsigned char)0;
			table->b[i][j] = (unsigned char)0;
			table->a[i][j] = (unsigned char)0;
			j += 1;
		}
		i += 1;
	}
}
