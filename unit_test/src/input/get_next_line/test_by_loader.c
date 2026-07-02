#include"get_next_line_tester.h"

int	main(void)
{
	int							fd;
	int							fd_length;
	char						**load;
	size_t						total_lines;
	size_t						i;
	size_t						score;
	size_t						max_score = 15;
	static const t_file_tester	arr[] = {
		{"42_no_nl", 1},
		{"41_with_nl", 2},
		{"42_no_nl", 1},
		{"42_with_nl", 2},
		{"43_no_nl", 1},
		{"43_with_nl", 2},
		{"alternate_line_nl_no_nl", 9},
		{"alternate_line_nl_with_nl", 9},
		{"big_line_no_nl", 1},
		{"big_line_with_nl", 1},
		{"empty", 0},
		{"multiple_line_no_nl", 5},
		{"multiple_line_with_nl", 5},
		{"multiple_nlx5", 5},
		{"nl", 1},
	}

	score = 0;
	i = 0;
	while (i < max_score)
	{
		fd = open_dir_file(arr[i].file_name, "test/input_examples/gnl_tester", READ);
		fd_length = open_dir_file(arr[i].file_name, "test/input_examples/gnl_tester", READ);
		total_lines = total_lines_of_file(fd_length);
		load = load_file_as_strarr(fd, total_lines);
		if (assert_file_with_strarr(fd_length, load, total_lines) == TRUE)
			score += 1;
		free_2d_arr((void **)load, length_of_strarr(load));

		fd = open_dir_file(arr[i].file_name, "test/input_examples/gnl_tester", READ);
		load = load_file_as_strarr(fd, 1);
		if (assert_file_with_strarr(fd_length, load, 1) == TRUE)
			score += 1;
		free_2d_arr((void **)load, length_of_strarr(load));

		fd = open_dir_file(arr[i].file_name, "test/input_examples/gnl_tester", READ);
		load = load_file_as_strarr(fd, 1);
		if (assert_file_with_strarr(fd_length, load, 3) == TRUE)
			score += 1;
		free_2d_arr((void **)load, length_of_strarr(load));
		i += 1;
	}
	write_total_score(score, max_score * 3);
	return (0);
}