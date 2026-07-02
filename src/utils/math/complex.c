#include"math.h"

// time : O(1)
// space: O(1)
t_complex	complex_multiplication(t_complex a, t_complex b)
{
	t_complex	dst;

	dst.re = a.re * b.re - a.im * b.im;
	dst.im = a.re * b.im + a.im * b.re;
	return (dst);
}

// time : O(1)
// space: O(1)
t_complex	complex_square(t_complex a)
{
	return (complex_multiplication(a, a));
}

// time : O(1)
// space: O(1)
t_complex	complex_cube(t_complex a)
{
	return (complex_multiplication(a,
		complex_multiplication(a, a)));
}

// https://math.stackexchange.com/questions/3872891/multiplicative-inverse-of-complex-numbers-proof
// time : O(1)
// space: O(1)
t_complex	complex_reciprocal(t_complex a)
{
	t_complex	dst;

	dst.re = 0;
	dst.im = 0;
	if (a.re == 0 && a.im == 0)
		return (dst);
	dst.re = a.re / (a.re * a.re + a.im * a.im);
	dst.im = -1 * a.im / (a.re * a.re + a.im * a.im);
	return (dst);
}

// time : O(1)
// space: O(1)
double	complex_magnitude(t_complex a, char is_square)
{
	float	y;

	y = a.re * a.re + a.im * a.im;
	if (is_square > 0)
		return (y);
	return (newton_method(y, 2, 12));
}
