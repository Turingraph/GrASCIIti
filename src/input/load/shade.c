#include"load.h"

// time : O(n)
// space: O(n)
t_load_fdf	cheche01_ascii_line(const char *line)
{
	return (one_ascii_line(line,
		" `'.,:_-;~!^\"/|(rvcil+xustf<=[*?{17L"
		"TC23%Yoyhk4$5IF&XUGSEwampbgPAKO680DQRHNB#WM@"
	));
}

// time : O(n)
// space: O(n)
t_load_fdf	standard_ascii_line(const char *line)
{
	return (one_ascii_line(line,
		" .'`^\",:;Il!i<~+_-?[{1(|/tfrxuvcs="
		"7T23y45FXYUCLQ0OmwpbkhaoGSEgPA*#MW&8%K6DRHNB@$"
	));
}

// time : O(n)
// space: O(n)
t_load_fdf	chungaloider_ascii_line(const char *line)
{
	return (one_ascii_line(line,
		" `.-~'\":_,^=;<+!rc*/?sLTv(7|FiC{fI3"
		"1tluo5Yxya[2ESwkP6h4pOGbUAKXHm8RD#$Bg0MNWQ%&@"
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
