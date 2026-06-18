#include"triangle_arr.h"

// time : O(n)
// space: O(n)
t_triangle_arr	*truncate_triangle_arr(t_triangle_arr *src, size_t len)
{
	t_triangle_arr	*dst;
	size_t			i;

	if (len < 1)
		return (NULL);
	dst = init_triangle_arr(len);
	i = 0;
	while (src != NULL && i < src->lenght)
	{
		if (dst != NULL && i < dst->capacity)
		{
			dst->arr[i] = src->arr[i];
			dst->lenght += 1;
		}
		else
			free_triangle(src[i]);
		i += 1;
	}
	free(src);
	return (dst);
}

// time : O(1)
// space: O(1)
t_triangle_arr	*append_triangle_arr(t_triangle_arr **arr, t_triangle *item)
{
	t_triangle_arr	*temp;
	t_triangle_arr	*new_arr;

	if ((*arr)->lenght < (*arr)->capacity)
	{
		(*arr)->arr[(*arr)->lenght] = item;
		(*arr)->lenght += 1;
		return (*arr);
	}
	temp = *arr;
	new_arr = truncate_triangle_arr(temp, 2 * (*arr)->capacity);
	if (new_arr == NULL)
		return (NULL);
	*arr = new_arr;
	return (append_triangle_arr(arr, item));
}

// time : O(n)
// space: O(n)
t_triangle_arr	*concat_triangle_arr(t_triangle_arr **update_arr, t_triangle_arr *arr)
{
	size_t	i;

	if (arr == NULL)
		return (*update_arr);
	if (arr->lenght == 0)
	{
		free(arr->arr);
		free(arr);
		return (*update_arr);
	}
	i = 0;
	while (i < arr->lenght)
	{
		if (append_triangle_arr(update_arr, arr->arr[i]) == NULL)
		{
			free_triangle_arr(*update_arr);
			free_triangle_arr(arr);
			*update_arr = NULL;
			return (NULL);
		}
		i += 1;
	}
	free(arr->arr);
	free(arr);
	return (*update_arr);
}

// time : O(1)
// space: O(1)
t_triangle	*clone_triangle(t_triangle *src)
{
	t_triangle	*dst;

	dst = malloc_talk(sizeof(t_triangle),
		"mesh/concat_tri.c/clone_triangle\n");
	if (dst == NULL)
	{
		free_triangle_arr(dst);
		return (NULL);
	}
	dst->r = src->r;
	dst->g = src->g;
	dst->b = src->b;
	dst->a = src->a;
	dst->p1 = create_3d_vector(src->p1[0], src->p1[1], src->p1[2]);
	dst->p2 = create_3d_vector(src->p2[0], src->p2[1], src->p2[2]);
	dst->p3 = create_3d_vector(src->p3[0], src->p3[1], src->p3[2]);
	return (dst);
}

// time : O(n)
// space: O(n)
t_triangle_arr	*clone_triangle_arr(t_triangle_arr *src, size_t len)
{
	t_triangle_arr	*dst;
	size_t			i;

	if (len < 1)
		return (NULL);
	dst = init_triangle_arr(len);
	i = 0;
	while (i < src->lenght && dst != NULL && i < dst->capacity)
	{
		dst->arr[i] = clone_triangle(src->arr[i]);
		if (dst->arr[i] == NULL)
		{
			free_triangle_arr(dst);
			return (NULL);
		}
		dst->lenght += 1;
		i += 1;
	}
	return (dst);
}
