/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 13:48:10 by phsottat          #+#    #+#             */
/*   Updated: 2026/08/30 18:49:52 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_H
# define TYPE_H

# include <stdlib.h>
# include <stdbool.h>

typedef enum t_enum_rgba
{
	RED,
	GREEN,
	BLUE,
	ALPHA,
	HEIGHT
}	t_enum_rgba;

// input/table/

typedef struct t_table_fdf
{
	size_t			row;
	size_t			col;
	int				*arr;
	unsigned char	*r;
	unsigned char	*g;
	unsigned char	*b;
	unsigned char	*a;
	bool			is_valid_map;
}	t_table_fdf;

#endif
