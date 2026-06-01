#include "table.h"

// time : O(1)
// space: O(1)
void	write_rgb_fdf(int fd, t_table_fdf *table, size_t i, size_t j)
{
	write(1, ",0x", 3);
	if (table->r != NULL && table->r[i] != NULL)
		ft_putnbr_fd((int)table->r[i][j], fd, "0123456789abcdef", 2);
	else
		write(fd, "00", 2);
	if (table->g != NULL && table->g[i] != NULL)
		ft_putnbr_fd((int)table->g[i][j], fd, "0123456789abcdef", 2);
	else
		write(fd, "00", 2);
	if (table->b != NULL && table->b[i] != NULL)
		ft_putnbr_fd((int)table->b[i][j], fd, "0123456789abcdef", 2);
	else
		write(fd, "00", 2);
	if (table->a != NULL && table->a[i] != NULL)
		ft_putnbr_fd((int)table->a[i][j], fd, "0123456789abcdef", 2);
	else
		write(fd, "00", 2);
}

// time : O(n)
// space: O(n)
void	write_table_fdf(int fd, t_table_fdf *table, char show_rgb, size_t n_digits)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < table->row)
	{
		j = 0;
		while (j < table->col)
		{
			if (table->arr != NULL && table->arr[i] != NULL)
				ft_putnbr_fd(table->arr[i][j], fd, "0123456789", n_digits);
			else
			{
				write(fd, "Error: table->arr == NULL from table/save/\
					write_table_fdf in line no.", 74);
				ft_putnbr_fd((int)i, 1, "0123456789", 1);
				write(1, "\n", 1);
			}
			if (show_rgb == 1)
				write_rgb_fdf(fd, table, i, j);
			write(fd, " ", 1);
			j += 1;
		}
		write(fd, "\n", 1);
		i += 1;
	}
}
