/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   public.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 17:03:34 by phsottat          #+#    #+#             */
/*   Updated: 2026/08/30 16:38:26 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_private.h"

// This function is only used for view_fdf.
bool	view_fdf_handle_00(mlx_t *mlx, mlx_image_t *img)
{
	if (img == NULL)
	{
		if (mlx != NULL)
			mlx_terminate(mlx);
		return (false);
	}
	return (true);
}

// This function is only used for view_fdf.
int32_t	view_fdf_handle_01(mlx_t *mlx, mlx_image_t *img)
{
	return (mlx_image_to_window(mlx, img,
			((int)mlx->width - (int)img->width) / 2,
			((int)mlx->height - (int)img->height) / 2));
}

// This function is only used for view_fdf.
void	view_fdf_handle_02(mlx_t *mlx, mlx_image_t *img)
{
	mlx_loop(mlx);
	mlx_delete_image(mlx, img);
	mlx_terminate(mlx);
}

/**
 * Display an FDF object in an interactive 2D MLX window.
 *
 * The FDF object is scaled to fit the viewing area and optionally
 * transformed by the initial 3D transformation specified by
 * view_config. The drawing style controls how the FDF object is
 * rendered, while view_config controls the background and initial
 * viewing configuration.
 *
 * The view supports interactive manipulation through the registered
 * FDF keyboard controller.
 *
 * Available keyboard input is handled by hook_fdf_controller(), including
 * 
 * - "ESC" = close the MLX window
 * 
 * - "Q" = reset 3D Fdf object
 * 
 * - "Left", "Right", "Up", "Down" = Panning the
 * 3D Fdf Object on 2D screen accordingly.
 * 
 * - "1" = rotaing 3D Fdf object on X Axis.
 * 
 * - "2" = rotaing 3D Fdf object on Y Axis.
 * 
 * - "3" = rotaing 3D Fdf object on Z Axis.
 * 
 * - "9" = Zoom in
 * 
 * - "0" = Zoom out
 *
 * time/space: O(n) / O(n)
 *
 * status: public api
 *
 * @param fdf FDF object to display
 * @param drawing_style style used to render the FDF object
 * @param background_color 32-bit color used for the background
 * @param is_isometric if is_isometric is true then render 3D
 * isometric projection, if not then render 2D projection.
 */
void	view_fdf(t_fdf *fdf, t_ink32 drawing_style,
	int32_t background_color, bool is_isometric)
{
	mlx_t			*mlx;
	t_2d_hook		hook;
	t_2d_camera		camera;
	size_t			window_width;
	size_t			window_height;

	window_width = 1440;
	window_height = 810;
	mlx = mlx_init(window_width, window_height, "Sunset at 4:42pm", true);
	hook = init_2d_hook(mlx, fdf, drawing_style, background_color);
	hook.master_piece.is_isometric = is_isometric;
	if (view_fdf_handle_00(mlx, hook.img) == false)
		return ;
	camera = init_2d_camera(window_width, window_height);
	hook.camera = &camera;
	scale_fdf_as_window_object(fdf, f_max(window_width, window_height));
	color_background_mlx(hook.img, background_color);
	draw_fdf_mlx(&hook, true);
	if (-1 == view_fdf_handle_01(mlx, hook.img))
	{
		mlx_terminate(mlx);
		return ;
	}
	mlx_key_hook(mlx, &hook_fdf_controller, &hook);
	view_fdf_handle_02(mlx, hook.img);
}
