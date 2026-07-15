#ifndef LIBFT_H
# define LIBFT_H

#include <unistd.h>
#include <stdlib.h>
#include "../type/type.h"

// arr.c
void			free_2d_arr(void **arr, size_t len);
void			*malloc_talk(size_t elem_size, const char *comment);
void			write_2d_index(int max_col, int row, int col);

// ascii.c
char			mirror_tune(char a, bool is_left);
int				f_ctoi(char a, const char *dict);
void			ft_put_ascii_fd(int fd, int cell, const char *dict,
					bool is_left);

// atoi.c
int				f_atoi(const char *src, bool *is_int, const char *base, size_t digits);
size_t			ft_putnbr_fd(int n, int fd, const char *base, size_t digits);

// split.c
size_t			f_split_len(const char *input, const char *space);
char			**f_split(const char *input, const char *space);

// utils.c
char			f_isspace(char s, const char *space);
size_t			f_strlen(const char *str);

#endif
