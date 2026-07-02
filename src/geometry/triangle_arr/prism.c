#include"triangle_arr.h"

// time : O(n)
// sapce: O(n)
t_triangle_arr	table_to_one_d_prism(t_table_fdf src, float width, char janus)
{
	t_triangle_arr	dst;
	t_triangle_arr	tsd;

	dst = init_triangle_arr(0);
	if ((src.row < 2 && src.col < 2) || src.arr == NULL)
		return (dst);
	if (src.row == 1 && src.col > 1)
		dst = all_triangle_side_xy(src, 'x');
	if (src.col == 1 && src.row > 1)
		dst = all_triangle_side_xy(src, 'y');
	if (dst.arr != NULL && dst.length > 0)
		setwidth_triangle_arr(&dst, width, 2);
	if (janus > 0 && dst.arr != NULL && dst.length > 0)
	{
		tsd = clone_triangle_arr(&dst, dst.length);
		concat_triangle_arr(&dst, &tsd);
	}
	return (dst);
}

// time : O(n)
// sapce: O(n)
t_triangle_arr	push_back_to_triangle_arr(t_triangle_arr *src, float width, char janus)
{
	t_triangle_arr	crs;

	setwidth_triangle_arr(src, width, 2);
	if (src->arr != NULL && src->length > 0)
	{
		crs = clone_triangle_arr(src, src->length);
		if (janus > 0)
			hadamard_triangle_arr(&crs, -1.0, 2);
		else
		{
			if (width > 0)
				width *= -1;
			setback_triangle_arr(&crs, width, 2);
		}
		concat_triangle_arr(src, &crs);
	}
	return (*src);
}

// time : O(n)
// sapce: O(n)
t_triangle_arr	table_to_prism(t_table_fdf src, float width, char janus)
{
	t_triangle_arr	dst;
	t_triangle_arr	items;

	if ((src.row < 2 && src.col < 2) || src.arr == NULL
		|| (src.row == 1 && src.col > 1) || (src.col == 1 && src.row > 1))
		return (table_to_one_d_prism(src, width, janus));
	dst = init_triangle_arr(1);
	items = all_triangle_faces(src, 1);
	push_back_to_triangle_arr(&items, width, janus);
	concat_triangle_arr(&dst, &items);
	items = all_triangle_side_xy(src, 'x');
	push_back_to_triangle_arr(&items, width, janus);
	concat_triangle_arr(&dst, &items);
	items = all_triangle_side_xy(src, 'y');
	push_back_to_triangle_arr(&items, width, janus);
	concat_triangle_arr(&dst, &items);
	items = all_triangle_side_lr(src, 'l');
	push_back_to_triangle_arr(&items, width, janus);
	concat_triangle_arr(&dst, &items);
	items = all_triangle_side_lr(src, 'r');
	push_back_to_triangle_arr(&items, width, janus);
	concat_triangle_arr(&dst, &items);
	items = copy_triangle_arr(&dst, dst.length);
	free(dst.arr);
	return (items);
}
