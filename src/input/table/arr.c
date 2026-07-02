#include"table.h"

// time : O(n^2)
// space: O(1)
void	copy_uchar_arr(unsigned char *dst, const unsigned char *src, size_t len, size_t scale_dim)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (dst != NULL && src != NULL && i < len)
	{
		j = 0;
		while (j < scale_dim)
		{
			dst[i * scale_dim + j] = src[i];
			j += 1;
		}
		i += 1;
	}
}

// time : O(n)
// space: O(n)
unsigned char	**init_2d_uchar_arr(size_t row, size_t col)
{
	size_t			i;
	unsigned char	**dst;

	dst = (unsigned char **)malloc_talk(sizeof(unsigned char **) * row, "table/arr.c/init_null_char_arr\n");
	if (dst == NULL)
		return (NULL);
	i = 0;
	while (i < row)
	{
		dst[i] = (unsigned char *)malloc_talk(sizeof(unsigned char *) * col, "table/arr.c/init_null_char_arr\n");
		if (dst[i] == NULL)
		{
			free_2d_arr((void *)dst, i);
			return (NULL);
		}
		i += 1;
	}
	return (dst);
}
