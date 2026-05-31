#include "table.h"

// time : O(n)
// space: O(1)
long	min_and_max_fdf(t_table_fdf *table, char mode)
{
	size_t	i;
	size_t	j;
	long	min;
	long	max;

	min = (long)table->arr[0][0];
	max = (long)0;
	i = 0;
	while (i < table->row)
	{
		j = 0;
		while (j < table->col)
		{
			if (max < (long)table->arr[i][j])
				max = (long)table->arr[i][j];
			if (min > (long)table->arr[i][j])
				min = (long)table->arr[i][j];
			j += 1;
		}
		i += 1;
	}
	if (mode == 0)
		return (min);
	return (max);
}

// time : O(n)
// space: O(1)
void	scale_relu_fdf(t_table_fdf *table, int min, int max, int expect)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < table->row)
	{
		j = 0;
		while (j < table->col)
		{
			if (table->arr[i][j] >= min && table->arr[i][j] <= max)
				table->arr[i][j] = expect;
			j += 1;
		}
		i += 1;
	}
}

// time : O(n)
// space: O(1)
void	scale_addition_fdf(t_table_fdf *table, int scale)
{
	size_t	i;
	size_t	j;
	long	check;

	i = 0;
	while (i < table->row)
	{
		j = 0;
		while (j < table->col)
		{
			check = (long)table->arr[i][j] + (long)scale;
			if (check > 2147483647)
				table->arr[i][j] = 2147483647;
			else if (check < -2147483648)
				table->arr[i][j] = -2147483648;
			else
				table->arr[i][j] = (int)check;
			j += 1;
		}
		i += 1;
	}
}

// time : O(n)
// space: O(1)
void	positive_table_fdf(t_table_fdf *table)
{
	long	min;

	min = min_and_max_fdf(table, 0);
	if (min <= -2147483648)
		min = 2147483647;
	else if (min < 0)
		min *= -1;
	else if (min > 2147483647)
		min = 2147483647;
	scale_addition_fdf(table, min);
}
