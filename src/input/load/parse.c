#include"load_private.h"

/**
 * Parse an ASCII-art line using the Cheche01 character ramp.
 *
 * Time/space: O(n) / O(n)
 *
 * @param line input line
 */
t_load_fdf	parse_ascii_line_cheche01(char *line)
{
	return (parse_ascii_line(line,
			" `'.,:_-;~!^\"\\|)rvcilj+xnzt>=]*?}17JTC23"
			"%Yoyhk4$5IF&XVUGZEwemqdgPKO980DQRHNB#WM@"));
}

/**
 * Parse an ASCII-art line using the standard character ramp.
 *
 * Time/space: O(n) / O(n)
 *
 * @param line input line
 */
t_load_fdf	parse_ascii_line_standard(char *line)
{
	return (parse_ascii_line(line,
			" .'`^\",:;Il!i>~+_-?]}1)|\\tjrxnvcz=7T23y"
			"45FXYUJCQ0OZmwqdkhoVGEegP*#MW&8%K9DRHNB@$"));
}

/**
 * Parse an ASCII-art line using the Chungaloider brightness ramp.
 *
 * Time/space: O(n) / O(n)
 *
 * @param line input line
 * @see https://stackoverflow.com/questions/30097953/
 *      ascii-art-sorting-an-array-of-ascii-characters-by-brightness-levels-c-c
 */
t_load_fdf	parse_ascii_line_chungaloider(char *line)
{
	return (parse_ascii_line(line,
			" `.-~'\":_,^=;>+!rc*\\z?TvJ7)|FiC}I31tlneoZ5Yxjy]"
			"2EwqkPh9d4VOGUKXHm8RD#$Bg0MNWQ%&@"));
}

/**
 * Parse an FDF line as colorful data.
 *
 * Time/space: O(n) / O(n)
 *
 * @param line input line
 */
t_load_fdf	parse_fdf_line_rgba(char *line)
{
	return (parse_fdf_line(line, true));
}

/**
 * Parse an FDF line as black and white data.
 *
 * Time/space: O(n) / O(n)
 *
 * @param line input line
 */
t_load_fdf	parse_fdf_line_bw(char *line)
{
	return (parse_fdf_line(line, false));
}
