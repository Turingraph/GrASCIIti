#include"unistd.h"

int	main(void)
{
	write(1, "This file isn't finished yet.\n", 30);
	return (0);
}

/*
valgrind --leak-check=full ./test/bin/graphic/rasterization.out
*/
