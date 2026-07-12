#ifndef LOAD_H
# define LOAD_H

#include "../get_next_line/get_next_line.h"
#include "../../utils/libft/libft.h"

/*
ChatGPT Function Naming Recommendation
*	parse 		→ convert text to data
*	read/open 	→ read from file descriptor or file
*	write 		→ serialize to text
*	init/free 	→ object lifetime
*	copy 		→ duplicate metadata or containers
*	count 		→ measure without allocating
*	update 		→ modify existing objects
*/

// all_files.c
t_load_fdf_arr	load_all_fdf_lines(int fd, t_load_fdf (*parse_line)(const char *line));
t_load_fdf_arr	open_fdf_file(const char *file_name, const char *dir,
					t_load_fdf (*parse_line)(const char *line));

// ascii.c
t_load_fdf		parse_ascii_line(const char *line, const char *dict);

// fdf.c
t_load_fdf		parse_fdf_line(const char *line, e_bool is_rgb);

// init.c
void			*free_load_fdf(t_load_fdf *src);
t_load_fdf		init_load_fdf(size_t line_len, e_bool is_rgb);
void			*free_load_fdf_arr(t_load_fdf_arr *src);
t_load_fdf_arr	init_load_fdf_arr(size_t length);

// parse.c
t_load_fdf		parse_ascii_line_cheche01(const char *line);
t_load_fdf		parse_ascii_line_standard(const char *line);
t_load_fdf		parse_ascii_line_chungaloider(const char *line);
t_load_fdf		parse_fdf_line_rgba(const char *line);
t_load_fdf		parse_fdf_line_bw(const char *line);

// rgba.c
size_t	count_hex_digits(const char *line, size_t max);
void	update_rgba(const char *line, t_load_fdf *dst, size_t index);

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
