#include"view.h"

// time : O(n)
// space: O(1)
void	draw_rectangle_mlx(mlx_image_t *dst, t_line rectangle,
	t_line boundary, int32_t ink)
{
	t_boundary		sub_area;
	int				i;
	int				j;

	if (dst != NULL)
	{
		sub_area = init_rectangle_boundary(boundary,
				dst->height, dst->width);
		rectangle = init_rectangle(rectangle, sub_area);
		i = rectangle.p1.x;
		while (i <= rectangle.p2.x)
		{
			j = rectangle.p1.y;
			while (j <= rectangle.p2.y)
			{
				if (is_in_boundary(i, j, sub_area.sub_area) == true)
					mlx_put_pixel(dst, i, j, ink);
				j += 1;
			}
			i += 1;
		}
	}
}

// time : O(n)
// sapce: O(1)
void	draw_mondrian_tiling_mlx(mlx_image_t *dst, t_line rectangle, int32_t ink, t_2d_int tiling_area)
{
	size_t	i;
	size_t	j;
	t_line	tiling;

	i = 0;
	while (dst != NULL && tiling_area.y > 0 && i < f_floor(dst->height / tiling_area.y) + 1)
	{
		j = 0;
		while (tiling_area.x > 0 && j < f_floor(dst->width / tiling_area.x) + 1)
		{
			tiling = get_tiling(tiling_area, i, j);
			draw_rectangle_mlx(dst, rectangle, tiling, ink);
			j += 1;
		}
		i += 1;
	}
}

// time : O(n)
// sapce: O(1)
void	draw_mondrian_tiling_fmlx_unit(mlx_image_t *dst, const t_2d_polygon *polygon,
	int32_t ink, t_line boundary)
{
	size_t	i;
	t_line	line;

	i = 0;
	while (dst != NULL && polygon != NULL
		&& polygon->length > 0 && i < polygon->length - 1)
	{
		line = init_float_line(polygon->arr[i], polygon->arr[i + 1], boundary);
		draw_rectangle_mlx(dst, line, boundary, ink);
		i += 1;
	}
	if (dst != NULL && polygon != NULL
		&& polygon->length > 0 && i == polygon->length - 1
		&& polygon->is_loop == true)
	{
		line = init_float_line(polygon->arr[i], polygon->arr[0], boundary);
		draw_rectangle_mlx(dst, line, boundary, ink);
	}
}

// time : O(n)
// sapce: O(1)
void	draw_mondrian_tiling_fmlx(mlx_image_t *dst, const t_2d_polygon *polygon,
	int32_t ink, t_2d_int tiling_area)
{
	size_t	i;
	size_t	j;
	t_line	tiling;

	i = 0;
	while (dst != NULL && polygon != NULL && tiling_area.y > 0
		&& i < f_floor(dst->height / tiling_area.y) + 1)
	{
		j = 0;
		while (tiling_area.x > 0 && j < f_floor(dst->width / tiling_area.x) + 1)
		{
			tiling = get_tiling(tiling_area, i, j);
			draw_mondrian_tiling_fmlx_unit(dst, polygon, ink, tiling);
			j += 1;
		}
		i += 1;
	}
}
