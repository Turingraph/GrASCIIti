#include"linalg.h"

// time : O(1)
// space: O(1)
void	*free_matrix(t_matrix *src)
{
	if (src == NULL)
		return (NULL);
	free(src->arr);
	src->arr = NULL;
	src->row = 0;
	src->col = 0;
	return (NULL);
}

// time : O(n)
// space: O(n)
t_matrix	init_matrix(size_t row, size_t col, float scale)
{
	t_matrix	dst;
	size_t		i;

	dst.row = row;
	dst.col = col;
	dst.arr = (float *)malloc(sizeof(float) * row * col);
	if (dst.arr == NULL)
	{
		free_matrix(&dst);
		return (dst);
	}
	i = 0;
	while (i < row * col)
	{
		dst.arr[i] = scale;
		i += 1;
	}
	return (dst);
}

// time : O(n^2)
// space: O(n^2)
t_matrix	outer_product_matrix(const float *vec_v, const float *vec_u, size_t dim)
{
	t_matrix	dst;
	size_t		i;

	dst = init_matrix(dim, dim, 1);
	if (dst.arr == NULL || (vec_u == NULL && vec_v == NULL))
		return (dst);
	i = 0;
	while (i < dim * dim)
	{
		if (vec_u != NULL)
			dst.arr[i] *= vec_u[i % dim];
		if (vec_v != NULL)
			dst.arr[i] *= vec_v[i / dim];
		i += 1;
	}
	return (dst);
}

/*
// time : O(n^3)
// space: O(n)
float	*square_matrix_product(float *update_v, const float *vec_u, size_t dim)
{
	size_t	i;
	size_t	j;
	size_t	col;
	float	*product;

	if (update_v == NULL || vec_u == NULL)
		return (NULL);
	col = (size_t)f_floor(f_root_finding(dim, 2));
	if (col < 1)
		return (NULL);
	product = malloc(sizeof(float) * dim);
	if (product == NULL)
		return (NULL);
	i = 0;
	while (i < dim)
	{
		i += 1;
	}
}
*/
