#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdbool.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

/*
Note that get_next_line.h is intended to be utilized by
1.	src/debug/debug/
2.	src/input/load/
*/

typedef enum e_file_mode
{
	READ = 'r',
	APPEND = 'a',
}	e_file_mode;

// public.c

int		open_dir_file(const char *file_name, const char *dir, e_file_mode mode);
char	*get_next_line(int fd, bool is_continue);
char	*concat_string(const char *str_1, const char *str_2);

// utils.c

size_t	knight_of_coin(const char *str, char stop);

#endif
