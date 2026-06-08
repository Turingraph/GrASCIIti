#include "table.h"

// time : O(n)
// space: O(n)
int	**init_null_int_arr(size_t row, size_t col)
{
	size_t	i;
	size_t	j;
	int		**dst;

	dst = (int **)malloc_talk(sizeof(int *) * row, "table/arr.c/init_null_int_arr\n");
	if (dst == NULL)
		return (NULL);
	i = 0;
	while (i < row)
	{
		dst[i] = (int *)malloc_talk(sizeof(int) * col, "table/arr.c/init_null_int_arr\n");
		if (dst[i] == NULL)
		{
			free_nest_arr((void **)dst, i);
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
