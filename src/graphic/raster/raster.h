#ifndef RASTER_H
# define RASTER_H

#include "../../editor/line/line.h"
#include "MLX42.h"

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

#endif
