#include"convolve.h"

int	main(void)
{
	t_table_fdf	table_a;
	t_table_fdf	table_b;
	t_matrix	kernel_2;
	t_matrix	kernel;
	size_t		half_dim;
	int			output;
	char		*dst = "unit_test/editor/convolve/input_ascii/";
	char		*src = "input_examples/ascii/";
	char		*arr_src[] = {
		"apartment_goofy.txt",
		"bangkok_usa_frag.txt",
		"cuneiform_peakslank.txt",
		"fast_and_ferious_speed.txt",
		"handsomeguy_nancyj.txt",
		"islamic_art.txt",
		"islamic_gauss.txt",
		"jellyfish_nvscript.txt",
		"lerem_ipsum_nvscript.txt",
		"lorem_Ipsum_script.txt",
		"mfdoom_georgi16.txt", 
		"mondrian_int.txt", 
		"o_isometric2.txt",
		"pillar.txt",
		"rain_with_cappuccino_rozzo.txt", 
		"startrack_starwars.txt",
		"the_last_of_us_poison.txt",
		"times4.txt", 
		"unix_o8.txt",
		"zutomayo_isometric2.txt"};
	char		*arr_dst[] = {
		"apartment_goofy.fdf",
		"bangkok_usa_frag.fdf",
		"cuneiform_peakslank.fdf",
		"fast_and_ferious_speed.fdf",
		"handsomeguy_nancyj.fdf",
		"islamic_art.fdf",
		"islamic_gauss.fdf",
		"jellyfish_nvscript.fdf",
		"lerem_ipsum_nvscript.fdf",
		"lorem_Ipsum_script.fdf",
		"mfdoom_georgi16.fdf", 
		"mondrian_int.fdf", 
		"o_isometric2.fdf",
		"pillar.fdf",
		"rain_with_cappuccino_rozzo.fdf", 
		"startrack_starwars.fdf",
		"the_last_of_us_poison.fdf",
		"times4.fdf", 
		"unix_o8.fdf",
		"zutomayo_isometric2.fdf"};
	size_t	  i;
	size_t	  length = 20;
    // t_rgba      target = {.a = 1, .r = 1, .g = 0, .b = 0};
    // t_rgba      target_2 = {.a = 0, .r = 1, .g = 1, .b = 1};

	half_dim = 3;
	kernel = gaussian_kernel(half_dim, 0.7, 0.7);
	kernel_2 = init_matrix(2 * half_dim + 1,
		2 * half_dim + 1,
		1.0 / ((2 * half_dim + 1) * (2 * half_dim + 1)));
	i = 0;
	while (i < length)
	{
		output = open_dir_file(arr_dst[i], dst, APPEND);
		table_a = open_table_fdf_file(arr_src[i], src,
				parse_ascii_line_chungaloider, false);
		table_b = scale_dimension_fdf((const t_table_fdf *)&table_a, 3, 3);
		free_table_fdf(&table_a);
		if (i % 2 == 0)
			table_a = convolve_rgba(&table_b, kernel, BLUE);
		else
			table_a = convolve_rgba(&table_b, kernel_2, RED);
		write_table_fdf(output, &table_a, 1, HEIGHT_RGBA);
		free_table_fdf(&table_a);
		free_table_fdf(&table_b);
		i += 1;
	}
	free_matrix(&kernel);
	free_matrix(&kernel_2);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./unit_test/out/editor/convolve/fdf.out

*/
