#include "libft.h"

// time : O(n)
// space: O(1)
void	*malloc_talk(size_t elem_size, char *comment)
{
	size_t			i;
	unsigned char	*d;
	void			*dst;

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
		i += 1;
	}
	return (dst);
}

// time : O(n)
// space: O(1)
void	free_nest_arr(void **arr, size_t len)
{
	while (len > 0)
	{
		if (arr[len - 1] != NULL)
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

// time : O(n)
// space: O(n)
void	**create_null_arr(size_t col, size_t row, size_t elem_size, char *comment)
{
	size_t	i;
	void	**dst;

	dst = (void **)malloc_talk(sizeof(void *) * col, "LIB/arr.c/create_null_arr\n");
	if (dst == NULL)
		return (NULL);
	i = 0;
	while (i < col)
	{
		dst[i] = NULL;
		if (row * elem_size > 0)
			dst[i] = (void *)malloc_talk(row * elem_size, "LIB/arr.c/create_null_arr\n");
		if (row * elem_size > 0 && dst[i] == NULL)
		{
			if (comment != NULL && f_strlen(comment) > 0)
			{
				write(1, "Create_Null_Arr Fail: ", 14);
				write(1, comment, f_strlen(comment));
			}
			free_nest_arr((void **)dst, i - 1);
			return (NULL);
		}
		i += 1;
	}
	return (dst);
}

// time : O(n)
// space: O(n)
void	copy_nested_arr(void **dst, void **src, size_t col, size_t row_x_elem_size)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;
	size_t			j;

	i = 0;
	while (i < col)
	{
		d = *dst;
		s = *src;
		j = 0;
		while (j < row_x_elem_size)
		{
			*d = *s;
			d += 1;
			s += 1;
			j += 1;
		}
		dst += 1;
		src += 1;
		i += 1;
	}
}
