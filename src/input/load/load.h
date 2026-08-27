#ifndef LOAD_H
# define LOAD_H

#include "../get_next_line/get_next_line.h"
#include "../../utils/libft/libft.h"

/*
Note that
*	load.h is for utilized by only src/input/table module and not by the user.
*	load_test.h is for checking if src/input/load/ works as expected.
*/

// all_files.c

t_load_fdf_arr	open_fdf_file(const char *file_name, const char *dir,
					t_load_fdf (*parse_line)(char *line));

// ascii.c

void			ft_put_ascii_fd(int fd, int cell, const char *dict,
					bool is_left);

// init.c

void			free_load_fdf_arr(t_load_fdf_arr *src);

// parse.c

t_load_fdf		parse_ascii_line_cheche01(char *line);
t_load_fdf		parse_ascii_line_standard(char *line);
t_load_fdf		parse_ascii_line_chungaloider(char *line);
t_load_fdf		parse_fdf_line_rgba(char *line);
t_load_fdf		parse_fdf_line_bw(char *line);

#endif
