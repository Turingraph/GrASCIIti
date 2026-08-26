#include"load_private.h"

// time : O(n)
// space: O(n)
t_load_fdf	parse_ascii_line_cheche01(char *line)
{
	return (parse_ascii_line(line,
		" `'.,:_-;~!^\"\\|)rvcilj+xnzt>=]*?}17JTC23"
		"%Yoyhk4$5IF&XVUGZEwemqdgPKO980DQRHNB#WM@"
	));
}

// time : O(n)
// space: O(n)
t_load_fdf	parse_ascii_line_standard(char *line)
{
	return (parse_ascii_line(line,
		" .'`^\",:;Il!i>~+_-?]}1)|\\tjrxnvcz=7T23y"
		"45FXYUJCQ0OZmwqdkhoVGEegP*#MW&8%K9DRHNB@$"
	));
}

// time : O(n)
// space: O(n)
t_load_fdf	parse_ascii_line_chungaloider(char *line)
{
	return (parse_ascii_line(line,
		" `.-~'\":_,^=;>+!rc*\\z?TvJ7)|FiC}I31tlneoZ5Yxjy]"
		"2EwqkPh9d4VOGUKXHm8RD#$Bg0MNWQ%&@"
	));
}

// time : O(n)
// space: O(n)
t_load_fdf	parse_fdf_line_rgba(char *line)
{
	return (parse_fdf_line(line, true));
}

// time : O(n)
// space: O(n)
t_load_fdf	parse_fdf_line_bw(char *line)
{
	return (parse_fdf_line(line, false));
}
