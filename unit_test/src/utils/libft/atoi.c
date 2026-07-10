#include"libft.h"

// time : O(1)
// space: O(1)
e_bool	assert_atoi(const char *strmin, const char *strmax, e_bool *err)
{
	int		min;
	int		max;

	min = f_atoi(strmin, err, "0123456789", f_strlen(strmin));
	max = f_atoi(strmax, err, "0123456789", f_strlen(strmax));
	if (err != NULL && *err == FALSE)
		return (FALSE);
	if (min <= max)
		return (TRUE);
	return (FALSE);
}

/*
// ChapGPT recommended me to write like this.
static const t_atoi_tester	arr[] = {
	{"5890", "5896", TRUE, TRUE},
	{"00820", "8230", TRUE, TRUE},
	{"0118", "jjij", FALSE, FALSE},
	...
};

// Instead of write like this (which is incorrect).
static const t_atoi_tester	arr[];
arr = [
	{"5890", "5896", TRUE, TRUE},
	{"00820", "8230", TRUE, TRUE},
	{"0118", "jjij", FALSE, FALSE},
	...
];

// According to https://stackoverflow.com/questions/18921559/initializing-array-of-structures
// The syntax that ChatGPT recommended me is correct.

// What does `static const` means in C?
// According to https://stackoverflow.com/questions/177437/what-does-const-static-mean-in-c-and-c
// This 2 lines define foo as read-only variable for small space optimization.
const int foo = 42; 
static const int foo = 42;
*/

int	main(void)
{
	size_t						i;
	size_t						score;
	size_t						max_score;
	e_bool						err;
	static const t_atoi_tester	arr[] = {
		{"5890", "5896", TRUE, TRUE},
		{"00820", "8230", TRUE, TRUE},
		{"0118", "jjij", FALSE, FALSE},
		{"jko", "-8509", FALSE, FALSE},
		{"2147483647", "2147483647", TRUE, TRUE},
		{"2147483644", "2147483648", FALSE, FALSE},
		{"557", "5557D", FALSE, FALSE},
		{"3524", "-3522", FALSE, TRUE},
		{"-8111", "-18441", FALSE, TRUE},
		{"0000774", "7764", TRUE, TRUE},
		{"71074", "7764", FALSE, TRUE},
		{"414", "4314", TRUE, TRUE},
		{"0", "0", TRUE, TRUE},
		{"-2819", "-2819", TRUE, TRUE},
		{"-2819", "0", TRUE, TRUE},
		{"0000462", "0004627", TRUE, TRUE}
	};

	max_score = 16;
	i = 0;
	score = 0;
	while (i < max_score)
	{
		err = TRUE;
		if (assert_atoi(arr[i].min_input, arr[i].max_input, &err) == arr[i].is_eq_or_less
			&& arr[i].is_number == err)
			score += 1;
		i += 1;
	}
	write_total_score(score, max_score);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./unit_test/bin/utils/libft/atoi.out
*/