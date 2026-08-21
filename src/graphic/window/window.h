#ifndef WINDOW_H
# define WINDOW_H

#include"../view/view.h"

typedef struct t_fline t_fline;

struct t_fline
{
	t_complex	p1;
	t_complex	p2;
};

typedef struct t_tile_format t_tile_format;

struct t_tile_format
{
	float		tile_size;
	t_2d_int	tile_counts;
	t_fline		offset;
};

typedef struct t_2d_camera t_2d_camera;

struct t_2d_camera
{
	t_2d_int	offset;
	t_2d_int	window_size;
	float		zoom;
};

typedef struct t_islamic_art t_islamic_art;

struct t_islamic_art
{
	t_2d_polygon	polygon;
	t_ink32			ink;
};

typedef struct t_islamic_arr t_islamic_arr;

struct t_islamic_arr
{
	t_islamic_art	*arr;
	size_t			length;
};

typedef struct t_master_piece t_master_piece;

struct t_master_piece
{
	int32_t			background;
	t_islamic_arr	*motif;
	t_triangle_arr	*still_life;
	t_tile_format	tiles;
};

typedef struct t_2d_hook t_2d_hook;

struct t_2d_hook
{
	mlx_t			*mlx;
	mlx_image_t		*img;
	t_2d_camera		*camera;
	t_master_piece	master_piece;
};

/*
typedef struct t_2d_hook t_2d_hook;

struct t_2d_hook
{
	mlx_t			*mlx;
	mlx_image_t		*img;
	t_2d_camera		*camera;
	int32_t			background;
	t_tile_format	tiles;
	t_ink32			ink;
};
*/

// hook.c
void	picture_at_an_exhibition(t_2d_hook *hook, bool is_draw);
void 			hook_pan_and_zoom(mlx_key_data_t keydata,
					void *param);

// tile_format.c
t_fline	init_offset_tile_area(size_t width, size_t height,
	size_t resolution, size_t fixed_length);
t_tile_format	init_tile_format(size_t width,
	size_t height, size_t resolution);
t_2d_int	get_first_interier_tile(t_tile_format tiles,
	t_2d_camera camera);
t_2d_int	get_last_interier_tile(t_tile_format tiles,
	t_2d_camera camera);
t_2d_int	get_ith_tile_screen(t_tile_format tiles,
	t_2d_camera camera, int ix, int iy);

// tile.c
size_t	init_tile_size(size_t side_length, size_t resolution);
size_t	init_alltiles_count(size_t side_length,
	size_t resolution, size_t fixed_length);
size_t	init_alltiles_size(size_t side_length,
	size_t resolution, size_t fixed_length);
int	init_alltiles_offset(size_t side_length,
	size_t resolution, size_t fixed_length);

// utils.c
bool			is_2dhook_valid(const t_2d_hook *src);
bool			is_valid_key(mlx_key_data_t keydata);
void			write_line(t_line src);
t_2d_camera		init_2d_camera(size_t width, size_t height);

// view
int	view_rectangle(size_t resolution, int32_t background);

// zoom.c
int	world_to_screen_xy(int offset, float world);
t_2d_int	world_to_screen_2d(t_2d_camera camera, t_complex world);

#endif
