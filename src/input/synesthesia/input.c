#include"synesthesia.h"

// time : O(1)
// space: O(1)
char	record_rgba_alphabet(t_synesthesia *dst, char *o_ffffff00, size_t ith_row, size_t jth_col)
{
	char	err;
	char	rgb;

	err = 'K';
	if (f_strlen(o_ffffff00) != 8)
		return ('E');
	rgb = (unsigned char)f_atoi(o_ffffff00 + 0, &err, "0123456789abcdef", 2);
	if (err == 'K')
		dst->r[ith_row][jth_col] = rgb;
	rgb = (unsigned char)f_atoi(o_ffffff00 + 2, &err, "0123456789abcdef", 2);
	if (err == 'K')
		dst->g[ith_row][jth_col] = rgb;
	rgb = (unsigned char)f_atoi(o_ffffff00 + 4, &err, "0123456789abcdef", 2);
	if (err == 'K')
		dst->b[ith_row][jth_col] = rgb;
	rgb = (unsigned char)f_atoi(o_ffffff00 + 6, &err, "0123456789abcdef", 2);
	if (err == 'K')
		dst->a[ith_row][jth_col] = rgb;
	return (err);
}

// time : O(n)
// space: O(n)
char	record_o_ffffff00(t_synesthesia *dst, char *o_ffffff00)
{
	char	**split;
	size_t	split_len;
	size_t	ith_row;
	size_t	jth_col;
	char	err;

	if (o_ffffff00 == NULL)
		return ('C');
	split_len = f_split_len(o_ffffff00, " \t\n\r\f\v");
	if (split_len < 2)
		return ('1');
	split = f_split(o_ffffff00, " \t\n\r\f\v");
	if (split == NULL)
		return ('S');
	ith_row = knight_of_coin(dst->alphabet, split[0][0]);
	if (ith_row == knight_of_coin(dst->alphabet, '\0'))
	{
		free_2d_arr((void **)split, split_len);
		return ('2');
	}
	err = 'K';
	jth_col = 0;
	while (jth_col < 4 && jth_col < split_len - 1 && err == 'K')
	{
		err = record_rgba_alphabet(dst, split[jth_col + 1], ith_row, jth_col);
		jth_col += 1;
	}
	free_2d_arr((void **)split, split_len);
	return (err);
}

// time : O(n)
// space: O(n)
void	line_to_synesthesia(char *line, char *dict, t_synesthesia *dst, size_t *ith_char)
{
	char	*o_ffffff00;
	char	alphabet;

	while (f_isspace(*line, " \t\n\r\f\v") == 1)
		line += 1;
	if ('A' <= *line && *line <= 'Z')
		*line += 'a' - 'A';
	if (knight_of_coin(line, '#') >= 10 && f_isspace(*line, dict) == 1 && *line != '#')
	{
		o_ffffff00 = ace_of_coin(line, knight_of_coin(line, '#'), 0);
		alphabet = '0';
		if (o_ffffff00 != NULL)
			alphabet = *o_ffffff00;
		synesthesia_warning(record_o_ffffff00(dst, o_ffffff00), alphabet);
		free(o_ffffff00);
		*ith_char += 1;
		replace_char(dict, *line, '#');
	}
	else
		synesthesia_warning_02(line, dict);
}

/*
Note: I cannot modify constant string, so I have to use malloc, and free,
to copy the constant string instead if I want to modify that string.

Reference
*	https://stackoverflow.com/questions/21387972/bad-permissions-for-mapped-region
*/

// time : O(n)
// space: O(n)
t_synesthesia	file_to_synesthesia(int fd)
{
	t_synesthesia	dst;
	char			*line;
	char			*dict;
	size_t			i;

	dst = init_default_synesthesia();
	if (fd < 0 || dst.alphabet == NULL || dst.r == NULL || dst.g == NULL || dst.b == NULL || dst.a == NULL)
		return (free_synesthesia(dst));
	dict = ace_of_coin("0123456789abcdefghijklmnopqrstuvwxyz&@$%+-=.,!?()/", 51, 0);
	if (dict == NULL)
		return (free_synesthesia(dst));
	i = 0;
	line = get_next_line(fd, 0);
	while (line != NULL && i < 50)
	{
		line_to_synesthesia(line, dict, &dst, &i);
		free(line);
		line = get_next_line(fd, 0);
	}
	get_next_line(fd, 1);
	free(dict);
	return (dst);
}
