#include"triangle_arr.h"

// time : O(n)
// space: O(1)
void	scale_triangle_arr(t_triangle_arr *src, double scale, size_t axis)
{
	size_t	i;

	i = 0;
	while (src != NULL && i < src->lenght)
	{
		src->arr[i]->p1[axis] *= scale;
		src->arr[i]->p2[axis] *= scale;
		src->arr[i]->p3[axis] *= scale;
		i += 1;
	}
}

// time : O(n)
// space: O(1)
void	shift_triangle_arr(t_triangle_arr *src, double shift, size_t axis)
{
	size_t	i;

	i = 0;
	while (src != NULL && i < src->lenght && 0 <= axis && axis <= 2)
	{
		src->arr[i]->p1[axis] += shift;
		src->arr[i]->p2[axis] += shift;
		src->arr[i]->p3[axis] += shift;
		i += 1;
	}
}

// time : O(n)
// space: O(1)
void	set_base_triangle_arr(t_triangle_arr *src, double base, size_t axis)
{
	size_t	i;

	i = 0;
	while (src != NULL && i < src->lenght)
	{
		if (src->arr[i]->p1[axis] > 0)
			src->arr[i]->p1[axis] = base;
		if (src->arr[i]->p2[axis] > 0)
			src->arr[i]->p2[axis] = base;
		if (src->arr[i]->p2[axis] > 0)
			src->arr[i]->p2[axis] = base;
		i += 1;
	}
}

// time : O(n)
// space: O(1)
void	set_width_triangle_arr(t_triangle_arr *src, double width, size_t axis)
{
	size_t	i;

	i = 0;
	while (src != NULL && i < src->lenght)
	{
		if (src->arr[i]->p1[axis] > 0)
			src->arr[i]->p1[axis] += width;
		if (src->arr[i]->p2[axis] > 0)
			src->arr[i]->p2[axis] += width;
		if (src->arr[i]->p2[axis] > 0)
			src->arr[i]->p2[axis] += width;
		i += 1;
	}
}

// time : O(n)
// space: O(1)
void	min_and_max_triangle(t_triangle_arr *src, size_t axis, char mode)
{
	size_t	i;
	long	min;
	long	max;

	min = (long)src->arr[0]->p1[axis];
	max = (long)0;
	i = 0;
	while (i < src->len)
	{
		if (max < src->arr[i]->p1[axis])
			max = src->arr[i]->p1[axis];
		if (max < src->arr[i]->p2[axis])
			max = src->arr[i]->p2[axis];
		if (max < src->arr[i]->p3[axis])
			max = src->arr[i]->p3[axis];
		if (min > src->arr[i]->p1[axis])
			min = src->arr[i]->p1[axis];
		if (min > src->arr[i]->p2[axis])
			min = src->arr[i]->p2[axis];
		if (min > src->arr[i]->p3[axis])
			min = src->arr[i]->p3[axis];
		i += 1;
	}
	if (mode == 0)
		return (min);
	return (max);
}
