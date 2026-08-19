#ifndef WINDOW_H
# define WINDOW_H

#include"../view/view.h"

typedef struct t_offset_tile t_offset_tile;

struct t_offset_tile
{
	size_t		tile_size;
	t_2d_int	tile_counts;
	t_line		offset;
};

typedef struct t_2d_camera t_2d_camera;

struct t_2d_camera
{
	t_2d_int	offset;
	float		zoom;
};

typedef struct t_hook2d t_hook2d;

struct t_hook2d
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_2d_camera	*camera;
	t_line		*rectangle;
	int32_t		color;
	int32_t		background_color;
};

/*
typedef struct t_hook t_hook;

struct t_hook
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	int32_t 	background_color;
	int32_t 	rectangle_color;
	t_2d_camera	*camera;
	t_line		rectangle;
};
*/

// hook.c
void 			hook_pan_and_zoom(mlx_key_data_t keydata,
					void *param);

// offset.c
t_line			init_offset_tile_area(size_t width, size_t height,
					size_t resolution, size_t max_length);
t_offset_tile	init_offset_tile(size_t width,
					size_t height, size_t resolution);

// tile.c
size_t			init_tile_size(size_t size_length, size_t resolution);
size_t			init_alltiles_count(size_t max_length,
					size_t size_length, size_t resolution);
size_t			init_alltiles_size(size_t max_length,
					size_t size_length, size_t resolution);
size_t			init_alltiles_offset(size_t max_length,
					size_t size_length, size_t resolution);

// view
int				view_rectangle(t_line rectangle,
					int32_t rectangle_color, int32_t background_color);

// zoom.c
int				zoom_object(int start, int stop,
					int target, float zoom);
t_line			pan_zoom_line(t_2d_camera camera, t_line target,
					size_t window_width, size_t window_height);

#endif
