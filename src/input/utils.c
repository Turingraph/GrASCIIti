#include "input.h"

// len : O(n)
// space: O(1)
void	free_llist(t_llist_int *ll)
{
	t_llist_int		*temp;

	if (ll != NULL)
	{
		while (ll->next != NULL)
		{
			temp = ll->next;
			free(ll->arr);
			free(ll);
			ll = temp;
		}
		free(ll);
	}
}

// time : O(1)
// space: O(1)
long int	f_atolongi(char *src, char *err, size_t *digit, size_t sign)
{
	long int	y;

	y = 0;
	while (src[*digit] != '\0' && *digit < 11 + sign && *err != 'E')
	{
		if (*digit == sign && src[*digit] == '0')
			*err = 'E';
		else if (src[*digit] >= '0' && src[*digit] <= '9')
			y += (long int)(src[*digit] - '0');
		else
			*err = 'E';
		*digit += 1;
		y *= 10;
	}
	y /= 10;
	return (y);
}

// time : O(1)
// space: O(1)
int	f_atoi(char *src, char *err)
{
	long int	y;
	size_t		digit;
	size_t		sign;

	if (src[0] == '0' && src[1] == '\0')
		return (0);
	digit = 0;
	sign = 0;
	if (src[digit] == '-')
		sign = 1;
	digit = sign;
	y = f_atolongi(src, err, &digit, sign);
	if (sign == 1)
		y *= -1;
	if (src[digit] != '\0' && digit >= 11 + sign)
	{
		*err = 'E';
		return (-1);
	}
	if (y < -2147483648 || y > 2147483647)
	{
		*err = 'E';
		return (-1);
	}
	return ((int) y);
}

// time : O(1)
// space: O(1)
char	f_isspace(char s)
{
	if (s == ' '
		|| s == '\t'
		|| s == '\n'
		|| s == '\v'
		|| s == '\f'
		|| s == '\r')
	{
		return (1);
	}
	return (0);
}

