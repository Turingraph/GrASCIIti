#include"table_tester.h"

int	main(void)
{
	int				clone_examples;
	size_t			i;
    size_t          is_rgb;
	size_t			score;
	size_t			max_score = 49;
	t_table_fdf     table;
	char			*arr[] = {
		"0.txt",
		"3.txt",
		"6.txt",
		"9.txt",
		"a.txt",
		"c.txt",
		"d.txt",
		"exclamation.txt",
		"h.txt",
		"k.txt",
		"minus.txt",
		"o.txt",
		"p.txt",
		"right_paren.txt",
		"slash.txt",
		"t.txt",
		"w.txt",
		"z.txt",
		"1.txt",
		"4.txt",
		"7.txt",
		"ampersand.txt"
		"b.txt",
		"dollar.txt",
		"equal.txt",
		"f.txt",
		"i.txt",
		"left_paren.txt",
		"m.txt",
		"percent.txt",
		"q.txt",
		"s.txt",
		"u.txt",
		"x.txt",
		"2.txt",
		"5.txt",
		"8.txt",
		"at_sign.txt",
		"comma.txt",
		"dot.txt",
		"e.txt",
		"g.txt",
		"j.txt",
		"l.txt",
		"n.txt",
		"plus.txt",
		"question.txt",
		"r.txt",
		"v.txt",
		"y.txt"
	};

    is_rgb = FALSE;
	score = 0;
	i = 0;
	while (i < max_score)
	{
		k = 0;
		while (k < 3)
		{
			if (k == 0)
				table = open_table_fdf_file(arr[i], "input_examples/font/rozzo/", cheche01_ascii_line, is_rgb);
			if (k == 1)
				table = open_table_fdf_file(arr[i], "input_examples/font/rozzo/", standard_ascii_line, );
			if (k == 2)
				table = open_table_fdf_file(arr[i], "input_examples/font/rozzo/", chungaloider_ascii_line);
			clone_examples = open_dir_file(arr[i], "clone_examples/", APPEND);
			if (clone_examples > -1)
			{
				if (k == 0)
					write_table_ascii_cheche01(clone_examples, &table);
				if (k == 1)
					write_table_ascii_standard(clone_examples, &table);
				if (k == 2)
					write_table_ascii_chungaloider(clone_examples, &table);
				if (assert_files_ascii(arr[i], arr[i],
						"input_examples/font/rozzo/", "clone_examples/") == TRUE)
					score += 1;
			}
			else
				warning_file_not_exists(arr[i]);
			free_table_fdf(&table);
			k += 1;
		}
		i += 1;
	}
	write_total_score(score, max_score * 3);
	return (0);
}
