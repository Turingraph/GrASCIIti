# Introduction

I plan to make fdf42, and I also add the feature that allow user to convert ASCII text (including Figlet output) as fdf42 input files, and display them as prism (with Z buffer) instead of isometric projection that looks like boring chocolate (as I see in original fdf42). The user can choose the origin of x and y on the tables of integers, also paint those prism with complex conformal map as rgba value on each cells, and use Gaussian convolution when they wish to do it and also save it as new fdf42 files. Also I plan to make it utilize mainly OpenGL/GLFW directly. The reason I do this is because I have grapheme color synesthesia, I never use Blender, and I want to show audience what is the color of alphabet and display it as 3D typography for pure artistic reason and as IT job portfolio. 

Another interesting idea is that I can also show the audience about my personal experience with how learning 3rd language and synesthesia experience interact with each other, if I have opportunity to learn 3rd language consistently.

Thing that I didn't do it yet, but I should do before Submission
1.	editor/line/ for drawing Bresenham line with n thickness and simple square tiling Islamic art
2.	graphic/window/ (with only keyboard based UXUI)
3.	user tutorial and README.md
4.	fix some part of coding_examples/ (triangle_pair, triangle_arr, and line)

Thing to do before release First Stable Version (but I should avoid doing it now because I have only 2 weeks to finish this Fdf42 and also finish Push Swap that I didn't begin at all, or else I'm "fired" from 42 Coding School)
1.	graphic/rasterization/ with z buffer
2.	detvolve (determanent based image filtering), Strassen algorithm (not because my matrix multiplication is too slow, but because I love DSA challenge), and matrix determinant in n dimension
3.	outlier for painting only some part of the table_fdf that have value greater or lower than n% percentile based on normal/uniform distribution, the means and standard deviation of the value of every cells.
4.	reflection (make table_fdf become upside down, reflected right to left, and rotating for 90 degree)
5.	compression (creating another table_fdf as the smaller version of the input table_fdf)
6.	conformal (creating another table_fdf that is the 2d conformal transformed of the original table_fdf)

Thing to do "after" the first stable version, to avoid scope creep.
1.	editor/mathart/derivative/ for draw the image according to the local derivative, curl, gradient, and Jacobian determanent of the image.
2.	editor/fractal/ (including Julia, Newton fractal etc.) for drawing/painting Fractal.
3.	mouse based UXUI and throttle
4.	Figlet in other languages and language specialized related features e.g. Thai (my native language and Thai and English are the only language that I can speak currently), Myanmar, Khmer, Ainu language, Zhuang, Japanese (I plan to learn Japanese as third language because I love anime, Jpop, and I want interesting writing system for this Git repo), Pali,Chinese (my parents and some other in my family tree can speak Chinese but I can't so I wish to learn this language as 4th language), Arabic, Biblaridion's Edun, Kat Mistberg's Unordered language (I might learn conlang as 5th language, or Pali as 5th language to study some Buddhism but I do not sure, and endangered language as 6th language for the sake of this Git repo) etc.
5.	Content about my personal experience with synesthesia, language, my experience with meditation while observing random thought, my experience with learning 3rd language and how this experience interact with my synesthesia experience and vise versa, written conlang, etymology, preserving near endangered language, Phenomenology, Calligraphy based Tarot cards etc.
6.	Blender/Piskel/Jpg/PDF compatible file
7.	React Typescript user friendly Frontend
8.	Font topology/geometry related analysis
