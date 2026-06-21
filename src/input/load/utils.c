#include"load.h"

// time : O(1)
// space: O(1)
unsigned char	f_rgb(char *str, size_t len, char *err)
{
	int	dst;

	dst = f_atoi(str, err, "0123456789abcdef", len);
	if (len == 1)
		dst = 16 * dst + dst;
	if (dst < 0)
		return (0);
	if (dst > 255)
		return (255);
	return ((unsigned char)dst);
}

// time : O(n)
// space: O(n)
void	write_load_fdf(int fd, t_load_fdf src, size_t digits, char rgb)
{
	size_t	i;

	i = 0;
	while (src.arr != NULL && i < src.length)
	{
		ft_putnbr_fd(src.arr[i], fd, "0123456789", digits);
		if (rgb == 1 && src.r != NULL && src.g != NULL
			&& src.b != NULL && src.a != NULL)
		{
			write(fd, ",0x", 3);
			ft_putnbr_fd((int)src.r[i], fd, "0123456789abcdef", 2);
			ft_putnbr_fd((int)src.g[i], fd, "0123456789abcdef", 2);
			ft_putnbr_fd((int)src.b[i], fd, "0123456789abcdef", 2);
			ft_putnbr_fd((int)src.a[i], fd, "0123456789abcdef", 2);
		}
		write(fd, "\t", 1);
		i += 1;
	}
	write(fd, "\n", 1);
}

// time : O(n)
// space: O(n)
void	write_load_fdf_arr(int fd, t_load_fdf_arr src, size_t digits, char rgb)
{
	size_t	i;

	i = 0;
	while (i < src.length && src.arr != NULL)
	{
		write_load_fdf(fd, src.arr[i], digits, rgb);
		i += 1;
	}
}

// time : O(1)
// space: O(1)
void	warning_load_fdf(t_load_fdf dst, size_t i)
{
	if (dst.int_err != 'K' || dst.rgb_err != 'K')
	{
		write(1, "Warning: Line no. ", 19);
		ft_putnbr_fd(i, 1, "0123456789", 1);
		write(1, " of input Fdf file is ", 23);
		if (dst.int_err == '0')
			write(1, "empty", 6);
		if (dst.int_err == 'E')
			write(1, "not a decimal number", 21);
		if (dst.int_err != 'K' && dst.rgb_err == 'E')
			write(1, " and ", 5);
		if (dst.rgb_err == 'E')
			write(1, " not a valid hexadecimal rgb representation", 44);
		write(1, ".\n", 2);
	}
}