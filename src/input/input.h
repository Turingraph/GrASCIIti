#ifndef INPUT_H
# define INPUT_H

#include <stdlib.h>
#include "get_next_line.h"

// https://stackoverflow.com/questions/36217352/
// unknown-type-name-error-in-c

typedef struct t_llist_int t_llist_int;

struct t_llist_int
{
	int			*arr;
	size_t		len;
	t_llist_int	*next;
};

// ascii.c
t_llist_int	*create_ascii_file(char *file_name);

// fdf.c
t_llist_int	*create_fdf_file(char *file_name);

// int.c
void		free_matrix(float **matrix, size_t len);
size_t		len_llist(t_llist_int *ll, size_t *width);
float		**create_matrix(t_llist_int *ll, size_t not_sharp, size_t col, size_t row);

// split_space.c
size_t		f_split_len(char *input);
void		f_free_nested_string(char **dst, size_t len);
char		**f_split_space(char *input);

// utils.c
void		free_llist(t_llist_int *ll);
int			f_atoi(char *src, char *err);
char		f_isspace(char s);

#endif
