#include"triangle_arr.h"

// time : O(1)
// space: O(1)
t_triangle	copy_triangle(t_triangle *src)
{
	t_triangle	dst;

	dst.r = src->r;
	dst.g = src->g;
	dst.b = src->b;
	dst.a = src->a;
	dst.p1 = src->p1;
	dst.p2 = src->p2;
	dst.p3 = src->p3;
	if (dst.p1 == NULL || dst.p2 == NULL || dst.p3 == NULL
		|| src->p1 == NULL || src->p2 == NULL || src->p3 == NULL)
	{
		free_triangle(&dst);
		free_triangle(src);
	}
	return (dst);
}

// time : O(n)
// space: O(n)
t_triangle_arr	copy_triangle_arr(t_triangle_arr *src, size_t length)
{
	t_triangle_arr	dst;
	size_t			i;

	if (length == 0 || dst.arr == NULL || src->arr == NULL)
		return (init_triangle_arr(0, 0, 0));
	dst = init_triangle_arr(length, src->table_row, src->col);
	i = 0;
	while (i < src->length && i < dst.capacity)
	{
		dst.arr[i] = copy_triangle(&(src->arr[i]));
		i += 1;
	}
	dst.length = i;
	while (i < src->length)
	{
		free_triangle(&(src->arr[i]));
		i += 1;
	}
	free(src->arr);
	src->arr = NULL;
	src->length = 0;
	src->capacity = 0;
	return (dst);
}

// time : O(n)
// space: O(n)
t_triangle_arr	clone_triangle_arr(const t_triangle_arr *src, size_t length)
{
	t_triangle_arr	dst;
	size_t			i;

	if (length == 0 || dst.arr == NULL || src->arr == NULL)
		return (init_triangle_arr(0, 0, 0));
	dst = init_triangle_arr(length, src->row, src->col);
	i = 0;
	while (i < src->length && i < dst.capacity)
	{
		dst.arr[i] = copy_triangle(&(src->arr[i]));
		if (src->arr[i].p1 != NULL && src->arr[i].p2 != NULL && src->arr[i].p3 != NULL)
		{
			dst.arr[i].p1 = create_3d_vector(src->arr[i].p1[0], src->arr[i].p1[1], src->arr[i].p1[2]);
			dst.arr[i].p2 = create_3d_vector(src->arr[i].p2[0], src->arr[i].p2[1], src->arr[i].p2[2]);
			dst.arr[i].p3 = create_3d_vector(src->arr[i].p3[0], src->arr[i].p3[1], src->arr[i].p3[2]);
		}
		i += 1;
	}
	dst.length = i;
	return (dst);
}

// time : O(1)
// space: O(1)
t_triangle_arr	push_triangle_arr(t_triangle_arr *dst, t_triangle *src)
{
	t_triangle_arr	large_dst;

	if (dst->length < dst->capacity)
	{
		if (dst->arr == NULL)
			return (*dst);
		dst->arr[dst->length] = *src;
		dst->length += 1;
		return (*dst);
	}
	large_dst = copy_triangle_arr(dst, dst->length * 2);
	if (large_dst.arr != NULL)
	{
		*dst = large_dst;
		return (push_triangle_arr(dst, src));
	}
	free_triangle(src);
	return (*dst);
}

// time : O(1)
// space: O(1)
t_triangle_arr	concat_triangle_arr(t_triangle_arr *dst, t_triangle_arr *src)
{
	size_t	i;

	if (src->arr == NULL)
	{
		free_triangle_arr(src);
		return (*dst);
	}
	i = 0;
	while (i < src->length)
	{
		push_triangle_arr(dst, &(src->arr[i]));
		i += 1;
	}
	free(src->arr);
	src->arr = NULL;
	src->length = 0;
	src->capacity = 0;
	return (*dst);
}