#include"synesthesia.h"

// time : O(n)
// space: O(1)
void	*free_synesthesia(t_synesthesia *table)
{
	if (table != NULL)
	{
		if (table->alphabet != NULL)
			free(table->alphabet);
		if (table->a != NULL)
			free_nest_arr((void **)table->a, table->row);
		if (table->r != NULL)
			free_nest_arr((void **)table->r, table->row);
		if (table->g != NULL)
			free_nest_arr((void **)table->g, table->row);
		if (table->b != NULL)
			free_nest_arr((void **)table->b, table->row);
		free(table);
	}
	return (NULL);
}

// time : O(n)
// space: O(1)
t_synesthesia	*init_synesthesia(size_t row, size_t col)
{
	t_synesthesia	*dst;

	dst = (t_synesthesia *)malloc_talk(sizeof(t_synesthesia), "table/convert.c\n");
	if (dst == NULL)
		return (NULL);
	dst->row = row;
	dst->col = col;
	dst->alphabet = malloc_talk(sizeof(char) * (row + 1),
		"synesthesia/convert.c/init_synesthesia\n");
	if (dst->alphabet != NULL)
		dst->alphabet[row] = '\0';
	dst->r = init_null_char_arr(row, col);
	dst->g = init_null_char_arr(row, col);
	dst->b = init_null_char_arr(row, col);
	dst->a = init_null_char_arr(row, col);
	if (dst->r == NULL || dst->g == NULL || dst->b == NULL
		|| dst->a == NULL|| dst->alphabet == NULL)
	{
		free_synesthesia(dst);
		return (NULL);
	}
	return (dst);
}

// time : O(1)
// space: O(1)
void	init_default_rgb_synesthesia(t_synesthesia *dst, size_t row)
{
	size_t			j;
	unsigned char	rgb;

	j = 0;
	while (j < 4)
	{
		rgb = 255;
		if (j == 1)
			rgb = 0;
		dst->r[row][j] = rgb;
		dst->g[row][j] = rgb;
		dst->b[row][j] = rgb;
		dst->a[row][j] = 255;
		j += 1;
	}
}

// time : O(1)
// space: O(1)
t_synesthesia	*init_default_synesthesia()
{
	t_synesthesia	*dst;
	size_t				i;
	char				*dict;

	dict = "&@$%+-=.,!?()/";
	dst = init_synesthesia(26 + 10 + 14, 4);
	if (dst == NULL)
		return (NULL);
	i = 0;
	while (i < 26 + 10 + 14)
	{
		if (i < 10)
			dst->alphabet[i] = (char)(i + '0');
		if (10 <= i && i < 26 + 10)
			dst->alphabet[i] = (char)(i + 'a' - 10);
		if (26 + 10 <= i && i < 26 + 10 + 14)
			dst->alphabet[i] = dict[i - 26 - 10];
		init_default_rgb_synesthesia(dst, i);
		i += 1;
	}
	return (dst);
}
