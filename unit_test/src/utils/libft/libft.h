#ifndef LIBFT_TESTER_H
# define LIBFT_TESTER_H

# include "../../../../src/utils/libft/libft.h"
# include "../../../test_helpers/test_helpers.h"

typedef struct t_atoi_tester t_atoi_tester;

struct t_atoi_tester
{
	char	*min_input;
	char	*max_input;
	bool	is_eq_or_less;
	bool	is_number;
};

typedef struct t_putnbr_tester t_putnbr_tester;

struct t_putnbr_tester
{
	int			input_n;
	size_t		input_digits;
	const char	*input_base;
	size_t		expected_length;
};

typedef struct t_split_tester t_split_tester;

struct t_split_tester
{
	const char	*input_str;
	const char	*input_space;
	size_t		expected_length;
	const char	**expected_output;
};

#endif
