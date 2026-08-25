#include "linalg.h"

// time : O(1)
// space: O(1)
t_matrix	init_3d_rotate_matrix_x(float delta)
{
	t_matrix	dst;

	dst.arr = malloc(sizeof(float) * 9);
	dst.col = 0;
	dst.row = 0;
	if (dst.arr == NULL)
		return (dst);
	dst.col = 3;
	dst.row = 3;
	dst.arr[0] = 1.0;
	dst.arr[1] = 0.0;
	dst.arr[2] = 0.0;
	dst.arr[3] = 0.0;
	dst.arr[4] = f_cos(delta);
	dst.arr[5] = -1.0 * f_sin(delta);
	dst.arr[6] = 0.0;
	dst.arr[7] = f_sin(delta);
	dst.arr[8] = f_cos(delta);
	return (dst);
}

// time : O(1)
// space: O(1)
t_matrix	init_3d_rotate_matrix_y(float delta)
{
	t_matrix	dst;

	dst.arr = malloc(sizeof(float) * 9);
	dst.col = 0;
	dst.row = 0;
	if (dst.arr == NULL)
		return (dst);
	dst.col = 3;
	dst.row = 3;
	dst.arr[0] = f_cos(delta);
	dst.arr[1] = 0.0;
	dst.arr[2] = f_sin(delta);
	dst.arr[3] = 0.0;
	dst.arr[4] = 1.0;
	dst.arr[5] = 0.0;
	dst.arr[6] = -1.0 * f_sin(delta);
	dst.arr[7] = 0.0;
	dst.arr[8] = f_cos(delta);
	return (dst);
}

// time : O(1)
// space: O(1)
t_matrix	init_3d_rotate_matrix_z(float delta)
{
	t_matrix	dst;

	dst.arr = malloc(sizeof(float) * 9);
	dst.col = 0;
	dst.row = 0;
	if (dst.arr == NULL)
		return (dst);
	dst.col = 3;
	dst.row = 3;
	dst.arr[0] = f_cos(delta);
	dst.arr[1] = -1.0 * f_sin(delta);
	dst.arr[2] = 0.0;
	dst.arr[3] = f_sin(delta);
	dst.arr[4] = f_cos(delta);
	dst.arr[5] = 0.0;
	dst.arr[6] = 0.0;
	dst.arr[7] = 0.0;
	dst.arr[8] = 1.0;
	return (dst);
}
