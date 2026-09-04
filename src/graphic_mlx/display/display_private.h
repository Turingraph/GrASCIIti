/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_private.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 19:02:00 by phsottat          #+#    #+#             */
/*   Updated: 2026/09/04 19:05:47 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_PRIVATE_H
# define DISPLAY_PRIVATE_H

# include "display_type.h"

// bool.c

bool	is_line_in_screen(t_2d_camera camera,
			t_line src);
bool	is_circle_in_screen(t_2d_camera camera,
			t_2d_int src, int radius);
float	get_fdf_point(t_fdf *fdf, t_2d_int ixiy, size_t dim, char next);

// linalg.c



#endif