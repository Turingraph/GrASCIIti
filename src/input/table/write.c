#include"table.h"

// time : O(1)
// space: O(1)
void	write_rgb_fdf(int fd, t_table_fdf src, size_t row, size_t col)
{
	write(1, ",0x", 3);
	if (src.r != NULL && src.r[row] != NULL)
		ft_putnbr_fd((int)src.r[row][col], fd, "0123456789abcdef", 2);
	else
		write(fd, "00", 2);
	if (src.g != NULL && src.g[row] != NULL)
		ft_putnbr_fd((int)src.g[row][col], fd, "0123456789abcdef", 2);
	else
		write(fd, "00", 2);
	if (src.b != NULL && src.b[row] != NULL)
		ft_putnbr_fd((int)src.b[row][col], fd, "0123456789abcdef", 2);
	else
		write(fd, "00", 2);
	if (src.a != NULL && src.a[row] != NULL)
		ft_putnbr_fd((int)src.a[row][col], fd, "0123456789abcdef", 2);
	else
		write(fd, "00", 2);
}

// time : O(n)
// space: O(n)
void	write_table_fdf(int fd, t_table_fdf src, e_bool is_rgb, size_t digits)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < src.row)
	{
		j = 0;
		while (j < src.col)
		{
			if (src.arr != NULL && src.arr[i] != NULL)
				ft_putnbr_fd(src.arr[i][j], fd, "0123456789", digits);
			else
			{
				write(fd, "Error: src.arr == NULL from table/save/"
					"write_table_fdf in line no.", 67);
				ft_putnbr_fd((int)i, fd, "0123456789", 1);
				write(fd, "\n", 1);
			}
			if (is_rgb == TRUE)
				write_rgb_fdf(fd, src, i, j);
			write(fd, "\t", 1);
			j += 1;
		}
		write(fd, "\n", 1);
		i += 1;
	}
}
