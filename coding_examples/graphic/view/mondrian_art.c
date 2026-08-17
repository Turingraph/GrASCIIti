#include"view.h"

/*
Reference
*	https://en.wikipedia.org/wiki/Composition_with_Red,_Blue_and_Yellow

*/

int	main(void)
{
	t_complex		square_00[] = {{.re = 1.0 / 24.0, .im =  1.0  / 24.0}, {.re = 5.0 / 24.0, .im = 8.0  / 24.0}};
	t_complex		square_01[] = {{.re = 1.0 / 24.0, .im =  11.0 / 24.0}, {.re = 5.0 / 24.0, .im = 17.0 / 24.0}};
	t_complex		square_02[] = {{.re = 1.0 / 24.0, .im =  19.0 / 24.0}, {.re = 5.0 / 24.0, .im = 23.0 / 24.0}};
	t_complex		square_03[] = {{.re = 7.0 / 24.0, .im =  1.0  / 24.0}, {.re = 23.0 / 24.0, .im = 17.0 / 24.0}};
	t_complex		square_04[] = {{.re = 7.0 / 24.0, .im =  19.0 / 24.0}, {.re = 19.0 / 24.0, .im = 23.0 / 24.0}};
	t_complex		square_05[] = {{.re = 21.0 / 24.0, .im = 19.0 / 24.0}, {.re = 23.0 / 24.0, .im = 20.0 / 24.0}};
	t_complex		square_06[] = {{.re = 21.0 / 24.0, .im = 22.0 / 24.0}, {.re = 23.0 / 24.0, .im = 23.0 / 24.0}};
	t_2d_int		tiling = {.x = 240, .y = 240};
	t_2d_polygon	s_00 = {.arr = square_00, .is_loop = false, .length = 2};
	t_2d_polygon	s_01 = {.arr = square_01, .is_loop = false, .length = 2};
	t_2d_polygon	s_02 = {.arr = square_02, .is_loop = false, .length = 2};
	t_2d_polygon	s_03 = {.arr = square_03, .is_loop = false, .length = 2};
	t_2d_polygon	s_04 = {.arr = square_04, .is_loop = false, .length = 2};
	t_2d_polygon	s_05 = {.arr = square_05, .is_loop = false, .length = 2};
	t_2d_polygon	s_06 = {.arr = square_06, .is_loop = false, .length = 2};
	t_ink32			ink  = {.color = (255 << 24 | 0 << 16 | 0 << 8 | 255), .thickness = 0, .type = E_RECTANGLE};
	t_ink32			ink2 = {.color = (100 << 24 | 255 << 16 | 255 << 8 | 255), .thickness = 0, .type = E_RECTANGLE};
	t_islamic_arr	mondrian_art = {
		.length = 7,
		.arr = (const t_islamic_art []){
			{.polygon = s_00, .ink = ink, .tiling = tiling},
			{.polygon = s_01, .ink = ink, .tiling = tiling},
			{.polygon = s_02, .ink = ink2, .tiling = tiling},
			{.polygon = s_03, .ink = ink2, .tiling = tiling},
			{.polygon = s_04, .ink = ink, .tiling = tiling},
			{.polygon = s_05, .ink = ink, .tiling = tiling},
			{.polygon = s_06, .ink = ink2, .tiling = tiling},
		}
	};
	int32_t	background = f_rgba_to_int32(123, 155, 244, 255);

	view_islamic_tiling(&mondrian_art, background);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./coding_examples/out/graphic/view/zutomayo_isometric2.txt

*/