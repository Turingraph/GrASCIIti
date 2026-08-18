#include"view.h"

// time : O(n)
// space: O(1)
size_t	get_cell_size(size_t size_length, size_t resolution)
{
	return (size_length / f_pow(2.0, resolution));
}

// time : O(n)
// space: O(1)
size_t	get_allcells_count(size_t max_length,
	size_t size_length, size_t resolution)
{
	size_t	cell_size;

	cell_size = get_cell_size(size_length, resolution);
	if (cell_size == 0)
		return (0);
	return ((size_t)f_floor((float)max_length / (float)cell_size));
}

// time : O(n)
// space: O(1)
size_t	get_allcells_size(size_t max_length,
	size_t size_length, size_t resolution)
{
	size_t	cell_size;
	size_t	allcells_count;

	cell_size = get_cell_size(size_length, resolution);
	allcells_count = get_allcells_count(max_length, size_length, resolution);
	return (allcells_count * cell_size);
}

// time : O(n)
// space: O(1)
size_t	get_allcells_offset(size_t max_length,
	size_t size_length, size_t resolution)
{
	size_t	allcells_size;

	allcells_size = get_allcells_size(
			max_length, size_length, resolution);
	return ((max_length - allcells_size) / 2);
}
