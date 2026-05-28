#include "libft.h"

// time : O(n)
// space: O(1)
size_t	f_atoonei(char c, char *base, char *err)
{
	size_t	i;
	char	big_c;

	big_c = c;
	if (c >= 'a' && c <= 'z')
		big_c = c - 'a' + 'A';
	if (c >= 'A' && c <= 'Z')
		big_c = c + 'a' - 'A';
	i = 0;
	while (*base != '\0' && *base != c && *base != big_c
		&& *base != '-' && *base != '+')
	{
		base += 1;
		i += 1;
	}
	if (*base == '\0' || *base == '-' || *base == '+')
	{
		*err = 'E';
		return (0);
	}
	return (i);
}

// time : O(1)
// space: O(1)
long int	f_atolongi(char *src, char *err, char *base, size_t len)
{
	long int	y;
	size_t		i;

	if (len == 0)
		len = f_strlen(src);
	i = 0;
	y = 0;
	while (*err != 'E' && *src != '\0' && i < len)
	{
		y += (long int) f_atoonei(*src, base, err);
		if (*err == 'E')
			return (-1);
		y *= f_strlen(base);
		src += 1;
		i += 1;
	}
	y /= f_strlen(base);
	return (y);
}

// time : O(1)
// space: O(1)
int	f_atoi(char *src, char *err, char *base, size_t len)
{
	long int	y;
	size_t		sign;

	if (src[0] == '0' && src[1] == '\0')
		return (0);
	sign = 0;
	if (src[sign] == '-')
		sign = 1;
	y = f_atolongi(src + sign, err, base, len);
	if (sign == 1)
		y *= -1;
	if (y < -2147483648 || y > 2147483647)
	{
		*err = 'E';
		return (-1);
	}
	return ((int) y);
}

// time : O(1)
// space: O(1)
void	display_int(int fd, long x, char *base)
{
	long	d;
	char	coef;
	size_t	len;

	len = f_strlen(base);
	d = 1;
	while (d < x)
		d *= len;
	if (d > x)
		d /= len;
	while (d > 0)
	{
		coef = base[x / d];
		write(fd, &coef, 1);
		x = x % d;
		d /= len;
	}
}

// time : O(1)
// space: O(1)
void	ft_putnbr_fd(int n, int fd, char *base)
{
	if (n == 0)
	{
		write(fd, base, 1);
	}
	else if (n > 0)
	{
		display_int(fd, (long) n, base);
	}
	else
	{
		write(fd, "-", 1);
		display_int(fd, (-1) * ((long) n), base);
	}
}
