#ifndef LOAD_H
# define LOAD_H

#include "../get_next_line/get_next_line.h"
#include "../../utils/libft/libft.h"

// all_files.c
t_load_fdf_arr	load_all_fdf_lines(int fd, t_load_fdf (*one_line)(const char *line));
t_load_fdf_arr	open_fdf_file(const char *file_name, const char *dir,
					t_load_fdf (*one_line)(const char *line));

// ascii.c
t_load_fdf		one_ascii_line(const char *line, const char *dict);

// fdf.c
t_load_fdf		one_fdf_line(const char *line, e_bool is_rgb);

// init.c
void			*free_load_fdf(t_load_fdf *src);
t_load_fdf		init_load_fdf(size_t line_len, e_bool is_rgb);
void			*free_load_fdf_arr(t_load_fdf_arr *src);
t_load_fdf_arr	init_load_fdf_arr(size_t length);

// shade.c
t_load_fdf		cheche01_ascii_line(const char *line);
t_load_fdf		standard_ascii_line(const char *line);
t_load_fdf		chungaloider_ascii_line(const char *line);
t_load_fdf		rgba_fdf_line(const char *line);
t_load_fdf		bw_fdf_line(const char *line);

// utils.c
unsigned char	f_rgb(const char *str, size_t len, e_bool *rgb_warn);

// write_ascii.c
void	write_load_ascii_arr_cheche01(int fd, const t_load_fdf_arr *src);
void	write_load_ascii_arr_standard(int fd, const t_load_fdf_arr *src);
void	write_load_ascii_arr_chungaloider(int fd, const t_load_fdf_arr *src);

// write.c
void			write_load_fdf_arr(int fd, const t_load_fdf_arr *src,
					size_t digits, e_write_style write_style);
void			write_load_ascii_arr(int fd, const t_load_fdf_arr *src,
					const char *dict);
void			warning_load_fdf(const t_load_fdf *src, size_t i);

#endif
