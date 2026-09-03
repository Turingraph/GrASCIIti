/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convolve.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 16:16:00 by phsottat          #+#    #+#             */
/*   Updated: 2026/08/30 14:30:05 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVOLVE_H
# define CONVOLVE_H

# include "../../input/table/table.h"
# include "../../utils/linalg/linalg.h"

// convolve_height.c

t_table_fdf	convolve_fdf(const t_table_fdf *src, float *kernel,
				size_t dim);

// kernel.c

float		*gaussian_kernel_1d(size_t half_dim, float std);
float		*gaussian_kernel(size_t half_dim, float std_1, float std_2);

#endif
