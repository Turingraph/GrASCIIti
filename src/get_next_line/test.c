#include "get_next_line.h"

/*
// time : O(1)
// space: O(1)
long int	f_atolongi(char *src, char *err, size_t *digit, size_t sign)
{
	long int	y;

	y = 0;
	while (src[*digit] != '\0' && *digit < 11 + sign && *err != 'E')
	{
		if (*digit == sign && src[*digit] == '0')
			*err = 'E';
		else if (src[*digit] >= '0' && src[*digit] <= '9')
			y += (long int)(src[*digit] - '0');
		else
			*err = 'E';
		*digit += 1;
		y *= 10;
	}
	y /= 10;
	return (y);
}

// time : O(1)
// space: O(1)
int	f_atoi(char *src, char *err)
{
	long int	y;
	size_t		digit;
	size_t		sign;

	if (src[0] == '0' && src[1] == '\0')
		return (0);
	digit = 0;
	sign = 0;
	if (src[digit] == '-')
		sign = 1;
	digit = sign;
	y = f_atolongi(src, err, &digit, sign);
	if (sign == 1)
		y *= -1;
	if (src[digit] != '\0' && digit >= 11 + sign)
	{
		*err = 'E';
		return (-1);
	}
	if (y < -2147483648 || y > 2147483647)
	{
		*err = 'E';
		return (-1);
	}
	return ((int) y);
}

int	main(int len, char **str)
{
	int		fd;
	char	*line;
	char	err;
	size_t	max;

	err = 'K';
	if (len < 3)
		return (0);
	max = (size_t) f_atoi(str[2], &err);
	if (err == 'E')
		return (0);
	fd = open(str[1], 'r');
	if (fd < 0)
		return (0);
	line = get_next_line(fd, 0);
	if (line == NULL)
		return (0);
	while (max > 0 && line != NULL)
	{
		write(1, ">>> ", 4);
		write(1, line, knight_of_coin(line, '\0'));
		free(line);
		line = get_next_line(fd, 0);
		max -= 1;
	}
	if (line != NULL)
		free(line);
	get_next_line(fd, 1);
	return (0);
}
*/

/*
int	main(int len, char **str)
{
	int				fd;
	t_temperance	*angel;
	char			ambition;

	if (len < 2)
		return (0);
	fd = open(str[1], 'r');
	if (fd < 0)
		return (0);
	ambition = 1;
	ace_of_cup(1, &angel);
	if (angel == NULL)
		return (0);
	the_chariot(fd, &ambition, &angel);
	if (angel == NULL)
		return (0);
	write(1, angel->arr, angel->length);
	write(1, "\n~ end\n", 7);
	free(angel->arr);
	free(angel);
	return (0);
}
*/

int	main(int len, char **str)
{
	int		fd;
	char	*line;

	if (len < 2)
		return (0);
	fd = open(str[1], 'r');
	if (fd < 0)
		return (0);
	line = get_next_line(fd, 0);
	if (line == NULL)
		return (0);
	while (line != NULL)
	{
		write(1, ">>> ", 5);
		write(1, line, knight_of_coin(line, '\0'));
		free(line);
		line = get_next_line(fd, 0);
	}
	return (0);
}

/*
cc -Wall -Wextra -Werror src/get_next_line/test.c src/get_next_line/get_next_line.c src/get_next_line/utils.c
valgrind --leak-check=full ./bin/get_next_line.out test/fdf/10-2.fdf
*/
