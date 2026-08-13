#include"triangle_arr.h"

// time : O(n)
// sapce: O(n)
t_triangle_arr	table_to_one_d_prism(const t_table_fdf *src, float width, bool is_2faces)
{
	t_triangle_arr	dst;
	t_triangle_arr	tsd;

	dst = init_triangle_arr(0, src->row, src->col);
	if (src == NULL || (src->row < 2 && src->col < 2) || src->arr == NULL)
		return (dst);
	if (src->row == 1 && src->col > 1)
		dst = all_triangle_edge_xy(src, 'x');
	if (src->col == 1 && src->row > 1)
		dst = all_triangle_edge_xy(src, 'y');
	if (dst.arr != NULL && dst.length > 0)
		setwidth_triangle_arr(&dst, width, 2);
	if (is_2faces == true && dst.arr != NULL && dst.length > 0)
	{
		tsd = clone_triangle_arr(&dst, dst.length);
		concat_triangle_arr(&dst, &tsd);
	}
	return (dst);
}

// time : O(n)
// sapce: O(n)
t_triangle_arr	push_back_to_triangle_arr(t_triangle_arr *src, float width, bool is_2faces)
{
	t_triangle_arr	crs;

	setwidth_triangle_arr(src, width, 2);
	if (src->arr != NULL && src->length > 0)
	{
		crs = clone_triangle_arr(src, src->length);
		if (is_2faces == true)
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
t_triangle_arr	table_to_prism(const t_table_fdf *src, float width, bool is_2faces, e_3d_shape shape)
{
	t_triangle_arr	dst;
	t_triangle_arr	items;

	if (src == NULL || src->arr == NULL)
		return (init_triangle_arr(0, 0, 0));
	if ((src->row < 2 && src->col < 2)
		|| (src->row == 1 && src->col > 1) || (src->col == 1 && src->row > 1))
		return (table_to_one_d_prism(src, width, is_2faces));
	dst = init_triangle_arr(1, src->row, src->col);
	items = all_triangle_faces(src, shape);
	push_back_to_triangle_arr(&items, width, is_2faces);
	concat_triangle_arr(&dst, &items);
	items = all_triangle_edge_xy(src, 'x');
	push_back_to_triangle_arr(&items, width, is_2faces);
	concat_triangle_arr(&dst, &items);
	items = all_triangle_edge_xy(src, 'y');
	push_back_to_triangle_arr(&items, width, is_2faces);
	concat_triangle_arr(&dst, &items);
	items = all_triangle_edge_lr(src, 'l');
	push_back_to_triangle_arr(&items, width, is_2faces);
	concat_triangle_arr(&dst, &items);
	items = all_triangle_edge_lr(src, 'r');
	push_back_to_triangle_arr(&items, width, is_2faces);
	concat_triangle_arr(&dst, &items);
	items = copy_triangle_arr(&dst, dst.length);
	free(dst.arr);
	return (items);
}
