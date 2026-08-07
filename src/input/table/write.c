#include"table.h"

// time : O(1)
// space: O(1)
void	write_rgba_fdf(int fd, const t_table_fdf *src, size_t index)
{
	if (fd > -1 && src != NULL)
	{
		write(fd, ",0x", 3);
		if (src->r != NULL)
			ft_putnbr_fd((int)src->r[index], fd, "0123456789abcdef", 2);
		else
			write(fd, "00", 2);
		if (src->g != NULL)
			ft_putnbr_fd((int)src->g[index], fd, "0123456789abcdef", 2);
		else
			write(fd, "00", 2);
		if (src->b != NULL)
			ft_putnbr_fd((int)src->b[index], fd, "0123456789abcdef", 2);
		else
			write(fd, "00", 2);
	}
}

// time : O(n)
// space: O(n)
void	write_table_fdf(int fd, const t_table_fdf *src,
	size_t digits, e_write_style mode)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (src != NULL && src->arr != NULL && i < src->row && fd > -1)
	{
		j = 0;
		while (j < src->col)
		{
			ft_putnbr_fd(src->arr[src->col * i + j], fd, "0123456789", digits);
			if (mode == HEIGHT_RGB || mode == HEIGHT_RGBA)
				write_rgba_fdf(fd, src, src->col * i + j);
			if (src->a != NULL && mode == HEIGHT_RGBA)
				ft_putnbr_fd((int)src->a[src->col * i + j],
					fd, "0123456789abcdef", 2);
			else if (src->a == NULL && mode == HEIGHT_RGBA)
				write(fd, "00", 2);
			write(fd, "\t", 1);
			j += 1;
		}
		write(fd, "\n", 1);
		i += 1;
	}
}

// time : O(1)
// space: O(1)
unsigned char	*choose_rgba_channel(const t_table_fdf *src, e_rgba channel)
{
	if (src == NULL)
		return (NULL);
	if (channel == RED && src->r != NULL)
		return (src->r);
	if (channel == GREEN && src->g != NULL)
		return (src->g);
	if (channel == BLUE && src->b != NULL)
		return (src->b);
	if (channel == ALPHA && src->a != NULL)
		return (src->a);
	return (NULL);
}

// time : O(n)
// space: O(n)
void	write_table_ascii(int fd, const t_table_fdf *src, e_rgba channel, const char *dict)
{
	size_t			i;
	size_t			j;
	unsigned char	*arr;
	int				rgb95;
	bool			left_char;

	i = 0;
	while (src != NULL && i < src->row && fd > -1)
	{
		j = 0;
		while (j < src->col)
		{
			left_char = true;
			if (j >= src->origin_x)
				left_char = false;
			arr = choose_rgba_channel(src, channel);
			if (src->arr != NULL && channel == HEIGHT)
				ft_put_ascii_fd(fd, (int)src->arr[i * src->col + j], dict, left_char);
			else if (arr != NULL && channel != HEIGHT)
			{
				rgb95 = (int)f_interval(f_round((float)arr[i * src->col + j] * 95.0 / 255),
					0, 255);
				ft_put_ascii_fd(fd, rgb95, dict, left_char);
			}
			j += 1;
		}
		write(fd, "\n", 1);
		i += 1;
	}
}

// time : O(n)
// space: O(n)
void	write_push_swap_fdf(int fd, const t_table_fdf *src,
	size_t digits)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (src != NULL && src->arr != NULL && i < src->row && fd > -1)
	{
		j = 0;
		while (j < src->col)
		{
			ft_putnbr_fd(src->arr[src->col * i + j], fd, "0123456789", digits);
			write(fd, ",\t", 2);
			j += 1;
		}
		write(fd, "\n", 1);
		i += 1;
	}
}