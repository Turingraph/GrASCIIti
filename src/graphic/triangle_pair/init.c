#include"triangle_pair.h"

// time : O(1)
// space: O(1)
void	*free_triangle(t_triangle *src)
{
	if (src == NULL)
		return (NULL);
	if (src->p1 != NULL)
		free(src->p1);
	if (src->p2 != NULL)
		free(src->p2);
	if (src->p3 != NULL)
		free(src->p3);
	src->r = 0;
	src->g = 0;
	src->b = 0;
	src->a = 0;
	src->p1 = NULL;
	src->p2 = NULL;
	src->p3 = NULL;
	return (NULL);
}

// time : O(1)
// space: O(1)
void	*free_triangle_arr(t_triangle_arr *src)
{
	size_t	i;

	if (src == NULL)
		return (NULL);
	if (src != NULL && src->arr != NULL)
	{
		i = 0;
		while (i < src->capacity)
		{
			free_triangle(&(src->arr[i]));
			i += 1;
		}
		free(src->arr);
	}
	src->arr = NULL;
	src->capacity = 0;
	src->length = 0;
	src->width_x = 0.0;
	src->width_y = 0.0;
	src->width_z = 0.0;
	return (NULL);
}

// time : O(1)
// space: O(1)
t_triangle	init_triangle()
{
	t_triangle	dst;

	dst.r = (unsigned char)255;
	dst.g = (unsigned char)255;
	dst.b = (unsigned char)255;
	dst.a = (unsigned char)0;
	dst.p1 = create_3d_vector(0, 0, 0);
	dst.p2 = create_3d_vector(0, 0, 0);
	dst.p3 = create_3d_vector(0, 0, 0);
	return (dst);
}

// time : O(1)
// space: O(1)
t_triangle_arr	init_triangle_arr(size_t length)
{
	t_triangle_arr	dst;

	dst.length = 0;
	dst.capacity = length;
	dst.width_x = 0.0;
	dst.width_y = 0.0;
	dst.width_z = 0.0;
	dst.arr = NULL;
	if (length > 0)
		dst.arr = malloc_talk(sizeof(t_triangle) * length,
			"mesh/init.c/init_triangle_arr\n");
	return (dst);
}

// time : O(1)
// space: O(1)
float	width_of_triangle(t_triangle src, size_t axis, char max)
{
	float	dst;
	float	sign;

	if (axis > 2 || src.p1 == NULL || src.p2 == NULL || src.p3 == NULL)
		return (0.0);
	dst = src.p1[axis];
	sign = 1;
	if (max == 0)
		sign *= -1;
	if (dst * sign < sign * src.p2[axis])
		dst = src.p2[axis];
	if (dst * sign < sign * src.p3[axis])
		dst = src.p3[axis];
	return (dst);
}