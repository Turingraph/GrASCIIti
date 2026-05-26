#include "get_next_line.h"

// time : O(n)
// space: O(n)
t_temperance	*ace_of_cup(size_t capacity, t_temperance **cup)
{
	*cup = (t_temperance *)malloc_talk(sizeof(t_temperance), "GNL/ace_of_cup\n");
	if (*cup == NULL)
		return (NULL);
	(*cup)->length = 0;
	(*cup)->capacity = capacity;
	(*cup)->arr = ace_of_coin("\0", 0, capacity);
	if ((*cup)->arr == NULL)
	{
		free(*cup);
		return (NULL);
	}
	return (*cup);
}

// time : O(1)
// space: O(1)
char	free_line(char *ambition, char **coin)
{
	*ambition = 2;
	if (*coin != NULL)
		free(*coin);
	*coin = NULL;
	return (0);
}

// time : O(n)
// space: O(n)
char	king_of_coin(char **coin, char *ambition, char anchor, t_temperance **angel)
{
	if (anchor == 2 || BUFFER_SIZE <= 0)
	{
		free((*angel)->arr);
		free((*angel));
		*angel = NULL;
		*ambition = 2;
		return (0);
	}
	if (anchor == 1 || *ambition == 2)
		return (free_line(ambition, coin));
	if (ace_of_cup(1, angel) == NULL)
		return (free_line(ambition, coin));
	if (*coin != NULL)
	{
		if (three_of_cups(angel, *coin) == NULL)
			return (free_line(ambition, coin));
		if (*coin != NULL)
			free(*coin);
		*coin = NULL;
	}
	return (1);
}

// time : O(n)
// space: O(n)
char	the_chariot(int fd, char *ambition, t_temperance **angel)
{
	char	stop;
	char	*coin;

	if (*ambition != (char) 1)
		return (1);
	stop = 0;
	while (stop == 0)
	{
		coin = ace_of_coin("\0", 0, BUFFER_SIZE);
		if (coin == NULL)
			return (king_of_coin(NULL, ambition, 2, angel));
		read(fd, coin, BUFFER_SIZE);
		if (three_of_cups(angel, coin) == NULL
			|| knight_of_coin(coin, '\n') < BUFFER_SIZE)
			stop = 1;
		if (knight_of_coin(coin, '\0') < BUFFER_SIZE)
			*ambition = 0;
		free(coin);
	}
	if (*angel == NULL)
	{
		*ambition = 2;
		return (0);
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

	if (king_of_coin(&coin, &ambition, anchor, &angel) == 0)
		return (NULL);
	if (the_chariot(fd, &ambition, &angel) == 0)
		return (NULL);
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
