#ifndef LOAD_H
# define LOAD_H

#include "../get_next_line/get_next_line.h"
#include "../../utils/libft/libft.h"
#include "../../utils/type/type.h"

// all_files.c
t_load_fdf_arr	load_all_fdf_lines(int fd, t_load_fdf (*one_line)(char *line));

// ascii.c
t_load_fdf		one_ascii_line(char *line, char *dict);

// fdf.c
t_load_fdf		one_fdf_line(char *line);

// init.c
void			*free_load_fdf(t_load_fdf *src);
t_load_fdf		init_load_fdf(size_t line_len, e_bool is_rgb);
void			*free_load_fdf_arr(t_load_fdf_arr *src);
t_load_fdf_arr	init_load_fdf_arr(size_t length);

// shade.c
t_load_fdf		cheche_one_ascii_line(char *line);
t_load_fdf		std_one_ascii_line(char *line);
t_load_fdf		chungaloider_one_ascii_line(char *line);

// utils.c
unsigned char	f_rgb(char *str, size_t len, e_bool *rgb_warn);
void			write_load_fdf(int fd, t_load_fdf src, size_t digits, e_bool is_rgb);
void			write_load_fdf_arr(int fd, t_load_fdf_arr src, size_t digits, e_bool is_rgb);
void			warning_load_fdf(t_load_fdf dst, size_t i);

#endif
