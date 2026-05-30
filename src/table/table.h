#ifndef TABLE_H
# define TABLE_H

#include <stdlib.h>
#include "../libft/libft.h"
#include "../type/type.h"

// table.c
void		*free_table_fdf(t_table_fdf *table);
t_table_fdf	*init_table(size_t col, size_t row);
t_table_fdf	*llist_to_table_fdf(t_llist_fdf *src);

#endif
