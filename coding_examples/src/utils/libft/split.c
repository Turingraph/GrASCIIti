#include"libft.h"
# include <fcntl.h>

int	main(int len, char **str)
{
	size_t	i;
	size_t	split_len;
	char	**split_arr;
	int		fd;

	if (len < 3)
		return (0);
	fd = 1;
	split_arr = f_split(str[1], str[2]);
	split_len = f_split_len(str[1], str[2]);
	i = 0;
	while (i < split_len)
	{
		ft_putnbr_fd((int) i, fd, "0123456789", 1);
		write(fd, ".\t: ", 4);
		write(fd, split_arr[i], f_strlen(split_arr[i]));
		write(fd, "\n", 1);
		i += 1;
	}
	free_2d_arr((void **) split_arr, split_len);
	return (0);
}

/*
fd = open(str[3], 'a');
if (fd < 0)
	return (0);
*/
/*
valgrind --leak-check=full --show-leak-kinds=all ./coding_examples/bin/utils/libft/split.out "Jojo CheChe Relu" " "

*/
