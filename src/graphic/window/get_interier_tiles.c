#include"window.h"

// time : O(1)
// space: O(1)
int	get_first_interier_tile(int tiles_offset,
	int camera_offset, float camera_zoom, size_t tile_size)
{
	int	dst;

	dst = 0;
	if (tiles_offset < camera_offset
		&& (size_t)(camera_zoom * tile_size) > 0)
	{
		dst = (camera_offset - tiles_offset);
		dst /= ((size_t)(camera_zoom * tile_size));
	}
	return (dst);
}

// time : O(1)
// space: O(1)
int	get_last_interier_tile(int tiles_right_offset,
	int window_right_offset, float zoom, size_t tile_size)
{
	int	dst;

	dst = -2;
	if (tiles_right_offset > window_right_offset)
	{
		dst = tiles_right_offset - window_right_offset;
		if ((size_t)(zoom * tile_size) > 0)
			dst /= (size_t)(zoom * tile_size);
	}
	return (dst);
}

// time : O(1)
// space: O(1)
t_2d_int	get_interier_tiles_p1(t_tile_format tiles,
	t_2d_camera camera, size_t window_width, size_t window_height)
{
	t_line		zoom_offset;
	t_2d_int	dst;

	zoom_offset = pan_zoom_line(camera, tiles.offset,
		window_width, window_height);
	dst.x = get_first_interier_tile(
		zoom_offset.p1.x, camera.offset.x, camera.zoom, tiles.tile_size);
	if (zoom_offset.p1.x > camera.offset.x + (int)window_width
		|| zoom_offset.p2.x < camera.offset.x)
		dst.x = -1;
	dst.y = get_first_interier_tile(
		zoom_offset.p1.y, camera.offset.y, camera.zoom, tiles.tile_size);
	if (zoom_offset.p1.y > camera.offset.y + (int)window_width
		|| zoom_offset.p2.y < camera.offset.y)
		dst.y = -1;
	return (dst);
}

// time : O(1)
// space: O(1)
t_2d_int	get_interier_tiles_p2(t_tile_format tiles,
	t_2d_camera camera, size_t window_width, size_t window_height)
{
	t_line		zoom_offset;
	t_2d_int	dst;

	zoom_offset = pan_zoom_line(camera, tiles.offset,
		window_width, window_height);
	dst.x = tiles.tile_counts.x;
	if (get_last_interier_tile(zoom_offset.p2.x,
			camera.offset.x + (int)window_width, camera.zoom, tiles.tile_size) > -2)
		dst.x = get_last_interier_tile(zoom_offset.p2.x,
			camera.offset.x + (int)window_width, camera.zoom, tiles.tile_size);
	dst.y = tiles.tile_counts.y;
	if (get_last_interier_tile(zoom_offset.p2.y,
			camera.offset.y + (int)window_height, camera.zoom, tiles.tile_size) > -2)
		dst.y = get_last_interier_tile(zoom_offset.p2.y,
			camera.offset.y + (int)window_height, camera.zoom, tiles.tile_size);
	return (dst);
}
