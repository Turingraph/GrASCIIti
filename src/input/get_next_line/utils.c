#include "get_next_line.h"

// time : O(n)
// space: O(1)
size_t	knight_of_coin(const char *str, char stop)
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
// space: O(1)
void	*queen_of_coin(size_t elem_size, const char *comment)
{
	void	*dst;

	dst = (void *)malloc(elem_size);
	if (dst == NULL)
	{
		if (comment != NULL && *comment != '\0')
		{
			write(1, "Malloc Fail: ", 14);
			write(1, comment, knight_of_coin(comment, '\0'));
		}
	}
	return (dst);
}

// time : O(n)
// space: O(n)
char	*ace_of_coin(const char *src, size_t length, size_t capacity)
{
	char	*coin;
	size_t	i;

	if (capacity == 0)
		capacity = length;
	if (capacity == 0)
		return (NULL);
	coin = (char *)queen_of_coin(sizeof(char) * (capacity + 1), "GNL/ace_of_coin\n");
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

// time : O(1)
// space: O(1)
t_temperance	*two_of_cups(t_temperance **left_cup, char c)
{
	t_temperance	*right_cup;

	if (left_cup == NULL || *left_cup == NULL)
		return (NULL);
	if ((*left_cup)->length < (*left_cup)->capacity)
	{
		(*left_cup)->arr[(*left_cup)->length] = c;
		(*left_cup)->length += 1;
		return (*left_cup);
	}
	right_cup = (t_temperance *)queen_of_coin(sizeof(t_temperance), "GNL/two_of_cups\n");
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
t_temperance	**three_of_cups(t_temperance **group, const char *friends)
{
	while (friends != NULL && group != NULL && *group != NULL && *friends != '\0')
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
