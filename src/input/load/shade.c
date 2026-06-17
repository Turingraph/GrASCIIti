#include"load.h"

// time : O(n)
// space: O(n)
t_load_fdf		cheche_one_ascii_line(char *line)
{
	return (one_ascii_line(line,
		" `'.,:_-;~!^\"/|(rvcil+xustf<=[*?{17L"
		"TC23%Yoyhk4$5IF&XUGSEwampbgPAKO680DQRHNB#WM@"
	));
}

// time : O(n)
// space: O(n)
t_load_fdf		std_one_ascii_line(char *line)
{
	return (one_ascii_line(line,
		" .'`^\",:;Il!i<~+_-?[{1(|/tfrxuvcs="
		"7T23y45FXYUCLQ0OmwpbkhaoGSEgPA*#MW&8%K6DRHNB@$"
	));
}

// time : O(n)
// space: O(n)
t_load_fdf		chungaloider_one_ascii_line(char *line)
{
	return (one_ascii_line(line,
		" `.-~'\":_,^=;<+!rc*/?sLTv(7|FiC{fI3"
		"1tluo5Yxya[2ESwkP6h4pOGbUAKXHm8RD#$Bg0MNWQ%&@"
	));
}