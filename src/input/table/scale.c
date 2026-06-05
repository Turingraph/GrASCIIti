#include"table.h"

// time : O(n)
// space: O(1)
char	f_rgbncpy(unsigned char *src, unsigned char *dst, size_t n, size_t scale)
{
	size_t			i;
	size_t			j;

	if (src == NULL || dst == NULL)
		return (0);
	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < scale)
		{
			dst[i * scale + j] = src[i];
			j += 1;
		}
		i += 1;
	}
	return (1);
}


// time : O(n)
// space: O(1)
char	f_intncpy(int *src, int *dst, size_t n, size_t scale)
{
	size_t			i;
	size_t			j;

	if (src == NULL || dst == NULL || scale == 0 || n == 0)
		return (0);
	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < scale)
		{
			dst[i * scale + j] = src[i];
			j += 1;
		}
		i += 1;
	}
	return (1);
}

// time : O(n * s^2)
// space: O(n * s^2)
t_table_fdf	*scale_dimension_fdf(t_table_fdf *src, size_t s_row, size_t s_col)
{
	size_t		i;
	size_t		j;
	t_table_fdf	*dst;

	dst = init_table_fdf(src->row * s_row, src->col * s_col);
	if (dst == NULL)
		return (NULL);
	i = 0;
	while (i < src->row)
	{
		j = 0;
		while (j < s_row)
		{
			f_intncpy(src->arr[i], dst->arr[s_row * i + j], src->col, s_col);
			f_rgbncpy(src->r[i], dst->r[s_row * i + j], src->col, s_col);
			f_rgbncpy(src->g[i], dst->g[s_row * i + j], src->col, s_col);
			f_rgbncpy(src->b[i], dst->b[s_row * i + j], src->col, s_col);
			f_rgbncpy(src->a[i], dst->a[s_row * i + j], src->col, s_col);
			j += 1;
		}
		i += 1;
	}
	return (dst);
}

// time : O(n * h)
// space: O(n * h)
void	scale_hadamard_fdf(t_table_fdf *table, double scale)
{
	size_t	i;
	size_t	j;
	long	check;

	i = 0;
	while (table != NULL && table->arr != NULL && i < table->row)
	{
		j = 0;
		while (j < table->col)
		{
			check = (long)f_floor((double)table->arr[i][j] * scale);
			if (table->arr[i] != NULL
				&& check <= (long)2147483647 && check > (long)-2147483648)
				table->arr[i][j] = (int)check;
			else if (table->arr[i] == NULL)
				write(1, "Warning: Some rows of the Table are empty.\n", 43);
			else if (check > (long)2147483647 && check <= (long)-2147483648)
				write(1, "Warning: Some Integer of the Table are Integer Overflow.\n", 57);
			else
				write(1, "Warning: Some Table related unknown Error.\n", 43);
			j += 1;
		}
		i += 1;
	}
}
