/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 10:33:14 by phsottat          #+#    #+#             */
/*   Updated: 2026/08/24 10:41:06 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

// options for mode
// 1.	READ
// 2.	APPEND
// time : O(n)
// space: O(n)
int	open_dir_file(const char *file_name, const char *dir,
	t_file_mode mode)
{
	t_temperance	*file;
	int				dst;

	if (dir == NULL || *dir == '\0')
	{
		dst = open(file_name, mode);
		if (dst < 1)
			return (1);
		return (dst);
	}
	file = NULL;
	ace_of_cup(1, &file);
	if (file == NULL)
		return (1);
	three_of_cups(&file, dir);
	three_of_cups(&file, file_name);
	if (file == NULL)
		return (1);
	dst = open(file->arr, mode);
	free(file->arr);
	free(file);
	return (dst);
}
