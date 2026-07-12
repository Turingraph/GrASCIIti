#include"test_helpers.h"

// time : O(n)
// space: O(1)
int	compare_string(const char *str_1,
	const char *str_2, size_t n, e_bool ignore_space)
{
	size_t	i;

	if (str_1 == NULL && str_2 == NULL)
		return (0);
	if ((str_1 == NULL && str_2 != NULL) || (str_1 != NULL && str_2 == NULL))
		return (-1);
	while (f_isspace(*str_1, " \n\t\r\f\v") == 1
		&& *str_1 != '\0' && ignore_space == TRUE)
		str_1 += 1;
	while (f_isspace(*str_2, " \n\t\r\f\v") == 1
		&& *str_2 != '\0' && ignore_space == TRUE)
		str_2 += 1;
	i = 0;
	while (i < n && *str_1 == *str_2 && *str_1 != '\0')
	{
		i += 1;
		str_1 += 1;
		str_2 += 1;
		while (f_isspace(*str_1, " \n\t\r\f\v") == 1
			&& *str_1 != '\0' && ignore_space == TRUE)
			str_1 += 1;
		while (f_isspace(*str_2, " \n\t\r\f\v") == 1
			&& *str_2 != '\0' && ignore_space == TRUE)
			str_2 += 1;
	}
	return (*str_1 - *str_2);
}

// time : O(n)
// space: O(1)
size_t	length_of_strarr(const char **src)
{
	size_t	i;

	i = 0;
	while (src != NULL && src[i] != NULL)
	{
		i += 1;
	}
	return (i);
}

// time : O(n)
// space: O(1)
e_bool	assert_strarr(const char **strarr_1,
	const char **strarr_2, size_t length, e_bool ignore_space)
{
	size_t	i;

	if (strarr_1 == NULL && strarr_2 == NULL)
		return (TRUE);
	if ((strarr_1 == NULL && strarr_2 != NULL)
		|| (strarr_2 == NULL && strarr_1 != NULL))
		return (FALSE);
	i = 0;
	while (i < length && strarr_1[i] != NULL && strarr_2[i] != NULL)
	{
		if (compare_string(strarr_1[i], strarr_2[i],
				f_strlen(strarr_1[i]), ignore_space) != 0)
			return (FALSE);
		i += 1;
	}
	if (strarr_1[i] == NULL && strarr_2[i] == NULL)
		return (TRUE);
	if (strarr_1[i] == NULL || strarr_2[i] == NULL)
		return (FALSE);
	return (TRUE);
}

// time : O(n)
// space: O(n)
size_t	write_strarr(const char **strarr, size_t length, int fd)
{
	size_t	y;
	size_t	i;

	y = 0;
	i = 0;
	while (i < length && strarr != NULL)
	{
		if (strarr[i] != NULL)
			y += write(fd, strarr[i], f_strlen(strarr[i]));
		i += 1;
	}
	return (y);
}

// time : O(n)
// space: O(n)
char	**load_file_as_strarr(int fd, size_t total_lines)
{
	char	**dst;
	size_t	i;

	if (total_lines == 0)
		return (NULL);
	dst = (char **)malloc_talk(sizeof(char *) * (total_lines + 1),
		"test/src/input/get_next_line/file_by_file.c\n");
	if (dst == NULL)
		return (dst);
	dst[total_lines] = NULL;
	dst[0] = get_next_line(fd, CONTINUE);
	if (dst[0] == NULL)
		return (dst);
	i = 1;
	while (i < total_lines)
	{
		dst[i] = get_next_line(fd, CONTINUE);
		i += 1;
	}
	get_next_line(fd, STOP_GNL);
	return (dst);
}
