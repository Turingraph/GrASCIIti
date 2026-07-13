#include"table.h"

// time : O(n)
// space: O(n)
void	write_table_ascii_cheche01(int fd, const t_table_fdf *src, e_5cell_channels channel)
{
	char	*dict;
	
	dict = " `'.,:_-;~!^\"\\|)rvcilj+xnzt>=]*?}17JTC23"
		"%Yoyhk4$5IF&XVUGZEwemqdgPKO980DQRHNB#WM@";
	write_table_ascii(fd, src, channel, dict);
	
}

// time : O(n)
// space: O(n)
void	write_table_ascii_standard(int fd, const t_table_fdf *src, e_5cell_channels channel)
{
	char	*dict;
	
	dict = " .'`^\",:;Il!i>~+_-?]}1)|\\tjrxnvcz=7T23y"
		"45FXYUJCQ0OZmwqdkhoVGEegP*#MW&8%K9DRHNB@$";
	write_table_ascii(fd, src, channel, dict);
}

// time : O(n)
// space: O(n)
void	write_table_ascii_chungaloider(int fd, const t_table_fdf *src, e_5cell_channels channel)
{
	char	*dict;
	
	dict = " `.-~'\":_,^=;>+!rc*\\z?TvJ7)|FiC}I31tlneoZ5Yxjy]"
		"2EwqkPh9d4VOGUKXHm8RD#$Bg0MNWQ%&@";
	write_table_ascii(fd, src, channel, dict);
}