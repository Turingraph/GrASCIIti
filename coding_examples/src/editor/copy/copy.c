#include"copy.h"

int	main(void)
{
	print_copy();
	write(1, "src/editor/copy/ is not finished yet.\n", 39);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./coding_examples/bin/editor/copy/copy.out
*/
