#include"triangle_arr.h"

int	main(int len, char **str)
{
	t_triangle_arr	output;
	t_table_fdf		table;

	if (len < 2)
		return (0);
	table = open_table_fdf_file(str[1], NULL, parse_ascii_line_cheche01, false);
	output = table_to_prism((const t_table_fdf *)&table, 30, true, PRISM_CROSS);
	update_width_of_triangle_arr(&output, 0);
	update_width_of_triangle_arr(&output, 1);
	update_width_of_triangle_arr(&output, 2);
	center_triangle_arr(&output, 0);
	free_table_fdf(&table);
	write(1, "*** output.arr ***\n", 20);
	write_triangle_arr(1, (const t_triangle_arr *)&output);
	write(1, "*** meta data ***\n", 19);
	write_triangle_arr_meta(1, (const t_triangle_arr *)&output);
	free_triangle_arr(&output, 0);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./coding_examples/out/graphic/triangle_arr/ascii_prism.out input_examples/line/islamic_gauss.txt
(113, 238, -31),(114, 238, -31),(114, 237, -33),0x00000000
(114, 238, -31),(114, 237, -33),(115, 237, -31),0x00000000
(114, 238, -31),(115, 238, -31),(115, 237, -31),0x00000000
(115, 238, -31),(115, 237, -31),(116, 237, -31),0x00000000
(115, 238, -31),(116, 238, -31),(116, 237, -31),0x00000000
(116, 238, -31),(116, 237, -31),(117, 237, -31),0x00000000
(116, 238, -31),(117, 238, -31),(117, 237, -31),0x00000000
(117, 237, -31),(118, 237, 000),(118, 238, -31),0x00000000
(-119, 239, -31),(-119, 238, -31),(-118, 238, -31),0x00000000
(-119, 239, -31),(-118, 239, -31),(-118, 238, -31),0x00000000
*** meta data ***
src->length = 177290
src->capacity = 177290
src->width_x = 239
src->width_y = 239
src->width_z = 218
==1750535== 
==1750535== HEAP SUMMARY:
==1750535==     in use at exit: 0 bytes in 0 blocks
==1750535==   total heap usage: 760,062 allocs, 760,062 frees, 50,330,410 bytes allocated
==1750535== 
==1750535== All heap blocks were freed -- no leaks are possible
==1750535== 
==1750535== For lists of detected and suppressed errors, rerun with: -s
==1750535== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
*/