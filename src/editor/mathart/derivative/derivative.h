#ifndef DERIVATIVE_H
# define DERIVATIVE_H

# include "../../../utils/type/type.h"
# include "../../../utils/libft/libft.h"
# include "../../../utils/math/math.h"

// filter.c
e_bool	is_evenodd_curl(size_t row, size_t col, t_table_fdf *dst);
e_bool	is_evenodd_divergence(size_t row, size_t col, t_table_fdf *dst);
e_bool	is_evenodd_gradient(size_t row, size_t col, t_table_fdf *dst);
e_bool	is_evenodd_partial_der(size_t row, size_t col, t_table_fdf *dst);
e_bool	is_evenodd_jacobian_det(size_t row, size_t col, t_table_fdf *dst);

// generator.c
int	gen_curl(size_t row, size_t col, t_table_fdf *dst);
int	gen_divergence(size_t row, size_t col, t_table_fdf *dst);
int	gen_gradient(size_t row, size_t col, t_table_fdf *dst);
int	gen_partial_der(size_t row, size_t col, t_table_fdf *dst);
int	gen_jacobian_det(size_t row, size_t col, t_table_fdf *dst);

// positive.c
e_bool	is_positive_curl(size_t row, size_t col, t_table_fdf *dst);
e_bool	is_positive_divergence(size_t row, size_t col, t_table_fdf *dst);
e_bool	is_positive_gradient(size_t row, size_t col, t_table_fdf *dst);
e_bool	is_positive_partial_der(size_t row, size_t col, t_table_fdf *dst);
e_bool	is_positive_jacobian_det(size_t row, size_t col, t_table_fdf *dst);

#endif
