#include"window.h"

// note that resolution <= 10, for "standard window"
// time : O(1)
// space: O(1)
size_t	init_tile_size(size_t size_length, size_t resolution)
{
	return (size_length / f_pow(2.0, resolution));
}

// note that resolution <= 10, for "standard window"
// time : O(1)
// space: O(1)
size_t	init_alltiles_count(size_t max_length,
	size_t size_length, size_t resolution)
{
	size_t	cell_size;

	cell_size = init_tile_size(size_length, resolution);
	if (cell_size == 0)
		return (0);
	return ((size_t)f_floor((float)max_length / (float)cell_size));
}

// note that resolution <= 10, for "standard window"
// time : O(1)
// space: O(1)
size_t	init_alltiles_size(size_t max_length,
	size_t size_length, size_t resolution)
{
	size_t	cell_size;
	size_t	allcells_count;

	cell_size = init_tile_size(size_length, resolution);
	allcells_count = init_alltiles_count(max_length, size_length, resolution);
	return (allcells_count * cell_size);
}

// note that resolution <= 10, for "standard window"
// time : O(1)
// space: O(1)
size_t	init_alltiles_offset(size_t max_length,
	size_t size_length, size_t resolution)
{
	size_t	allcells_size;

	allcells_size = init_alltiles_size(
			max_length, size_length, resolution);
	return ((max_length - allcells_size) / 2);
}
