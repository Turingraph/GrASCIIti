#include"table.h"

// time : O(n)
// space: O(n)
void	write_table_ascii_cheche01(int fd, const t_table_fdf *src, e_5cell_channels channel)
{
	char	*dict;
	
	dict = " `'.,:_-;~!^\"/|(rvcil+xustf<=[*?{17L"
		"TC23%Yoyhk4$5IF&XUGSEwampbgPAKO680DQRHNB#WM@";
	write_table_ascii(fd, src, channel, dict);
	
}

// time : O(n)
// space: O(n)
void	write_table_ascii_standard(int fd, const t_table_fdf *src, e_5cell_channels channel)
{
	char	*dict;
	
	dict = " .'`^\",:;Il!i<~+_-?[{1(|/tfrxuvcs="
		"7T23y45FXYUCLQ0OmwpbkhaoGSEgPA*#MW&8%K6DRHNB@$";
	write_table_ascii(fd, src, channel, dict);
}

// time : O(n)
// space: O(n)
void	write_table_ascii_chungaloider(int fd, const t_table_fdf *src, e_5cell_channels channel)
{
	char	*dict;
	
	dict = " `.-~'\":_,^=;<+!rc*/?sLTv(7|FiC{fI3"
		"1tluo5Yxya[2ESwkP6h4pOGbUAKXHm8RD#$Bg0MNWQ%&@";
	write_table_ascii(fd, src, channel, dict);
}