#include"triangle_arr.h"

// time : O(n)
// space: O(1)
float	update_width_of_triangle_arr(t_triangle_arr *src, size_t axis)
{
	size_t	i;
	float	min;
	float	max;

	min = 0;
	max = 0;
	if (src->arr != NULL && 0 < src->length && axis <= 2)
		min = width_of_triangle(src->arr[0], axis, 0);
	i = 0;
	while (src->arr != NULL && i < src->length && axis <= 2)
	{
		if (max < width_of_triangle(src->arr[i], axis, 1))
			max = width_of_triangle(src->arr[i], axis, 1);
		if (min > width_of_triangle(src->arr[i], axis, 0))
			min = width_of_triangle(src->arr[i], axis, 0);
		i += 1;
	}
	if (axis == 0)
		src->width_x = max - min;
	if (axis == 1)
		src->width_y = max - min;
	if (axis == 2)
		src->width_z = max - min;
	return (min);
}

// time : O(n)
// space: O(1)
float	center_triangle_arr(t_triangle_arr *src, size_t axis)
{
	float	min;
	float	max;

	min = update_width_of_triangle_arr(src, axis);
	max = min;
	if (axis == 0)
		max += src->width_x;
	if (axis == 1)
		max += src->width_y;
	if (axis == 2)
		max += src->width_z;
	shift_triangle_arr(src, -1 * (max + min) / 2, axis);
	return ((max + min) / 2);
}

// time : O(n)
// space: O(1)
float	average_triangle_arr(t_triangle_arr *src, size_t axis, char update)
{
	size_t	i;
	float	y;

	y = 0;
	i = 0;
	while (i < src->length && src->arr != NULL && axis <= 2)
	{
		if (src->arr[i].p1 != NULL)
			y += src->arr[i].p1[axis];
		if (src->arr[i].p2 != NULL)
			y += src->arr[i].p2[axis];
		if (src->arr[i].p3 != NULL)
			y += src->arr[i].p3[axis];
		i += 1;
	}
	if (src->length > 0)
		y /= 3 * src->length;
	if (update == 0)
		return (y);
	shift_triangle_arr(src, -1 * y, axis);
	return (y);
}
