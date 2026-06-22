#include"paint.h"

// time : O(1)
// space: O(1)
void	mixing_over_rgb(unsigned char *color, t_gradient rgb, int ratio, e_rgba rgb_type)
{
	if (ratio <= rgb.x1 && rgb_type == RED)
		*color = rgb.r1;
	if (ratio <= rgb.x1 && rgb_type == GREEN)
		*color = rgb.g1;
	if (ratio <= rgb.x1 && rgb_type == BLUE)
		*color = rgb.b1;
	if (ratio <= rgb.x1 && rgb_type == ALPHA)
		*color = rgb.a1;
	if (ratio > rgb.x1 && rgb_type == RED)
		*color = rgb.r1;
	if (ratio > rgb.x1 && rgb_type == GREEN)
		*color = rgb.g1;
	if (ratio > rgb.x1 && rgb_type == BLUE)
		*color = rgb.b1;
	if (ratio > rgb.x1 && rgb_type == ALPHA)
		*color = rgb.a1;
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
void	mixing_rgb(unsigned char *color, t_gradient rgb, int ratio, e_rgba rgb_type)
{
	float	mix_rgb;
	float	delta;
	float	y1;

	delta = 1.0;
	if (rgb_type == RED)
		delta = (float)f_floor(rgb.r2 - rgb.r1);
	if (rgb_type == GREEN)
		delta = (float)f_floor(rgb.g2 - rgb.g1);
	if (rgb_type == BLUE)
		delta = (float)f_floor(rgb.b2 - rgb.b1);
	if (rgb_type == ALPHA)
		delta = (float)f_floor(rgb.a2 - rgb.a1);
	if (rgb_type == RED)
		y1 = (float)f_floor(rgb.r1);
	if (rgb_type == GREEN)
		y1 = (float)f_floor(rgb.g1);
	if (rgb_type == BLUE)
		y1 = (float)f_floor(rgb.b1);
	if (rgb_type == ALPHA)
		y1 = (float)f_floor(rgb.a1);
	if (ratio >= rgb.x1 && ratio <= rgb.x2 && rgb.x2 != rgb.x1)
	{
		mix_rgb = f_floor(ratio - (rgb.x1)) * delta / f_floor(rgb.x2 - rgb.x1) + y1;
		*color = (unsigned char)f_floor(mix_rgb);
	}
	else
		mixing_over_rgb(color, rgb, (int)f_floor(ratio), rgb_type);
}

// time : O(1)
// space: O(1)
int	gradient_input(t_table_fdf table, char dim, size_t row, size_t col)
{
	if (dim == 0)
		return ((int)row);
	if (dim == 1)
		return ((int)col);
	if (dim == 2)
		return (table.arr[row][col]);
	if (dim == 3)
		return ((int)table.r[row][col]);
	if (dim == 4)
		return ((int)table.g[row][col]);
	if (dim == 5)
		return ((int)table.b[row][col]);
	if (dim == 6)
		return ((int)table.a[row][col]);
	return ((int)row);
}

// time : O(n)
// space: O(1)
void	paint_gradient_fdf(t_table_fdf *table, t_gradient rgb, char dim)
{
	size_t	i;
	size_t	j;
	int		z;

	i = 0;
	while (table != NULL && i < table->row)
	{
		j = 0;
		while (j < table->col)
		{
			z = gradient_input(*table, dim, i, j);
			if (rgb.x1 <= z && z <= rgb.x2 && 0 <= dim && dim <= 6)
			{
				mixing_rgb(table->r[i] + j, rgb, z, RED);
				mixing_rgb(table->g[i] + j, rgb, z, GREEN);
				mixing_rgb(table->b[i] + j, rgb, z, BLUE);
				mixing_rgb(table->a[i] + j, rgb, z, ALPHA);
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
