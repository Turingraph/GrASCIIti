/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 15:26:10 by phsottat          #+#    #+#             */
/*   Updated: 2026/01/26 09:24:31 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct t_temperance
{
	size_t	length;
	size_t	capacity;
	char	*arr;
}	t_temperance;

// get_next_line_utils.c
char			*ace_of_coin(char *src, size_t length, size_t capacity);
t_temperance	*ace_of_cup(size_t capacity, char create_arr);
t_temperance	**three_of_cups(t_temperance **group, char *friends);

// get_next_line.c
size_t			knight_of_coin(char *str, char stop);
char			the_chariot(int fd, t_temperance **angel, char *ambition);
char			*get_next_line(int fd);

#endif
