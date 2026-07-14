# *** COMMAND ***

CC = cc -Wall -Wextra -Werror
BUFFER_SIZE = 42

# https://stackoverflow.com/questions/2483182/recursive-wildcards-in-gnu-make
# rwildcard=$(foreach d,$(wildcard $(1 =/*)),$(call rwildcard,$d,$2) $(filter $(subst *,%,$2),$d))

# `call` command is explained in Function section of the Makefile tutorial
# https://makefiletutorial-com.translate.goog/?_x_tr_sl=en&_x_tr_tl=th&_x_tr_hl=th&_x_tr_pto=tc#first-functions
remove_slash = $(patsubst %/,%,$1)

#-----------------------------------------------------------------------------------------------
# https://stackoverflow.com/questions/9488256/use-directory-path-of-target-in-list-of-prerequisites-in-makefile
# https://www.gnu.org/software/make/manual/make.html#Secondary-Expansion
.SECONDEXPANSION:

# *** atom src ***
SRC_libft = $(wildcard src/utils/libft/*.c)
SRC_math = $(wildcard src/utils/math/*.c)
SRC_get_next_line = $(wildcard src/input/get_next_line/*.c)

# *** composed src ***
SRC_linalg = $(wildcard src/utils/linalg/*.c)
SRC_load = $(wildcard src/input/load/*.c)
SRC_table = $(wildcard src/input/table/*.c)

SRC_convolve = $(wildcard src/editor/convolve/*.c)
SRC_copy = $(wildcard src/editor/copy/*.c)
SRC_mathart = $(wildcard src/editor/mathart/*/*.c)
SRC_paint = $(wildcard src/editor/paint/*.c)

SRC_triangle_pair = $(wildcard src/geometry/triangle_pair/*.c)
SRC_triangle_arr = $(wildcard src/geometry/triangle_arr/*.c)

#-----------------------------------------------------------------------------------------------
# *** elementary bin ***
BIN_libft = $(patsubst src/%.c, bin/%.o, $(SRC_libft))
BIN_math = $(patsubst src/%.c, bin/%.o, $(SRC_math))
BIN_get_next_line = $(patsubst src/%.c, bin/%.o, $(SRC_get_next_line))

# *** composed bin ***
BIN_linalg = $(patsubst src/%.c, bin/%.o, $(SRC_linalg)) $(BIN_math)
BIN_load = $(patsubst src/%.c, bin/%.o, $(SRC_load)) $(BIN_libft) $(BIN_get_next_line)
BIN_table = $(patsubst src/%.c, bin/%.o, $(SRC_table)) $(BIN_load) $(BIN_math)

BIN_convolve = $(patsubst src/%.c, bin/%.o, $(SRC_convolve)) $(BIN_table) $(BIN_linalg)
BIN_copy = $(patsubst src/%.c, bin/%.o, $(SRC_copy))
BIN_mathart = $(patsubst src/%.c, bin/%.o, $(SRC_mathart)) $(BIN_table)
BIN_paint = $(patsubst src/%.c, bin/%.o, $(SRC_paint)) $(BIN_table)

BIN_triangle_pair = $(patsubst src/%.c, bin/%.o, $(SRC_triangle_pair)) $(BIN_libft) $(BIN_linalg)
BIN_triangle_arr = $(patsubst src/%.c, bin/%.o, $(SRC_triangle_arr)) $(BIN_triangle_pair)

#-----------------------------------------------------------------------------------------------
# *** coding coding_examples src ***
EXAMPLE_SRC_TRIANGLES = $(wildcard coding_examples/src/geometry/*/*.c)
EXAMPLE_BIN_TRIANGLES = $(patsubst coding_examples/src/%.c, coding_examples/bin/%.out, $(EXAMPLE_SRC_TRIANGLES))
EXAMPLE_SRC_PAINT = $(wildcard coding_examples/src/editor/paint/*.c)
EXAMPLE_BIN_PAINT = $(patsubst coding_examples/src/%.c, coding_examples/bin/%.out, $(EXAMPLE_SRC_PAINT))
# https://stackoverflow.com/questions/10276202/exclude-source-file-in-compilation-using-makefile
EXAMPLE_SRC = $(filter-out $(EXAMPLE_SRC_PAINT) $(EXAMPLE_SRC_TRIANGLES), $(wildcard coding_examples/src/*/*/*.c))
EXAMPLE_BIN = $(patsubst coding_examples/src/%.c, coding_examples/bin/%.out, $(EXAMPLE_SRC))

#-----------------------------------------------------------------------------------------------
# *** coding unit_test src ***
TEST_SRC = $(wildcard unit_test/src/*/*/*.c)
TEST_BIN = $(patsubst unit_test/src/%.c, unit_test/bin/%.out, $(TEST_SRC))
TEST_HELPER_SRC = $(wildcard unit_test/test_helpers/*.c)
TEST_HELPER_BIN = $(patsubst unit_test/test_helpers/%.c, unit_test/bin/test_helpers/%.o, $(TEST_HELPER_SRC))

INPUT_CLONE_SRC = $(filter-out $(wildcard input_examples/font/*), $(wildcard input_examples/*/*))
INPUT_CLONE_SRC_FONT = $(wildcard input_examples/*/*/*)
INPUT_CLONE_BIN = $(patsubst input_examples/%, clone_examples/%, $(INPUT_CLONE_SRC) $(INPUT_CLONE_SRC_FONT))
INPUT_FDFASCII = $(patsubst input_examples/fdf/%.fdf, input_examples/ascii/%.txt, $(wildcard input_examples/fdf/*))

#-----------------------------------------------------------------------------------------------
# *** create unit_test ***

all_unit_tests: $(TEST_BIN) $(INPUT_CLONE_BIN) $(INPUT_FDFASCII)

$(TEST_BIN): unit_test/bin/%.out: lib/$$(call remove_slash,$$(dir $$*)).a lib/test_helper.a unit_test/bin/%.o
	@mkdir -p $(@D)
	$(CC) -o $@ $(filter %.o, $^) -L. $(filter %.a, $^)

unit_test/bin/%.o: unit_test/src/%.c
	@mkdir -p $(@D)
	$(CC) -c $< -o $@

lib/test_helper.a: $(TEST_HELPER_BIN) $(BIN_libft) $(BIN_get_next_line)
	@mkdir -p $(@D)
	ar rcs $@ $^

unit_test/bin/test_helpers/%.o: unit_test/test_helpers/%.c
	@mkdir -p $(@D)
	$(CC) -c $< -o $@

all_clone_examples: $(INPUT_CLONE_BIN)

all_fdfascii_examples: $(INPUT_FDFASCII)

input_examples/ascii/%.txt: input_examples/fdf/%.fdf
	@mkdir -p $(@D)
	touch $@

clone_examples/%: input_examples/%
	@mkdir -p $(@D)
	touch $@

#-----------------------------------------------------------------------------------------------
# *** create coding_examples ***

# https://www.gnu.org/software/make/manual/make.html#Static-Pattern
all_coding_examples: $(EXAMPLE_BIN) $(EXAMPLE_BIN_PAINT) $(EXAMPLE_BIN_TRIANGLES)

# https://stackoverflow.com/questions/519342/what-is-the-difference-between-i-and-l-in-makefile
# https://www.geeksforgeeks.org/c/how-to-create-a-static-library-in-c/
# https://youtu.be/3RmIVDgPmGk?si=IKgavhDbLhuG3TO8
# https://stackoverflow.com/questions/48549272/gnu-make-get-and-modify-target-name-in-prerequisites
# -L is the path to the directories containing the libraries. A search path for libraries.
# -l is the name of the library you want to link to.

$(EXAMPLE_BIN_PAINT): coding_examples/bin/%.out: lib/$$(call remove_slash,$$(dir $$*)).a lib/editor/mathart.a coding_examples/bin/%.o
	@mkdir -p $(@D)
	$(CC) -o $@ $(filter %.o, $^) -L. $(filter %.a, $^)

$(EXAMPLE_BIN_TRIANGLES): coding_examples/bin/%.out: lib/$$(call remove_slash,$$(dir $$*)).a lib/input/table.a coding_examples/bin/%.o
	@mkdir -p $(@D)
	$(CC) -o $@ $(filter %.o, $^) -L. $(filter %.a, $^)

$(EXAMPLE_BIN): coding_examples/bin/%.out: lib/$$(call remove_slash,$$(dir $$*)).a coding_examples/bin/%.o
	@mkdir -p $(@D)
	$(CC) -o $@ $(filter %.o, $^) -L. $(filter %.a, $^)

coding_examples/bin/%.o: coding_examples/src/%.c
	@mkdir -p $(@D)
	$(CC) -c $< -o $@

# *** create library ***
# ChatGPT recommended me this solution.
# The takes away is reading the functions for files name section of Makefile manual first
# (a.k.a. https://ftp.gnu.org/old-gnu/Manuals/make-3.79.1/html_node/make_79.html )
# if you have to manipulating the string of the files/folders name according to correct 
# format like this, for example you might want to split string as arrays of string,
# with `,` or `/` as the separators.
lib/%.a: $$(BIN_$$(notdir $$(basename $$@)))
	@mkdir -p $(@D)
	ar rcs $@ $^

# *** create object files. ***
# https://stackoverflow.com/questions/1950926/create-directories-using-make-file
bin/%.o: src/%.c
	@mkdir -p $(@D)
	$(CC) -c $< -o $@

bin/input/get_next_line/%.o: src/input/get_next_line/%.c
	@mkdir -p $(@D)
	$(CC) -D BUFFER_SIZE=$(BUFFER_SIZE) -c $< -o $@

# *** clean ***
# https://askubuntu.com/questions/802996/how-to-remove-directory-with-all-of-its-contents
clean:
	rm -r -f lib/
	rm -r -f bin/
	rm -r -f coding_examples/bin/
	rm -r -f unit_test/bin/
	rm -r -f clone_examples/
	rm -r -f input_examples/ascii/

clean_all_unit_tests:
	rm -r -f unit_test/bin/
	rm -r -f clone_examples/

clean_all_clone_examples:
	rm -r -f clone_examples/

clean_all_coding_examples:
	rm -r -f coding_examples/bin/

clean_all_fdfascii_examples:
	rm -r -f input_examples/ascii/

# Lol, both Makefile tutorial and Suisei already cover .PHONY
# https://youtu.be/N029UUlH1Dc?si=8PragRfDm3MzFOBc
.PHONY: all clean test clean_all_coding_examples all_coding_examples clean_all_unit_tests all_unit_tests clean_all_clone_examples all_clone_examples clean_all_fdfascii_examples
