#include"convolve.h"

int	main(void)
{
	t_table_fdf	table_a;
	t_table_fdf	table_b;
	t_matrix	kernel;
	size_t		half_dim;
	// int			output;
	// char		*dst_dir = "unit_test/editor/convolve/fdf_k/";
	char		*src_dir = "input_examples/fdf/";
	char			*arr[] = {
		"100-6.fdf",
		"20-60.fdf",
		"basictest.fdf",
		"elem.fdf",
		"julia.fdf",
		"pentenegpos.fdf",
		"prism_pyramid.fdf",
		"pyramide.fdf",
		"10-2.fdf",
		"42.fdf",
		"convolution_9.fdf",
		"elem2.fdf",
		"elem-fract.fdf",
		"large_plat.fdf",
		"plat.fdf",
		"pylone.fdf",
		"t1.fdf",
		"10-70.fdf",
		"50-4.fdf",
		"elem-col.fdf",
		"empty.fdf",
		"mars.fdf",
		"pnp_flat.fdf",
		"pyra.fdf",
		"t2.fdf",
	};
	size_t	  i;
	size_t	  length = 25;

	half_dim = 5;
	kernel = init_matrix(2 * half_dim + 1,
		2 * half_dim + 1,
		1.0 / ((2 * half_dim + 1) * (2 * half_dim + 1)));
	i = 0;
	while (i < length)
	{
		// output = open_dir_file(arr[i], dst_dir, APPEND);
		table_a = open_table_fdf_file(arr[i], src_dir,
				parse_ascii_line_chungaloider, true);
		table_b = convolve_hight(&table_a, kernel);
		// write_table_fdf(output, &table_a, 1, HEIGHT_ONLY);
		free_table_fdf(&table_a);
		free_table_fdf(&table_b);
		i += 1;
	}
	free_matrix(&kernel);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./unit_test/out/editor/convolve/fdf_k.out

*/
