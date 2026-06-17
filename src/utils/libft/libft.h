#ifndef LIBFT_H
# define LIBFT_H

#include <unistd.h>
#include <stdlib.h>
#include "../type/type.h"

// arr.c
void			free_nest_arr(void **arr, size_t len);
void			*malloc_talk(size_t elem_size, char *comment);
unsigned char	**init_null_char_arr(size_t row, size_t col);
void			copy_int_arr(int *dst, int *src, size_t len);
void			copy_uchar_arr(unsigned char *dst, unsigned char *src, size_t len);

// atoi.c
int				f_atoi(char *src, char *err, char *base, size_t digits);
void			ft_putnbr_fd(int n, int fd, char *base, size_t digits);

// split.c
size_t			f_split_len(char *input, char *space);
char			**f_split(char *input, char *space);

// utils.c
char			f_isspace(char s, char *space);
char			f_strncmp(char *dst, char *src, size_t n);
void			non_numerical_file_warning(char *file, size_t i_th_line, char error_mode);
size_t			f_strlen(char *str);

#endif
