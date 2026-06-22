#include"triangle_pair.h"

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

// time : O(1)
// space: O(1)
unsigned char	triangle_side_rgb(unsigned char **src, size_t row, size_t col, char mode)
{
	if (mode == 'x' && src != NULL && src[row] != NULL)
		return ((unsigned char)f_interval(f_round((src[row][col] + src[row][col + 1]) / 2), 0, 255));
	if (mode == 'y' && src != NULL && src[row] != NULL && src[row + 1] != NULL)
		return ((unsigned char)f_interval(f_round((src[row][col] + src[row + 1][col]) / 2), 0, 255));
	if (mode == 'l' && src != NULL && src[row] != NULL && src[row + 1] != NULL)
		return ((unsigned char)f_interval(f_round((src[row][col] + src[row + 1][col + 1]) / 2), 0, 255));
	if (mode == 'r' && src[row] != NULL && src[row + 1] != NULL)
		return ((unsigned char)f_interval(f_round((src[row][col + 1] + src[row + 1][col]) / 2), 0, 255));
	return (0);
}

// time : O(1)
// space: O(1)
unsigned char	triangle_face_rgb(t_table_fdf src, size_t row, size_t col, e_rgba rgb_type)
{
	float	drgb;

	drgb = 0;
	if (rgb_type == RED && src.r != NULL && src.r[row] != NULL && src.r[row + 1] != NULL)
		drgb = (float)((int)src.r[row][col] + (int)src.r[row + 1][col] + (int)src.r[row][col + 1] + (int)src.r[row + 1][col + 1]) / 4;
	if (rgb_type == GREEN && src.g != NULL && src.g[row] != NULL && src.g[row + 1] != NULL)
		drgb = (float)((int)src.g[row][col] + (int)src.g[row + 1][col] + (int)src.g[row][col + 1] + (int)src.g[row + 1][col + 1]) / 4;
	if (rgb_type == BLUE && src.b != NULL && src.b[row] != NULL && src.b[row + 1] != NULL)
		drgb = (float)((int)src.b[row][col] + (int)src.b[row + 1][col] + (int)src.b[row][col + 1] + (int)src.b[row + 1][col + 1]) / 4;
	if (rgb_type == ALPHA && src.a != NULL && src.a[row] != NULL && src.a[row + 1] != NULL)
		drgb = (float)((int)src.a[row][col] + (int)src.a[row + 1][col] + (int)src.a[row][col + 1] + (int)src.a[row + 1][col + 1]) / 4;
	return ((unsigned char)f_round(f_interval(drgb, 0, 255)));
}
