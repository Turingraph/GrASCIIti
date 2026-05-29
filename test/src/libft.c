#include "libft.h"
#include <fcntl.h>

/*
To Do Now
1.	Fix ft_putnbr_fd
2.	Update libft.h of other dir accordingly
3.	Implementing save_table_fdf
4.	Implementing save_table_ascii
*/

// f_atoi
int	main(int len, char **str)
{
	char			err;
	unsigned char	min;
	unsigned char	max;

	err = 'K';
	if (len < 3)
		return (0);
	min = (unsigned char)f_atoi(str[1], &err, "0123456789ABCDEF", f_strlen(str[1]));
	max = (unsigned char)f_atoi(str[2], &err, "0123456789ABCDEF", f_strlen(str[2]));
	if (err == 'E')
	{
		write(1, "input is invalid.\n", 18);
		return (0);
	}
	ft_putnbr_fd((int) min, 1, "0123456789ABCDEF", 5);
	if (min <= max)
		write(1, " is less than or equal to ", 26);
	else
		write(1, " is greater than ", 17);
	ft_putnbr_fd((int) max, 1, "0123456789ABCDEF", 5);
	write(1, "\n", 1);
	return (0);
}

/*
// f_split
int	main(int len, char **str)
{
	size_t	i;
	size_t	split_len;
	char	**split_arr;
	int		fd;

	if (len < 4)
		return (0);
	fd = open(str[3], 'a');
	if (fd < 0)
		return (0);
	split_arr = f_split(str[1], str[2]);
	split_len = f_split_len(str[1], str[2]);
	i = 0;
	while (i < split_len)
	{
		ft_putnbr_fd((int) i, fd, "0123456789");
		write(fd, ".\t: ", 4);
		write(fd, split_arr[i], f_strlen(split_arr[i]));
		write(fd, "\n", 1);
		i += 1;
	}
	free_nest_arr((void **) split_arr, split_len);
	return (0);
}
*/

/*
valgrind --leak-check=full ./test/bin/libft.out "Mumu CheChe Tata" " C" test/write/main.txt
*/
