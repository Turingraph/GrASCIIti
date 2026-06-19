#include"load.h"

// time : O(1)
// space: O(1)
void	*free_load_fdf(t_load_fdf *src)
{
	if (src == NULL)
		return (NULL);
	if (src->arr != NULL)
		free(src->arr);
	if (src->r != NULL)
		free(src->r);
	if (src->g != NULL)
		free(src->g);
	if (src->b != NULL)
		free(src->b);
	if (src->a != NULL)
		free(src->a);
	src->arr = NULL;
	src->r = NULL;
	src->g = NULL;
	src->b = NULL;
	src->a = NULL;
	return (NULL);
}

// time : O(n)
// space: O(n)
t_load_fdf	init_load_fdf(size_t line_len, char is_rgb)
{
	t_load_fdf	dst;

	dst.arr = NULL;
	dst.r = NULL;
	dst.g = NULL;
	dst.b = NULL;
	dst.a = NULL;
	if (is_rgb > 0)
	{
		dst.r = malloc_talk(sizeof(unsigned char) * line_len,
			"load/ascii.c/int_load_fdf\n");
		dst.g = malloc_talk(sizeof(unsigned char) * line_len,
			"load/ascii.c/int_load_fdf\n");
		dst.b = malloc_talk(sizeof(unsigned char) * line_len,
			"load/ascii.c/int_load_fdf\n");
		dst.a = malloc_talk(sizeof(unsigned char) * line_len,
			"load/ascii.c/int_load_fdf\n");
	}
	dst.int_err = 'K';
	if (line_len == 0)
		dst.int_err = '0';
	dst.rgb_err = 'K';
	dst.length = line_len;
	return (dst);
}

// time : O(n)
// space: O(1)
void	*free_load_fdf_arr(t_load_fdf_arr *src)
{
	size_t	i;

	if (src == NULL)
		return (NULL);
	if (src != NULL && src->arr != NULL)
	{
		i = 0;
		while (i < src->capacity)
		{
			free_load_fdf(&(src->arr[i]));
			i += 1;
		}
		free(src->arr);
	}
	src->arr = NULL;
	src->capacity = 0;
	src->length = 0;
	return (NULL);
}

// time : O(1)
// space: O(n)
t_load_fdf_arr	init_load_fdf_arr(size_t length)
{
	t_load_fdf_arr	dst;

	dst.capacity = length;
	dst.length = 0;
	dst.arr = malloc_talk(sizeof(t_load_fdf) * length,
		"load/init.c/init_load_fdf_arr\n");
	return (dst);
}
