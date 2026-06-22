#ifndef PAINT_H
# define PAINT_H

# include "../../utils/type/type.h"
# include "../../utils/libft/libft.h"
# include "../../utils/math/math.h"
# include <fcntl.h>

/*
direction == 0 => x
direction == 1 => y
direction == 2 => z

r1, g1, b1, a1 = r2, g2, b2, a2 => sharp coloring
*/

typedef struct t_gradient t_gradient;

struct t_gradient
{
	unsigned char	r1;
	unsigned char	g1;
	unsigned char	b1;
	unsigned char	a1;
	unsigned char	r2;
	unsigned char	g2;
	unsigned char	b2;
	unsigned char	a2;
	int				x1;
	int				x2;
};

// paint.c
void		paint_gradient_fdf(t_table_fdf *table, t_gradient rgb, char dim);
void		reset_gradient_fdf(t_table_fdf *table);

// set_color.c
e_bool	collatz_coloring(size_t row, size_t col, t_table_fdf *dst);
e_bool	is_colored_cell(size_t row, size_t col, t_table_fdf *dst);
e_bool	gaussian_prime(size_t row, size_t col, t_table_fdf *dst);
e_bool	imaginary_square(size_t row, size_t col, t_table_fdf *dst);
void	set_color_every_cells(
	t_table_fdf *dst,
	e_rgba rgb_type,
	unsigned char new_rgb,
	e_bool(*is_color_target)(size_t row, size_t col, t_table_fdf *dst));

#endif
