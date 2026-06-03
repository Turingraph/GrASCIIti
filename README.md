# Description

This is FdF from 42 coding school assignment. FdF is about converting the `.fdf` files with the columns of integer to 3D isometric wireframe, and display it on 2D screen using XML42 library.

I add the following features for bonus part
1.	`--bonus` option for display 3D object with the following default bonus features.
2.	Z Buffer calculation, so the only surface of the object that are in front of another surface will be shown accordingly.
3.	color is based on the angle between cross project vector of 2D triangles, and the light vector.
4.	quaternion rotation of 3D object and light source. (I have to design how user specify the rotation of the 3D object and light source later)
5.	`--prism` so the 3D model will looks like prism instead of chocolate as seen in most FdF project.
6.	`--not_sharp=n` to make `n` duplicated integer and integer array to make isometric projection less "sharp" for example if `--not_sharp=2` then `0 1 0` -> `0 0 1 1 0 0` (which have plateau than sharp mountain), or if `--not_sharp=3` then `0 1 1 0` -> `0 0 0 1 1 1 1 1 1 1 0 0 0`. If you use `--not_sharp`, then default value of `n` is `2`.
7.	`--double_face` to make back side of the 3D model has the same face as the front side.
8.	`--only_triangle` to display isometric 3D model with triangle meshes and without Z buffer calculation.
9.	Display 3D input text when use `./fdf "Hello World"` base on FIGlet style ASCII files input (`text/a.txt`, `text/b.txt`, etc.). If there is no target files, then return the error.
10.	`--Adir` option to specify which folder that have `dir/a.txt`, `dir/b.txt` etc. to include for `./fdf "Goodbye Mars"` input.
11.	`--obj_rgb=#a6c0d3`, `--background_rgb=#000000`, and `--light_rgb=#FFFFFF` to specify the color of 3D object, background, and light, accordingly. The default color of objects, background, and light, are red, black, and white, accordingly.
12.	`synesthesia.txt` as 3 column text to color object based on user defined graphite color synesthesia as the color of 3D object (instead of `#a6c0d3` a.k.a. light blue, in 10-th feature), is based on the color of the first character of user string/file name input. If `synesthesia.txt` file don't exists in the current directory, than the default color of the object is `#a6c0d3`. If `synesthesia.txt` file exists in the current directory, then the color of each text is color based on the user defined graphite color synesthesia mixing with the color of the first character according to this formula `(1 - a) * current_char + a * first_char`
13.	The default value of `a` is `0` if `a` isn't specified.
14.	All invalid line of text inside `synesthesia.txt` and all the string in between `#` and `\n`, is treated as programming comment (in other words, those line of text does not affect the output at all).

Here is the example of `synesthesia.txt`

### 1st example

```
0 FFFFFF a=0
1 000000 a=0.3
2 b58b1b 
2 reminds me of Euler constant. (This line of text is also treated as comment because it isn't valid. My software will show `WARNING: invalid line at line ...`).
# 2 reminds me of Euler constant. (This line of text is also treated as comment because it isn't valid. My software won't show `WARNING: invalid line at line ...` because `#` make this line valid).
3 998811 3 is too boring (This line of text is also treated as comment because this line of text isn't valid).
3 998811 # 3 is too boring (This line of text is also not treated as comment because this line of text is valid).
2 f58b00 # (This line of text is also treated as comment because this line of text is duplicated). Also my software will display `WARNING: color duplication at line ...` on CLI.
4 fa0 # This line of text is not valid because user have to write 6 characters to specify the color of alphabets or write 0 character to set the color of that alphabet as default color.
5 a=0.2 # This is valid.
6 a=3 # If a isn't number or a is greater than 1 or a is less than 0, then this line isn't valid and my software will display `WARNING: a value at line ... isn't valid.`
...
z 4e4736 a=0.7
```

### 2nd example

```
a ff0000 a=0.7
b 0000ff a=0.7
c ffff00 a=0.6
...
z 4e4736 a=0.7
```

### 3rd example

Note that `synesthesia.txt` can be applied with any well defined alphabet, for example

```
ก FF0000 
ข d2bc97
ค 5b4c38 a=0.4
```

As long as there is available `dir/ก.txt`, `dir/ข.txt`, `dir/ค.txt`. However the unique language dependence character placement e.g. ดี, ลิง, กล้วย ฯลฯ isn't supported by this first version now, but might be supported in future version.

## Future Project Plan

I add those features because MiniRT is the project about displaying light interaction with 3D object, so I can reuse some of my code and my experience in this future project. 

Even through, people can use Blender and/or Gen AI model to create the cool looking rotated 3D prism/text interacting with light, Blender is hard to use and Gen AI art tool don't have deterministic behavior, so this project is suitable for user who just want to convert ASCII text/art into simple 3D model that interacting with light. I will make this app compatible with Blender and add user friendly React Typescript based UXUI in the future.

<!--

--bonus
*	Z buffer
*	quaternion
*	triangle mesh
*	light

--prism
*	line mesh

--not_sharp
*	input/ transformation

--double_face
*	mesh

./fdf "Hello World" --Adir
*	input/

--obj_rgb --background_rgb --light_rgb synesthesia.txt
*	color

--only_triangle
*	mesh

-->

## How to download this project ? (EMPTY)

## Basic user tutorial (EMPTY)

## Folder Structure

Here is the directory structure
1.	`build/` for computing the binary files
2.	`doc/` for user tutorial, installation tutorial, and explaining how 3D graphic related algorithms work.
3.	`examples/` for showing my 4 artworks
	1.	Gen AI Artwork (a.k.a. `examples/ai_art/`) that have my 3D Graffiti visual components. This is the only artwork that is made by AI, and other artworks aren't made by AI and made by me manually.
	2.	Photo of my physical drawing (a.k.a. `examples/draw_art/`) is the only artwork that use that use 3D Graffiti visual components as drawing reference, and other artwork use 3D Graffiti visual components as the part of the artwork directly.
	3.	Photo (a.k.a. `examples/photo_art/`) that have my 3D Graffiti visual components by photo editing.
	4.	Pixel Art (a.k.a. `examples/pixel_art/`) that have my 3D Graffiti visual components. This artwork is made using Piskel pixel art drawing app.
4.	`include/` for including the header files and other files of the static library including `libft.h`, `libft/`, `glfw/`, `MLX42.h`, `MLX42/`, and `get_next_line.h`. Note that I don't include some library in this Git repo e.including `glfw/` and `MLX42/`, but include it in my PC anyway. I will use static library for the early version of this project and might migrate as dynamic library later.
5.	`input/` for checking if my project works with fdf files, `synesthesia.txt`, `alphabet/a.txt` and txt files correctly.
6.	`src/` for the source code of this project.

# Instructions (EMPTY)

## Check if my project follow the subject requirement (EMPTY)

## Check memory leak with Valgrind (EMPTY)

# Additional Information

1.	`doc/dev_plan_0_introduction.md` is about Graphic Rendering Pipeline and my Project Plan for the MVP version.
2.	`doc/synesthesia.md` is about what is synesthesia ?
3.	`doc/user_tutorial.md` for more user tutorial.

# Resource

1.	Computer Graphic pipeline
	1.	How Real Time Computer Graphics and Rasterization work
	*	https://youtu.be/brDJVEPOeY8?si=Tt-vaGcUnZng1LDp
2.	import MXL42 library
	1.  MLX42
	*   https://github.com/codam-coding-college/MLX42#download-and-build---mlx42
	2.  `-I`, `-L`, and `-l` option for `cc` command
	*   https://stackoverflow.com/questions/519342/what-is-the-difference-between-i-and-l-in-makefile
	3.  Pthread
	*   https://www.reddit.com/r/explainlikeimfive/comments/1jwix0w/eli5_what_are_threads_in_operating_system/
	*   https://stackoverflow.com/questions/15127279/whats-a-pthread
	4.  Static linking vs dynamic linking
	*	https://stackoverflow.com/questions/1993390/static-linking-vs-dynamic-linking
	5.	Install OpenGL on Ubuntu
	*	https://stackoverflow.com/questions/7842622/setting-up-opengl-on-ubuntu
	6.	Install X11 on Ubuntu.
	*	https://askubuntu.com/questions/1167278/how-to-install-x11-development-libraries-on-ubuntu-19-04
	7.	RandR headers not found; install libxrandr development package error
	*	https://github.com/openMVG/openMVG/issues/85
	8.	Install GLFW
	*	https://stackoverflow.com/questions/17768008/how-to-build-install-glfw-3-and-use-it-in-a-linux-project
	*	https://www.glfw.org/docs/latest/compile.html#compile_deps_wayland
3.	Quaternion
	1.	Visualizing the 4d numbers Quaternions
	*	https://youtu.be/d4EgbgTm0Bg?si=wdYcMB8PoKzabdQJ
4.	Figlet
	1.	Figlet
	*	https://textarttools.com/Figletfontstool/
	2.	ASCII Art gradient
	*	https://paulbourke.net/dataformats/asciiart/
5.	Makefile
	1.	Wildcard in Makefile
	*	https://stackoverflow.com/questions/11184389/what-does-wildcard-mean-in-makefile
	2.	ar on an existing .a file?
	*	https://stackoverflow.com/questions/4318906/ar-on-an-existing-a-file
6.	Synesthesia
	1.	I spent a day with SYNESTHETES (Neurological condition aka SYNESTHESIA) 
	*	https://youtu.be/lP58G70QmpA?si=L086y0idPJ9W9uyV
	2.	A simple yet impossible test
	*	https://youtu.be/-hc29pbzM1A?si=P2j8dik4Lz00w28V
	3.	Born On A Blue Day: Inside the Extraordinary Mind of an Autistic Savant
	*	https://www.amazon.com/Born-Blue-Day-Extraordinary-Autistic/dp/1416549013
7.	Convolution
	1.	But what is a convolution?
	*	https://youtu.be/KuXjwB4LzSA?si=5538Gr5xpS-cfLwV
	2.	Gaussian Blur implementation
	*	https://stackoverflow.com/questions/1696113/how-do-i-gaussian-blur-an-image-without-using-any-in-built-gaussian-functions
8.	Software testing tool
	1.	Valgrind
	*	https://stackoverflow.com/questions/5134891/how-do-i-use-valgrind-to-find-memory-leaks
	2.	Get Next Line Tester
	*	https://github.com/Tripouille/gnlTester

<!-- 1.	`ascii/`
2.	import MXL42 library.
3.	`tessellation/`
4.	`rasterization/`
5.	`rotation/`
6.	`cli/`
7.	Synesthesia
8.	basic computer graphic
9.	Art tool
	1.	Stable Diffusion
	2.	Piskel
	*	https://www.piskelapp.com/p/create/sprite/ -->


<!--
Skeleton 
1. Plate
2. Chocolate 
3. Double face

Skin
1. Rectangle 
2. Triangle 
3. Z buffer
4. Mixed (rectangle + triangle = triangle, order also matter)

Color
1. Background 
2. Shadow
3. Skin
4. Skeleton

Rotation
1. Global vs local
2. Speed
3. Initial Orientation 
4. Direction of Orientation
-->

<!--
Pixel Art Tool required features
1. Undo
2. File safe
3. Tools
4. Animation 
5. Some FEM (ver 2)

What not to add now (but will in future)
1. Gen AI
2. Color editor (with PCA, HSL, K mean etc.)
3. Layers
4. Conformal/non Euclidean  2D map 
5.
-->