#include "triangle_pair.h"

// time : O(1)
// space: O(1)
void	write_triangle_pair_geometry(const t_table_fdf *src, size_t row, size_t col)
{
	if (src != NULL && (size_t)(row + 1) < src->row
		&& (size_t)(col + 1) < src->col && src->arr != NULL
		&& src->arr[row] != NULL && src->arr[row + 1] != NULL)
	{
		ft_putnbr_fd(src->arr[row][col], 1, "0123456789", 1);
		write(1, "\t", 1);
		ft_putnbr_fd(src->arr[row][col + 1], 1, "0123456789", 1);
		write(1, "\n", 1);
		ft_putnbr_fd(src->arr[row + 1][col], 1, "0123456789", 1);
		write(1, "\t", 1);
		ft_putnbr_fd(src->arr[row + 1][col + 1], 1, "0123456789", 1);
		write(1, "\n", 1);
	}
}
