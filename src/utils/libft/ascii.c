#include"libft.h"

// https://paulbourke.net/dataformats/asciiart/

// time : O(1)
// space: O(1)
char	mirror_tune(char a, e_bool is_left)
{
	size_t	i;
	char	*left_dict;
	char	*right_dict;
	size_t	half_dict_len;

	half_dict_len = 15;
	left_dict = "VZJdqznej])}>\\9";
	right_dict = "ASLbpsuaf[({</6";
	i = 0;
	while (i < half_dict_len)
	{
		if (left_dict[i] == a || right_dict[i] == a)
		{
			if (is_left == TRUE)
				return (left_dict[i]);
			else
				return (right_dict[i]);
		}
		i += 1;
	}
	return (a);
}


// time : O(n)
// space: O(1)
int	f_ctoi(char a, const char *dict)
{
	size_t	i;

	if (a == '\0')
		return (0);
	i = 0;
	while (dict[i] != '\0' && dict[i] != a && dict[i] != mirror_tune(a, TRUE))
		i += 1;
	return ((int)i);
}

// time : O(1)
// space: O(1)
void	ft_put_ascii_fd(int fd, int cell, const char *dict, e_bool is_left)
{
	size_t	i;
	char	right_twin;
	char	left_twin;

	if (cell <= 0)
		write(fd, " ", 1);
	else
	{
		i = 0;
		while (dict[i] != '\0' && cell != (int)i)
			i += 1;
		if (dict[i] == '\0' && i > 0)
			i -= 1;
		left_twin = mirror_tune(dict[i], TRUE);
		right_twin = mirror_tune(dict[i], FALSE);
		if (is_left == TRUE)
			write(fd, &left_twin, 1);
		if (is_left == FALSE)
			write(fd, &right_twin, 1);
	}
}

/*
		// write(1, ">>> ", 4);
		// ft_putnbr_fd(i, 1, "0123456789", 1);
		// write(1, "\n", 1);
		left_twin = mirror_tune(dict[i], TRUE);
		right_twin = mirror_tune(dict[i], FALSE);
		if (is_left == FALSE)
		{
			write(1, &right_twin, 1);
			write(fd, &right_twin, 1);
		}
		else if (dict[i] != '\0')
		{
			write(1, &left_twin, 1);
			write(fd, &left_twin, 1);
		}
	}
*/