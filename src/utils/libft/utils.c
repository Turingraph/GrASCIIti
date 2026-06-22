#include "libft.h"

// time : O(n)
// space: O(1)
char	f_strncmp(char *dst, char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && *dst == *src && *dst != '\0')
	{
		i += 1;
		*dst += 1;
		*src += 1;
	}
	return (*dst - *src);
}

// time : O(n)
// space: O(1)
char	f_isspace(char s, char *space)
{
	while (*space != '\0')
	{
		if (*space == s)
			return (1);
		space += 1;
	}
	return (0);
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
