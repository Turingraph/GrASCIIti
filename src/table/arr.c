#include "table.h"

// time : O(n)
// space: O(n)
unsigned char	**init_null_char_arr(size_t row, size_t col)
{
	size_t			i;
	size_t			j;
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
			free_nest_arr((void *)dst, i + 1);
			return (NULL);
		}
		j = 0;
		while (j < col)
		{
			dst[i][j] = (unsigned char)0;
			j += 1;
		}
		i += 1;
	}
	return (dst);
}

// time : O(n)
// space: O(1)
// void	copy_nested_rgb_arr(unsigned char **dst, unsigned char **src, size_t row, size_t col)
// {
// 	size_t	i;
// 	size_t	j;

// 	i = 0;
// 	while (i < row)
// 	{
// 		j = 0;
// 		while (j < col)
// 		{
// 			dst[i][j] = src[i][j];
// 			j += 1;
// 		}
// 		i += 1;
// 	}
// }

// time : O(n)
// space: O(n)
int	**init_null_int_arr(size_t row, size_t col)
{
	size_t	i;
	size_t	j;
	int		**dst;

	dst = (int **)malloc_talk(sizeof(int *) * row, "table/arr.c/init_null_char_arr\n");
	if (dst == NULL)
		return (NULL);
	i = 0;
	while (i < row)
	{
		dst[i] = (int *)malloc_talk(sizeof(int) * col, "table/arr.c/init_null_char_arr\n");
		if (dst[i] == NULL)
		{
			free_nest_arr((void **)dst, i + 1);
			return (NULL);
		}
		j = 0;
		while (j < col)
		{
			dst[i][j] = (int)0;
			j += 1;
		}
		i += 1;
	}
	return (dst);
}
