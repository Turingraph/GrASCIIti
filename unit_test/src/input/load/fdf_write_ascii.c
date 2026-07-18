#include"load.h"

int	main(void)
{
	int				clone_examples;
	size_t			i;
	size_t			score;
	size_t			max_score = 36;
	t_load_fdf_arr	fdf_file;
	char			*arr[] = {
		"0.txt",
		"3.txt",
		"6.txt",
		"9.txt",
		"a.txt",
		"c.txt",
		"d.txt",
		"h.txt",
		"k.txt",
		"o.txt",
		"p.txt",
		"t.txt",
		"w.txt",
		"z.txt",
		"1.txt",
		"4.txt",
		"7.txt",
		"b.txt",
		"f.txt",
		"i.txt",
		"m.txt",
		"q.txt",
		"s.txt",
		"u.txt",
		"x.txt",
		"2.txt",
		"5.txt",
		"8.txt",
		"e.txt",
		"g.txt",
		"j.txt",
		"l.txt",
		"n.txt",
		"r.txt",
		"v.txt",
		"y.txt"
	};

	score = 0;
	i = 0;
	while (i < max_score)
	{
		fdf_file = open_fdf_file(arr[i], "input_examples/font/rozzo/", parse_ascii_line_cheche01);
		// fdf_file = open_fdf_file(arr[i], "input_examples/font/rozzo/", standard_ascii_line);
		// fdf_file = open_fdf_file(arr[i], "input_examples/font/rozzo/", chungaloider_ascii_line);
		
		clone_examples = open_dir_file(arr[i], "unit_test/clone_examples/font/rozzo/", APPEND);
		// write(1, ">>> ", 4);
		// ft_putnbr_fd(clone_examples, 1, "0123456789", 1);
		// write(1, "\n", 1);
		if (clone_examples > -1)
		{
			write_load_ascii_arr_cheche01(clone_examples, &fdf_file);
			
			// write_load_ascii_arr_standard(clone_examples, &fdf_file);
			
			// write_load_ascii_arr_chungaloider(clone_examples, &fdf_file);
			
			if (assert_files_ascii(arr[i], arr[i],
					"input_examples/font/rozzo/", "unit_test/clone_examples/font/rozzo/") == true)
				score += 1;
			else
			{
				write(1, "wrong: ", 8);
				write(1, arr[i], f_strlen(arr[i]));
				write(1, "\n", 1);
			}
		}
		free_load_fdf_arr(&fdf_file);
		i += 1;
	}
	write_total_score(score, max_score);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./unit_test/out/input/load/fdf_write_ascii.out
*/
