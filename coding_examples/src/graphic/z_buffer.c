#include"unistd.h"

int	main(void)
{
	write(1, "This file isn't finished yet.\n", 30);
	return (0);
}

/*
valgrind --leak-check=full ./test/bin/graphic/z_buffer.out test/input/fdf/20-60.fdf
*/
