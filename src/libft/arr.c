#include "libft.h"

// time : O(1)
// space: O(1)
char	f_isspace(char s, char *space)
{
	size_t	i;

	i = 0;
	while (*space != '\0')
	{
		if (*space == s)
			return (1);
		space += 1;
		i += 1;
	}
	return (0);
}

// time : O(n)
// space: O(1)
void	free_strarr(char **arr, size_t len)
{
	while (len > 0)
	{
		free(arr[len - 1]);
		len -= 1;
	}
	free(arr);
}

// time : O(n)
// space: O(1)
size_t	f_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (*str != '\0')
	{
		i += 1;
		str += 1;
	}
	return (i);
}
