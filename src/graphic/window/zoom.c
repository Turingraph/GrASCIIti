#include"window.h"

/*
// time : O(1)
// space: O(1)
t_2d_int	points_addition(t_2d_int a, t_2d_int b)
{
	t_2d_int	c;

	c.x = a.x + b.x;
	c.y = a.y + b.y;
	return (c);
}

// time : O(1)
// space: O(1)
t_line	lines_addition(t_line a, t_line b)
{
	t_line	c;

	c.p1 = points_addition(a.p1, b.p1);
	c.p2 = points_addition(a.p2, b.p2);
	return (c);
}
*/

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
t_line	pan_zoom_line(t_2d_camera camera, t_line target,
	size_t window_width, size_t window_height)
{
	t_line	dst;

	dst.p1.x = zoom_object(camera.offset.x,
		camera.offset.x + window_width, target.p1.x, camera.zoom);
	dst.p1.y = zoom_object(camera.offset.y,
		camera.offset.y + window_height, target.p1.y, camera.zoom);
	dst.p2.x = zoom_object(camera.offset.x,
		camera.offset.x + window_width, target.p2.x, camera.zoom);
	dst.p2.y = zoom_object(camera.offset.y,
		camera.offset.y + window_height, target.p2.y, camera.zoom);
	return (dst);
}
