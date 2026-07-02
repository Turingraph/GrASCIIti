#include"assert_string.h"

// time : O(1)
// space: O(1)
void	write_total_score(size_t score, size_t max_score)
{
	write(1, "Score: ", 8);
	ft_putnbr_fd((int)score, 1, "0123456789", 1);
	write(1, " / ", 3);
	ft_putnbr_fd((int)max_score, 1, "0123456789", 1);
	write(1, "\n", 1);
}

// time : O(n)
// space: O(n)
int	open_dir_file(const char *file_name, const char *dir, e_file_mode mode)
{
	t_temperance	*file;
	int				dst;

	if (path == NULL || *path == '\0')
		return (open(file_name, mode));
	file = NULL;
	ace_of_cup(1, &file);
	if (file == NULL)
		return (-1);
	three_of_cups(&file, path);
	three_of_cups(&file, file_name);
	if (file == NULL)
		return (-1);
	dst = open(file->arr, mode);
	free(file->arr);
	free(file);
	return (dst);
}

// time : O(n)
// space: O(1)
int	compare_intarr(const int *str_1, const int *str_2, size_t n)
{
	size_t	i;

	i = 0;
	if (str_1 == NULL && str_2 == NULL)
		return (0);
	if ((str_1 == NULL && str_2 != NULL) || (str_1 != NULL && str_2 == NULL))
		return (-1);
	while (i < n - 1 && *str_1 == *str_2)
	{
		i += 1;
		str_1 += 1;
		str_2 += 1;
	}
	return (*str_1 - *str_2);
}
