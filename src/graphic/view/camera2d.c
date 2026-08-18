#include "view.h"

/*
Define (all the value of the object 'a' should be positive)
1.  o_v = start position
2.  o_w = stop position
3.  a = object vector
4.  z = zoom level

Define
1.  o_c = center = 1 / 2 * (o_w + o_v)
2.  a + o_v = object vector that in the center of the camera
3.  o_d = different between o_w and o_v = o_w - o_v

Then calculate this equality
*  o_v = 1 / 2 (o_w + o_v - o_w + o_v)
*  o_v = 1 / 2 (o_w + o_v) - 1 / 2 (o_w - o_v)
*  o_v = o_c - 1 / 2 (o_w - o_v)
*  o_v = o_c - 1 / 2 o_d

Implies that
*   a + o_v = a + o_c - 1 / 2 o_d
*   a + o_v = z a - z / 2 o_d + o_c, when z = 1
*	a + o_v = z a - 1 / 2 (z (o_w - o_v) + (o_w + o_v))

Reference
*   https://www.desmos.com/calculator/r8lvqclwww
*/

// time : O(1)
// space: O(1)
int	zoom_object(int start, int stop,
	int target, float zoom)
{
	int		temp;
	float	dst;

	if (start > stop)
	{
		temp = start;
		start = stop;
		stop = temp;
	}
	dst = zoom * (float)target;
	dst -= (zoom * (float)(stop - start)) / 2.0;
	dst += (1.0 / 2.0) * (float)(stop + start);
	return ((int)dst);
}

// time : O(1)
// space: O(1)
t_2d_camera	init_2d_camera(size_t row, size_t col)
{
	t_2d_camera	dst;

	dst.dim.x = col;
	dst.dim.y = row;
	dst.offset.x = 0;
	dst.offset.y = 0;
	dst.zoom = 1.0;
	return (dst);
}

// time : O(1)
// space: O(1)
t_line	zoom_world_boundary(t_line the_world,
	t_2d_camera camera)
{
	t_line	dst;

	dst.p1.x = zoom_object(
			camera.offset.x,
			camera.offset + camera.dim.x,
			the_world.p1.x,
			camera.zoom);
	dst.p1.y = zoom_object(
			camera.offset.y,
			camera.offset + camera.dim.y,
			the_world.p1.y,
			camera.zoom);
	dst.p2.x = zoom_object(
			camera.offset.x,
			camera.offset + camera.dim.x,
			the_world.p2.x,
			camera.zoom);
	dst.p2.y = zoom_object(
			camera.offset.y,
			camera.offset + camera.dim.y,
			the_world.p2.y,
			camera.zoom);
	return (dst);
}

// time : O(1)
// space: O(1)
t_line	selected_tiling(t_line the_world,
	t_2d_camera camera,
	t_2d_int allcells, size_t cell_size)
{
	t_2d_int	offset;
	t_2d_int	dst;

	if (cell_size > 0)
	{
		the_world = zoom_world_boundary(
				the_world, camera);
		offset = the_world.p1;
		dst.x = f_floor(offset.x / cell_size);
		dst.y = f_floor(offset.y / cell_size);
	}
}
