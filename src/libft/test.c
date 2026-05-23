#include "libft.h"

/*
// f_atoi
int	main(int len, char **str)
{
	char	err;
	int		min;
	int		max;

	err = 'K';
	if (len < 3)
		return (0);
	min = f_atoi(str[1], &err);
	max = f_atoi(str[2], &err);
	if (err == 'E')
	{
		write(1, "input is invalid,\n", 18);
		return (0);
	}
	ft_putnbr_fd(min, 1);
	if (min <= max)
		write(1, " is less than or equal to ", 26);
	else
		write(1, " is greater than ", 17);
	ft_putnbr_fd(max, 1);
	write(1, "\n", 1);
	return (0);
}
*/

// f_split
int	main(int len, char **str)
{
	size_t	i;
	size_t	split_len;
	char	**split_arr;

	if (len < 3)
		return (0);
	split_arr = f_split(str[1], str[2]);
	split_len = f_split_len(str[1], str[2]);
	i = 0;
	while (i < split_len)
	{
		ft_putnbr_fd((int) i, 1);
		write(1, ".\t: ", 4);
		write(1, split_arr[i], f_strlen(split_arr[i]));
		write(1, "\n", 1);
		i += 1;
	}
	free_strarr(split_arr, split_len);
	return (0);
}
