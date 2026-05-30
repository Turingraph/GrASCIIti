#include "table.h"

// time : O(1)
// space: O(1)
void	write_rgb_fdf(int fd, int **rgb, size_t i, size_t j)
{
	if (rgb != NULL && rgb[i] != NULL)
		ft_putnbr_fd((int) rgb[i][j], fd, "0123456789abcdef", 2);
	else
		write(fd, "00", 2);
}

// time : O(n)
// space: O(n)
void	write_table_fdf(int fd, t_table_fdf *table)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < table->col)
	{
		j = 0;
		while (j < table->row)
		{
			if (table->table != NULL && table->table[i] != NULL)
				ft_putnbr_fd(table->table[i][j], fd, "0123456789", 1);
			else
				write(fd, "Error: table->table from table/\
					write_table_fdf is empty.\n", 51);
			write_rgb_fdf(fd, table->r, i, j);
			write_rgb_fdf(fd, table->g, i, j);
			write_rgb_fdf(fd, table->b, i, j);
			write_rgb_fdf(fd, table->a, i, j);
			write(fd, " ", 1);
			j += 1;
		}
		write(fd, "\n", 1);
		i += 1;
	}
}

// time : O(n)
// space: O(1)
char	f_intncpy(char *src, int *dst, size_t n, size_t scale)
{
	size_t	i;
	size_t	j;

	if (src == NULL || dst == NULL)
		return (0);
	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < scale)
		{
			dst[scale * i + j] = src[i];
			j += 1;
		}
		i += 1;
	}
	return (1);
}

// time : O(n * s^2)
// space: O(n * s^2)
t_table_fdf	*scale_table_fdf(t_table_fdf *src, size_t scale)
{
	size_t		i;
	size_t		j;
	t_table_fdf	*dst;

	dst = init_table(src->col * scale, src->row * scale);
	if (dst == NULL)
		return (NULL);
	i = 0;
	while (i < src->col)
	{
		j = 0;
		while (j < scale)
		{
			f_intncpy(src->table[i], dst->table[scale * i + j], src->row, scale);
			f_intncpy(src->r[i], dst->r[scale * i + j], src->row, scale);
			f_intncpy(src->g[i], dst->g[scale * i + j], src->row, scale);
			f_intncpy(src->b[i], dst->b[scale * i + j], src->row, scale);
			f_intncpy(src->a[i], dst->a[scale * i + j], src->row, scale);
			j += 1;
		}
		i += 1;
	}
	return (dst);
}

// time : O(n * h)
// space: O(n * h)
void	higher_table_fdf(t_table_fdf *table, size_t scale)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (table != NULL && table->table != NULL && i < table->col)
	{
		j = 0;
		while (j < table->row)
		{
			if (table->table[i] != NULL
				&& (long)(table->table[i][j]) * (long)scale <= (long)2147483647
				&& (long)(table->table[i][j]) * (long)scale > (long)-2147483648)
				table->table[i][j] *= (int) scale;
			else if (table->table[i] == NULL)
				write(1, "Warning: Some rows of the Table are empty.\n", 43);
			else if ((long)(table->table[i][j]) * (long)scale > (long)2147483647
				|| (long)(table->table[i][j]) * (long)scale <= (long)-2147483648)
				write(1, "Warning: Some Integer of the Table are Integer Overflow.\n", 57);
			else
				write(1, "Warning: Some Table related unknown Error.\n", 43);
			j += 1;
		}
		i += 1;
	}
}

// else if (table->table[i] == NULL)
// {
// 	write(1, "Warning: ", 9);
// 	ft_putnbr_fd((int)i, 1, "0123456789", 1);
// 	write(1, "-th line of the Table is Empty.\n", 32);
// }
// else
// {
// 	write(1, "Warning: ", 9);
// 	ft_putnbr_fd((int)i, 1, "0123456789", 1);
// 	write(1, "-th line of the Table is Integer Overflow.\n", 43);
// }
