/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 10:04:46 by phsottat          #+#    #+#             */
/*   Updated: 2026/08/24 19:17:26 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_H
# define TYPE_H

# include <stdlib.h>
# include <stdbool.h>

typedef enum e_rgba
{
	RED,
	GREEN,
	BLUE,
	ALPHA,
	HEIGHT
}	t_ergba;

typedef enum e_write_style
{
	HEIGHT_ONLY,
	HEIGHT_RGBA,
	HEIGHT_RGB
}	t_write_style;

// input/load/

typedef enum e_load_warning
{
	CORRECT,
	NOT_DECIMAL,
	NOT_HEX,
	EMPTY
}	t_load_warning;

// input/load/

typedef struct t_load_fdf
{
	int				*arr;
	unsigned char	*r;
	unsigned char	*g;
	unsigned char	*b;
	unsigned char	*a;
	size_t			length;
	t_load_warning	int_warn;
	t_load_warning	rgb_warn;
}	t_load_fdf;

typedef struct t_load_fdf_arr
{
	t_load_fdf	*arr;
	size_t		length;
	size_t		capacity;
}	t_load_fdf_arr;

typedef enum e_sampling_rgba
{
	SAMPLE_TOP_LEFT,
	SAMPLE_AVERAGE,
	SAMPLE_EDGE_AVERAGE
}	t_sampling_rgba;

// input/table/

typedef struct t_table_fdf
{
	size_t			row;
	size_t			col;
	size_t			origin_x;
	size_t			origin_y;
	t_sampling_rgba	color_sampling;
	float			zoom;
	int				*arr;
	unsigned char	*r;
	unsigned char	*g;
	unsigned char	*b;
	unsigned char	*a;
}	t_table_fdf;

// editor/paint/

typedef struct t_rgba
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	unsigned char	a;
}	t_rgba;

// utils/green_counts/

typedef struct t_complex
{
	double	re;
	double	im;
}	t_complex;

#endif

/*
To Do List
1.	Make enum and struct compatible with norm
2.	replace graphic/fdf/ with additional files in graphic/window
	and utils/linalg and code Makefile accordingly.
3.	fix rotating hook
4.	write the main.c
5.	write README.md

To Do List After Finish
1.	Remove useless function except the graphic/triangle/ module
2.	Imprimenting prism features
3.	replace MLX42 with actual OpenGL
4.	user Documentation
5.	Some GPU optimization
6.	Makefile for each module.
*/