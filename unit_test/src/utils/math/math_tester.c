#include "math_tester.h"

// time : O(n)
// space: O(1)
double	test_sqrt(double x, size_t accuracy)
{
	return (newton_method(x, 2, accuracy));
}

// time : O(n)
// space: O(1)
double	test_cubrt(double x, size_t accuracy)
{
	return (newton_method(x, 3, accuracy));
}

// time : O(n)
// space: O(1)
double	test_cube12(double x, size_t accuracy)
{
	return (f_pow(x, 3) + (double)accuracy);
}

// time : O(n)
// space: O(1)
double	test_normal(double x, size_t accuracy)
{
	return (normal_distribution_function(1, 2, x) * accuracy);
}

// time : O(n)
// space: O(1)
e_bool	math_tester(size_t max_score, const double **arr,
	double (*math_func)(double x, size_t accuracy))
{
	size_t	i;
	size_t	score;
	double	err;

	i = 0;
	while (i < max_score)
	{
		err = math_func(arr[i][0], 12) - arr[i][1];
		if (err < 0.001 && err > -0.001)
			score += 1;
		i += 1;
	}
	write_total_score(score, max_score);
	if (score == max_score)
		return (TRUE);
	return (FALSE);
}

int	main(void)
{
	size_t	score;
	size_t	max_score = 6;
	double	*arr_sin_tester[] = {
		{112  , -0.8899},
		{23   , -0.8462},
		{0.665, 0.61705},
		{6.650, 0.35864}
	};
	double	*arr_cos_tester[] = {
		{112  , 0.4559},
		{23   ,-0.5328},
		{0.665, 0.7869},
		{6.650, 0.9334}
	};
	double	*arr_sqrt_tester[] = {
		{112  , 10.5830},
		{23   , 4.79583},
		{0.665, 0.81547},
		{6.650, 2.57875}
	};
	double	*arr_cubrt_tester[] = {
		{112  , 4.82028},
		{23   , 2.84386},
		{0.665, 0.87285},
		{6.650, 1.88050}
	};
	double	*arr_cube12_tester[] = {
		{112  , 1404940.0},
		{23   , 12179.0},
		{0.665, 12.2940},
		{6.650, 306.079}
	};
	double	*arr_normal_tester[] = {
		{1.12  , 3.25036},
		{2.3   , 4.57665},
		{0.665 , 1.96374},
		{6.650 , 0}
	};
	double	*arr_exp_tester[] = {
		{1.12  , 3.06485},
		{2.3   , 9.97418},
		{0.665 , 1.94449},
		{6.650 , 772.784}
	};

	score = 0;
	if (math_tester(4, arr_sin_tester, f_sin) == TRUE)
		score += 1;
	if (math_tester(4, arr_cos_tester, f_cos) == TRUE)
		score += 1;
	if (math_tester(4, arr_exp_tester, f_exp) == TRUE)
		score += 1;
	if (math_tester(4, arr_cubrt_tester, test_cubrt) == TRUE)
		score += 1;
	if (math_tester(4, arr_cube12_tester, test_cube12) == TRUE)
		score += 1;
	if (math_tester(4, arr_normal_tester, test_normal) == TRUE)
		score += 1;
	if (score == 7)
		write(1, "The utils/math/ module works correctly.\n", 41);
	else
		write(1, "The utils/math/ module have issue.\n", 36);
}
