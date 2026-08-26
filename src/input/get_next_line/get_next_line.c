#include "get_next_line_private.h"

// time : O(n)
// space: O(n)
t_temperance	*ace_of_cup(size_t capacity, t_temperance **cup)
{
	if (cup == NULL)
		return (NULL);
	*cup = (t_temperance *)queen_of_coin(sizeof(t_temperance));
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
e_dream	the_lost_treasure(e_dream *ambition, char **coin, t_temperance **angel)
{
	if (angel != NULL && *(angel) != NULL)
	{
		free((*angel)->arr);
		free((*angel));
		*angel = NULL;
	}
	if (coin != NULL)
	{
		free(*coin);
		*coin = NULL;
	}
	if (ambition == NULL)
		return (STOP_GNL);
	*ambition = STOP_GNL;
	return (STOP_GNL);
}

// time : O(n)
// space: O(n)
e_dream	king_gnu(char **coin, e_dream *ambition, e_dream anchor, t_temperance **angel)
{
	if (anchor == CONTINUE)
		*ambition = CONTINUE;
	if (anchor == STOP_GNL || BUFFER_SIZE <= 0 || *ambition == STOP_GNL)
		return (the_lost_treasure(ambition, coin, angel));
	if (ace_of_cup(1, angel) == NULL)
		return (the_lost_treasure(ambition, coin, angel));
	if (*coin != NULL)
	{
		if (three_of_cups(angel, *coin) == NULL)
			return (the_lost_treasure(ambition, coin, angel));
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

