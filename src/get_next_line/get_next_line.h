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

// utils.c
char			*ace_of_coin(char *src, size_t length, size_t capacity);
t_temperance	*ace_of_cup(size_t capacity, t_temperance **cup);
t_temperance	*two_of_cups(t_temperance **left_cup, char c);
t_temperance	**three_of_cups(t_temperance **group, char *friends);

// get_next_line.c
size_t			knight_of_coin(char *str, char stop);
char			the_chariot(int fd, char *ambition, t_temperance **angel);
// char			*get_next_line(int fd);
char			*get_next_line(int fd, char anchor);

#endif
