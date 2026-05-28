#ifndef LIBFT_H
# define LIBFT_H

#include <unistd.h>
#include <stdlib.h>

typedef struct t_rgb t_rgb;

struct t_rgb
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	unsigned char	a;
};

// arr.c
void	free_nest_arr(void **arr, size_t len);
size_t	f_strlen(char *str);
void	**create_null_arr(size_t col, size_t row, size_t elem_size, char *comment);
void	*malloc_talk(size_t elem_size, char *comment);
void	copy_nested_arr(void **dst, void **src, size_t col, size_t row_x_elem_size);

// atoi.c
int		f_atoi(char *src, char *err, char *base, size_t len);
void	ft_putnbr_fd(int n, int fd, char *base);

// split.c
size_t	f_split_len(char *input, char *space);
char	**f_split(char *input, char *space);

// utils.c
char	f_isspace(char s, char *space);
t_rgb	*f_atorgb(char *src, char *err, t_rgb *dst);
char	f_strncmp(char *dst, char *src, size_t n);
void	non_numerical_file_warning(char *file, size_t i_th_line, char error_mode);

#endif
