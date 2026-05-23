#include "get_next_line.h"

// time : O(n)
// space: O(n)
char	*ace_of_coin(char *src, size_t length, size_t capacity)
{
	char	*coin;
	size_t	i;

	if (capacity == 0)
		capacity = length;
	if (capacity == 0)
		return (NULL);
	coin = (char *)malloc(sizeof(char) * (capacity + 1));
	if (coin == NULL)
		return (NULL);
	coin[capacity] = '\0';
	i = 0;
	while (*src != '\0' && i < length && i < capacity)
	{
		coin[i] = *src;
		src += 1;
		i += 1;
	}
	while (i < capacity)
	{
		coin[i] = '\0';
		i += 1;
	}
	return (coin);
}

// time : O(n)
// space: O(n)
t_temperance	*ace_of_cup(size_t capacity, t_temperance **cup)
{
	*cup = (t_temperance *)malloc(sizeof(t_temperance));
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
t_temperance	*two_of_cups(t_temperance **left_cup, char c)
{
	t_temperance	*right_cup;

	if ((*left_cup)->length < (*left_cup)->capacity)
	{
		(*left_cup)->arr[(*left_cup)->length] = c;
		(*left_cup)->length += 1;
		return (*left_cup);
	}
	right_cup = (t_temperance *)malloc(sizeof(t_temperance));
	if (right_cup == NULL)
		return (NULL);
	right_cup->capacity = (*left_cup)->capacity * 2;
	right_cup->length = (*left_cup)->length;
	right_cup->arr = ace_of_coin((*left_cup)->arr,
		(*left_cup)->length, (*left_cup)->capacity * 2);
	if (right_cup->arr == NULL)
	{
		free(right_cup);
		return (NULL);
	}
	free((*left_cup)->arr);
	free((*left_cup));
	*left_cup = right_cup;
	return (two_of_cups(left_cup, c));
}

// time : O(n)
// space: O(1)
t_temperance	**three_of_cups(t_temperance **group, char *friends)
{
	while (*friends != '\0')
	{
		if (two_of_cups(group, *friends) == NULL)
		{
			free((*group)->arr);
			free((*group));
			*group = NULL;
			return (NULL);
		}
		friends += 1;
	}
	return (group);
}
