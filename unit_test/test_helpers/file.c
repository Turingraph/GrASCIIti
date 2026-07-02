#include"assert_string.h"

// time : O(n)
// space: O(n)
size_t	total_lines_of_file(int fd)
{
	size_t	total_lines;
	char	*line;

	total_lines = 0;
	line = get_next_line(fd, CONTINUE);
	if (line == NULL)
		return (0);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd, CONTINUE);
		total_lines += 1;
	}
	return (total_lines);
}

// time : O(n)
// space: O(n)
e_bool	assert_files(const char *file_name_1, const char *file_name_2,
	const char *dir_name_1, const char *dir_name_2)
{
	int		fd;
	size_t	length;
	char	**strarr_1;
	char	**strarr_2;
	e_bool	result;

	fd = open_dir_file(file_name_1, dir_name_1, READ);
	length = total_lines_of_file(fd);
	fd = open_dir_file(file_name_2, dir_name_2, READ);
	if (length != total_lines_of_file(fd))
		return (FALSE);
	fd = open_dir_file(file_name_1, dir_name_1, READ);
	strarr_1 = load_file_as_strarr(fd, length);
	fd = open_dir_file(file_name_2, dir_name_2, READ);
	strarr_2 = load_file_as_strarr(fd, length);
	result = assert_strarr(strarr_1, strarr_2, length, TRUE);
	free_2d_arr((void **)strarr_1, length);
	free_2d_arr((void **)strarr_2, length);
	return (result);
}

// time : O(n)
// space: O(n)
e_bool	is_file_empty(int fd)
{
	char	*actual_y;

	if (fd < 0)
	{
		*correct = FALSE;
		return (NULL);
	}
	actual_y = get_next_line(fd, CONTINUE);
	if (actual_y == NULL)
		return (TRUE);
	free(actual_y);
	get_next_line(fd, STOP_GNL);
	return (FALSE);
}

// time : O(n)
// space: O(n)
char	*assert_gnl_and_line(char *actual_line,
	const char *expected_line, int fd)
{
	if (compare_strings(actual_line,
			expected_line, f_strlen(expected_line), FALSE) != 0
		|| f_strlen(actual_line) != f_strlen(expected_line))
	{
		free(actual_line);
		get_next_line(fd, STOP_GNL);
		return (NULL);
	}
	free(actual_line);
	return (get_next_line(fd, CONTINUE));
}

// total_lines = 0 means to verify all lines.
// time : O(n)
// space: O(n)
e_bool	assert_file_with_strarr(int fd, const char **strarr, size_t total_lines)
{
	char	*line;
	char	*next_line;
	size_t	i;

	if (strarr == NULL || fd < 0
		|| strarr[0] == NULL)
		return (FALSE);
	if (strarr[0] == NULL)
		return (is_file_empty(fd));
	line = get_next_line(fd, CONTINUE);
	i = 0;
	while (line != NULL && (i < total_lines || total_lines == 0))
	{
		next_line = assert_gnl_and_line(line, strarr[i], fd);
		line = next_line;
		i += 1;
	}
	get_next_line(fd, STOP_GNL);
	if (i != length_of_strarr(strarr))
		return (FALSE);
	return (TRUE);
}
