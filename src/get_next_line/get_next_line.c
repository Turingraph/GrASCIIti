#include "get_next_line.h"

// time : O(n)
// space: O(1)
size_t	knight_of_coin(char *str, char stop)
{
	size_t	i;

	i = 0;
	while (*str != '\0' && *str != stop)
	{
		i += 1;
		str += 1;
	}
	return (i);
}

// time : O(n)
// space: O(n)
char	the_chariot(int fd, char *ambition, t_temperance **angel)
{
	char	stop;
	char	*coin;

	if (*ambition == 0)
		return (1);
	stop = 0;
	if (*angel == NULL)
		return (0);
	while (stop == 0)
	{
		coin = ace_of_coin("\0", 0, BUFFER_SIZE);
		if (coin == NULL)
		{
			free((*angel)->arr);
			free((*angel));
			*angel = NULL;
			*ambition = 2;
			return (0);
		}
		read(fd, coin, BUFFER_SIZE);
		if (three_of_cups(angel, coin) == NULL
			|| knight_of_coin(coin, '\n') < BUFFER_SIZE)
			stop = 1;
		if (knight_of_coin(coin, '\0') < BUFFER_SIZE)
			*ambition = 0;
		free(coin);
	}
	return (1);
}

// time : O(n)
// space: O(n)
char	king_gnl(char **coin, t_temperance **angel, char *ambition)
{
	if (ace_of_cup(1, angel) == NULL)
	{
		if (*coin != NULL)
			free(*coin);
		*ambition = 2;
		return (0);
	}
	if (*coin != NULL)
	{
		three_of_cups(angel, *coin);
		free(*coin);
		*coin = NULL;
	}
	return (1);
}

// time : O(n)
// space: O(n)
char	*get_next_line(int fd, char anchor)
{
	static char		*coin = NULL;
	static char		ambition = 1;
	t_temperance	*angel;
	char			*knight;
	size_t			length;

	if (anchor == 1 || ambition == 2 || BUFFER_SIZE <= 0)
	{
		if (coin != NULL)
			free(coin);
		coin = NULL;
		ambition = 2;
		return (NULL);
	}
	if (king_gnl(&coin, &angel, &ambition) == 0)
		return (NULL);
	if (the_chariot(fd, &ambition, &angel) == 0)
		return (NULL);
	if (angel->length == 0)
	{
		free(angel->arr);
		free(angel);
		ambition = 2;
		return (NULL);
	}
	length = knight_of_coin(angel->arr, '\n');
	if (angel->arr[length] == '\n')
		length += 1;
	knight = ace_of_coin(angel->arr, length, 0);
	coin = ace_of_coin(angel->arr + length,
		knight_of_coin(angel->arr + length, '\0'), 0);
	free(angel->arr);
	free(angel);
	return (knight);
}

// char	*get_next_line(int fd)
// {
// 	return (king_of_coin(fd, 0));
// }
