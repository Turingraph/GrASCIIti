/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 10:22:20 by phsottat          #+#    #+#             */
/*   Updated: 2026/08/24 10:22:21 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// time : O(1)
// space: O(n)
void	*malloc_talk(size_t elem_size, const char *comment)
{
	size_t			i;
	unsigned char	*d;
	void			*dst;

	if (elem_size == 0)
		return (NULL);
	dst = (void *)malloc(elem_size);
	if (dst == NULL)
	{
		if (comment != NULL && *comment != '\0')
		{
			write(1, "Malloc Fail: ", 14);
			write(1, comment, f_strlen(comment));
		}
	}
	d = (unsigned char *)dst;
	i = 0;
	while (i < elem_size)
	{
		*d = 0;
		d += 1;
		i += 1;
	}
	return (dst);
}

// time : O(n)
// space: O(1)
void	free_2d_arr(void **arr, size_t len)
{
	while (len > 0 && arr != NULL)
	{
		if (len > 0 && arr[len - 1] != NULL)
			free(arr[len - 1]);
		len -= 1;
	}
	free(arr);
}

// time : O(1)
// space: O(1)
void	write_2d_index(int max_col, int row, int col)
{
	write(1, "row = ", 7);
	ft_putnbr_fd(row, 1, "0123456789", 1);
	write(1, "\n", 1);
	write(1, "col = ", 7);
	ft_putnbr_fd(col, 1, "0123456789", 1);
	write(1, "\n", 1);
	row = row * max_col + col;
	write(1, "index = ", 9);
	ft_putnbr_fd(row, 1, "0123456789", 1);
	write(1, "\n", 1);
	write(1, "max_col = ", 11);
	ft_putnbr_fd(max_col, 1, "0123456789", 1);
	write(1, "\n", 1);
}
