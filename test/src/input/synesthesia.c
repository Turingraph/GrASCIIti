#include"../../../src/input/synesthesia/synesthesia.h"

int	main(int len, char **str)
{
	int				fd;
	t_synesthesia	synesthesia;

	if (len < 2)
		return (0);
	fd = open(str[1], 'r');
	if (fd < 0)
		return (0);
	synesthesia = file_to_synesthesia(fd);
	write_synesthesia(1, synesthesia);
	free_synesthesia(&synesthesia);
	return (0);
}

/*
make test/bin/input/synesthesia.out
valgrind --leak-check=full ./test/bin/input/synesthesia.out test/input/synesthesia/my_synesthesia.txt
*/
