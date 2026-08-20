#include"window.h"

/*
int	main(void)
{
	t_line	src = {.p1 = {.x = 100, .y = 300}, .p2 = {.x = 500, .y = 400}};

	view_rectangle(src, 
		f_rgba_to_int32(255, 155, 100, 255),
		f_rgba_to_int32(123, 155, 244, 255));
	return (0);
}
*/

int	main(void)
{
	t_ink32	ink = {.color = f_rgba_to_int32(155, 15, 100, 255), .thickness = 5, .type = E_LINE};

	view_rectangle(3, ink, f_rgba_to_int32(123, 155, 244, 255));
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./coding_examples/out/graphic/window/window.out
*/