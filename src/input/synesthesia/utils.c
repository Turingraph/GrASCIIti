#include"synesthesia.h"

// time : O(1)
// space: O(1)
void	synesthesia_warning(char err, char alphabet)
{
	if (f_isspace(err, "E12SC") == 1)
		write(1, "synesthesia.txt Warning: ", 26);
	if (err == 'E' || err == '1')
	{
		write(1, "hexadecimal color of \'", 23);
		write(1, &alphabet, 1);
		write(1, "\' is invalid or isn't specified.\n", 34);
	}
	if (err == '2')
	{
		write(1, "\'", 1);
		write(1, &alphabet, 1);
		write(1, "\' is not supported by GrASCIIfi current version.\n", 50);
	}
	if (err == 'S' || err == 'C')
	{
		write(1, "Malloc Fail when using ", 24);
		if (err == 'S')
			write(1, "f_split", 8);
		else
			write(1, "ace_of_coin", 12);
		write(1, " on \'", 6);
		write(1, &alphabet, 1);
		write(1, "\'\n", 2);
	}
}

// time : O(n)
// space: O(1)
void	synesthesia_warning_02(char *line, char *dict)
{
	if (knight_of_coin(line, '#') < 10 && f_isspace(*line, dict) == 1 && *line != '#')
	{
		write(1, "synesthesia.txt Warning: hexadecimal color of \'", 48);
		write(1, line, 1);
		write(1, "\' isn't specified.\n", 20);
		replace_char(dict, *line, '#');
	}
	else if (f_isspace(*line, dict) == 0 && *line != '#' && *line != '\0')
	{
		write(1, "synesthesia.txt Warning: \'", 27);
		write(1, line, 1);
		if (f_isspace(*line, "0123456789abcdefghijklmnopqrstuvwxyz&@$%+-=.,!?()/") == 1)
			write(1, "\' is duplicated.\n", 18);
		else
			write(1, "\' is not supported by GrASCIIfi current version.\n", 50);
	}
}

// time : O(n)
// space: O(1)
void	replace_char(char *dst, char before, char after)
{
	size_t	i;

	i = 0;
	while (dst[i] != '\0')
	{
		if (dst[i] == before)
			dst[i] = after;
		i += 1;
	}
}

// time : O(n)
// space: O(n)
void	write_synesthesia(int fd, t_synesthesia *src)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < src->row)
	{
		j = 0;
		write(fd, src->alphabet + i, 1);
		while (j < src->col)
		{
			write(fd, " ", 1);
			ft_putnbr_fd((int)(src->r[i][j]), fd, "0123456789abcdef", 2);
			ft_putnbr_fd((int)(src->g[i][j]), fd, "0123456789abcdef", 2);
			ft_putnbr_fd((int)(src->b[i][j]), fd, "0123456789abcdef", 2);
			ft_putnbr_fd((int)(src->a[i][j]), fd, "0123456789abcdef", 2);
			j += 1;
		}
		write(fd, "\n", 1);
		i += 1;
	}
}
