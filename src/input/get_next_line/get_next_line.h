/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 10:28:15 by phsottat          #+#    #+#             */
/*   Updated: 2026/08/24 19:18:21 by phsottat         ###   ########.fr       */
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
char			*get_next_line(int fd, t_dream anchor);

// open_file.c
t_temperance	**three_of_cups(t_temperance **group, const char *friends);
int				open_dir_file(const char *file_name,
					const char *dir, t_file_mode mode);

// utils.c
size_t			knight_of_coin(const char *str, char stop);
void			*queen_of_coin(size_t elem_size, const char *comment);
char			*ace_of_coin(const char *src, size_t length, size_t capacity);
t_temperance	*two_of_cups(t_temperance **l_cup, char c);

#endif
