#include "libft.h"

// time : O(1)
// space: O(n)
void	*malloc_talk(size_t elem_size, const char *comment)
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

// time : O(1)
// space: O(1)
unsigned char	*get_rgba_of_table_fdf(const t_table_fdf *src, e_rgba rgba_type)
{
	if (src == NULL)
		return (NULL);
	if (src->r != NULL && rgba_type == RED)
		return (src->r);
	if (src->g != NULL && rgba_type == GREEN)
		return (src->g);
	if (src->b != NULL && rgba_type == BLUE)
		return (src->b);
	if (src->a != NULL && (rgba_type == ALPHA))
		return (src->a);
	return (NULL);
}
