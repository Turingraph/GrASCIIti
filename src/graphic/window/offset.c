#include"window.h"

// time : O(1)
// space: O(1)
t_line	init_offset_tile_area(size_t width, size_t height,
	size_t resolution, size_t fixed_length)
{
	t_line	output;

	output.p1.x = init_alltiles_offset(width, resolution, fixed_length);
	output.p1.y = init_alltiles_offset(height, resolution, fixed_length);
	output.p2.x = output.p1.x + init_alltiles_size(width, resolution, fixed_length);
	output.p2.y = output.p1.y + init_alltiles_size(height, resolution, fixed_length);
	return (output);
}

// time : O(1)
// space: O(1)
t_tile_format	init_tile_format(size_t width,
	size_t height, size_t resolution)
{
	t_tile_format	dst;
	size_t			fixed_side;

	fixed_side = (size_t)f_min((float)width, (float)height);
	dst.offset = init_offset_tile_area(width, height, resolution, fixed_side);
	dst.tile_size = init_tile_size(fixed_side, resolution);
	dst.tile_counts.x = init_alltiles_count(width, resolution, fixed_side);
	dst.tile_counts.y = init_alltiles_count(height, resolution, fixed_side);
	return (dst);
}
