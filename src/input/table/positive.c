#include"table.h"

// time : O(n)
// space: O(1)
int	get_minmax_from_table_fdf(t_table_fdf *dst, bool is_max, e_rgba channels)
{
	int		sign;
	size_t	i;
	int		y;

	y = 0;
	sign = 1;
	if (is_max == false)
		sign = -1;
	i = 0;
	while (dst != NULL && i < dst->row * dst->col)
	{
		if (dst->arr != NULL && y * sign < dst->arr[i] * sign && channels == HEIGHT)
			y = dst->arr[i];
		if (dst->r != NULL && y * sign < (int)(dst->r[i] * sign) && channels == RED)
			y = (int)dst->r[i];
		if (dst->g != NULL && y * sign < (int)(dst->g[i] * sign) && channels == GREEN)
			y = (int)dst->g[i];
		if (dst->b != NULL && y * sign < (int)(dst->b[i] * sign) && channels == BLUE)
			y = (int)dst->b[i];
		if (dst->a != NULL && y * sign < (int)(dst->a[i] * sign) && channels == ALPHA)
			y = (int)dst->a[i];
		i += 1;
	}
	return (y);
}

// time : O(n)
// space: O(1)
void	scale_positive_fdf(t_table_fdf *dst)
{
	int	y;

	y = get_minmax_from_table_fdf(dst, false, HEIGHT);
	if (y < 0 && y > -2147483648)
		y *= -1;
	else if (y == -2147483648)
		y = 0;
	scale_addition_fdf(dst, y, HEIGHT);
}
