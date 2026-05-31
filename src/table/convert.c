#include "table.h"

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
			free_nest_arr((void **)table->table, table->row);
		if (table->a != NULL)
			free_nest_arr((void **)table->a, table->row);
		if (table->r != NULL)
			free_nest_arr((void **)table->r, table->row);
		if (table->g != NULL)
			free_nest_arr((void **)table->g, table->row);
		if (table->b != NULL)
			free_nest_arr((void **)table->b, table->row);
		free(table);
	}
	return (NULL);
}

// time : O(n)
// space: O(1)
t_table_fdf	*init_table_fdf(size_t row, size_t col)
{
	t_table_fdf	*dst;

	dst = (t_table_fdf *)malloc_talk(sizeof(t_table_fdf), "table/convert.c\n");
	if (dst == NULL)
		return (NULL);
	dst->row = row;
	dst->col = col;
	dst->table = init_null_int_arr(row, col);
	dst->r = init_null_char_arr(row, col);
	dst->g = init_null_char_arr(row, col);
	dst->b = init_null_char_arr(row, col);
	dst->a = init_null_char_arr(row, col);
	if (dst->r == NULL || dst->g == NULL || dst->b == NULL
		|| dst->a == NULL|| dst->table == NULL)
	{
		free_table_fdf(dst);
		return (NULL);
	}
	return (dst);
}

// time : O(n)
// space: O(1)
void	copy_int_arr(int *dst, int *src, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		dst[i] = src[i];
		i += 1;
	}
}

// time : O(n)
// space: O(n)
t_table_fdf	*llist_to_table_fdf(t_llist_fdf *src)
{
	t_table_fdf	*dst;
	size_t		i;
	size_t		j;
	
	dst = init_table_fdf(get_dim(src, 0), get_dim(src, 1));
	if (dst == NULL)
		return (NULL);
	i = 0;
	while (i < dst->row)
	{
		copy_int_arr(dst->table[i], src->arr, dst->row);
		j = 0;
		while (j < dst->col && src->rgb != NULL && src->rgb[i] != NULL)
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
