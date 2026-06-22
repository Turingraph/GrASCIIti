#include"math.h"

// https://www.geeksforgeeks.org/dsa/
// sieve-of-eratosthenes/#sieve-of-eratosthenes-onloglogn-time-and-on-space
// time : O(n log(log(n)))
// space: O(1)
char	*sieve_of_eratosthenes(size_t num, char *sieve)
{
	size_t	y;
	size_t	sun;

	sieve[0] = '1';
	sieve[1] = '1';
	y = 2;
	while (y * y < num)
	{
		if (sieve[y] == '0')
		{
			sun = 2 * y;
			while (sun < num)
			{
				sieve[sun] = '1';
				sun += y;
			}
		}
		y += 1;
	}
	return (sieve);
}

// time : O(n log(log(n)))
// space: O(n)
size_t	next_prism(size_t num)
{
	char	*sieve;
	size_t	y;
	size_t	i;

	if (num == 0 || num == 1)
		return (2);
	sieve = (char *)malloc(sizeof(char) * (2 * num + 1));
	if (sieve == NULL)
		return (0);
	i = 0;
	while (i < 2 * num)
	{
		sieve[i] = '0';
		i += 1;
	}
	sieve[i] = '\0';
	sieve_of_eratosthenes(2 * num, sieve);
	y = num;
	while (sieve[y] == '1')
		y += 1;
	free(sieve);
	return (y);
}

// time : O(n log(log(n)))
// space: O(n)
char	is_prime(size_t num)
{
	char	*sieve;
	char	y;
	size_t	i;

	sieve = (char *)malloc(sizeof(char) * (2 * num + 1));
	if (sieve == NULL)
		return (0);
	i = 0;
	while (i < 2 * num)
	{
		sieve[i] = '0';
		i += 1;
	}
	sieve[i] = '\0';
	sieve_of_eratosthenes(2 * num, sieve);
	y = sieve[i];
	free(sieve);
	if (y == '1')
		return (1);
	return (0);
}
