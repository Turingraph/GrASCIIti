#include"line.h"

// time : O(n)
// space: O(1)
t_line	get_allcells_horizontal_boundary(size_t width,
	size_t height, size_t resolution)
{
	t_line	dst;

	dst.p1.x = get_offset_tiling(
			width, height, resolution);
	dst.p1.y = get_offset_tiling(
			height, height, resolution);
	dst.p2.x = dst.p1.x + get_total_cells_length(
			width, height, resolution);
	dst.p2.y = dst.p1.y + get_total_cells_length(
			height, height, resolution);
	return (dst);
}

// time : O(n)
// space: O(1)
t_2d_int	get_allcells_horizontal_count(size_t width,
	size_t height, size_t resolution)
{
	t_2d_int	dst;

	dst.x = get_allcells_count(width, height,
			resolution);
	dst.y = get_allcells_count(height, height,
			resolution);
	return (dst);
}
