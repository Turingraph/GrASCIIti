#ifndef TEST_HELPERS_H
# define TEST_HELPERS_H

# include "stdlib.h"
# include "../../src/utils/libft/libft.h"
# include "../../src/input/get_next_line/get_next_line.h"

typedef struct t_intarr t_intarr;

struct t_intarr
{
	size_t		length;
	const int	*arr;
};

typedef struct t_intarr_tester t_intarr_tester;

struct t_intarr_tester
{
	const t_intarr	*arr;
	const char		*file_name;
	size_t			length;
};

// ascii.c
e_bool	assert_files_ascii(const char *file_name_1, const char *file_name_2,
			const char *dir_name_1, const char *dir_name_2);

// file.c
size_t	total_lines_of_file(int fd);
e_bool	assert_files(const char *file_name_1, const char *file_name_2,
			const char *dir_name_1, const char *dir_name_2);
e_bool	assert_file_with_strarr(int fd, const char **strarr,
			size_t total_lines);

// strarr.c
int		compare_string(const char *str_1, const char *str_2,
			size_t n, e_bool ignore_space);
size_t	length_of_strarr(const char **src);
e_bool	assert_strarr(const char **strarr_1, const char **strarr_2,
			size_t length, e_bool ignore_space);
size_t	write_strarr(const char **strarr, size_t length, int fd);
char	**load_file_as_strarr(int fd, size_t total_lines);

// utils.c
void	write_total_score(size_t score, size_t max_score);
int		compare_intarr(const int *str_1, const int *str_2, size_t n);
void	warning_file_not_exists(const char *src);

#endif
