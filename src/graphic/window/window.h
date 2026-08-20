#ifndef WINDOW_H
# define WINDOW_H

#include"../view/view.h"

typedef struct t_tile_format t_tile_format;

struct t_tile_format
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
	mlx_t			*mlx;
	mlx_image_t		*img;
	t_2d_camera		*camera;
	int32_t			background;
	t_tile_format	tiles;
	t_ink32			ink;
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

// get_interier_tiles.c
t_2d_int		get_interier_tiles_p1(t_tile_format tiles,
					t_2d_camera camera, size_t window_width,
					size_t window_height);
t_2d_int		get_interier_tiles_p2(t_tile_format tiles,
					t_2d_camera camera, size_t window_width,
					size_t window_height);

// hook.c
void	picture_at_an_exhibition(t_hook2d *arg);
void 			hook_pan_and_zoom(mlx_key_data_t keydata,
					void *param);

// offset.c
t_line			init_offset_tile_area(size_t width, size_t height,
	size_t resolution, size_t fixed_length);
t_tile_format	init_tile_format(size_t width,
	size_t height, size_t resolution);

// tile.c
size_t	init_tile_size(size_t side_length, size_t resolution);
size_t	init_alltiles_count(size_t side_length,
	size_t resolution, size_t fixed_length);
size_t	init_alltiles_size(size_t side_length,
	size_t resolution, size_t fixed_length);
int	init_alltiles_offset(size_t side_length,
	size_t resolution, size_t fixed_length);

// utils.c
bool			is_2dhook_valid(const t_hook2d *src);
bool			is_valid_key(mlx_key_data_t keydata);
void			write_line(t_line src);

// view
int	view_rectangle(size_t resolution, t_ink32 ink, int32_t background);

// zoom.c
int				zoom_object(int start, int stop,
					int target, float zoom);
t_line			pan_zoom_line(t_2d_camera camera, t_line target,
					size_t window_width, size_t window_height);

#endif
