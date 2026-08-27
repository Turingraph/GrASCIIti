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

typedef enum e_dream
{
	CONTINUE,
	STOP_CHARIOT,
	STOP_GNL,
	STOP_NEWLINE
}	e_dream;

typedef enum e_file_mode
{
	READ = 'r',
	APPEND = 'a',
}	e_file_mode;

// get_next_line.c
t_temperance	*ace_of_cup(size_t capacity, t_temperance **cup);
e_dream			the_lost_treasure(e_dream *ambition,
					char **coin, t_temperance **angel);
e_dream			king_gnu(char **coin, e_dream *ambition,
					e_dream anchor, t_temperance **angel);
char			the_chariot(int fd, e_dream *ambition, t_temperance **angel);

// utils.c
size_t			knight_of_coin(const char *str, char stop);
void			*queen_of_coin(size_t elem_size);
char			*ace_of_coin(const char *src, size_t length, size_t capacity);
t_temperance	**three_of_cups(t_temperance **group, const char *friends);

#endif
