#include"table.h"

// time : O(1)
// space: O(1)
void	write_rgb_fdf(int fd, const t_table_fdf *src, size_t row, size_t col)
{
	if (fd > -1)
	{
		write(fd, ",0x", 3);
		if (src->r != NULL && src->r[row] != NULL)
			ft_putnbr_fd((int)src->r[row][col], fd, "0123456789abcdef", 2);
		else
			write(fd, "00", 2);
		if (src->g != NULL && src->g[row] != NULL)
			ft_putnbr_fd((int)src->g[row][col], fd, "0123456789abcdef", 2);
		else
			write(fd, "00", 2);
		if (src->b != NULL && src->b[row] != NULL)
			ft_putnbr_fd((int)src->b[row][col], fd, "0123456789abcdef", 2);
		else
			write(fd, "00", 2);
		if (src->a != NULL && src->a[row] != NULL)
			ft_putnbr_fd((int)src->a[row][col], fd, "0123456789abcdef", 2);
		else
			write(fd, "00", 2);
	}
}

// time : O(n)
// space: O(n)
void	write_table_fdf(int fd, const t_table_fdf *src, size_t digits, e_write_style mode)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (src != NULL && src->arr != NULL && i < src->row && fd > -1)
	{
		j = 0;
		while (src->arr[i] != NULL && j < src->col)
		{
			ft_putnbr_fd(src->arr[i][j], fd, "0123456789", digits);
			if (mode == HEIGHT_RGB && mode == HEIGHT_RGBA
				|| (mode == FDF42
					&& FALSE == is_default_rgba(src->r, src->g, src->b, src->a)))
				write_rgb_fdf(fd, src, i, j);
			write(fd, "\t", 1);
			j += 1;
		}
		write(fd, "\n", 1);
		i += 1;
	}
}

// time : O(n)
// space: O(n)
void	write_table_ascii(int fd, const t_table_fdf *src, e_5cell_channels channel, const char *dict)
{
	size_t	i;
	size_t	j;
	void	**arr;
	int		rgb95;
	e_bool	left_char;

	i = 0;
	while (src != NULL && src->arr != NULL && i < src->row && fd > -1)
	{
		j = 0;
		while (src->arr[i] != NULL && j < src->col)
		{
			left_char = TRUE;
			if (i > src->origin_x)
				left_char = FALSE;
			arr = choose_5cell_channel(src, channel, i);
			if (arr != NULL && channel == D5_HEIGHT)
				ft_put_ascii_fd(fd, (int)arr[i][j], dict, left_char);
			else if (arr != NULL && channel != D5_HEIGHT)
			{
				rgb95 = (int)f_interval(f_round((float)arr[i][j] * 255.0 / 95.0),
					0, 255);
				ft_put_ascii_fd(fd, rgb95, dict, left_char);
			}
			j += 1;
		}
		write(fd, "\n", 1);
		i += 1;
	}
}
