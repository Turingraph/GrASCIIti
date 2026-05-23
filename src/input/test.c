#include "input.h"
#include "libft.h"

/*
int	main(int len, char **str)
{
	t_llist_int	*ll;
	float		**matrix;
	size_t		col;
	size_t		row;
	size_t		i;

	if (len < 2)
		return (0);
	ll = create_ascii_file(str[1]);
	if (ll == NULL)
		return (0);
	col = len_llist(ll, &row);
	matrix = create_matrix(ll, 1, col, row);
	while (col > 0)
	{
		i = 0;
		while (i < row)
		{
			ft_putnbr_fd((int) matrix[col][i], 1);
			write(1, ", ", 2);
			i += 1;
		}
		write(1, "\n", 1);
		col -= 1;
	}
	return (0);
}
*/

int	main(int len, char **str)
{
	t_llist_int	*ll;
	// t_llist_int	*temp;
	// size_t		i;

	if (len < 2)
		return (0);
	ll = create_fdf_file(str[1]);
	if (ll == NULL)
		return (0);
	// while (ll != NULL)
	// {
	// 	i = 0;
	// 	while (i < ll->len)
	// 	{
	// 		ft_putnbr_fd(ll->arr[i], 1);
	// 		write(1, ",\t", 2);
	// 		i += 1;
	// 	}
	// 	temp = ll;
	// 	ll = ll->next;
	// 	free(temp->arr);
	// 	free(temp);
	// 	write(1, "\n", 1);
	// }
	free_llist(ll);
	return (0);
}

/*
// cc -Wall -Wextra -Werror src/input/main.c -Iinclude build/libmlx42.a build/libft.a build/get_next_line.a -ldl -lglfw3 -pthread -lm


cc -Wall -Wextra -Werror src/input/test.c fdf_lib build/libft.a build/get_next_line.a
valgrind --leak-check=full ./a.out a.txt
*/
