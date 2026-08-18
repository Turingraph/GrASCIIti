#include"view.h"

// time : O(n)
// space: O(1)
void	draw_grids(mlx_image_t *dst, size_t resolution)
{
	size_t	i;
	size_t	j;
	t_line	boundary;

	if (dst != NULL)
	{
		boundary = get_allcells_horizontal_boundary(
				dst->width, dst->height, resolution);
		i = 0;
		while (i < boundary.p2.y - boundary.p1.y)
		{
			j = 0;
			while (j < boundary.p2.x - boundary.p1.x)
			{
				j += 1;
			}
			i += 1;
		}
	}
}

// time : O(n)
// space: O(n)
int	view_grids(size_t resolution, int32_t background_color, t_ink32 ink)
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_2d_camera	camera_2d;

	mlx = mlx_init(1920, 1080, "Subset at 4:42pm", true);
	img = handle_mlx_error(mlx);
	if (img == NULL)
		return (-1);
	color_background_mlx(img, background_color);
	draw_grids(img, resolution, ink);
	if (-1 == mlx_image_to_window(mlx, img, 0, 0))
	{
		mlx_terminate(mlx);
		return (-1);
	}
	mlx_loop(mlx);
	mlx_delete_image(mlx, img);
	mlx_terminate(mlx);
	return (1);
}
