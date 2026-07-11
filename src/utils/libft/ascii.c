#include"libft.h"

// https://paulbourke.net/dataformats/asciiart/

// time : O(n)
// space: O(1)
char	mirror_tune(char a, e_bool is_left)
{
	size_t	i;
	char	*dict;
	size_t	dict_len;

	dict_len = 15;
	dict = "ASLbpsuaf[({</6VZJdqznej])}>\\9";
	i = 0;
	while (i < dict_len)
	{
		if (is_left == TRUE && dict[i] == a)
			return (a);
		if (is_left == FALSE && dict[i] == a)
			return (dict[dict_len + i]);
		i += 1;
	}
	while (i < dict_len * 2)
	{
		if (is_left == FALSE && dict[i] == a)
			return (a);
		if (is_left == TRUE && dict[i] == a)
			return (dict[dict_len - i]);
		i += 1;
	}
	return ('\0');
}


// time : O(n)
// space: O(1)
int	f_ctoi(char a, const char *dict)
{
	size_t	i;

	if (a == '\0')
		return (0);
	i = 0;
	while (dict[i] != '\0' && dict[i] != a && dict[i] != mirror_tune(a, FALSE))
		i += 1;
	if (dict[i] == '\0')
		return (0);
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
		while (dict[i] != '\0' && cell != (int)i
			&& dict[i] != mirror_tune(dict[i], TRUE))
			i += 1;
		left_twin = mirror_tune(dict[i], TRUE);
		right_twin = mirror_tune(dict[i], FALSE);
		if (is_left == FALSE && dict[i] == left_twin
			&& dict[i] != '\0')
			write(fd, &right_twin, 1);
		else if (dict[i] != '\0')
			write(fd, dict + i, 1);
	}
}
