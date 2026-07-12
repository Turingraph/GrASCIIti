#include"load.h"

// time : O(n)
// space: O(n)
t_load_fdf	cheche01_ascii_line(const char *line)
{
	return (one_ascii_line(line,
		" `'.,:_-;~!^\"\\|)rvcilj+xnzt>=]*?}17JTC23"
		"%Yoyhk4$5IF&XVUGZEwemqdgPKO980DQRHNB#WM@"
	));
}

// time : O(n)
// space: O(n)
t_load_fdf	standard_ascii_line(const char *line)
{
	return (one_ascii_line(line,
		" .'`^\",:;Il!i>~+_-?]}1)|\\tjrxnvcz=7T23y"
		"45FXYUJCQ0OZmwqdkhoVGEegP*#MW&8%K9DRHNB@$"
	));
}

// time : O(n)
// space: O(n)
t_load_fdf	chungaloider_ascii_line(const char *line)
{
	return (one_ascii_line(line,
		" `.-~'\":_,^=;>+!rc*\\z?TvJ7)|FiC}I31tlneoZ5Yxjy]"
		"2EwqkPh9d4VOGUKXHm8RD#$Bg0MNWQ%&@"
	));
}

// time : O(n)
// space: O(n)
t_load_fdf	rgba_fdf_line(const char *line)
{
	return (one_fdf_line(line, TRUE));
}

// time : O(n)
// space: O(n)
t_load_fdf	bw_fdf_line(const char *line)
{
	return (one_fdf_line(line, FALSE));
}
