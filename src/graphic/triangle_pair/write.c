#include"triangle_pair.h"

// time : O(1)
// space: O(1)
void	write_3d_vector(int fd, double *vec_v)
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
