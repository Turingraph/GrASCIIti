#include"load.h"

// time : O(1)
// space: O(1)
unsigned char	f_rgb(const char *str, size_t len, e_bool *rgb_warn)
{
	int	dst;

	dst = f_atoi(str, rgb_warn, "0123456789abcdef", len);
	if (len == 1)
		dst = 16 * dst + dst;
	if (dst < 0)
		return (0);
	if (dst > 255)
		return (255);
	return ((unsigned char)dst);
}

