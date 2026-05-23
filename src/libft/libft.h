#ifndef LIBFT_H
# define LIBFT_H

#include <unistd.h>
#include <stdlib.h>

// arr.c
void	free_strarr(char **arr, size_t len);
size_t	f_strlen(char *str);
char	f_isspace(char s, char *space);

// atoi.c
int		f_atoi(char *src, char *err);

// putnbr_fd.c
void	ft_putnbr_fd(int n, int fd);

// split.c
size_t	f_split_len(char *input, char *space);
char	**f_split(char *input, char *space);

#endif
