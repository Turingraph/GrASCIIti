#ifndef GET_NEXT_LINE_PRIVATE_H
# define GET_NEXT_LINE_PRIVATE_H

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

typedef enum e_file_mode e_file_mode;

enum e_file_mode
{
	READ = 'r',
	APPEND = 'a',
};

// get_next_line.c
char	the_chariot(int fd, e_dream *ambition, t_temperance **angel);


// open_file.c
int				open_dir_file(const char *file_name,
					const char *dir, e_file_mode mode);
t_temperance	*ace_of_cup(size_t capacity, t_temperance **cup);

// utils.c
size_t			knight_of_coin(const char *str, char stop);
void			*queen_of_coin(size_t elem_size);
char			*ace_of_coin(const char *src, size_t length, size_t capacity);
t_temperance	**three_of_cups(t_temperance **group, const char *friends);

#endif
