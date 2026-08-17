#ifndef VIEW_LINE_H
# define VIEW_LINE_H

#include "../../editor/line/line.h"
#include "MLX42.h"

typedef enum e_2d_shape e_2d_shape;

enum e_2d_shape
{
	E_RECTANGLE,
	E_CIRCLE,
	E_LINE
};

typedef struct t_ink32 t_ink32;

struct t_ink32
{
	int32_t		color;
	size_t		thickness;
	e_2d_shape	type;
};

typedef struct t_islamic_art t_islamic_art;

struct t_islamic_art
{
	t_2d_polygon	polygon;
	t_ink32			ink;
	t_2d_int		tiling;
};

typedef struct t_islamic_arr t_islamic_arr;

struct t_islamic_arr
{
	const t_islamic_art	*arr;
	size_t				length;
};

// circle.c
void	midpoint_circle_mlx(mlx_image_t *dst,
			int32_t color, t_circle point, t_boundary boundary);
void	draw_kusama_tiling_fmlx(mlx_image_t *dst, const t_2d_polygon *polygon,
			t_ink32 ink, t_2d_int tiling_area);

// line.c
void	draw_mlx_straight_line(mlx_image_t *dst, t_line line,
			t_line rectangle_boundary, t_ink32 ink);

// polygon.c
void	draw_polygon_mlx(mlx_image_t *dst, const t_2d_polygon *polygon,
			t_ink32 ink, t_line rectangle_boundary);
void	draw_square_tiling_mlx(mlx_image_t *dst, const t_2d_polygon *polygon,
			t_ink32 ink, t_2d_int tiling_area);
void	draw_kusama_circle_mlx(mlx_image_t *dst, t_circle circle,
			t_ink32 ink, t_2d_int tiling_area);

// rectangle.c
void	draw_rectangle_mlx(mlx_image_t *dst, t_line rectangle,
			t_line boundary, int32_t ink);
void	draw_mondrian_tiling_mlx(mlx_image_t *dst, t_line rectangle,
			int32_t ink, t_2d_int tiling_area);
void	draw_mondrian_tiling_fmlx(mlx_image_t *dst, const t_2d_polygon *polygon,
			int32_t ink, t_2d_int tiling_area);

// view.c
int32_t	f_rgba_to_int32(unsigned char r,
			unsigned char g, unsigned char b, unsigned char a);
void	color_background_mlx(mlx_image_t *img, int32_t color);
int		view_islamic_tiling(const t_islamic_arr *src, int32_t background_color);

#endif
