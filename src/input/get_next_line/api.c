#include"get_next_line_private.h"

// options for mode
// 1.	READ
// 2.	APPEND
// time : O(n)
// space: O(n)
int	open_dir_file(const char *file_name, const char *dir, e_file_mode mode)
{
	t_temperance	*file;
	int				dst;

	if (dir == NULL || *dir == '\0')
	{
		dst = open(file_name, mode);
		if (dst < 1)
			return (1);
		return (dst);
	}
	file = NULL;
	ace_of_cup(1, &file);
	if (file == NULL)
		return (1);
	three_of_cups(&file, dir);
	three_of_cups(&file, file_name);
	if (file == NULL)
		return (1);
	dst = open(file->arr, mode);
	free(file->arr);
	free(file);
	return (dst);
}

// time : O(n)
// space: O(n)
char	*get_next_line(int fd, e_dream anchor)
{
	static char		*coin = NULL;
	static e_dream	ambition = CONTINUE;
	t_temperance	*angel;
	char			*knight;
	size_t			length;

	angel = NULL;
	if (king_gnu(&coin, &ambition, anchor, &angel) == STOP_GNL)
		return (NULL);
	if (the_chariot(fd, &ambition, &angel) == STOP_GNL)
		return (NULL);
	length = knight_of_coin(angel->arr, '\n');
	if (angel->arr[length] == '\n')
		length += 1;
	knight = ace_of_coin(angel->arr, length, 0);
	coin = ace_of_coin(angel->arr + length,
		knight_of_coin(angel->arr + length, '\0'), 0);
	free(angel->arr);
	free(angel);
	return (knight);
}
