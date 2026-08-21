#include"window.h"

// time : O(1)
// space: O(1)
bool	is_2dhook_valid(const t_2d_hook *src,
	e_drawing_target drawing_target)
{
	bool	aphantasia;

	aphantasia = true;
	if (drawing_target == E_MINIMALISM)
		aphantasia = false;
	if (drawing_target == E_MOTIF
		&& src != NULL && src->master_piece.motif != NULL
		&& src->master_piece.motif->length > 0
		&& src->master_piece.motif->arr != NULL)
		aphantasia = false;
	if (drawing_target == E_STILL_LIFE
		&& src != NULL && src->master_piece.still_life != NULL
		&& (is_triangle_arr_valid(&(src->master_piece.still_life->faces)) == true
			|| is_triangle_arr_valid(
				&(src->master_piece.still_life->edges)) == true))
		aphantasia = false;
	if (src != NULL && src->mlx != NULL && src->img != NULL
		&& src->img->width * src->img->height > 0
		&& aphantasia == false
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

// time : O(1)
// space: O(1)
t_2d_camera	init_2d_camera(size_t width, size_t height)
{
	t_2d_camera	camera;

	camera.offset.x = 0;
	camera.offset.y = 0;
	camera.zoom = 1.0;
	camera.window_size.x = width;
	camera.window_size.y = height;
	return (camera);
}

// time : O(1)
// space: O(1)
t_line	connecting_2d_point_pair(t_2d_int p1, t_2d_int p2)
{
	t_line	dst;

	dst.p1 = p1;
	dst.p2 = p2;
	return (dst);
}
