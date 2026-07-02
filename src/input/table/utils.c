#include"table.h"

// time : O(1)
// space: O(1)
void	set_table_fdf_origin(t_table_fdf *dst, e_axis direction, size_t ith_position, size_t max_position)
{
	if (direction == AXIS_X && dst != NULL && ith_position <= max_position && max_position <= dst->col)
		dst->origin_x = (dst->col / max_position) * ith_position;
	if (direction == AXIS_Y && dst != NULL && ith_position <= max_position && max_position <= dst->col)
		dst->origin_y = (dst->row / max_position) * ith_position;
}

// time : O(1)
// space: O(1)
void	set_table_fdf_origin_4(t_table_fdf *dst, e_axis direction, char level)
{
	set_table_fdf_origin(dst, direction, level, 4);
}

// time : O(n^2)
// space: O(1)
void	copy_int_arr(int *dst, const int *src, size_t len, size_t scale_dim)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (dst != NULL && src != NULL && i < len)
	{
		j = 0;
		while (j < scale_dim)
		{
			dst[i * scale_dim + j] = src[i];
			j += 1;
		}
		i += 1;
	}
}

// time : O(n)
// space: O(n)
int	**init_2d_int_arr(size_t row, size_t col)
{
	size_t	i;
	int		**dst;

	dst = (int **)malloc_talk(sizeof(int **) * row, "table/arr.c/init_null_char_arr\n");
	if (dst == NULL)
		return (NULL);
	i = 0;
	while (i < row)
	{
		dst[i] = (int *)malloc_talk(sizeof(int *) * col, "table/arr.c/init_null_char_arr\n");
		if (dst[i] == NULL)
		{
			free_2d_arr((void *)dst, i);
			return (NULL);
		}
		i += 1;
	}
	return (dst);
}
