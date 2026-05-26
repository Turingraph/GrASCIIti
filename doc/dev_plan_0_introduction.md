# Graphic Rendering Pipeline

We can render simple 3D rotated object interacting with light by 
1.	Converting input text file (fdf file) or ASCII text file into 2D integer array.
2.	Converting 2D integer array into array of 2D triangle on R^3 with processed called tessellation. This process should takes O(n) space and O(n) time.
3.	Apply 2D Z Buffer to detect which 2D triangle is in front or behind another 2D triangle.
4.	Calculating the angle between cross product of 2D triangle and the light vector to get correct color according to how light interacting with 2D triangle.
5.	Draw 2D triangle with Rasterization. The process no.3,4, and 5, should takes O(w * h) times and O(n) space, where n is the number of all 2D triangles
6.	Apply quaternion rotation to rotate light source and 2D triangles according to user input hook, based on 3B1B tutorial (https://youtu.be/zjMuIxRvygQ?si=ym0EEDROthW9-CV0)

# Folder structure of `src/`

There are 5 folders inside `src/`
1.	`input/`
2.	`cli/`
3.	`rasterization/`
4.	`rotation/`
5.	`tessellation/`

# My Project Plan for the MVP version.

Here is the 6 steps plan on how am I implementing this project inside `src/` directory.
1.	I will implement the following algorithms in this list in special case in `ascii/` without using MXL42 and without using miniLibX, first. `ascii/` helps us implement other directory better even it isn't used directly (except handle with ASCII art text file).
	1.	`bresenham_line.c`
		*	time : O(n)
		*	space: O(1)
	<!-- 2.	`flood_fill.c` (for my React based Piskel clone project in this Git repo https://github.com/Turingraph/Planck_Palette and also for edit ASCII art much more easily)
		*	time : O(n^2)
		*	space: O(n) -->
	2.	`rasterization.c`
		*	time : O(n^2)
		*	space: O(1)
	3.	`z_buffer_1d.c`
		*	time : O(n)
		*	space: O(n)
2.	import MXL42 library.
3.	converting input text file (fdf file) or ASCII text file to 2D triangle on R^3, using the following algorithm from `tessellation/`
	1.	`get_next_line.c`
	*	time : O(n)
	*	space: O(n)
	2.	`split` ...
4.	implementing 2D Z buffer, light brightness calculation, and Rasterization, on multiple 2D triangles in `rasterization/`.
5.	implement `rotation/` to rotaing the 3D object and light source, using Quaternion ring.
6.	implement `cli/` for dealing with user option (read `README.md` for more information)
	1.	`--bonus`
	2.	`--not_sharp`
	3.	`--Adir`
	4.	`--prism`
	5.	`--obj_rgb=#FF0000`, `--background_rgb=#000000`, and `--light_rgb=#FFFFFF`
	6.	`synesthesia.txt`
	7.	Add option that specify the quaternion rotation

Note that `test.c` is used for checking if my code in the current directory (which is also `src/` sub directory) works as expected.
