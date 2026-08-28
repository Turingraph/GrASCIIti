#include"fdf_private.h"

// time : O(1)
// space: O(1)
float	init_fdf_position_unit(const t_table_fdf *src, char axis, size_t i)
{
	if (src == NULL || src->arr == NULL || axis < 0 || axis > 2
		|| src->row * src->col == 0)
		return (0.0);
	if (axis == 0)
		return ((float)(i % src->col) - (float)(src->col / 2));
	if (axis == 1)
		return ((float)(i / src->col) - (float)(src->row / 2));
	return ((float)src->arr[i]);
}

// time : O(n)
// space: O(n)
float	*init_fdf_position(const t_table_fdf *src, char axis)
{
	float	*dst;
	size_t	i;

	if (src == NULL || src->arr == NULL || axis < 0 || axis > 2
		|| src->row * src->col == 0)
		return (NULL);
	dst = (float *)malloc(sizeof(float) * src->row * src->col);
	if (dst == NULL)
		return (NULL);
	i = 0;
	while (i < src->row * src->col)
	{
		dst[i] = init_fdf_position_unit(src, axis, i);
		i += 1;
	}
	return (dst);
}

/**
 * Initialize a 3D FDF object from a t_table_fdf table.
 *
 * The returned object owns the position arrays and 3D transformation
 * matrix created from the source table. The source table itself is also
 * owned by the returned t_fdf and must not be freed separately before
 * free_fdf() is called.
 *
 * The position arrays represent the X, Y, and Z coordinates used by
 * the FDF renderer.
 *
 * This function does not display the object. The caller is responsible
 * for checking the returned object and calling free_fdf() when it is
 * no longer needed.
 *
 * time/space: O(n) / O(n)
 *
 * status: public api
 *
 * @param src source table containing the FDF data
 * @return initialized t_fdf object
 */
t_fdf	init_fdf(t_table_fdf *src)
{
	t_fdf	dst;
	float	max_x;
	float	min_x;

	dst.src = src;
	dst.pos_x = init_fdf_position(src, 0);
	dst.pos_y = init_fdf_position(src, 1);
	dst.pos_z = init_fdf_position(src, 2);
	dst.matrix = init_3d_zoom_matrix(1.0);
	min_x = (float)get_minmax_from_table_fdf(
		(const t_table_fdf *)src, false, HEIGHT);
	max_x = (float)get_minmax_from_table_fdf(
		(const t_table_fdf *)src, true, HEIGHT);
	dst.width = f_max3(max_x - min_x, src->row, src->col);
	return (dst);
}

/**
 * Release all resources owned by an FDF object.
 *
 * This function frees the source table, position arrays, and
 * transformation matrix owned by the t_fdf object. After this function
 * returns, the object's owned pointers are set to NULL and its matrix
 * dimensions are reset to zero.
 *
 * view_fdf() does not call free_fdf(). The caller therefore remains
 * responsible for releasing an FDF object created by init_fdf().
 *
 * Calling free_fdf() with NULL is safe.
 *
 * time/space: O(1) /  O(1)
 *
 * status: public api
 *
 * @param src FDF object to release
 */
void	free_fdf(t_fdf *src)
{
	if (src == NULL)
		return ;
	free_table_fdf(src->src);
	free(src->pos_x);
	free(src->pos_y);
	free(src->pos_z);
	free(src->matrix.arr);
	src->pos_x = NULL;
	src->pos_y = NULL;
	src->pos_z = NULL;
	src->src = NULL;
	src->matrix.arr = NULL;
	src->matrix.col = 0;
	src->matrix.row = 0;
}

// time : O(1)
// space: O(1)
bool	is_fdf_valid(const t_2d_hook *src)
{
	t_table_fdf	*table;

	if (src == NULL)
		return (false);
	table = src->src;
	if (table == NULL || table->arr == NULL
		|| src->width == 0
		|| table->row * table->col == 0
		|| src->matrix.col != 3
		|| src->matrix.row != 3
		|| src->matrix.arr == NULL
		|| src->pos_x == NULL
		|| src->pos_y == NULL
		|| src->pos_z == NULL)
		return (false);
	return (true);
}
