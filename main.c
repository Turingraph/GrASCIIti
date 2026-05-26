/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 10:00:28 by phsottat          #+#    #+#             */
/*   Updated: 2026/03/23 10:18:08 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include "libft.h"
#include <stdio.h>

int	main(int av, char **ac)
{
	char	*y;
	int		len_y;

	if (av < 3)
		return (0);
	y = ft_strtrim(*(ac + 1), *(ac + 2));
	if (y == NULL)
	{
		write(1, "NULL\n", 5);
		return (0);
	}
	write(1, "len(y) = ", 9);
	len_y = (int) ft_strlen(y);
	ft_putnbr_fd(len_y, 1);
	write(1, "\n", 1);
	write(1, y, ft_strlen(y));
	write(1, "\n", 1);
	free(y);
	return (0);
}
*/

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"
#include "libft.h"
#include "MLX42.h"
#define WIDTH 750
#define HEIGHT 750

static mlx_image_t* image;

// -----------------------------------------------------------------------------

int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

void ft_randomize(void* param)
{
	(void)param;
	for (uint32_t i = 0; i < image->width; ++i)
	{
		for (uint32_t y = 0; y < image->height; ++y)
		{
			uint32_t color = ft_pixel(
				0x22,
				0x00,
				0xAA,
				0xFF
				// rand() % 0xFF, // R
				// rand() % 0xFF, // G
				// rand() % 0xFF, // B
				// rand() % 0xFF  // A
			);
			mlx_put_pixel(image, i, y, color);
		}
	}
}

void ft_hook(void* param)
{
	mlx_t* mlx = param;

	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_UP))
		image->instances[0].y -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
		image->instances[0].y += 5;
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
		image->instances[0].x -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
		image->instances[0].x += 5;
}

// -----------------------------------------------------------------------------

int32_t main(void)
{
	mlx_t* mlx;

	// Gotta error check this stuff
	if (!(mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true)))
	{
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	if (!(image = mlx_new_image(mlx, 128, 128)))
	{
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	if (mlx_image_to_window(mlx, image, 0, 0) == -1)
	{
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	
	mlx_loop_hook(mlx, ft_randomize, mlx);
	mlx_loop_hook(mlx, ft_hook, mlx);

	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}

/*
// https://askubuntu.com/questions/951847/how-to-compile-a-c-code-in-one-directory-in-another-directory-using-gcc
cc -Wall -Wextra -Werror main.c -Iinclude build/libmlx42.a build/libft.a build/get_next_line.a -ldl -lglfw3 -pthread -lm
*/

/*
To Do List
1.	finish 2D projection of 3D image https://www.desmos.com/calculator/bxklvqtozp
2.	MLX 2D projection of 3D image
3.	implementing flood filling and Rasterization in ASCII art.
4.	learn light physics
5.	learn quaternion
*/
