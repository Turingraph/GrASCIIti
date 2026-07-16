#include"line.h"

// time : O(n)
// space: O(1)
void	xiaolin_wu_line_int_x(int *dst, t_line line)
{
	float	distance_a;
	float	distance_b;
	float	delta;
	float	y1;

	if (dst != NULL)
	{
		sort_line_index(&line, 0);
		y1 = line.y1;
		delta = 1;
		if (line.x2 - line.x1 != 0)
			delta = (line.y2 - line.y1) / (line.x2 - line.x1);
		while (line.x1 <= line.x2 && line.x1 < line.row && line.y1 < line.col)
		{
			distance_a = delta * (line.x1 + 1) + y1 - 
			line.x1 += 1;
		}
	}
}