/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_private.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 14:35:31 by phsottat          #+#    #+#             */
/*   Updated: 2026/08/29 14:38:42 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_PRIVATE_H
# define GET_NEXT_LINE_PRIVATE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdbool.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct t_temperance
{
	size_t	length;
	size_t	capacity;
	char	*arr;
}	t_temperance;

typedef enum t_dream
{
	CONTINUE,
	STOP_CHARIOT,
	STOP_GNL,
	STOP_NEWLINE
}	t_dream;

typedef enum t_file_mode
{
	READ = 'r',
	APPEND = 'a',
}	t_file_mode;

// get_next_line.c

t_temperance	*ace_of_cup(size_t capacity, t_temperance **cup);
t_dream			the_lost_treasure(t_dream *ambition,
					char **coin, t_temperance **angel);
t_dream			king_gnu(char **coin, t_dream *ambition,
					t_dream anchor, t_temperance **angel);
char			the_chariot(int fd, t_dream *ambition, t_temperance **angel);

// utils.c

size_t			knight_of_coin(const char *str, char stop);
char			*ace_of_coin(const char *src, size_t length, size_t capacity);
t_temperance	**three_of_cups(t_temperance **group, const char *friends);

#endif
