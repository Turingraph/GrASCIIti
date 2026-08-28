#include"fdf_private.h"

/**
 * Initialize a 2D camera for an MLX window.
 *
 * The camera starts at the origin (0,0) with a zoom factor of 1.0.
 * The window size defines the initial camera viewport.
 *
 * time/space: O(1) / O(1)
 *
 * status: internal helper
 *
 * @param window_width width of the camera viewport
 * @param window_height height of the camera viewport
 * @return initialized 2D camera
 */
t_2d_camera	init_2d_camera(size_t window_width, size_t window_height)
{
	t_2d_camera	camera;

	camera.offset.x = 0;
	camera.offset.y = 0;
	camera.zoom = 1.0;
	camera.window_size.x = window_width;
	camera.window_size.y = window_height;
	return (camera);
}

/**
 * Create an MLX image using the dimensions of an MLX window.
 *
 * The image uses the same width and height as the supplied MLX
 * context. If the MLX context is invalid or image creation fails,
 * NULL is returned. When image creation fails, the MLX context is
 * terminated.
 *
 * time/space: O(n) / O(1)
 *
 * status: internal helper
 *
 * @param mlx MLX window context used to create the image
 * @return newly created MLX image, or NULL on failure
 */
mlx_image_t	*init_mlx_image(mlx_t *mlx)
{
	mlx_image_t	*dst;

	if (mlx == NULL || mlx->width * mlx->height == 0)
		return (NULL);
	dst = mlx_new_image(mlx, mlx->width, mlx->height);
	if (dst == NULL)
	{
		mlx_terminate(mlx);
		return (NULL);
	}
	return (dst);
}

/**
* Initialize the rendering hook context for a 2D FDF view.
*
* The context stores the FDF object, drawing style, and view
* configuration. The camera is initialized separately because
* its lifetime is managed by the caller.
*
* time/space: O(1) / O(1)
*
* status: internal helper
*
* @param mlx MLX window context used by the view
* @param calligraphy FDF object to display
* @param drawing_style style used to render the FDF object
* @param view_config configuration controlling the view
* @return initialized 2D FDF rendering context
*/
t_2d_hook	init_2d_hook(mlx_t *mlx, t_fdf *calligraphy,
	t_ink32 drawing_style, t_view_config view_config)
{
	t_2d_hook	dst;

	dst.mlx = mlx;
	dst.camera = NULL;
	dst.master_piece.calligraphy = calligraphy;
	dst.master_piece.view_config = view_config;
	dst.master_piece.drawing_style = drawing_style;
	dst.img = init_mlx_image(mlx);
	return (dst);
}

/**
 * Prepare an FDF object for 3D viewing.
 *
 * The FDF object is first scaled to fit within the requested window
 * size. If an initial 3D transformation is supplied, that
 * transformation is then applied to the object and recorded in its
 * transformation matrix.
 *
 * This allows the caller to choose the initial orientation of the
 * FDF object before it is projected onto the 2D window.
 *
 * time/space: O(n) / O(n)
 *
 * status: internal helper
 *
 * @param src FDF object to transform
 * @param fixed_window_size target size used for initial scaling
 * @param init_3d_transform optional initial 3D transformation
 */
void	init_3d_fdf_object(t_fdf *src, size_t fixed_window_size,
	t_matrix *init_3d_transform)
{
	t_matrix	transform;

	if (is_fdf_valid(src) == false || fixed_window_size == 0)
		return ;
	transform = init_3d_zoom_matrix(fixed_window_size / src->width);
	if (transform.arr == NULL)
		return ;
	linear_map_fdf_all(src, transform);
	if (init_3d_transform != NULL && is_matrix_valid(init_3d_transform) == true)
	{
		linear_map_fdf_all(src, *init_3d_transform);
		matrix_3d_product(*init_3d_transform, &(src->matrix));
	}
	free(transform.arr);
}
