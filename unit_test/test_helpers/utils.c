#include"test_helpers.h"

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

// time : O(n)
// space: O(n)
void	warning_file_not_exists(const char *src)
{
	write(1, "Warning: ", 10);
	write(1, src, f_strlen(src));
	write(1, " is not exists.\n", 17);
}