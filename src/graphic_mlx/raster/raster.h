#ifndef RASTER_H
# define RASTER_H

# include "../../utils/green_counts/green_counts.h"
# include "../../utils/libft/libft.h"
#include "MLX42.h"


typedef struct t_2d_int t_2d_int;

struct t_2d_int
{
	int	x;
	int	y;
};

typedef struct t_line t_line;

struct t_line
{
	t_2d_int	p1;
	t_2d_int	p2;
};

typedef struct t_boundary t_boundary;

struct t_boundary
{
	t_2d_int	all_area;
	t_line		sub_area;
};

typedef struct t_circle t_circle;

struct t_circle
{
	int	x;
	int	y;
	int	radius;
};

typedef struct t_2d_polygon t_2d_polygon;

struct t_2d_polygon
{
	t_complex	*arr;
	size_t		length;
	bool		is_loop;
};

typedef enum e_2d_shape e_2d_shape;

enum e_2d_shape
{
	E_RECTANGLE,
	E_CIRCLE,
	E_LINE,
	E_PIXEL_ART
};

typedef struct t_ink32 t_ink32;

struct t_ink32
{
	int32_t		color;
	size_t		thickness;
	e_2d_shape	type;
};

// circle.c
void		midpoint_circle_mlx(mlx_image_t *dst,
				int32_t color, t_circle point, t_boundary boundary);
void		draw_kusama_mlx(mlx_image_t *dst,
				const t_2d_polygon *polygon, t_ink32 ink, t_line boundary);
void		draw_kusama_tiling_mlx(mlx_image_t *dst,
				const t_2d_polygon *polygon,
				t_ink32 ink, t_2d_int tiling_area);

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

// pixel_art.c
void		draw_pixel_art(mlx_image_t *dst, const t_table_fdf *src);

// polygon.c
void		draw_polygon_mlx(mlx_image_t *dst,
	const t_2d_polygon *polygon, t_ink32 ink, t_line boundary);
void		draw_islamic_tiling_mlx(mlx_image_t *dst,
				const t_2d_polygon *polygon,
				t_ink32 ink, t_2d_int tiling_area);

// rectangle.c
void	draw_rectangle_mlx(mlx_image_t *dst, t_line rectangle,
	t_line boundary, int32_t ink);
void	draw_mondrian_mlx(mlx_image_t *dst,
	const t_2d_polygon *polygon, int32_t ink, t_line boundary);
void		draw_mondrian_tiling_mlx(mlx_image_t *dst,
				const t_2d_polygon *polygon,
				int32_t ink, t_2d_int tiling_area);

// utils.c
bool		is_in_boundary(int x, int y, t_line boundary);
t_line		define_circle_boundary(t_circle point,
				int ix, int iy, char mode);
t_line		reverse_line(t_line line);
t_line		get_tiling(t_2d_int tiling_area, size_t i, size_t j);
t_boundary	get_all_area(size_t row, size_t col);

#endif
