#include "input.h"

// time : O(n)
// space: O(1)
size_t	len_llist(t_llist_int *ll, size_t *width)
{
	size_t	i;

	*width = 0;
	i = 1;
	while (ll->next != NULL)
	{
		i += 1;
		if (*width < ll->len)
			*width = ll->len;
		ll = ll->next;
	}
	return (i);
}

// time : O(n)
// space: O(1)
void	sub_floatcpy(float **dst, float src, size_t not_sharp)
{
	size_t	j;

	j = 0;
	while (j < not_sharp)
	{
		**dst = src;
		*dst += 1;
		j += 1;
	}
}

// time : O(n)
// space: O(1)
float	*intcpy(int *src, size_t srclen, size_t dstlen, size_t not_sharp)
{
	size_t	i;
	float	*dst;

	dst = (float *)malloc(sizeof(float) * dstlen * not_sharp);
	if (dst == NULL)
		return (NULL);
	i = 0;
	while (i < srclen)
	{
		sub_floatcpy(&dst, (float) *src, not_sharp);
		src += 1;
		i += 1;
	}
	while (i < dstlen)
	{
		sub_floatcpy(&dst, 0, not_sharp);
		i += 1;
	}
	return (dst);
}

// time : O(n)
// space: O(1)
void	free_matrix(float **matrix, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		free(matrix[i]);
		i += 1;
	}
	free(matrix);
}

// time : O(n)
// space: O(n)
// it is matrix, a.k.a. array of array with the same length. fill 0 as default elements.
float	**create_matrix(t_llist_int *ll, size_t not_sharp, size_t col, size_t row)
{
	float		**arr;
	size_t		i;
	size_t		ii;
	size_t		j;
	t_llist_int	*temp;

	arr = (float **)malloc(sizeof(float *) * col * not_sharp);
	if (arr == NULL)
	{
		free_llist(ll);
		return (NULL);
	}
	ii = 0;
	i = 0;
	while (i < col)
	{
		temp = ll;
		j = 0;
		while (j < not_sharp)
		{
			arr[ii + j] = intcpy(ll->arr, ll->len, row, not_sharp);
			if (arr[ii + j] == NULL)
			{
				free_matrix(arr, ii + j);
				free_llist(ll);
				return (NULL);
			}
			j += 1;
		}
		ll = ll->next;
		free(temp);
		i += 1;
		ii += not_sharp;
	}
	return (arr);
}