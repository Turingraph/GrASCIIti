/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 10:24:32 by phsottat          #+#    #+#             */
/*   Updated: 2026/08/24 10:25:28 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// time : O(n)
// space: O(1)
size_t	f_split_len(const char *input, const char *space)
{
	size_t	i;
	size_t	y;

	if (input == NULL || space == NULL)
		return (0);
	y = 0;
	i = 0;
	while (input[i] != '\0')
	{
		if (f_isspace(input[i], space) == 0)
		{
			while (f_isspace(input[i], space) == 0 && input[i] != '\0')
				i += 1;
			y += 1;
		}
		else
			i += 1;
	}
	return (y);
}

// time : O(n)
// space: O(1)
char	*f_create_copy_text(const char *input, const char *space)
{
	char	*dst;
	size_t	dst_len;
	size_t	i;

	dst_len = 0;
	while (input[dst_len] != '\0' && f_isspace(input[dst_len], space) == 0)
		dst_len += 1;
	dst = (char *)malloc_talk(sizeof(char) * (dst_len + 1),
			"LIB/split.c/f_create_copy_text\n");
	if (dst == NULL)
		return (NULL);
	dst[dst_len] = '\0';
	i = 0;
	while (input[i] != '\0' && f_isspace(input[i], space) == 0)
	{
		dst[i] = input[i];
		i += 1;
	}
	return (dst);
}

// time : O(n)
// space: O(1)
char	**f_split_push(const char *input, char **dst, const char *space)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	while (input[i] != '\0')
	{
		if (f_isspace(input[i], space) == 0)
		{
			dst[j] = f_create_copy_text(input + i, space);
			if (dst[j] == NULL)
			{
				free_2d_arr((void **) dst, j);
				write(1, "Malloc Fail: LIB/split.c/f_split_push\n", 22);
				return (NULL);
			}
			while (f_isspace(input[i], space) == 0 && input[i] != '\0')
				i += 1;
			j += 1;
		}
		else
			i += 1;
	}
	return (dst);
}

// time : O(n)
// space: O(n)
char	**f_split(const char *input, const char *space)
{
	char	**dst;
	size_t	dst_len;

	if (input == NULL || space == NULL)
		return (NULL);
	dst_len = f_split_len(input, space);
	if (dst_len == 0)
		return (NULL);
	dst = (char **)malloc_talk(sizeof(char *) * (dst_len + 1),
			"LIB/split.c/f_split\n");
	if (dst == NULL)
		return (NULL);
	dst[dst_len] = NULL;
	return (f_split_push(input, dst, space));
}
