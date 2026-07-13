#include"table.h"

int	main(void)
{
	int				fdf_dst;
	size_t			i;
	size_t			score;
	size_t			max_score = 16;
	t_table_fdf     table;
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
	};

	score = 0;
	i = 0;
	while (i < max_score)
	{
		table = open_table_fdf_file(arr[i], "input_examples/fdf/", parse_fdf_line_bw, FALSE);
		fdf_dst = open_dir_file(arr[i], "clone_examples/fdf/", APPEND);
		if (fdf_dst > -1)
		{
			write_table_fdf(fdf_dst, &table, 1, HEIGHT_ONLY);
			if (assert_files(arr[i], arr[i],
					"input_examples/fdf/", "clone_examples/fdf/") == TRUE)
				score += 1;
			else
			{
				write(1, "Incorrect: ", 12);
				write(1, arr[i], f_strlen(arr[i]));
				write(1, "\n", 1);
			}
		}
		else
			warning_file_not_exists(arr[i]);
		free_table_fdf(&table);
		i += 1;
	}
	write_total_score(score, max_score);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./unit_test/bin/input/table/table_write_fdf.out
*/
