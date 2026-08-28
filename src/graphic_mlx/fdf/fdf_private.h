#ifndef FDF_PRIVATE_H
# define FDF_PRIVATE_H

#include"../raster/raster.h"
#include "../../utils/linalg/linalg.h"
#include "../../input/table/table.h"

/**
 * FDF object containing source data (t_table_fdf) and its transformed positions.
 * 
 * The source table stores the original FDF data. The position arrays
 * represent the coordinates used for rendering and may be modified by
 * transformations without changing the source table.
 * 
 * @param src source FDF table
 * @param pos_x transformed x coordinates for each FDF cell
 * @param pos_y transformed y coordinates for each FDF cell
 * @param pos_z transformed z coordinates for each FDF cell
 * @param matrix 3D transformation matrix associated with the object. This matrix is used for undo every linear transformation when user press "Q" button.
 * @param width current width of the transformed FDF object
 */
typedef struct s_fdf
{
	t_table_fdf *src;
	float *pos_x;
	float *pos_y;
	float *pos_z;
	t_matrix matrix;
	float width;
}	t_fdf;

/**
 * 2D camera describing the visible portion of a rendered object.
 * 
 * The camera controls the position and scale used to map object
 * coordinates into the 2D rendering area.
 * 
 * @param offset position of the camera relative to the rendered object
 * @param window_size size of the visible 2D rendering area
 * @param zoom scale applied by the camera
 */
typedef struct s_2d_camera
{
	t_2d_int	offset;
	t_2d_int	window_size;
	float		zoom;
} t_2d_camera;

/**
 * Describes the background and initial transformation of a view.
 * 
 * The initial 3D transformation can be used to change the orientation
 * of the first 3D object before it is projected and rasterized.
 * This is useful when a user wants to inspect a static 2D view of an
 * FDF object from a particular orientation without interactively
 * transforming the object during rendering.
 * 
 * @param background_color 32-bit color used for the background
 * @param initial_3d_transform optional transformation applied to the
 * first 3D object before rendering
 */
typedef struct s_view_config
{
	int32_t		background_color;
	t_matrix	*init_3d_transform;
}	t_view_config;

/**
 * Describes the object and drawing configuration presented by a view.
 * 
 * A master piece combines the FDF object with the drawing style and
 * background configuration required to display it.
 * 
 * @param drawing_style describes how the FDF object is rasterized
 * @param calligraphy FDF object to display
 * @param view_config the utility configuration for coloring background and transforming 3D object.
 */
typedef struct s_master_piece
{
	t_ink32			drawing_style;
	t_fdf			*calligraphy;
	t_view_config	view_config;
}	t_master_piece;

/**
 * Runtime state required by the 2D MLX viewer.
 * 
 * The hook owns the MLX image and keeps references to the camera and
 * master piece used while the rendering loop is running.
 * 
 * @param mlx MLX window context
 * @param img image used as the rendering target
 * @param camera camera used to transform the displayed object
 * @param master_piece 3D FDF object and drawing configuration displayed by the viewer
 */
typedef struct s_2d_hook
{
	mlx_t			*mlx;
	mlx_image_t		*img;
	t_2d_camera		*camera;
	t_master_piece	master_piece;
}	t_2d_hook;

// draw_unit.c

t_ink32	get_hook_ink(t_2d_hook *hook, bool is_draw, t_2d_int ixiy);
void	draw_fdf_mlx_unit(t_line line, t_ink32 ink, t_2d_camera camera, mlx_image_t *img);
void	draw_fdf_mlx_y_unit(t_2d_hook *hook,
	bool is_draw, t_2d_int ixiy);
void	draw_fdf_mlx_x_unit(t_2d_hook *hook,
	bool is_draw, t_2d_int ixiy);

// draw_fdf.c

void	draw_fdf_mlx(t_2d_hook *hook, bool is_draw);

// geometry.c

float	linear_map_fdf(const t_fdf *src, t_matrix matrix, size_t i, char axis);
void	linear_map_fdf_all(t_fdf *src, t_matrix matrix);
t_2d_int	world_3d_to_screen_2d(t_2d_camera camera,
	float x, float y);
bool	is_line_in_screen(t_2d_camera camera,
	t_2d_int src);
bool	is_circle_in_screen(t_2d_camera camera,
	t_2d_int src, int thickness);

// hook.c

void	hook_fdf_controller(mlx_key_data_t keydata, void *param);

// init_2d_hook.c

t_2d_camera	init_2d_camera(size_t window_width, size_t window_height);
t_2d_hook	init_2d_hook(mlx_t *mlx, t_fdf *calligraphy,
	t_ink32 drawing_style, t_view_config view_config);
void	init_3d_fdf_object(t_fdf *src, size_t fixed_window_size,
	t_matrix *init_3d_transform);

// init_fdf.c

t_fdf	init_fdf(t_table_fdf *src);
void	free_fdf(t_fdf *src);
bool	is_fdf_valid(t_fdf *src);

// public.c

void	view_fdf(t_fdf *still_life, t_ink32 drawing_style, t_view_config view_config);

// verify.c

bool	is_2dhook_valid(const t_2d_hook *src);
bool	is_valid_key(mlx_key_data_t keydata);
bool	is_valid_pan_key(mlx_key_data_t keydata);
bool	is_valid_rotate_key(mlx_key_data_t keydata);
bool	is_valid_zoom_key(mlx_key_data_t keydata, float zoom);

#endif
