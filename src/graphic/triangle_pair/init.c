#include"triangle_pair.h"

// time : O(1)
// space: O(1)
void	*free_triangle(t_triangle *src)
{
	if (src != NULL)
	{
		if (src->p1 != NULL)
			free(src->p1);
		if (src->p2 != NULL)
			free(src->p2);
		if (src->p3 != NULL)
			free(src->p3);
		free(src);
	}
	return (NULL);
}

// time : O(1)
// space: O(1)
t_triangle	*init_triangle()
{
	t_triangle	*dst;

	dst = malloc_talk(sizeof(t_triangle),
		"mesh/mesh.c/init_triangle\n");
	if (dst == NULL)
		return (NULL);
	dst->r = (unsigned char)255;
	dst->g = (unsigned char)255;
	dst->b = (unsigned char)255;
	dst->a = (unsigned char)0;
	dst->p1 = create_3d_vector(0, 0, 0);
	dst->p2 = create_3d_vector(0, 0, 0);
	dst->p3 = create_3d_vector(0, 0, 0);
	if (dst->p1 == NULL || dst->p2 == NULL || dst->p3 == NULL)
	{
		free_triangle(dst);
		return (NULL);
	}
	return (dst);
}

// time : O(n)
// space: O(1)
void	*free_triangle_arr(t_triangle_arr *arr)
{
	size_t	i;

	i = 0;
	while (arr != NULL && arr->arr != NULL && i < arr->capacity)
	{
		free_triangle(arr->arr[i]);
		i += 1;
	}
	if (arr != NULL && arr->arr != NULL)
		free(arr->arr);
	if (arr != NULL)
		free(arr);
	return (NULL);
}

// time : O(1)
// space: O(1)
t_triangle_arr	*init_triangle_arr(size_t length)
{
	t_triangle_arr	*dst;

	if (length < 1)
		return (NULL);
	dst = malloc_talk(sizeof(t_triangle_arr),
		"mesh/init.c/init_triangle_arr\n");
	if (dst == NULL)
		return (NULL);
	dst->length = 0;
	dst->capacity = length;
	dst->arr = malloc_talk(sizeof(t_triangle *) * length,
		"mesh/init.c/init_triangle_arr\n");
	if (dst->arr == NULL)
	{
		free(dst);
		return (NULL);
	}
	return (dst);
}

// time : O(1)
// space: O(1)
char	fdf_side_detection(t_table_fdf *src, size_t row, size_t col, char axis)
{
	if (axis == 'x' && src->arr[row][col] > 0 && src->arr[row][col + 1] > 0 && ((row == 0)
		|| (row > 0 && src->arr[row - 1][col] <= 0 && src->arr[row - 1][col + 1] <= 0)
		|| (row < src->row - 1 && src->arr[row + 1][col] <= 0 && src->arr[row + 1][col + 1] <= 0)
		|| (row + 1 == src->row - 1)))
		return ('x');
	if (axis == 'y' && src->arr[row][col] > 0 && src->arr[row + 1][col] > 0 && ((col == 0)
		|| (col > 0 && src->arr[row][col - 1] <= 0 && src->arr[row + 1][col - 1] <= 0)
		|| (col < src->col - 1 && src->arr[row][col + 1] <= 0 && src->arr[row + 1][col + 1] <= 0)
		|| (col + 1 == src->col - 1)))
		return ('y');
	if (axis == 'l' && row + 1 < src->row && col + 1 < src->col
		&& src->arr[row][col] > 0 && src->arr[row + 1][col + 1] > 0
		&& (src->arr[row][col + 1] <= 0 || src->arr[row + 1][col] <= 0))
		return ('l');
	if ((axis == 'r' && row + 1 < src->row && col + 1 < src->col
		&& src->arr[row + 1][col] > 0 && src->arr[row][col + 1] > 0)
		&& ((src->arr[row][col] <= 0 || src->arr[row + 1][col + 1] <= 0)))
		return ('r');
	return ('n');
}
