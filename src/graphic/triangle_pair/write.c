#include"triangle_pair.h"

// time : O(1)
// space: O(1)
void	write_3d_vector(int fd, float *vec_v)
{
	write(fd, "(", 1);
	ft_putnbr_fd(f_floor(vec_v[0]), fd, "0123456789", 3);
	write(fd, ", ", 2);
	ft_putnbr_fd(f_floor(vec_v[1]), fd, "0123456789", 3);
	write(fd, ", ", 2);
	ft_putnbr_fd(f_floor(vec_v[2]), fd, "0123456789", 3);
	write(fd, "),\t", 2);
}

// time : O(1)
// space: O(1)
void	write_triangle(int fd, t_triangle src)
{
	write_3d_vector(fd, src.p1);
	write_3d_vector(fd, src.p2);
	write_3d_vector(fd, src.p3);
	write(fd, "0x", 2);
	ft_putnbr_fd(src.r, fd, "0123456789abcdef", 2);
	ft_putnbr_fd(src.g, fd, "0123456789abcdef", 2);
	ft_putnbr_fd(src.b, fd, "0123456789abcdef", 2);
	ft_putnbr_fd(src.a, fd, "0123456789abcdef", 2);
	write(fd, "\n", 1);
}

// time : O(1)
// space: O(1)
void	write_triangle_arr(int fd, t_triangle_arr src)
{
	size_t	i;

	i = 0;
	while (src.arr != NULL && i < src.length)
	{
		write_triangle(fd, src.arr[i]);
		i += 1;
	}
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
