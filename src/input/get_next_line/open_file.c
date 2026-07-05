#include"get_next_line.h"

// options for mode
// 1.	READ
// 2.	APPEND
// time : O(n)
// space: O(n)
int	open_dir_file(const char *file_name, const char *dir, e_file_mode mode)
{
	t_temperance	*file;
	int				dst;

	if (path == NULL || *path == '\0')
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
	three_of_cups(&file, path);
	three_of_cups(&file, file_name);
	if (file == NULL)
		return (1);
	dst = open(file->arr, mode);
	free(file->arr);
	free(file);
	return (dst);
}
