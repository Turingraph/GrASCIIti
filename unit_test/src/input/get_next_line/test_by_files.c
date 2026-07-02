#include"get_next_line_tester.h"

int	main(void)
{
	size_t	i;
	size_t	score;
	size_t	max_score = 15;
	size_t	total_lines;
	int		fd;
	char	**load;
	char	*arr[] = {
		"42_no_nl",
		"41_with_nl",
		"42_no_nl",
		"42_with_nl",
		"43_no_nl",
		"43_with_nl",
		"alternate_line_nl_no_nl",
		"alternate_line_nl_with_nl",
		"big_line_no_nl",
		"big_line_with_nl",
		"empty",
		"multiple_line_no_nl",
		"multiple_line_with_nl",
		"multiple_nlx5",
		"nl"
	}

	score = 0;
	max_score = 15;
	i = 0;
	while (i < max_score && arr[i] != NULL)
	{
		fd = open_dir_file(arr[i], "test/input_examples/", READ);
		if (fd > -1)
		{
			total_lines = total_lines_of_file(fd);
			fd = open_dir_file(arr[i], "test/input_examples/", READ);
			load = load_file_as_strarr(fd, total_lines);
			fd = open_dir_file(arr[i], "clone_examples/", APPEND);
			if (fd > -1)
			{
				write_strarr(load, fd);
				if (assert_files(arr[i], arr[i],
					"test/input_examples/", "clone_examples/") == TRUE)
					score += 1;
			}
			if (load != NULL)
				free_2d_arr((void **)load, length_of_strarr(load));
		}
		i += 1;
	}
	write_total_score(score, max_score);
	return (0);
}
