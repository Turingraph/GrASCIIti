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
size_t			knight_of_coin(char *str, char stop);
void			*malloc_talk(size_t elem_size, char *comment);
char			*ace_of_coin(char *src, size_t length, size_t capacity);
t_temperance	**three_of_cups(t_temperance **group, char *friends);

// get_next_line.c

// char			*get_next_line(int fd);
char			*get_next_line(int fd, char anchor);

#endif
