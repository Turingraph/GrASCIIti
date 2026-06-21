#include "get_next_line.h"

// time : O(n)
// space: O(n)
t_temperance	*ace_of_cup(size_t capacity, t_temperance **cup)
{
	*cup = (t_temperance *)queen_of_coin(sizeof(t_temperance), "GNL/ace_of_cup\n");
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
e_dream	the_lost_treasure(e_dream *ambition, char **coin)
{
	*ambition = STOP_GNL;
	if (*coin != NULL)
		free(*coin);
	*coin = NULL;
	return (STOP_GNL);
}

// time : O(n)
// space: O(n)
e_dream	king_gnu(char **coin, e_dream *ambition, e_dream anchor, t_temperance **angel)
{
	if (anchor == STOP_GNL || BUFFER_SIZE <= 0)
	{
		free((*angel)->arr);
		free((*angel));
		*angel = NULL;
		*ambition = STOP_GNL;
		return (STOP_GNL);
	}
	if (anchor == STOP_GNL || *ambition == STOP_GNL)
		return (the_lost_treasure(ambition, coin));
	if (ace_of_cup(1, angel) == NULL)
		return (the_lost_treasure(ambition, coin));
	if (*coin != NULL)
	{
		if (three_of_cups(angel, *coin) == NULL)
			return (the_lost_treasure(ambition, coin));
		if (*coin != NULL)
			free(*coin);
		*coin = NULL;
	}
	return (CONTINUE);
}

// time : O(n)
// space: O(n)
char	the_chariot(int fd, e_dream *ambition, t_temperance **angel)
{
	e_dream	stop;
	char	*coin;

	if (*ambition != CONTINUE)
		return (STOP_CHARIOT);
	stop = CONTINUE;
	while (stop == CONTINUE)
	{
		coin = ace_of_coin("\0", 0, BUFFER_SIZE);
		if (coin == NULL)
			return (king_gnu(NULL, ambition, 2, angel));
		read(fd, coin, BUFFER_SIZE);
		if (three_of_cups(angel, coin) == NULL
			|| knight_of_coin(coin, '\n') < BUFFER_SIZE)
			stop = STOP_NEWLINE;
		if (knight_of_coin(coin, '\0') < BUFFER_SIZE)
			*ambition = STOP_CHARIOT;
		free(coin);
	}
	if (*angel == NULL)
	{
		*ambition = STOP_GNL;
		return (STOP_GNL);
	}
	return (CONTINUE);
}

// time : O(n)
// space: O(n)
char	*get_next_line(int fd, e_dream anchor)
{
	static char		*coin = NULL;
	static e_dream	ambition = CONTINUE;
	t_temperance	*angel;
	char			*knight;
	size_t			length;

	if (king_gnu(&coin, &ambition, anchor, &angel) == STOP_GNL)
		return (NULL);
	if (the_chariot(fd, &ambition, &angel) == STOP_GNL)
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
