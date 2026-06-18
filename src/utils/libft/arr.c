#include "libft.h"

// time : O(1)
// space: O(n)
void	*malloc_talk(size_t elem_size, char *comment)
{
	size_t			i;
	unsigned char	*d;
	void			*dst;

	if (elem_size == 0)
		return (NULL);
	dst = (void *)malloc(elem_size);
	if (dst == NULL)
	{
		if (comment != NULL && *comment != '\0')
		{
			write(1, "Malloc Fail: ", 14);
			write(1, comment, f_strlen(comment));
		}
	}
	d = (unsigned char *)dst;
	i = 0;
	while (i < elem_size)
	{
		*d = 0;
		d += 1;
		i += 1;
	}
	return (dst);
}

// time : O(n)
// space: O(1)
void	free_2d_arr(void **arr, size_t len)
{
	while (len > 0)
	{
		if (len > 0 && arr[len - 1] != NULL)
			free(arr[len - 1]);
		len -= 1;
	}
	free(arr);
}

// time : O(n^2)
// space: O(1)
void	copy_uchar_arr(unsigned char *dst, unsigned char *src, size_t len, size_t scale_dim)
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
