#include"convolve.h"

int	main(void)
{
	t_table_fdf	table_a;
	t_table_fdf	table_b;
	t_matrix	kernel_2;
	t_matrix	kernel;
	size_t		half_dim;
	int			output;
	char		*dst_dir = "unit_test/editor/convolve/input_fdf/";
	char		*src_dir = "input_examples/ascii/";
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

	half_dim = 5;
	kernel = gaussian_kernel(half_dim, 1.0, 1.0);
	kernel_2 = init_matrix(2 * half_dim + 1,
		2 * half_dim + 1,
		1.0 / ((2 * half_dim + 1) * (2 * half_dim + 1)));
	i = 0;
	while (i < length)
	{
		output = open_dir_file(arr_dst[i], dst_dir, APPEND);
		table_a = open_table_fdf_file(arr_src[i], src_dir,
				parse_ascii_line_chungaloider, true);
		table_b = scale_dimension_fdf((const t_table_fdf *)&table_a, 3, 3);
		free_table_fdf(&table_a);
		table_fdf_height_to_color(&table_b, GREEN);
		if (i % 2 == 0)
			table_a = convolve_rgba(&table_b, kernel, GREEN);
		else
			table_a = convolve_rgba(&table_b, kernel_2, RED);
		write_table_fdf(output, &table_a, 1, HEIGHT_RGB);
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
