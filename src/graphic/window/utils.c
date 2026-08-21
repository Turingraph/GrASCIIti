#include"window.h"

// time : O(1)
// space: O(1)
bool	is_2dhook_valid(const t_2d_hook *src)
{
	if (src != NULL && src->mlx != NULL && src->img != NULL
		&& src->img->width * src->img->height > 0
		&& src->camera != NULL)
		return (true);
	return (false);
}

// time : O(1)
// space: O(1)
bool	is_valid_key(mlx_key_data_t keydata)
{
	if (keydata.key == MLX_KEY_ESCAPE
		|| keydata.key == MLX_KEY_UP
		|| keydata.key == MLX_KEY_DOWN
		|| keydata.key == MLX_KEY_LEFT
		|| keydata.key == MLX_KEY_RIGHT)
		return (true);
	return (false);
}

// time : O(1)
// space: O(1)
void	write_line(t_line src)
{
	write(1, "write_line: ", 13);
	ft_putnbr_fd(src.p1.x, 1, "0123456789", 1);
	write(1, ", ", 2);
	ft_putnbr_fd(src.p1.y, 1, "0123456789", 1);
	write(1, " --> ", 5);
	ft_putnbr_fd(src.p2.x, 1, "0123456789", 1);
	write(1, ", ", 2);
	ft_putnbr_fd(src.p2.y, 1, "0123456789", 1);
	write(1, "\n", 1);
}
