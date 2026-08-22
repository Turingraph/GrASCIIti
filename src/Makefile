
#-----------------------------------------------------------------------------------------------
# *** command ***

CC = cc -Wall -Wextra -Werror
BUFFER_SIZE = 42
# get_obj_files = $(filter %.o, $1)
# get_lib_a_files = $(filter %.a, $^)

#-----------------------------------------------------------------------------------------------
# https://stackoverflow.com/questions/9488256/use-directory-path-of-target-in-list-of-prerequisites-in-makefile
# https://www.gnu.org/software/make/manual/make.html#Secondary-Expansion
.SECONDEXPANSION:

# *** library ***
LIBRARY = $(patsubst %, lib/%.a, libft math get_next_line linalg load table view window\
	convolve mathart paint line triangle_pair triangle_arr debug debug_triangle)

# *** atom src ***
SRC_libft = $(wildcard utils/libft/*.c)
SRC_math = $(wildcard utils/math/*.c)
SRC_get_next_line = $(wildcard input/get_next_line/*.c)

# *** composed src ***
SRC_debug = $(wildcard debug/debug/*.c)
SRC_debug_triangle = $(wildcard debug/debug_triangle/*.c)
SRC_linalg = $(wildcard utils/linalg/*.c)
SRC_load = $(wildcard input/load/*.c)
SRC_table = $(wildcard input/table/*.c)

SRC_convolve = $(wildcard editor/convolve/*.c)
SRC_mathart = $(wildcard editor/mathart/*/*.c)
SRC_paint = $(wildcard editor/paint/*.c)
SRC_line = $(wildcard editor/line/*.c)

SRC_triangle_pair = $(wildcard graphic/triangle_pair/*.c)
SRC_triangle_arr = $(wildcard graphic/triangle_arr/*.c)
SRC_view = $(wildcard graphic/view/*.c)
SRC_window = $(wildcard graphic/window/*.c)

#-----------------------------------------------------------------------------------------------

# *** elementary obj ***
OBJ_libft = $(patsubst %.c, obj/%.o, $(SRC_libft))
OBJ_math = $(patsubst %.c, obj/%.o, $(SRC_math))
OBJ_get_next_line = $(patsubst %.c, obj/%.o, $(SRC_get_next_line))

# *** composed obj ***
OBJ_debug = $(patsubst %.c, obj/%.o, $(SRC_debug)) $(OBJ_libft) $(OBJ_get_next_line)
OBJ_debug_triangle = $(patsubst %.c, obj/%.o, $(SRC_debug_triangle))
OBJ_linalg = $(patsubst %.c, obj/%.o, $(SRC_linalg)) $(OBJ_math)
OBJ_load = $(patsubst %.c, obj/%.o, $(SRC_load)) $(OBJ_libft) $(OBJ_get_next_line)
OBJ_table = $(patsubst %.c, obj/%.o, $(SRC_table)) $(OBJ_load) $(OBJ_math)

OBJ_convolve = $(patsubst %.c, obj/%.o, $(SRC_convolve)) $(OBJ_table) $(OBJ_linalg)
OBJ_mathart = $(patsubst %.c, obj/%.o, $(SRC_mathart)) $(OBJ_table)
OBJ_paint = $(patsubst %.c, obj/%.o, $(SRC_paint)) $(OBJ_table)
OBJ_line = $(patsubst %.c, obj/%.o, $(SRC_line)) $(OBJ_math) $(OBJ_libft)

OBJ_triangle_pair = $(patsubst %.c, obj/%.o, $(SRC_triangle_pair)) $(OBJ_libft) $(OBJ_linalg)
OBJ_triangle_arr = $(patsubst %.c, obj/%.o, $(SRC_triangle_arr)) $(OBJ_triangle_pair)
OBJ_view = $(patsubst %.c, obj/%.o, $(SRC_view)) $(OBJ_line)
OBJ_window = $(patsubst %.c, obj/%.o, $(SRC_window)) $(OBJ_view) $(OBJ_linalg)

# https://stackoverflow.com/questions/59465799/avoid-gnu-make-automatic-file-deletion
# This command will preserve the selected files.
# .PRECIOUS: $(OBJ_libft) $(OBJ_get_next_line)

#-----------------------------------------------------------------------------------------------
# *** create library ***

all: $(LIBRARY)

# ChatGPT recommended me this solution.
# The takes away is reading the functions for files name section of Makefile manual first
# (a.k.a. https://ftp.gnu.org/old-gnu/Manuals/make-3.79.1/html_node/make_79.html )
# if you have to manipulating the string of the files/folders name according to correct 
# format like this, for example you might want to split string as arrays of string,
# with `,` or `/` as the separators.
lib/%.a: $$(OBJ_$$(notdir $$(basename $$@)))
	@mkdir -p $(@D)
	ar rcs $@ $^

# *** create object files. ***
# https://stackoverflow.com/questions/1950926/create-directories-using-make-file
obj/%.o: %.c
	@mkdir -p $(@D)
	$(CC) -c $< -o $@

obj/input/get_next_line/%.o: input/get_next_line/%.c
	@mkdir -p $(@D)
	$(CC) -D BUFFER_SIZE=$(BUFFER_SIZE) -c $< -o $@

#-----------------------------------------------------------------------------------------------
# *** clean ***
# https://askubuntu.com/questions/802996/how-to-remove-directory-with-all-of-its-contents
clean:
	rm -r -f lib/
	rm -r -f obj/

# Lol, both Makefile tutorial and Suisei already cover .PHONY
# https://youtu.be/N029UUlH1Dc?si=8PragRfDm3MzFOBc
.PHONY: all clean
