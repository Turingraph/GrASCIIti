#ifndef RASTER_H
# define RASTER_H

# include "../../utils/green_counts/green_counts.h"
# include "../../utils/libft/libft.h"
#include "MLX42.h"

/**
 * a pair of integer (x, y) for representing a 2D point, 2D coordinate,
 * and/or the size of row and column of t_table_fdf.
 */
typedef struct s_2d_int
{
int	x;
int	y;
}	t_2d_int;

/**
 * Line segment between two 2D integer coordinates.
 *
 * p1 and p2 represent the two endpoints of the 2D line segment.
 */
typedef struct s_line
{
t_2d_int	p1;
t_2d_int	p2;
}	t_line;

/**
 * Rectangular boundary containing a sub-area of a larger 2D area.
 *
 * @param all_area the dimensions of the complete area
 * @param sub_area represents the rectangular region currently selected within it.
 */
typedef struct s_boundary
{
t_2d_int	all_area;
t_line		sub_area;
}	t_boundary;

/**
 * 2D circle represented by an integer center and radius.
 */
typedef struct s_circle
{
int	x;
int	y;
int	radius;
}	t_circle;

/**
 * Supported 2D motif and rendering types.
 * 
 * The type determines how the motif geometry or FDF data is interpreted
 * by the raster layer.
 * 
 * ENUM TYPE
 * 
 * - E_RECTANGLE draws rectangular geometry.
 * 
 * - E_CIRCLE draws circular geometry.
 * 
 * - E_LINE draws polygon edges as lines.
 * 
 * - E_PIXEL_ART interprets a t_table_fdf as a grid of rectangular cells,
 * allowing the FDF data to be rendered as pixel art.
 * 
 */
typedef enum e_2d_shape
{
E_RECTANGLE,
E_CIRCLE,
E_LINE,
E_PIXEL_ART
}	e_2d_shape;

/**
 * Describes the rendering properties of a 2D motif or FDF drawing.
 * 
 * color stores the 32-bit drawing color. type determines how the associated
 * geometry or FDF data is rendered. thickness controls the size of the
 * rendered primitive where applicable.
 * 
 * ENUM TYPE of type
 * 
 * - E_LINE uses thickness as line thickness.
 * 
 * - E_CIRCLE uses thickness as the circle radius.
 * 
 * - E_RECTANGLE uses thickness according to the rectangle raster operation.
 * 
 * - E_PIXEL_ART uses the FDF cell geometry to render each cell as a rectangle;
 * its type is converted to E_RECTANGLE internally when individual cells
 * are rasterized.
 * 
 * @param color 32-bit drawing color
 * @param thickness size parameter used by the selected rendering type
 * @param type geometric primitive or rendering mode
 */
typedef struct s_ink32
{
int32_t		color;
size_t		thickness;
e_2d_shape	type;
}	t_ink32;

// color.c

int32_t		f_rgba_to_int32(unsigned char r,
				unsigned char g, unsigned char b, unsigned char a);
void		color_background_mlx(mlx_image_t *dst, int32_t color);
int32_t		get_table_rgba_int32(const t_table_fdf *src, size_t index);

// init.c

int			float_to_2d_int(float src, t_line boundary, char mode);
int			init_swap_bresenham_y(t_line *line, int *delta_x, int *delta_y);
int			init_swap_bresenham_x(t_line *line, int *delta_x, int *delta_y);
t_boundary	init_rectangle_boundary(t_line sub_area, size_t row, size_t col);
t_line		init_first_line(t_line src, t_boundary boundary);

// line.c

void		draw_mlx_straight_line(mlx_image_t *dst, t_line line,
				t_line rectangle_boundary, t_ink32 ink);

// shape.c

void	draw_rectangle_mlx(mlx_image_t *dst, t_line rectangle,
	t_line boundary, int32_t ink);
void		midpoint_circle_mlx(mlx_image_t *dst,
				int32_t color, t_circle point, t_boundary boundary);

// utils.c

bool		is_in_boundary(int x, int y, t_line boundary);
t_line		reverse_line(t_line line);
t_line		get_tiling(t_2d_int tiling_area, size_t i, size_t j);
t_boundary	get_all_area(size_t row, size_t col);

#endif
