#include"load.h"

int	main(void)
{
	int				clone_examples;
	size_t			i;
	size_t			score;
	size_t			max_score = 16;
	t_load_fdf_arr	fdf_file;
	char			*arr[] = {
		"100-6.fdf",
		"10-70.fdf",
		"42.fdf",
		"basictest.fdf",
		"elem2.fdf",
		"elem.fdf",
		"mars.fdf",
		"plat.fdf",
		"pyra.fdf",
		"20-60.fdf",
		"50-4.fdf",
		"convolution_9.fdf",
		"large_plat.fdf",
		"pentenegpos.fdf",
		"pnp_flat.fdf",
		"pylone.fdf",
		// "julia.fdf"
	};

	score = 0;
	i = 0;
	while (i < max_score)
	{
		fdf_file = open_fdf_file(arr[i], "input_examples/fdf/", parse_fdf_line_bw);
		// fdf_file = open_fdf_file(arr[i], "input_examples/fdf/", parse_fdf_line_rgba);
		clone_examples = open_dir_file(arr[i], "unit_test/clone_examples/fdf/", APPEND);
		if (clone_examples > -1)
		{
			write_load_fdf_arr(clone_examples, &fdf_file, 1, HEIGHT_ONLY);
			if (assert_files(arr[i], arr[i],
					"input_examples/fdf/", "unit_test/clone_examples/fdf/") == true)
				score += 1;
		}
		free_load_fdf_arr(&fdf_file);
		i += 1;
	}
	write_total_score(score, max_score);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./unit_test/out/input/load/fdf_write_fdf.out
*/
