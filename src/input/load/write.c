/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 11:15:33 by phsottat          #+#    #+#             */
/*   Updated: 2026/08/24 19:38:30 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "load.h"

// time : O(n)
// space: O(n)
void	write_load_fdf(int fd, const t_load_fdf *src,
		size_t digits, t_write_style mode)
{
	size_t	i;

	i = 0;
	while (src != NULL && src->arr != NULL && i < src->length)
	{
		ft_putnbr_fd(src->arr[i], fd, "0123456789", digits);
		if (mode == HEIGHT_RGB || mode == HEIGHT_RGBA)
		{
			write(fd, ",0x", 3);
			if (src->r != NULL)
				ft_putnbr_fd((int)src->r[i], fd, "0123456789abcdef", 2);
			if (src->g != NULL)
				ft_putnbr_fd((int)src->g[i], fd, "0123456789abcdef", 2);
			if (src->b != NULL)
				ft_putnbr_fd((int)src->b[i], fd, "0123456789abcdef", 2);
		}
		if (mode == HEIGHT_RGBA && src->a != NULL)
			ft_putnbr_fd((int)src->a[i], fd, "0123456789abcdef", 2);
		write(fd, "\t", 1);
		i += 1;
	}
	write(fd, "\n", 1);
}

// time : O(n)
// space: O(n)
void	write_load_fdf_arr(int fd,
		const t_load_fdf_arr *src, size_t digits, t_write_style mode)
{
	size_t	i;

	i = 0;
	while (src != NULL && i < src->length && src->arr != NULL)
	{
		write_load_fdf(fd, (const t_load_fdf *)&(src->arr[i]), digits, mode);
		i += 1;
	}
}

// time : O(n)
// space: O(n)
void	write_load_ascii(int fd, const t_load_fdf *src, const char *dict)
{
	size_t	i;

	i = 0;
	while (src != NULL && src->arr != NULL && i < src->length)
	{
		if (i < src->length / 2)
			ft_put_ascii_fd(fd, src->arr[i], dict, true);
		else
			ft_put_ascii_fd(fd, src->arr[i], dict, false);
		i += 1;
	}
	write(fd, "\n", 1);
}

// time : O(n)
// space: O(n)
void	write_load_ascii_arr(int fd, const t_load_fdf_arr *src,
			const char *dict)
{
	size_t	i;

	i = 0;
	while (src != NULL && i < src->length && src->arr != NULL)
	{
		write_load_ascii(fd, (const t_load_fdf *)&(src->arr[i]), dict);
		i += 1;
	}
}

// time : O(1)
// space: O(1)
void	warning_load_fdf(const t_load_fdf *src, size_t i)
{
	if (src->int_warn != CORRECT || src->rgb_warn != CORRECT)
	{
		write(1, "Warning: Line no. ", 19);
		ft_putnbr_fd(i, 1, "0123456789", 1);
		write(1, " of input Fdf file is ", 23);
		if (src->int_warn == EMPTY)
			write(1, "empty", 6);
		if (src->int_warn == NOT_DECIMAL)
			write(1, "not a decimal number", 21);
		if (src->int_warn != CORRECT && src->rgb_warn == 'E')
			write(1, " and ", 5);
		if (src->rgb_warn == NOT_HEX)
			write(1, " not a valid hexadecimal rgb representation", 44);
		write(1, ".\n", 2);
	}
}
