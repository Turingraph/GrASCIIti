#include"window.h"

// note that resolution <= 10, for "standard window"
// time : O(1)
// space: O(1)
t_line	init_offset_tile_area(size_t width, size_t height,
	size_t resolution, size_t max_length)
{
	t_line	dst;

	dst.p1.x = init_alltiles_offset(max_length,
			width, resolution);
	dst.p1.y = init_alltiles_offset(max_length,
			height, resolution);
	dst.p2.x = dst.p1.x + init_alltiles_size(max_length,
			width, resolution);
	dst.p2.y = dst.p1.y + init_alltiles_size(max_length,
			height, resolution);
	return (dst);
}

// note that resolution <= 10, for "standard window"
// time : O(1)
// space: O(1)
t_2d_int	init_offset_tiles_count(size_t width, size_t height,
	size_t resolution, size_t max_length)
{
	t_2d_int	dst;

	dst.x = init_alltiles_count(max_length,
			width, resolution);
	dst.y = init_alltiles_count(max_length,
			height, resolution);
	return (dst);
}

// note that resolution <= 10, for "standard window"
// time : O(1)
// space: O(1)
t_offset_tile	init_offset_tile(size_t width, size_t height,
	size_t resolution)
{
	size_t			max_length;
	t_offset_tile	dst;

	max_length = width;
	if (width < height)
		max_length = height;
	dst.tile_counts = init_offset_tiles_count(width, height,
			resolution, max_length);
	dst.offset = init_offset_tile_area(width, height,
			resolution, max_length);
	dst.tile_size = init_tile_size(height, resolution);
	if (width < height)
		dst.tile_size = init_tile_size(width, resolution);
	return (dst);
}
