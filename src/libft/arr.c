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
		if (len > 0 && arr[len - 1] != NULL)
			free(arr[len - 1]);
		len -= 1;
	}
	free(arr);
}

// https://stackoverflow.com/questions/41856771/
// write-your-own-implementation-of-maths-floor-function-c

// time : O(1)
// space: O(1)
double	f_floor(double num)
{
    long long	n;
    double		d;

	n = (long long)num;
	d = (double)n;
	if (num >= 2147483647 || num <= -2147483648 || num != num)
        return (num);
    if (d == num || num >= 0)
        return (d);
    return (d - 1);
}
