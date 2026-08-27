#include"load_private.h"

// time : O(n)
// space: O(n)
void	write_load_fdf(int fd, const t_load_fdf *src,
		size_t digits, e_write_style mode)
{
	size_t	i;

	i = 0;
	while (src != NULL && src->arr != NULL && i < src->length)
	{
		ft_putnbr_fd(src->arr[i], fd, "0123456789", digits);
		if (mode == HEIGHT_RGB || mode == HEIGHT_RGBA)
		{
			write(fd, ",0x", 3);
			if (src->r != NULL)
				ft_putnbr_fd((int)src->r[i], fd, "0123456789abcdef", 2);
			if (src->g != NULL)
				ft_putnbr_fd((int)src->g[i], fd, "0123456789abcdef", 2);
			if (src->b != NULL)
				ft_putnbr_fd((int)src->b[i], fd, "0123456789abcdef", 2);
		}
		if (mode == HEIGHT_RGBA && src->a != NULL)
			ft_putnbr_fd((int)src->a[i], fd, "0123456789abcdef", 2);
		write(fd, "\t", 1);
		i += 1;
	}
	write(fd, "\n", 1);
}

// time : O(n)
// space: O(n)
void	write_load_fdf_arr(int fd,
		const t_load_fdf_arr *src, size_t digits, e_write_style mode)
{
	size_t	i;

	i = 0;
	while (src != NULL && i < src->length && src->arr != NULL)
	{
		write_load_fdf(fd, (const t_load_fdf *)&(src->arr[i]), digits, mode);
		i += 1;
	}
}

// time : O(1)
// space: O(1)
void	warning_load_fdf(const t_load_fdf *src, size_t i)
{
	if (src->int_warn != CORRECT || src->rgb_warn != CORRECT)
	{
		write(1, "Warning: Line no. ", 19);
		ft_putnbr_fd(i, 1, "0123456789", 1);
		write(1, " of input Fdf file is ", 23);
		if (src->int_warn == EMPTY)
			write(1, "empty", 6);
		if (src->int_warn == NOT_DECIMAL)
			write(1, "not a decimal number", 21);
		if (src->int_warn != CORRECT && src->rgb_warn == 'E')
			write(1, " and ", 5);
		if (src->rgb_warn == NOT_HEX)
			write(1, " not a valid hexadecimal rgb representation", 44);
		write(1, ".\n", 2);
	}
}
