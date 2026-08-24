/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 10:21:54 by phsottat          #+#    #+#             */
/*   Updated: 2026/08/24 21:19:44 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include "../type/type.h"

// arr.c
void			free_2d_arr(void **arr, size_t len);
void			*malloc_talk(size_t elem_size, const char *comment);
void			write_2d_index(int max_col, int row, int col);

// atoi.c
int				f_atoi(const char *src, bool *is_int,
					const char *base, size_t digits);
size_t			ft_putnbr_fd(int n, int fd, const char *base, size_t digits);

// split.c
size_t			f_split_len(const char *input, const char *space);
char			**f_split(const char *input, const char *space);

// utils.c
char			f_isspace(char s, const char *space);
size_t			f_strlen(const char *str);

#endif
