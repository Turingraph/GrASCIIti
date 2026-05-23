#include "libft.h"

// time : O(1)
// space: O(1)
void	display_int(int fd, int x)
{
	long	d;
	char	coef;

	d = 1;
	while (d < x)
		d *= 10;
	if (d > x)
		d /= 10;
	while (d > 0)
	{
		coef = x / d + '0';
		write(fd, &coef, 1);
		x = x % d;
		d /= 10;
	}
}

// time : O(1)
// space: O(1)
void	ft_putnbr_fd(int n, int fd)
{
	if (n == 0)
	{
		write(fd, "0", 1);
	}
	else if (n > 0)
	{
		display_int(fd, n);
	}
	else if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
	}
	else
	{
		write(fd, "-", 1);
		display_int(fd, (-1) * n);
	}
}
