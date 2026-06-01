#ifndef PAINT_H
# define PAINT_H

# include "../type/type.h"
# include "../libft/libft.h"
# include <fcntl.h>

typedef struct t_gradient t_gradient;
typedef struct t_paint_func t_paint_func;

/*
direction == 0 => x
direction == 1 => y
direction == 2 => z

r1, g1, b1, a1 = r2, g2, b2, a2 => sharp coloring
*/

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

/*
e_line_log = 0 => scale * (x + shift)
e_line_log = 1 => shift * scale^x
e_line_log = 2 => ???

shift, percent in [0, 1]
*/

struct t_paint_func
{
	double		scale;
	double		shift;
	double		percent;
};

// paint.c
void		paint_gradient_fdf(t_table_fdf *table, t_gradient *gradient, char direction);
void		reset_gradient_fdf(t_table_fdf *table);
void		f_gradient_cpy(t_gradient *src, t_gradient *dst);

#endif
