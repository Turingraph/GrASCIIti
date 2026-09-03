/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 14:37:16 by phsottat          #+#    #+#             */
/*   Updated: 2026/08/29 14:44:19 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_private.h"

/**
 * Count how many characters that the string have before 
 * encounter the target characters and/or '\0'.
 * 
 * time/space: O(n) / O(1)
 * 
 * status: public api
 * 
 * @param str string
 * @param stop the target character
 * 
 * @return a number of all characters before the target character and/or '\0'
 */
size_t	knight_of_coin(const char *str, char stop)
{
	size_t	i;

	i = 0;
	while (str != NULL && str[i] != '\0' && str[i] != stop)
		i += 1;
	return (i);
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
t_temperance	*two_of_coin(t_temperance *src)
{
	t_temperance	*dst;

	if (src == NULL || src->arr == NULL
		|| src->capacity == 0 || src->length == 0)
		return (NULL);
	dst = (t_temperance *)malloc(sizeof(t_temperance));
	if (dst == NULL)
		return (NULL);
	dst->length = src->length;
	dst->capacity = src->length * 2;
	dst->arr = ace_of_coin(src->arr, src->length, src->capacity * 2);
	if (dst->arr == NULL)
		free(dst);
	return (dst);
}

// time : O(1)
// space: O(1)
t_temperance	*two_of_cups(t_temperance **left_cup, char c)
{
	t_temperance	*right_cup;

	if (left_cup == NULL || *left_cup == NULL
		|| (*left_cup)->arr == NULL)
		return (NULL);
	if ((*left_cup)->length < (*left_cup)->capacity)
	{
		(*left_cup)->arr[(*left_cup)->length] = c;
		(*left_cup)->length += 1;
		return (*left_cup);
	}
	right_cup = two_of_coin(*left_cup);
	free((*left_cup)->arr);
	free((*left_cup));
	*left_cup = right_cup;
	return (two_of_cups(left_cup, c));
}

// time : O(n)
// space: O(1)
t_temperance	**three_of_cups(t_temperance **group, const char *friends)
{
	while (friends != NULL && group != NULL
		&& *group != NULL && *friends != '\0')
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
