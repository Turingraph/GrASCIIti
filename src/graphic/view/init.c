#include"view.h"

// // time : O(1)
// // space: O(1)
size_t	get_window_dimension_fdf(size_t row, size_t col, char axis)
{
	size_t	window_size;

	window_size = 810;
	if (row > window_size || col > window_size || row * col == 0)
		return (0);
	if (row == col || (row < col && axis == 0) || (row > col && axis == 1))
		return (window_size);
	if (row > col && axis == 0)
		return (col * (size_t)f_floor((float)window_size / (float)row));
	if (row < col && axis == 1)
		return (row * (size_t)f_floor((float)window_size / (float)col));
	return (0);
}

// time : O(n)
// space: O(1)
mlx_image_t	*solve_1st_mlx_error(mlx_t *mlx, t_table_fdf *table)
{
	mlx_image_t	*dst;

	if (mlx == NULL || table == NULL)
	{
		free_table_fdf(table);
		if (mlx != NULL)
			mlx_terminate(mlx);
		return (NULL);
	}
	dst = mlx_new_image(mlx, table->col, table->row);
	if (dst == NULL)
	{
		free_table_fdf(table);
		mlx_terminate(mlx);
		return(NULL);
	}
	return (dst);
}

// time : O(n)
// space: O(n)
int	view_table_fdf(const t_table_fdf *src)
{
	t_table_fdf	scale_src;
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_view		var;

	if (src != NULL && src->row * src->col > 0)
	{
		scale_src = scale_window_dimension_fdf(src);
		mlx = mlx_init(1440, 810, "Subset at 4:42pm", true);
		img = solve_1st_mlx_error(mlx, &scale_src);
		if (img == NULL)
			return (-1);
		paint_table_on_image(&scale_src, img);
		if (-1 == mlx_image_to_window(mlx, img,
			1440 / 2 - get_window_dimension_fdf(src->row, src->col, 0) / 2,
			810 / 2 - get_window_dimension_fdf(src->row, src->col, 1) / 2))
		{
			mlx_terminate(mlx);
			return(-1);
		}
		var.img = img;
		var.mlx = mlx;
		mlx_key_hook(mlx, &hook_pan, &var);
		mlx_loop(mlx);
		mlx_delete_image(mlx, img);
		mlx_terminate(mlx);
		free_table_fdf(&scale_src);
	}
	return (1);
}

/*
cc -Wall -Wextra -Werror -Wall -Wextra -Werror -Iinclude -c graphic/view/init.c -o obj/graphic/view/init.o
graphic/view/init.c: In function ‘view_table_fdf’:
graphic/view/init.c:68:35: error: passing argument 2 of ‘mlx_key_hook’ from incompatible pointer type [-Werror=incompatible-pointer-types]
   68 |                 mlx_key_hook(mlx, &hook_pan, NULL);
      |                                   ^~~~~~~~~
      |                                   |
      |                                   void (*)(mlx_t *, mlx_key_data_t,  mlx_image_t *) {aka void (*)(struct mlx *, struct mlx_key_data,  struct mlx_image *)}
In file included from graphic/view/view.h:6,
                 from graphic/view/init.c:1:
graphic/view/MLX42.h:767:51: note: expected ‘mlx_keyfunc’ {aka ‘void (*)(struct mlx_key_data,  void *)’} but argument is of type ‘void (*)(mlx_t *, mlx_key_data_t,  mlx_image_t *)’ {aka ‘void (*)(struct mlx *, struct mlx_key_data,  struct mlx_image *)’}
  767 | MLX_API void mlx_key_hook(mlx_t* mlx, mlx_keyfunc func, void* param);
      |                                       ~~~~~~~~~~~~^~~~
cc1: all warnings being treated as errors
make[1]: *** [Makefile:92: obj/graphic/view/init.o] Error 1
rm obj/graphic/view/hook.o obj/graphic/view/color.o
make[1]: Leaving directory '/home/pc/Desktop/GrASCIIfi/src'
make[1]: Entering directory '/home/pc/Desktop/GrASCIIfi/unit_test'
cc -Wall -Wextra -Werror -o out/input/get_next_line/test_by_compare.out obj/input/get_next_line/test_by_compare.o -L. ../src/lib/debug.a ../src/lib/get_next_line.a
/usr/bin/ld: cannot find ../src/lib/debug.a: No such file or directory
collect2: error: ld returned 1 exit status
make[1]: *** [Makefile:54: out/input/get_next_line/test_by_compare.out] Error 1
make[1]: Leaving directory '/home/pc/Desktop/GrASCIIfi/unit_test'
make[1]: Entering directory '/home/pc/Desktop/GrASCIIfi/coding_examples'
cc -Wall -Wextra -Werror -o out/editor/convolve/gauss_h.out obj/editor/convolve/gauss_h.o -L. ../src/lib/convolve.a
/usr/bin/ld: cannot find ../src/lib/convolve.a: No such file or directory
collect2: error: ld returned 1 exit status
make[1]: *** [Makefile:43: out/editor/convolve/gauss_h.out] Error 1
make[1]: Leaving directory '/home/pc/Desktop/GrASCIIfi/coding_examples'
make: *** [Makefile:5: all] Error 2
pc@pc-System-Product-Name:~/Desktop/GrASCIIfi$ 

It seem my pan hook is not working and cause error.

*/