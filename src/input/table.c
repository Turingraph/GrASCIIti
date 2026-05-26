#include "input.h"

// time : O(n)
// space: O(1)
size_t	get_dim(t_llist_fdf *src, char dim)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	while (src != NULL)
	{
		if (j < src->len)
			j = src->len;
		src = src->next;
		i += 1;
	}
	if (dim == 0)
		return (i);
	return (j);
}

// time : O(n)
// space: O(1)
void	*free_table_fdf(t_table_fdf *table)
{
	if (table != NULL)
	{
		if (table->table != NULL)
			free_nest_arr((void **)table->table, table->col);
		if (table->a != NULL)
			free_nest_arr((void **)table->a, table->col);
		if (table->r != NULL)
			free_nest_arr((void **)table->a, table->col);
		if (table->g != NULL)
			free_nest_arr((void **)table->a, table->col);
		if (table->b != NULL)
			free_nest_arr((void **)table->a, table->col);
		free(table);
	}
	return (NULL);
}

// time : O(n)
// space: O(1)
t_table_fdf	*init_table(size_t col, size_t row)
{
	t_table_fdf	*dst;

	dst = (t_table_fdf *)malloc(sizeof(t_table_fdf));
	if (dst == NULL)
		return (NULL);
	dst->col = col;
	dst->row = row;
	dst->table = (int **)create_null_arr(col, row,
		sizeof(int), "input/table.c/init_table\n");
	dst->r = (unsigned char **)create_null_arr(col, row,
		sizeof(unsigned char), "input/table.c/init_table\n");
	dst->g = (unsigned char **)create_null_arr(col, row,
		sizeof(unsigned char), "input/table.c/init_table\n");
	dst->b = (unsigned char **)create_null_arr(col, row,
		sizeof(unsigned char), "input/table.c/init_table\n");
	dst->a = (unsigned char **)create_null_arr(col, row,
		sizeof(unsigned char), "input/table.c/init_table\n");
	if (dst->r == NULL || dst->g == NULL || dst->b == NULL
		|| dst->a == NULL|| dst->table == NULL)
	{
		free_table_fdf(dst);
		return (NULL);
	}
	return (dst);
}

// time : O(n)
// space: O(n)
t_table_fdf	*llist_to_table_fdf(t_llist_fdf *src)
{
	t_table_fdf	*dst;
	size_t		i;
	size_t		j;
	
	dst = init_table(get_dim(src, 0), get_dim(src, 1));
	if (dst == NULL)
		return (NULL);
	i = 0;
	while (i < dst->col)
	{
		copy_nested_arr((void **)&(dst->table[i]), (void **)&(src->arr), 1, dst->row * sizeof(int));
		j = 0;
		while (j < dst->row && src->rgb != NULL && src->rgb[i] != NULL)
		{
			dst->r[i][j] = src->rgb[i]->r;
			dst->g[i][j] = src->rgb[i]->g;
			dst->b[i][j] = src->rgb[i]->b;
			dst->a[i][j] = src->rgb[i]->a;
			j += 1;
		}
		src = src->next;
		i += 1;
	}
	return (dst);
}
