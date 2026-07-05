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
t_load_fdf_arr	copy_load_fdf_arr(const t_load_fdf_arr *src, size_t length)
{
	t_load_fdf_arr	dst;
	size_t			i;

	if (src == NULL || length == 0 || src->arr != NULL || src->length == 0)
		return (init_load_fdf_arr(0));
	dst = init_load_fdf_arr(length);
	i = 0;
	while (dst.arr != NULL && i < src->length && i < dst.capacity)
	{
		dst.arr[i] = copy_load_fdf(src->arr[i]);
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

	if (src == NULL || src->arr == NULL)
		return (init_load_fdf_arr(0));
	if (src->length < src->capacity)
	{
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

	if (one_line == NULL || fd < 1)
		return (init_load_fdf_arr(0));
	dst = init_load_fdf_arr(1);
	if (one_line == NULL)
	{
		write(1, "Warning: one_line is NULL\n", 27);
		return (dst);
	}
	line = get_next_line(fd, CONTINUE);
	while (line != NULL)
	{
		push_load_fdf_arr(&dst, one_line(line));
		if (dst.length > 0 && dst.arr != NULL)
			warning_load_fdf(&dst.arr[dst.length - 1], dst.length - 1);
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

// options for one_line
// 1.	cheche01_ascii_line(const char *line) (from txt files)
// 2.	standard_ascii_line(const char *line) (from txt files)
// 3.	chungaloider_ascii_line(const char *line) (from txt files)
// 4.	bw_fdf_line(const char *line) (from fdf files)
// 5.	rgba_fdf_line(const char *line) (the only option that load rgb color from fdf files)
// time : O(n)
// space: O(n)
t_load_fdf_arr	open_fdf_file(const char *file_name, const char *dir,
		t_load_fdf (*one_line)(char *line))
{
	t_temperance	*file;
	int				dst;

	if (path == NULL || *path == '\0' || one_line == NULL)
		return (load_all_fdf_lines(open(file_name, mode), one_line));
	file = NULL;
	ace_of_cup(1, &file);
	if (file == NULL)
		return (-1);
	three_of_cups(&file, path);
	three_of_cups(&file, file_name);
	if (file == NULL)
		return (-1);
	dst = open(file->arr, mode);
	free(file->arr);
	free(file);
	return (load_all_fdf_lines(dst, one_line));
}
