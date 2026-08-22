#ifndef WINDOW_H
# define WINDOW_H

#include"../raster/raster.h"
#include"../../utils/linalg/linalg.h"

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

typedef struct t_motif t_motif;

struct t_motif
{
	t_2d_polygon	polygon;
	t_ink32			ink;
};

typedef struct t_motif_arr t_motif_arr;

struct t_motif_arr
{
	t_motif	*arr;
	size_t	length;
};

typedef struct t_master_piece t_master_piece;

struct t_master_piece
{
	t_ink32			style;
	t_motif_arr		*motif;
	t_table_fdf		*still_life;
	t_matrix		*pos_x;
	t_matrix		*pos_y;
	t_matrix		*pos_z;
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

typedef enum e_drawing_target e_drawing_target;

enum e_drawing_target
{
	E_MINIMALISM,
	E_MOTIF,
	E_STILL_LIFE
};

// hook.c
void	update_camera(mlx_key_data_t keydata, t_2d_camera *camera);

// motif.c
void	draw_motif_mlx(t_2d_hook *hook, bool is_draw);
void 			hook_pan_motif(mlx_key_data_t keydata,
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
bool			is_2dhook_valid(const t_2d_hook *src,
					e_drawing_target drawing_target);
bool			is_valid_key(mlx_key_data_t keydata);
void			write_line(t_line src);
t_2d_camera		init_2d_camera(size_t width, size_t height);
t_line		connecting_2d_point_pair(t_2d_int p1, t_2d_int p2);

// view
void	view_master_piece(t_motif_arr *motif, t_ink32 ink, size_t resolution);

// zoom.c
int	world_to_screen_xy(int offset, float world);
t_2d_int	world_to_screen_2d(t_2d_camera camera, t_complex world);

#endif
