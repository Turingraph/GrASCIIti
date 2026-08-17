#include"view_line.h"

/*
Reference
*	https://youtu.be/pg1NpMmPv48?si=eAqEWgsZeGCyIC8K
*	https://www.desmos.com/calculator/ujafhqcj4e
*/

int	main(void)
{
	float		u_0 = 0.25;
	float		u_1 = 0.396447;
	float		u_2 = 0.08579;
	t_complex	shape_00[] = {
		{.re = 0, .im = 2 * u_0},
		{.re = u_0, .im = u_1},
		{.re = u_0, .im = u_0},
		{.re = u_1, .im = u_0},
		{.re = 2 * u_0, .im = 0},
		{.re = 0, .im = 0}
	};
	t_complex	shape_01[] = {
		{.re = 1 - 0, .im = 2 * u_0},
		{.re = 1 - u_0, .im = u_1},
		{.re = 1 - u_0, .im = u_0},
		{.re = 1 - u_1, .im = u_0},
		{.re = 1 - 2 * u_0, .im = 0},
		{.re = 1 - 0, .im = 0}
	};
	t_complex	shape_02[] = {
		{.re = 0, .im = 1 - 2 * u_0},
		{.re = u_0, .im = 1 - u_1},
		{.re = u_0, .im = 1 - u_0},
		{.re = u_1, .im = 1 - u_0},
		{.re = 2 * u_0, .im = 1 - 0},
		{.re = 0, .im = 1 - 0}
	};
	t_complex	shape_03[] = {
		{.re = 1 - 0, .im = 1 - 2 * u_0},
		{.re = 1 - u_0, .im = 1 - u_1},
		{.re = 1 - u_0, .im = 1 - u_0},
		{.re = 1 - u_1, .im = 1 - u_0},
		{.re = 1 - 2 * u_0, .im = 1 - 0},
		{.re = 1 - 0, .im = 1 - 0}
	};
	t_2d_int		tiling = {.x = 240, .y = 240};
	t_ink32			ink = {
		.color = (255 << 24 | 0 << 16 | 0 << 8 | 255),
		.thickness = 50, .type = E_LINE};
	t_ink32			ink2 = {
		.color = (100 << 24 | 255 << 16 | 255 << 8 | 255),
		.thickness = 20, .type = E_LINE};
	t_2d_polygon	polygon_00 = {.arr = shape_00, .is_loop = false, .length = 5};
	t_2d_polygon	polygon_01 = {.arr = shape_01, .is_loop = false, .length = 5};
	t_2d_polygon	polygon_02 = {.arr = shape_02, .is_loop = false, .length = 5};
	t_2d_polygon	polygon_03 = {.arr = shape_03, .is_loop = false, .length = 5};
	t_complex		thickline_00[] = {
		{.re = u_2, .im = 0},
		{.re = 2 * u_0, .im = 1}
	};
	t_complex		thickline_01[] = {
		{.re = 2 * u_0, .im = 1},
		{.re = 1 - u_2, .im = 0}
	};
	t_complex		thickline_02[] = {
		{.re = u_2, .im = 1},
		{.re = 2 * u_0, .im = 0}
	};
	t_complex		thickline_03[] = {
		{.re = 2 * u_0, .im = 0},
		{.re = 1 - u_2, .im = 1}
	};
	t_2d_polygon	thickline_arr_00 = {.arr = thickline_00, .is_loop = false, .length = 2};
	t_2d_polygon	thickline_arr_01 = {.arr = thickline_01, .is_loop = false, .length = 2};
	t_2d_polygon	thickline_arr_02 = {.arr = thickline_02, .is_loop = false, .length = 2};
	t_2d_polygon	thickline_arr_03 = {.arr = thickline_03, .is_loop = false, .length = 2};
	t_islamic_arr	islamic_art = {
		.length = 8,
		.arr = (const t_islamic_art []){
			{
				.polygon = thickline_arr_00,
				.ink = ink,
				.tiling = tiling
			},
			{
				.polygon = thickline_arr_01,
				.ink = ink,
				.tiling = tiling
			},
			{
				.polygon = thickline_arr_02,
				.ink = ink,
				.tiling = tiling
			},
			{
				.polygon = thickline_arr_03,
				.ink = ink,
				.tiling = tiling
			},
			{
				.polygon = polygon_00,
				.ink = ink2,
				.tiling = tiling
			},
			{
				.polygon = polygon_01,
				.ink = ink2,
				.tiling = tiling
			},
			{
				.polygon = polygon_02,
				.ink = ink2,
				.tiling = tiling
			},
			{
				.polygon = polygon_03,
				.ink = ink2,
				.tiling = tiling
			},
		}
	};
	int32_t	background = f_rgba_to_int32(123, 155, 244, 255);

	view_islamic_tiling(&islamic_art, background);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./coding_examples/out/graphic/view_line/islamic_art.out
*/