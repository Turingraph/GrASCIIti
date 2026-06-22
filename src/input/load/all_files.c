#include "load.h"

// time : O(1)
// space: O(1)
t_load_fdf	copy_load_fdf(t_load_fdf src)
{
	t_load_fdf	dst;

	dst.length = src.length;
	dst.arr = src.arr;
	dst.r = src.r;
	dst.g = src.g;
	dst.b = src.b;
	dst.a = src.a;
	dst.int_warn = src.int_warn;
	dst.rgb_warn = src.rgb_warn;
	return (dst);
}

// time : O(n)
// space: O(n)
t_load_fdf_arr	copy_load_fdf_arr(t_load_fdf_arr src, size_t length)
{
	t_load_fdf_arr	dst;
	size_t			i;

	dst = init_load_fdf_arr(length);
	i = 0;
	while (dst.arr != NULL && src.arr != NULL
		&& i < src.length && i < dst.capacity)
	{
		dst.arr[i] = copy_load_fdf(src.arr[i]);
		i += 1;
	}
	dst.length = i;
	return (dst);
}

// time : O(1)
// space: O(1)
t_load_fdf_arr	push_load_fdf_arr(t_load_fdf_arr *src, t_load_fdf item)
{
	t_load_fdf_arr	dst;

	if (src->length < src->capacity)
	{ 
		if (src->arr == NULL)
			return (*src);
		src->arr[src->length] = item;
		src->length += 1;
		return (*src);
	}
	dst = copy_load_fdf_arr(*src, src->length * 2);
	if (dst.arr != NULL)
	{
		free(src->arr);
		*src = dst;
		return (push_load_fdf_arr(src, item));
	}
	free_load_fdf(&item);
	return (*src);
}

// time : O(n)
// space: O(n)
t_load_fdf_arr	load_all_fdf_lines(int fd, t_load_fdf (*one_line)(char *line))
{
	t_load_fdf_arr	dst;
	t_load_fdf_arr	truncate;
	char			*line;

	dst = init_load_fdf_arr(1);
	line = get_next_line(fd, CONTINUE);
	while (line != NULL)
	{
		push_load_fdf_arr(&dst, one_line(line));
		if (dst.length > 0)
			warning_load_fdf(dst.arr[dst.length - 1], dst.length - 1);
		free(line);
		line = get_next_line(fd, CONTINUE);
	}
	if (line != NULL)
		free(line);
	get_next_line(fd, STOP_GNL);
	truncate = copy_load_fdf_arr(dst, dst.length);
	free(dst.arr);
	return (truncate);
}
