#include "display_private.h"

// time : O(1)
// space: O(1)
t_ink32	get_hook_ink32(t_2d_hook *hook, bool is_draw, t_2d_int ixiy,
	size_t thickness)
{
	t_ink32		ink;
	t_fdf		*fdf;

	fdf = hook->master_piece.fdf;
	ink.thickness = thickness;
	ink.color = hook->master_piece.artstyle.background_color;
	if (is_draw == true)
		ink.color = get_fdf_rgba_int32((const t_fdf *)fdf,
				ixiy.y * fdf->col + ixiy.x);
	else
		ink.color = hook->master_piece.artstyle.background_color;
	return (ink);
}

// time : O(1)
// space: O(1)
void	draw_circle_fdf(t_2d_int point,
	t_ink32 ink, t_2d_camera camera, mlx_image_t *img)
{
	t_circle	circle;
	t_boundary	boundary;

	if (is_circle_in_screen(camera, point, ink.thickness) == false)
		return ;
	boundary = get_all_area(img->height, img->width);
	circle.radius = ink.thickness;
	circle.x = point.x;
	circle.y = point.y;
	midpoint_circle_mlx(img, ink.color, circle, boundary);
}

// time : O(1)
// space: O(1)
void	draw_rectangle_fdf(t_line line, int32_t ink,
	t_2d_camera camera, mlx_image_t *img)
{
	t_line		rectangle_boundary;

	if (is_line_in_screen(camera, line) == false)
		return ;
	rectangle_boundary = get_all_area(img->height, img->width).sub_area;
	draw_rectangle_mlx(img, line, rectangle_boundary, ink);
}

// time : O(1)
// space: O(1)
void	draw_line_fdf(t_line line, t_ink32 ink,
	t_2d_camera camera, mlx_image_t *img)
{
	t_line		rectangle_boundary;

	rectangle_boundary = get_all_area(img->height, img->width).sub_area;
	if (is_line_in_screen(camera, line) == true)
		draw_mlx_straight_line(img, line, rectangle_boundary, ink);
	else
	{
		draw_circle_fdf(line.p1, ink, camera, img);
		draw_circle_fdf(line.p2, ink, camera, img);
	}
}

// time : O(1)
// space: O(1)
bool	is_2dhook_valid(const t_2d_hook *src)
{
	if (src == NULL
		|| src->camera == NULL
		|| src->img == NULL
		|| src->mlx == NULL
		|| is_fdf_valid(src->master_piece.fdf) == false)
		return (false);
	return (true);
}
