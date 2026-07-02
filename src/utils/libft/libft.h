#ifndef LIBFT_H
# define LIBFT_H

#include <unistd.h>
#include <stdlib.h>
#include "../type/type.h"

// arr.c
void			free_2d_arr(void **arr, size_t len);
void			*malloc_talk(size_t elem_size, const char *comment);
void			copy_uchar_arr(unsigned char *dst, const unsigned char *src, size_t len, size_t scale_dim);
unsigned char	**init_2d_uchar_arr(size_t row, size_t col);

// atoi.c
int				f_atoi(char *src, e_bool *is_int, const char *base, size_t digits);
size_t			ft_putnbr_fd(int n, int fd, const char *base, size_t digits);

// split.c
size_t			f_split_len(const char *input, const char *space);
char			**f_split(const char *input, const char *space);

// utils.c
char			f_isspace(char s, char *space);
size_t			f_strlen(char *str);

#endif
