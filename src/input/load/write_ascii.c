#include"load_private.h"

// time : O(n)
// space: O(n)
void	write_load_ascii_arr_cheche01(int fd, const t_load_fdf_arr *src)
{
	write_load_ascii_arr(fd, src,
		" `'.,:_-;~!^\"\\|)rvcilj+xnzt>=]*?}17JTC23"
		"%Yoyhk4$5IF&XVUGZEwemqdgPKO980DQRHNB#WM@"
	);
}

// time : O(n)
// space: O(n)
void	write_load_ascii_arr_standard(int fd, const t_load_fdf_arr *src)
{
	write_load_ascii_arr(fd, src,
		" .'`^\",:;Il!i>~+_-?]}1)|\\tjrxnvcz=7T23y"
		"45FXYUJCQ0OZmwqdkhoVGEegP*#MW&8%K9DRHNB@$"
	);
}

// time : O(n)
// space: O(n)
void	write_load_ascii_arr_chungaloider(int fd, const t_load_fdf_arr *src)
{
	write_load_ascii_arr(fd, src,
		" `.-~'\":_,^=;>+!rc*\\z?TvJ7)|FiC}I31tlneoZ5Yxjy]"
		"2EwqkPh9d4VOGUKXHm8RD#$Bg0MNWQ%&@"
	);
}