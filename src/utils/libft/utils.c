#include "libft.h"

// time : O(n)
// space: O(1)
char	f_strncmp(char *dst, char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && *dst == *src && *dst != '\0')
	{
		i += 1;
		*dst += 1;
		*src += 1;
	}
	return (*dst - *src);
}

/*
// error_mode = 0 : error decimal
// error_mode = 1 : error hexadecimal
// error_mode = 2 : error this is invalid input
// error_mode = 3 : warning decimal
// error_mode = 4 : warning hexadecimal
// error_mode = 5 : warning empty line
// time : O(n)
// space: O(1)
void	non_numerical_file_warning(char *file, size_t i_th_line, char error_mode)
{
	if (error_mode == 0 || error_mode == 1 || error_mode == 2)
		write(1, "Error: line no.", 15);
	else
		write(1, "Warning: line no.", 17);
	ft_putnbr_fd((int) i_th_line, 1, "0123456789", 1);
	write(1, " of ", 4);
	write(1, file, f_strlen(file));
	if (error_mode == 0 || error_mode == 3)
		write(1, " Input file should be decimal number.\n", 38);
	if (error_mode == 1 || error_mode == 4)
		write(1, " Input file should be hexadecimal number.\n", 42);
	if (error_mode == 2)
		write(1, " Input file is invalid, according to synesthesia.txt rule. \
			Write `#` at the beginning of the line to write comment.\n", 119);
	if (error_mode == 5)
		write(1, " Input file is invalid because this line is empty.\n", 51);
}
*/

// time : O(n)
// space: O(1)
char	f_isspace(char s, char *space)
{
	size_t	i;

	i = 0;
	while (*space != '\0')
	{
		if (*space == s)
			return (1);
		space += 1;
		i += 1;
	}
	return (0);
}

// time : O(n)
// space: O(1)
size_t	f_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (*str != '\0')
	{
		i += 1;
		str += 1;
	}
	return (i);
}
