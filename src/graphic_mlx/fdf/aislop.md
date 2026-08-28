/**
 * Calculate the side length of one tile for a given resolution.
 *
 * The tile size is obtained by dividing the supplied side length by
 * 2^resolution. Increasing the resolution therefore produces smaller
 * tiles. The result is truncated to an integer number of pixels.
 *
 * @param side_length reference side length (the width or height of the window) used to calculate the tile size
 * @param resolution tile resolution; higher values produce smaller tiles
 * @return side length of one tile, or 0 when the resolution is too large
 
 * status: internal helper
 *
 * time/space: O(resolution, where resolution is limited to 10) / O(1)
 */

/**
* Calculate how many tiles fit along one side of the drawing area.
*
* The tile size is derived from fixed_length and resolution, then the
* supplied side length is divided by that tile size. Any incomplete tile
* at the edge is excluded.
*
* @param side_length side length of the drawing area
* @param resolution tile resolution
* @param fixed_length reference side length used to determine tile size
* @return number of complete tiles that fit along the supplied side
*
* status: internal helper
*
* time: O(resolution), where resolution is limited to 10
* space: O(1)
*/

/**

* Calculate the total side length occupied by complete tiles.
*
* The result is the number of complete tiles multiplied by the side
* length of each tile. Any remaining space that cannot contain a
* complete tile is excluded.
*
* @param side_length side length of the drawing area
* @param resolution tile resolution
* @param fixed_length reference side length used to determine tile size
* @return total side length occupied by complete tiles
*
* status: internal helper
*
* time: O(resolution), where resolution is limited to 10
* space: O(1)
  */



