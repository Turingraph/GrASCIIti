#include"table.h"

int	main(void)
{
	int				clone_examples;
	size_t			i;
    size_t          is_rgb;
	size_t			score;
	size_t			max_score = 36;
	t_table_fdf     table;
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

    is_rgb = FALSE;
	score = 0;
	i = 0;
	while (i < max_score)
	{
		table = open_table_fdf_file(arr[i], "input_examples/font/rozzo/", parse_ascii_line_cheche01, is_rgb);
		clone_examples = open_dir_file(arr[i], "clone_examples/font/rozzo/", APPEND);
		if (clone_examples > -1)
		{
			write_table_ascii_cheche01(clone_examples, &table, D5_HEIGHT);
			if (assert_files_ascii(arr[i], arr[i],
					"input_examples/font/rozzo/", "clone_examples/font/rozzo/") == TRUE)
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
valgrind --leak-check=full --show-leak-kinds=all ./unit_test/bin/input/table/table_write_ascii.out
*/
