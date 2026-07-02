#include"libft_tester.h"

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
	char					**strarr_dst;
	size_t					length_dst;
	size_t					i;
	size_t					score;
	size_t					max_score;
	static const t_split_tester	arr[] = {
		{"", "", 1, (const char *[]){NULL}},
		{"", "zero", 1, (const char *[]){NULL}},
		{"additive_identity", "", 1, (const char *[]){"additive_identity", NULL}},
		{"Nujabes", "ja", 2, (const char *[]){"Nu", "bes", NULL}},
		{"Tally Hall", " ", 2, (const char *[]){"Tally", "Hall", NULL}},
		{"Radiohead", "Dio", 2 (const char *[]){"Rad", "head", NULL}},
		{"zutomayorushika", "yoASOBi", 4, (const char *[]){"zut", "ma", "rush", "ka", NULL}},
		{"atatcgctagccta", "atc", 2, (const char *[]){"g", "g", NULL}},
		{"atatcgctagccta", "atcg", 0, (const char *[]){NULL}},
		{"ATATCGCTAGCCTA", "atcg", 1, (const char *[]){"ATATCGCTAGCCTA", NULL}},
		{"atatcgctagccta", "tcg", 3, (const char *[]){"a", "a", "a", NULL}},
		{" \t\n\t\n\n  \n   \t\t ", "\n", 4, (const char *[]){" \t", "\t", "  ", "   \t\t ", NULL}}
	};

	max_score = 12;
	i = 0;
	score = 0;
	while (i < max_score)
	{
		length_dst = f_split_len(arr[i].input_str, arr[i].input_space);
		strarr_dst = f_split(arr[i].input_str, arr[i].input_space);
		if (length_of_strarr(strarr_dst) == length_dst
			&& length_dst == arr[i].expected_length
			&& assert_strarr(arr[i].expected_output,
				strarr_dst, length_dst, TRUE) == TRUE)
			score += 1;
		free_2d_arr((void**)strarr_dst, length_dst);
		i += 1;
	}
	write_total_score(score, max_score);
	return (0);
}

