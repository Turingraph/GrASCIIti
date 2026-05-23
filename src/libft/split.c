#include "libft.h"

size_t	f_split_len(char *input, char *space)
{
	size_t	i;
	size_t	y;

	y = 0;
	i = 0;
	while (input[i] != '\0')
	{
		if (f_isspace(input[i], space) == 0)
		{
			while (f_isspace(input[i], space) == 0 && input[i] != '\0')
				i += 1;
			y += 1;
		}
		else
			i += 1;
	}
	return (y);
}

char	*f_create_copy_text(char *input, char *space)
{
	char	*dst;
	size_t	dst_len;
	size_t	i;

	dst_len = 0;
	while (input[dst_len] != '\0' && f_isspace(input[dst_len], space) == 0)
		dst_len += 1;
	dst = (char *)malloc(sizeof(char) * (dst_len + 1));
	if (dst == NULL)
		return (NULL);
	dst[dst_len] = '\0';
	i = 0;
	while (input[i] != '\0' && f_isspace(input[i], space) == 0)
	{
		dst[i] = input[i];
		i += 1;
	}
	return (dst);
}

void	f_free_nested_string(char **dst, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		free(dst[i]);
		i += 1;
	}
	free(dst);
}

char	**f_split_push(char *input, char **dst, char *space)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	while (input[i] != '\0')
	{
		if (f_isspace(input[i], space) == 0)
		{
			dst[j] = f_create_copy_text(input + i, space);
			if (dst[j] == NULL)
			{
				f_free_nested_string(dst, j);
				return (NULL);
			}
			while (f_isspace(input[i], space) == 0 && input[i] != '\0')
				i += 1;
			j += 1;
		}
		else
			i += 1;
	}
	return (dst);
}

char	**f_split(char *input, char *space)
{
	char	**dst;
	size_t	dst_len;

	dst_len = f_split_len(input, space);
	dst = (char **)malloc(sizeof(char *) * (dst_len + 1));
	if (dst == NULL)
		return (NULL);
	dst[dst_len] = NULL;
	return (f_split_push(input, dst, space));
}
