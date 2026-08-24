/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 10:34:02 by phsottat          #+#    #+#             */
/*   Updated: 2026/08/24 16:25:08 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	coin = (char *)queen_of_coin(sizeof(char) * (capacity + 1),
			"GNL/ace_of_coin\n");
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
t_temperance	*two_of_coins(t_temperance *src)
{
	t_temperance	*dst;

	if (src == NULL || src->arr == NULL)
		return (NULL);
	dst = (t_temperance *)malloc(sizeof(t_temperance));
	if (dst == NULL)
		return (NULL);
	dst->capacity = src->capacity * 2;
	dst->length = src->length;
	dst->arr = ace_of_coin(src->arr,
			src->length, src->capacity * 2);
	return (dst);
}

// time : O(1)
// space: O(1)
t_temperance	*two_of_cups(t_temperance **l_cup, char c)
{
	t_temperance	*r_cup;

	if (l_cup == NULL || *l_cup == NULL || (*l_cup)->arr == NULL)
		return (NULL);
	if ((*l_cup)->length < (*l_cup)->capacity)
	{
		(*l_cup)->arr[(*l_cup)->length] = c;
		(*l_cup)->length += 1;
		return (*l_cup);
	}
	r_cup = two_of_coins(*l_cup);
	if (r_cup == NULL || r_cup->arr == NULL)
	{
		free(r_cup);
		return (NULL);
	}
	free((*l_cup)->arr);
	free((*l_cup));
	*l_cup = r_cup;
	return (two_of_cups(l_cup, c));
}
