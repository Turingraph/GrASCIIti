#include"triangle_pair.h"

// time : O(1)
// space: O(1)
void	*free_triangle(t_triangle src)
{
	if (src.p1 != NULL)
		free(src.p1);
	if (src.p2 != NULL)
		free(src.p2);
	if (src.p3 != NULL)
		free(src.p3);
	return (NULL);
}

// time : O(1)
// space: O(1)
void	free_triangle_arr(t_triangle_arr src)
{
	size_t	i;

	i = 0;
	while (src.arr != NULL && i < src.capacity)
	{
		free_triangle(src.arr[i]);
		i += 1;
	}
	if (src.arr != NULL)
		free(src.arr);
}

// time : O(1)
// space: O(1)
t_triangle	init_triangle()
{
	t_triangle	dst;

	dst.r = (unsigned char)255;
	dst.g = (unsigned char)255;
	dst.b = (unsigned char)255;
	dst.a = (unsigned char)0;
	dst.p1 = create_3d_vector(0, 0, 0);
	dst.p2 = create_3d_vector(0, 0, 0);
	dst.p3 = create_3d_vector(0, 0, 0);
	return (dst);
}

// time : O(1)
// space: O(1)
t_triangle_arr	init_triangle_arr(size_t length)
{
	t_triangle_arr	dst;

	dst.length = 0;
	dst.capacity = length;
	dst.arr = NULL;
	if (length > 0)
		dst.arr = malloc_talk(sizeof(t_triangle) * length,
			"mesh/init.c/init_triangle_arr\n");
	return (dst);
}

// time : O(1)
// space: O(1)
char	fdf_side_detection(t_table_fdf src, size_t row, size_t col, char axis)
{
	if (row >= src.row || col >= src.col)
		return ('n');
	if ((axis == 'l' || axis == 'r') && (row + 1 >= src.row || col + 1 >= src.col))
		return ('n');
	if (axis == 'x' && row < src.row && col + 1 < src.col
		&& src.arr[row][col] > 0 && src.arr[row][col + 1] > 0 && ((row == 0)
		|| (row > 0 && src.arr[row - 1][col] <= 0 && src.arr[row - 1][col + 1] <= 0)
		|| (row < src.row - 1 && src.arr[row + 1][col] <= 0 && src.arr[row + 1][col + 1] <= 0)
		|| (row + 1 == src.row - 1)))
		return ('x');
	if (axis == 'y' && row + 1 < src.row && col < src.col
		&& src.arr[row][col] > 0 && src.arr[row + 1][col] > 0 && ((col == 0)
		|| (col > 0 && src.arr[row][col - 1] <= 0 && src.arr[row + 1][col - 1] <= 0)
		|| (col < src.col - 1 && src.arr[row][col + 1] <= 0 && src.arr[row + 1][col + 1] <= 0)
		|| (col + 1 == src.col - 1)))
		return ('y');
	if (axis == 'l' && row + 1 < src.row && col + 1 < src.col
		&& src.arr[row][col] > 0 && src.arr[row + 1][col + 1] > 0
		&& (src.arr[row][col + 1] <= 0 || src.arr[row + 1][col] <= 0))
		return ('l');
	if ((axis == 'r' && row + 1 < src.row && col + 1 < src.col
		&& src.arr[row + 1][col] > 0 && src.arr[row][col + 1] > 0)
		&& ((src.arr[row][col] <= 0 || src.arr[row + 1][col + 1] <= 0)))
		return ('r');
	return ('n');
}
