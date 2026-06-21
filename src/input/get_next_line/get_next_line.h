#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct t_temperance t_temperance;

struct t_temperance
{
	size_t	length;
	size_t	capacity;
	char	*arr;
};

typedef enum e_dream e_dream;

enum e_dream
{
	CONTINUE,
	STOP_CHARIOT,
	STOP_GNL,
	STOP_NEWLINE
};

// utils.c
size_t			knight_of_coin(char *str, char stop);
void			*queen_of_coin(size_t elem_size, char *comment);
char			*ace_of_coin(char *src, size_t length, size_t capacity);
t_temperance	**three_of_cups(t_temperance **group, char *friends);

// get_next_line.c

// char			*get_next_line(int fd);
char			*get_next_line(int fd, e_dream anchor);

#endif
