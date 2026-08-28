#include"motif_private.h"

/**
 * Draw one motif instance inside a single tile.
 *
 * Each polygon in the motif is rendered.
 * The coordinates of the polygon are interpreted relative to the tile boundary.
 *
 * time/space: O(n) / O(1)
 *
 * status: internal helper
 *
 * @param img MLX image receiving the rendered motif
 * @param src Islamic-art motif configuration containing motif data
 * @param tile screen-space boundary of the tile to render into
 */
static void	draw_motif_mlx_unit(mlx_image_t *img, t_islamic_art *src, t_line tile)
{
	size_t	i;
	t_motif	*arr;
	t_ink32	ink;

	arr = src->motif->arr;
	i = 0;
	while (i < src->motif->length)
	{
		ink = arr[i].ink;
		if (ink.type == E_LINE)
			draw_polygon_mlx(img, &(arr[i].polygon), ink, tile);
		else if (ink.type == E_CIRCLE)
			draw_kusama_mlx(img, &(arr[i].polygon), ink, tile);
		else if (ink.type == E_RECTANGLE)
			draw_mondrian_mlx(img, &(arr[i].polygon), ink.color, tile);
		i += 1;
	}
}

/**
 * Draw a motif across a selected rectangular range of tiles.
 *
 * Each tile in the supplied range is converted from tile-grid coordinates
 * into screen coordinates and rendered independently. The range allows
 * callers to restrict rendering to a subset of the complete tile grid.
 *
 * This helper does not perform camera movement or panning. The range
 * parameter is retained so that a future interactive renderer can select
 * which tiles are visible without changing the motif rendering logic.
 *
 * time/space: O(n) / O(1)
 *
 * status: internal helper
 *
 * @param img MLX image receiving the rendered motif
 * @param src Islamic-art motif configuration
 * @param interier_tile rectangular range of tile indices to render
 */
static void	draw_motif_mlx_loop(mlx_image_t *img, t_islamic_art *src, t_line interier_tile)
{
	t_line		tile;
	int			ix;
	int			iy;

	iy = interier_tile.p1.y;
	while (iy < interier_tile.p2.y)
	{
		ix = interier_tile.p1.x;
		while (ix < interier_tile.p2.x)
		{
			tile.p1 = get_ith_tile_screen(src->tiles, ix, iy);
			tile.p2 = get_ith_tile_screen(src->tiles, ix + 1, iy + 1);
			draw_motif_mlx_unit(img, src, tile);
			ix += 1;
		}
		iy += 1;
	}
}

/**
 * Draw the configured motif across the complete tile grid.
 *
 * The motif is rendered once for every tile in the grid. The complete tile
 * range is constructed from src->tiles.tile_counts and passed to the
 * internal tile-loop helper.
 *
 * This function provides the current non-interactive motif rendering API.
 * Camera control, panning, and unified FDF/motif interaction are intentionally
 * outside its scope and may be introduced by a future rendering layer.
 *
 * time/space: O(n) / O(1)
 *
 * status: internal helper
 *
 * @param img MLX image receiving the rendered motif
 * @param src motif configuration containing the motif, tile format, and
 *            background configuration
 */
void	draw_motif_mlx(mlx_image_t *img, t_islamic_art *src)
{
	t_line	interier_tile;

	if (is_islamic_art_valid(src) == false)
		return ;
	interier_tile.p1.x = 0;
	interier_tile.p1.y = 0;
	interier_tile.p2 = src->tiles.tile_counts;
	draw_motif_mlx_loop(img, src, interier_tile);
}
