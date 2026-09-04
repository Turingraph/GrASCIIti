/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   green_counts.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 14:28:15 by phsottat          #+#    #+#             */
/*   Updated: 2026/09/04 17:49:07 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GREEN_COUNTS_H
# define GREEN_COUNTS_H

# include <stdlib.h>
# include "../type/type.h"

typedef struct t_complex
{
	float	re;
	float	im;
}	t_complex;

// as_int.c

float		f_floor(float num);
float		f_round(float num);
float		f_interval(float num, float min, float max);
float		f_max(float a, float b);
float		f_min(float a, float b);

// complex_trig.c

t_complex	complex_exp(t_complex a);
t_complex	complex_sin(t_complex a);
t_complex	complex_cos(t_complex a);

// complex.c

t_complex	complex_multiplication(t_complex a, t_complex b);
t_complex	complex_square(t_complex a);
t_complex	complex_cube(t_complex a);
t_complex	complex_reciprocal(t_complex a);
float		complex_magnitude(t_complex a, char is_square);

// math.c

float		f_pow(float x, size_t a);
float		f_root_finding(float x, size_t a);
float		f_sin(float x);
float		f_cos(float x);

// stats.c

float		f_exp(float x);
float		normal_distribution_function(float std, float means, float x);
float		f_std(const float *vec_v, size_t dim);
float		f_sum(const float *vec_v, size_t dim);

// utils.c

size_t		collatz_max_point(size_t x);
size_t		binary_search_count(size_t min_input, size_t max_input);
float		f_abs(float x);
float		f_max3(float a, float b, float c);

#endif
