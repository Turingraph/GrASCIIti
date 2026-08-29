/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_type.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 13:58:04 by phsottat          #+#    #+#             */
/*   Updated: 2026/08/29 13:58:06 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOAD_TYPE_H
# define LOAD_TYPE_H

# include <stdlib.h>

typedef enum t_write_style
{
	HEIGHT_ONLY,
	HEIGHT_RGBA,
	HEIGHT_RGB
}	t_write_style;

// input/load/

typedef enum t_load_warning
{
	CORRECT,
	NOT_DECIMAL,
	NOT_HEX,
	EMPTY
}	t_load_warning;

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

#endif
