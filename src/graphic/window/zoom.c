#include"window.h"

// https://youtu.be/ZQ8qtAizis4?si=mscCRKnmR9QVH6cy

// time : O(1)
// space: O(1)
int	world_to_screen_xy(int offset, float world)
{
	return ((int)world + offset);
}

// time : O(1)
// space: O(1)
t_2d_int	world_to_screen_2d(t_2d_camera camera, t_complex world)
{
	t_2d_int	dst;

	dst.x = world_to_screen_xy(camera.offset.x, world.re);
	dst.y = world_to_screen_xy(camera.offset.y, world.im);
	return (dst);
}

// time : O(1)
// space: O(1)
float	screen_to_world_xy(int offset, int screen)
{
	return ((float)(screen - offset));
}

// time : O(1)
// space: O(1)
t_complex	screen_to_world_2d(t_2d_camera camera, t_2d_int screen)
{
	t_complex	dst;

	dst.re = screen_to_world_xy(camera.offset.x, screen.x);
	dst.im = screen_to_world_xy(camera.offset.y, screen.y);
	return (dst);
}
