# *** COMMAND ***

CC = cc -Wall -Wextra -Werror
BUFFER_SIZE = 42

# https://stackoverflow.com/questions/2483182/recursive-wildcards-in-gnu-make
rwildcard=$(foreach d,$(wildcard $(1:=/*)),$(call rwildcard,$d,$2) $(filter $(subst *,%,$2),$d))

CODING_EXAMPLES = coding_examples/

# https://www.gnu.org/software/make/manual/make.html#Secondary-Expansion
.SECONDEXPANSION:
SRC_ATOM_libft:= $(wildcard src/utils/libft/*)
SRC_ATOM_math:= $(wildcard src/utils/math/*)
SRC_ATOM_gnl:= $(wildcard src/input/get_next_line/*)

SRC_linalg:= $(wildcard src/utils/linalg/*)
SRC_load:= $(wildcard src/input/load/*)
SRC_table:= $(wildcard src/input/table/*)

SRC_convolve:= $(wildcard src/editor/convolution/*)
SRC_mathart:= $(rwildcard,src/editor/mathart,*c)
SRC_paint:= $(wildcard src/editor/paint/*)

SRC_triangle_pair:= $(wildcard src/geometry/triangle_pair/*)
SRC_triangle_arr:= $(wildcard src/geometry/triangle_arr/*)

BUILD_ATOM_libft:= $(patsubst src/%.c, build/%.o, $(SRC_ATOM_libft))
BUILD_ATOM_math:= $(patsubst src/%.c, build/%.o, $(SRC_ATOM_math))
BUILD_ATOM_gnl:= $(patsubst src/%.c, build/%.o, $(SRC_ATOM_gnl))

BUILD_linalg:= $(patsubst src/%.c, build/%.o, $(SRC_linalg)) $(BUILD_ATOM_math)
BUILD_load:= $(patsubst src/%.c, build/%.o, $(SRC_load)) $(BUILD_ATOM_libft) $(BUILD_ATOM_gnl)
BUILD_table:= $(patsubst src/%.c, build/%.o, $(SRC_table)) $(BUILD_ATOM_load) $(BUILD_ATOM_math)

BUILD_convolve:= $(patsubst src/%.c, build/%.o, $(SRC_convolve)) $(BUILD_table)
BUILD_mathart:= $(patsubst src/%.c, build/%.o, $(SRC_mathart)) $(BUILD_table)
BUILD_paint:= $(patsubst src/%.c, build/%.o, $(SRC_paint)) $(BUILD_table)

BUILD_triangle_pair:= $(patsubst src/%.c, build/%.o, $(SRC_triangle_pair)) $(BUILD_ATOM_libft) $(BUILD_ATOM_linalg)
BUILD_triangle_arr:= $(patsubst src/%.c, build/%.o, $(SRC_triangle_arr)) $(BUILD_triangle_pair)

# *** create unit_test ***

# *** create coding_examples ***

coding_examples/bin/geometry/triangle_pair/%.out: lib/geometry/triangle_pair.a lib/input/table.a
	@mkdir -p $(@D)
	$(CC) $(patsubst $(CODING_EXAMPLES)bin/%.out, $(CODING_EXAMPLES)src/%.c, $@) $^ -o $@
	chmod +x $@

# https://stackoverflow.com/questions/9488256/use-directory-path-of-target-in-list-of-prerequisites-in-makefile

coding_examples/bin/%.out: lib/$$(@D).a
	@mkdir -p $(@D)
	$(CC) $(patsubst $(CODING_EXAMPLES)bin/%.out, $(CODING_EXAMPLES)src/%.c, $@) $^ -o $@
	chmod +x $@

# *** create library ***

lib/graphic/%.a: $$(BUILD_$$@)
	@mkdir -p $(@D)
	ar rcs $@ $^

# *** create object files. ***

build/%.o: src/%.c
	@mkdir -p $(@D)
	$(CC) -c $< -o $@

# https://stackoverflow.com/questions/1950926/create-directories-using-make-file
build/input/get_next_line/%.o: src/input/get_next_line/%.c
	@mkdir -p $(@D)
	$(CC) -D BUFFER_SIZE=$(BUFFER_SIZE) -c $< -o $@

# *** clean ***

# https://askubuntu.com/questions/802996/how-to-remove-directory-with-all-of-its-contents
clean:
	rm -r build/
	rm -r lib/
	rm -r $(CODING_EXAMPLES)bin/

clean_coding_examples:
	rm -r $(CODING_EXAMPLES)bin/

.PHONY: all clean test clean_coding_examples
