#ifndef PAINT_H
# define PAINT_H

# include "input.h"
# include "libft.h"
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
	int				int_1st;
	int				int_2nd;
	char			direction;
};

/*
e_line_log = 0 => ???
e_line_log = 1 => scale * x + constant
e_line_log = 2 => constant * scale^x
*/

struct t_paint_func
{
	char		e_line_log;
	double		scale;
	double		constant;
	double		percent;
	t_gradient	*color;
};

// copy.c
t_table_fdf	*expand_table_fdf(size_t scale, t_table_fdf *src);

// high.c
t_table_fdf	*positive_table_fdf(t_table_fdf *table);
t_table_fdf	*high_table_fdf(t_table_fdf *table, size_t scale);

// kernel.c
double		**blur_kernel(size_t col, size_t row, double scale);
double		**gaussian_kernel(size_t col, size_t row);
t_table_fdf	*paint_kernel(t_table_fdf *src, size_t col, size_t row, double **table);

// paint.c
t_table_fdf	*paint_gradient(t_table_fdf *src, t_gradient *gradient);

// safe.c
void		save_table_fdf(char *target_file, t_table_fdf *src);
void		save_table_ascii(char *target_file, t_table_fdf *src);

/*
Easiest to Hardest
1.	copy.c
2.	save.c
3.	high.c
4.	paint.c
5.	kernel.c
*/

#endif
