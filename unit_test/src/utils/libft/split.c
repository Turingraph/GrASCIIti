#include"libft.h"

/*
// ChatGPT also recommended me to use Compound literals feature of C.

// According to https://www.geeksforgeeks.org/c/compound-literals-c/,
// Compound literals feature allows us to create unnamed objects 
// with given list of initialized values. In the above example, 
// an array is created without any name. 
// Address of first element of array is assigned to pointer p, as shown in this example.

#include <stdio.h>
int main()
{
	int *p = (int []){2, 4, 6};
	printf("%d %d %d", p[0], p[1], p[2]);
	return 0;
}

// This feature is useful when I have to
// define the array of struct that have array of string, given that
// {"Nu", "bes", NULL} is unnamed array of string.

static const t_split_tester	arr[] = {
	{"Nujabes", "ja", 2, (const char *[]){"Nu", "bes", NULL}},
	...
}

*/

int	main(void)
{
	char			**strarr_dst;
	size_t			length_dst;
	size_t			i;
	size_t			score;
	size_t			max_score;
	t_split_tester	arr[] = {
		{(const char *)"", (const char *)"", 0, (const char *[]){NULL}},
		{(const char *)"", (const char *)"zero", 0, (const char *[]){NULL}},
		{(const char *)"additive_identity", (const char *)"", 1, (const char *[]){"additive_identity", NULL}},
		{(const char *)"Nujabes", (const char *)"ja", 2, (const char *[]){"Nu", "bes", NULL}},
		{(const char *)"Tally Hall", (const char *)" ", 2, (const char *[]){"Tally", "Hall", NULL}},
		{(const char *)"Radiohead", (const char *)"Dio", 2, (const char *[]){"Rad", "head", NULL}},
		{(const char *)"zutomayorushika", (const char *)"yoASOBi", 4, (const char *[]){"zut", "ma", "rush", "ka", NULL}},
		{(const char *)"atatcgctagccta", (const char *)"atc", 2, (const char *[]){"g", "g", NULL}},
		{(const char *)"atatcgctagccta", (const char *)"atcg", 0, (const char *[]){NULL}},
		{(const char *)"ATATCGCTAGCCTA", (const char *)"atcg", 1, (const char *[]){"ATATCGCTAGCCTA", NULL}},
		{(const char *)"atatcgctagccta", (const char *)"tcg", 4, (const char *[]){"a", "a", "a", "a", NULL}},
		{(const char *)" \t\n\t\n\n  \n   \t\t ", (const char *)"\n", 4, (const char *[]){" \t", "\t", "  ", "   \t\t ", NULL}}
	};

	max_score = 12;
	i = 0;
	score = 0;
	while (i < max_score)
	{
		length_dst = f_split_len((const char *)arr[i].input_str, (const char *)arr[i].input_space);
		strarr_dst = f_split((const char *)arr[i].input_str, (const char *)arr[i].input_space);
		if (length_of_strarr((const char **)strarr_dst) == length_dst
			&& length_dst == arr[i].expected_length
			&& (assert_strarr((const char **)arr[i].expected_output,
				(const char **)strarr_dst, length_dst, TRUE) == TRUE || arr[i].expected_output[0] == (const char *)strarr_dst))
			score += 1;
		free_2d_arr((void**)strarr_dst, length_dst);
		i += 1;
	}
	write_total_score(score, max_score);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./unit_test/bin/utils/libft/split.out
*/