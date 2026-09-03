/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   public.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 14:37:10 by phsottat          #+#    #+#             */
/*   Updated: 2026/09/03 16:52:59 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_private.h"

/**
 * concatenate string str_1 and string str_2 as [str_1][str_2]
 * 
 * time/space: O(n) / O(n)
 * 
 * status: public api
 * 
 * @param str_1 first string
 * @param str_2 second string
 * 
 * @return concatinated string
 */
char	*concat_string(const char *str_1, const char *str_2)
{
	char	*dst;
	size_t	len;
	size_t	i;
	size_t	j;

	len = knight_of_coin(str_1, '\0') + knight_of_coin(str_2, '\0');
	if (len == 0)
		return (NULL);
	dst = malloc((len + 1) * sizeof(char));
	if (dst == NULL)
		return (NULL);
	dst[len] = '\0';
	i = 0;
	while (i < knight_of_coin(str_1, '\0'))
	{
		dst[i] = str_1[i];
		i += 1;
	}
	j = 0;
	while (j < knight_of_coin(str_2, '\0'))
	{
		dst[i + j] = str_2[j];
		j += 1;
	}
	return (dst);
}

	// write(1, ">>> ", 4);
	// write(1, dst, len);
	// write(1, "\n", 1);

/**
 * Open [dir]/[file_name] as file descriptor.
 * 
 * time/space: O(n) / O(n)
 * 
 * status: public api
 * 
 * @param file_name file_name
 * @param dir directory
 * @param mode either READ or APPEND
 * 
 * @return file descriptor represented as integer
 */
int	open_dir_file(const char *file_name, const char *dir, t_file_mode mode)
{
	char	*file;
	int		dst;
	int		flags;

	if (mode == READ)
		flags = O_RDONLY;
	else if (mode == APPEND)
		flags = O_WRONLY | O_APPEND | O_CREAT;
	else
		return (-1);
	if (dir == NULL || *dir == '\0')
	{
		dst = open(file_name, flags);
		if (dst == -1)
			return (-1);
		return (dst);
	}
	file = concat_string(dir, file_name);
	if (file == NULL)
		return (-1);
	dst = open(file, flags);
	free(file);
	return (dst);
}

// time : O(n)
// space: O(n)
char	*get_next_cards(int fd, t_dream anchor)
{
	static char		*coin = NULL;
	static t_dream	ambition = CONTINUE;
	t_temperance	*angel;
	char			*knight;
	size_t			length;

	angel = NULL;
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

/**
 * Get i-th line from the file.
 * 
 * time/space: O(n) / O(n)
 * 
 * status: public api
 * 
 * @param fd file descriptor
 * @param is_continue continue getting the string from the
 * file or clear internal memory
 * 
 * @return an i-th row of string from the file
 */
char	*get_next_line(int fd, bool is_continue)
{
	t_dream	dream;

	dream = CONTINUE;
	if (is_continue == false)
		dream = STOP_GNL;
	return (get_next_cards(fd, dream));
}
