CC = cc -Wall -Wextra -Werror
BUFFER_SIZE = 42

# https://stackoverflow.com/questions/2483182/recursive-wildcards-in-gnu-make
rwildcard=$(foreach d,$(wildcard $(1:=/*)),$(call rwildcard,$d,$2) $(filter $(subst *,%,$2),$d))

#----------------------------------------------------------------------------------

SRC_ATOM_LIBFT = $(wildcard src/utils/libft/*)
SRC_ATOM_MATH = $(wildcard src/utils/math/*)
SRC_ATOM_GNL = $(wildcard src/input/get_next_line/*)

SRC_LINALG = $(wildcard src/utils/linalg/*)
SRC_LOAD = $(wildcard src/input/load/*)
SRC_TABLE = $(wildcard src/input/table/*)

SRC_CONVOLVE = $(wildcard src/editor/convolution/*)
SRC_MATHART = $(rwildcard,src/editor/mathart,*c)
SRC_PAINT = $(wildcard src/editor/paint/*)

SRC_TRIANGLE_PAIR = $(wildcard src/geometry/triangle_pair/*)
SRC_TRIANGLE_ARR = $(wildcard src/geometry/triangle_arr/*)

#----------------------------------------------------------------------------------

BUILD_ATOM_LIBFT = $(patsubst src/%.c, build/%.o, $(SRC_ATOM_LIBFT))
BUILD_ATOM_MATH = $(patsubst src/%.c, build/%.o, $(SRC_ATOM_MATH))
BUILD_ATOM_GNL = $(patsubst src/%.c, build/%.o, $(SRC_ATOM_GNL))

BUILD_LINALG = $(patsubst src/%.c, build/%.o, $(SRC_LINALG)) $(BUILD_ATOM_MATH)
BUILD_LOAD = $(patsubst src/%.c, build/%.o, $(SRC_LOAD)) $(BUILD_ATOM_LIBFT) $(BUILD_ATOM_GNL)
BUILD_TABLE = $(patsubst src/%.c, build/%.o, $(SRC_TABLE)) $(BUILD_ATOM_LOAD) $(BUILD_ATOM_MATH)

BUILD_CONVOLVE = $(patsubst src/%.c, build/%.o, $(SRC_CONVOLVE)) $(BUILD_TABLE)
BUILD_MATHART = $(patsubst src/%.c, build/%.o, $(SRC_MATHART)) $(BUILD_TABLE)
BUILD_PAINT = $(patsubst src/%.c, build/%.o, $(SRC_PAINT)) $(BUILD_TABLE)

BUILD_TRIANGLE_PAIR = $(patsubst src/%.c, build/%.o, $(SRC_TRIANGLE_PAIR)) $(BUILD_ATOM_LIBFT) $(BUILD_ATOM_LINALG)
BUILD_TRIANGLE_ARR = $(patsubst src/%.c, build/%.o, $(SRC_TRIANGLE_ARR)) $(BUILD_TRIANGLE_PAIR)

#----------------------------------------------------------------------------------
# create unit_test

#----------------------------------------------------------------------------------
# create coding_examples


#----------------------------------------------------------------------------------
# create library

lib/graphic/triangle_arr.a: $(BUILD_TRIANGLE_ARR)
	@mkdir -p $(@D)
	ar rcs $@ $^

lib/graphic/triangle_pair.a: $(BUILD_TRIANGLE_PAIR)
	@mkdir -p $(@D)
	ar rcs $@ $^

lib/editor/convolution.a: $(BUILD_CONVOLVE)
	@mkdir -p $(@D)
	ar rcs $@ $^

lib/editor/mathart.a: $(BUILD_MATHART)
	@mkdir -p $(@D)
	ar rcs $@ $^

lib/editor/paint.a: $(BUILD_PAINT)
	@mkdir -p $(@D)
	ar rcs $@ $^

lib/input/table.a: $(BUILD_TABLE)
	@mkdir -p $(@D)
	ar rcs $@ $^

lib/input/load.a: $(BUILD_LOAD)
	@mkdir -p $(@D)
	ar rcs $@ $^

lib/input/get_next_line.a: $(BUILD_ATOM_GNL)
	@mkdir -p $(@D)
	ar rcs $@ $^

lib/utils/linalg.a: $(BUILD_LINALG)
	@mkdir -p $(@D)
	ar rcs $@ $^

lib/utils/math.a: $(BUILD_ATOM_MATH)
	@mkdir -p $(@D)
	ar rcs $@ $^

lib/utils/libft.a: $(BUILD_ATOM_LIBFT)
	@mkdir -p $(@D)
	ar rcs $@ $^

#----------------------------------------------------------------------------------
# create object files.

build/%.o: src/%.c
	@mkdir -p $(@D)
	$(CC) -c $< -o $@

# https://stackoverflow.com/questions/1950926/create-directories-using-make-file
build/input/get_next_line/%.o: src/input/get_next_line/%.c
	@mkdir -p $(@D)
	$(CC) -D BUFFER_SIZE=$(BUFFER_SIZE) -c $< -o $@

#----------------------------------------------------------------------------------
# clean

# https://askubuntu.com/questions/802996/how-to-remove-directory-with-all-of-its-contents
clean:
	rm -r build/
	rm -r lib/
	rm -r test/bin/

clean_test:
	rm -r test/bin/

.PHONY: all clean test clean_test
