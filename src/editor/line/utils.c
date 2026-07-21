#include"line.h"

// time : O(1)
// space: O(1)
void	sort_2d_points(t_line *line)
{
	int		temp;
	int		delta_x;
	int		delta_y;

	delta_y = 0;
	delta_x = 0;
	if (line != NULL)
	{
		delta_y = (int)f_abs(line->p2.x - line->p1.x);
		delta_x = (int)f_abs(line->p2.y - line->p1.y);
		write(1, "::: ", 4);
		ft_putnbr_fd(delta_x, 1, "0123456789", 2);
		write(1, ", ", 2);
		ft_putnbr_fd(delta_y, 1, "0123456789", 2);
		write(1, "\n", 1);
	}
	if (line != NULL && ((delta_x >= delta_y && line->p2.x < line->p1.x)
			|| (line->p2.y < line->p1.y && delta_x <= delta_y)))
	{
		write(1, "Battle Sprits\n", 15);
		temp = line->p2.x;
		line->p2.x = line->p1.x;
		line->p1.x = temp;
		temp = line->p2.y;
		line->p2.y = line->p1.y;
		line->p1.y = temp;
	}
	// else if (line != NULL && (delta_x < delta_y || line->p2.x >= line->p1.x))
	// {
	// 	write(1, ">>> [", 5);
	// 	ft_putnbr_fd(line->p1.x, 1, "0123456789", 2);
	// 	write(1, ", ", 2);
	// 	ft_putnbr_fd(line->p1.y, 1, "0123456789", 2);
	// 	write(1, "] --> [", 8);
	// 	ft_putnbr_fd(line->p2.x, 1, "0123456789", 2);
	// 	write(1, ", ", 2);
	// 	ft_putnbr_fd(line->p2.y, 1, "0123456789", 2);
	// 	write(1, "]\n", 2);
	// }
}

// time : O(1)
// space: O(1)
bool	is_in_boundary(int x, int y, t_line boundary)
{
	if (x >= boundary.p1.x
		&& x < boundary.p2.x
		&& y >= boundary.p1.y
		&& y < boundary.p2.y)
		return (true);
	return (false);
}
