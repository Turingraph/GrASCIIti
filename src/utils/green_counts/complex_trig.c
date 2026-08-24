/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_trig.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 10:15:17 by phsottat          #+#    #+#             */
/*   Updated: 2026/08/24 10:15:27 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "green_counts.h"

// https://en-wikipedia-org.translate.goog/wiki/Euler%27s_formula?
// _x_tr_sl=en&_x_tr_tl=th&_x_tr_hl=th&_x_tr_pto=tc
// time : O(1)
// space: O(1)
t_complex	complex_exp(t_complex a)
{
	t_complex	dst;

	dst.re = f_cos(a.im) * f_exp(a.re);
	dst.im = f_sin(a.im) * f_exp(a.re);
	return (dst);
}

/*
According to Euler formula
*	e^{a + bi} = e^a * (cos(b) + i * sin(b))

According to Trigonometry
*	cos(-x) = cos(x)
*	sin(-x) = -sin(x)

Calculate e^{a - bi}
*	e^{a - bi} = e^a * (cos(-b) + i * sin(-b))
*	e^{a - bi} = e^a * (cos(b) - i * sin(b))

Calculate cos(b)
*	e^{a + bi} + e^{a - bi} = e^a*cos(b) + e^a*sin(b)i + e^a*cos(b) - e^a*sin(b)i
*	e^{a + bi} + e^{a - bi} = e^a*cos(b) + e^a*cos(b)
*	e^{bi} + e^{- bi} = 2 * cos(b)
*	cos(b) = (e^{bi} + e^{- bi}) / 2

Reference
*	https://youtu.be/CjQTWtW_x9o?si=ZnGRHjQ-SNRfhmjt
*	https://www.wolframalpha.com/input?i=cos%28a%2Bbi%29
*/

// time : O(1)
// space: O(1)
t_complex	complex_cos(t_complex a)
{
	t_complex	y;
	t_complex	x1;
	t_complex	x2;
	t_complex	e1;
	t_complex	e2;

	x1.re = -1 * a.im;
	x1.im = a.re;
	e1 = complex_exp(x1);
	x2.re = a.im;
	x2.im = -1 * a.re;
	e2 = complex_exp(x2);
	y.re = (e1.re + e2.re) / 2;
	y.im = (e1.im + e2.im) / 2;
	return (y);
}

// time : O(1)
// space: O(1)
t_complex	complex_sin(t_complex a)
{
	t_complex	y;
	t_complex	x1;
	t_complex	x2;
	t_complex	e1;
	t_complex	e2;

	x1.re = a.im;
	x1.im = -1 * a.re;
	e1 = complex_exp(x1);
	x2.re = -1 * a.im;
	x2.im = a.re;
	e2 = complex_exp(x2);
	y.re = (e1.re - e2.re) / 2;
	y.im = (e1.im - e2.im) / 2;
	return (y);
}
