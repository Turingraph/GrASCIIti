#include "../../../src/input/input/input.h"
#include "../../../src/input/table/table.h"
#include "../../../src/editor/paint/paint.h"

int	main(int len, char **str)
{
	t_llist_fdf	*llist;
	t_table_fdf	*table;
	int			fd;
	t_gradient	*rgb;

	if (len < 2)
		return (0);
	fd = open(str[1], 'r');
	if (fd < 0)
		return (0);
	llist = all_lines(str[1], fd, one_fdf_line);
	if (llist == NULL)
		return (0);
	table = llist_to_table_fdf(llist);
	free_llist_fdf(llist);
	if (table == NULL)
		return (0);
	rgb = (t_gradient *)malloc_talk(sizeof(t_gradient), "test/src/paint.c\n");
	if (rgb == NULL)
	{
		free_table_fdf(table);
		return (0);
	}
	rgb->r1 = 255;
	rgb->g1 = 0;
	rgb->b1 = 0;
	rgb->a1 = 255;
	rgb->x1 = 2;
	rgb->r2 = 0;
	rgb->g2 = 0;
	rgb->b2 = 255;
	rgb->a2 = 255;
	rgb->x2 = 5;
	paint_gradient_fdf(table, rgb, 0);
	write_table_fdf(1, table, 1, 3);
	free_table_fdf(table);
	free(rgb);
	return (0);
}

/*
valgrind --leak-check=full ./test/bin/editor/paint.out test/input/fdf/10-2.fdf
*/
