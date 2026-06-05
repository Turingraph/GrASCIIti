#ifndef INPUT_H
# define INPUT_H

#include <stdlib.h>
#include "../get_next_line/get_next_line.h"
#include "../../utils/libft/libft.h"
#include "../../utils/type/type.h"

// all_lines.c
void		free_llist_fdf(t_llist_fdf *src);
t_llist_fdf	*all_lines(char *file, int fd, t_llist_fdf *(*one_line)(char *));
void		write_all_lines(int fd, t_llist_fdf *llist, char show_rgb, size_t n_digits);

// ascii.c
t_llist_fdf	*init_llist_fdf(size_t line_len);
t_llist_fdf	*one_ascii_line(char *line);

// fdf.c
t_llist_fdf	*one_fdf_line(char *line);

#endif
