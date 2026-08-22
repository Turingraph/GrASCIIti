#include"window.h"

// time : O(1)
// space: O(1)
t_2d_polygon	triangle_2d_line_projection(t_triangle *src, float radius)
{
	t_2d_polygon	polygon;

	polygon.arr = NULL;
	polygon.is_loop = true;
	polygon.length = 0;
	if (src == NULL || radius == 0
		|| src->p1 == NULL || src->p2 == NULL || src->p3 == NULL)
		return (polygon);
	polygon.arr = (t_complex *)malloc(sizeof(t_complex) * 3);
	if (polygon.arr == NULL)
		return (polygon);
	polygon.arr[0].re = src->p1[0] / (2.0 * radius) + 1.0 / 2.0;
	polygon.arr[0].im = src->p1[1] / (2.0 * radius) + 1.0 / 2.0;
	polygon.arr[1].re = src->p2[0] / (2.0 * radius) + 1.0 / 2.0;
	polygon.arr[1].im = src->p2[1] / (2.0 * radius) + 1.0 / 2.0;
	polygon.arr[2].re = src->p3[0] / (2.0 * radius) + 1.0 / 2.0;
	polygon.arr[2].im = src->p3[1] / (2.0 * radius) + 1.0 / 2.0;
	return (polygon);
}

// time : O(n)
// space: O(1)
void	draw_still_life(t_2d_hook *hook, bool is_draw, bool no_face)
{
	t_triangle_arr	arr;
	t_2d_polygon	polygon;
	size_t			i;
	float			radius;
	t_line			boundary;
	t_ink32			ink;

	if (is_2dhook_valid(hook, E_STILL_LIFE) == false)
		return ;
	arr = hook->master_piece.still_life->faces;
	if (no_face == true)
		arr = hook->master_piece.still_life->edges;
	radius = f_max3(arr.width_x, arr.width_y, arr.width_z) / 2;
	boundary.p1 = world_to_screen_2d(*(hook->camera),
			hook->master_piece.tiles.offset.p1);
	boundary.p2.x = world_to_screen_xy(hook->camera->window_size.x,
			hook->master_piece.tiles.offset.p1.re + hook->camera->window_size.x);
	boundary.p2.y = world_to_screen_xy(hook->camera->window_size.y,
			hook->master_piece.tiles.offset.p1.im + hook->camera->window_size.y);
	ink.thickness = hook->master_piece.thickness;
	ink.type = hook->master_piece.artstyle;
	ink.color = hook->master_piece.background;
	i = 0;
	while (arr.arr != NULL && i < arr.length)
	{
		polygon = triangle_2d_line_projection(&(arr.arr[i]), radius);
		if (is_draw == true)
			ink.color = f_rgba_to_int32(arr.arr[i].r, arr.arr[i].g,
					arr.arr[i].b, arr.arr[i].a);
		draw_polygon_mlx(hook->img, &polygon, ink, boundary);
		free((void *)(polygon.arr));
		i += 1;
	}
}

	// if (is_draw == true && no_face == false)
	// {
	// 	write(1, "radius: ", 9);
	// 	ft_putnbr_fd((int)radius, 1, "0123456789", 1);
	// 	write(1, "\n", 1);
	// }
	// else
	// 	write(1, "radius: 0\n", 11);
