#include"load_tester.h"

int	main(void)
{
	int				clone_examples;
	size_t			i;
	size_t			k;
	size_t			score;
	size_t			max_score = 23;
	t_load_fdf_arr	fdf_file;
	char			*arr[] = {
		"100-6.fdf",
		"10-70.fdf",
		"42.fdf",
		"basictest.fdf",
		"elem2.fdf",
		"elem.fdf",
		"julia.fdf",
		"mars.fdf",
		"plat.fdf",
		"prism_pyramid.fdf",
		"pyra.fdf",
		"t1.fdf",
		"20-60.fdf",
		"50-4.fdf",
		"convolution_9.fdf",
		"elem-col.fdf",
		"elem-fract.fdf",
		"large_plat.fdf",
		"pentenegpos.fdf",
		"pnp_flat.fdf",
		"pylone.fdf",
		"pyramide.fdf",
		"t2.fdf"
	};

	score = 0;
	i = 0;
	while (i < max_score)
	{
		k = 0;
		while (k < 2)
		{
			if (k == 0)
				fdf_file = open_fdf_file(arr[i], "input_examples/fdf/", bw_fdf_line);
			else
				fdf_file = open_fdf_file(arr[i], "input_examples/fdf/", rgba_fdf_line);
			clone_examples = open_dir_file(arr[i], "clone_examples/", APPEND);
			if (clone_examples > -1)
			{
				write_load_fdf_arr(clone_examples, &fdf_file, 1, FDF42);
				if (assert_files(arr[i], arr[i],
						"input_examples/fdf/", "clone_examples/") == TRUE)
					score += 1;
			}
			free_load_fdf_arr(&clone_examples);
			k += 1;
		}
		i += 1;
	}
	write_total_score(score, max_score * 2);
	return (0);
}
