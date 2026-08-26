#include"load_private.h"

// time : O(n)
// space: O(1)
char	f_isspace(char s, const char *space)
{
	while (space != NULL && *space != '\0')
	{
		if (*space == s)
			return (1);
		space += 1;
	}
	return (0);
}

// time : O(n)
// space: O(1)
size_t	f_strlen(const char *str)
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
