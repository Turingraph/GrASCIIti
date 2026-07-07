# *** COMMAND ***

CC = cc -Wall -Wextra -Werror
BUFFER_SIZE = 42

# https://stackoverflow.com/questions/2483182/recursive-wildcards-in-gnu-make
rwildcard=$(foreach d,$(wildcard $(1 =/*)),$(call rwildcard,$d,$2) $(filter $(subst *,%,$2),$d))

CODING_EXAMPLES = coding_examples/

# https://stackoverflow.com/questions/9488256/use-directory-path-of-target-in-list-of-prerequisites-in-makefile
# https://www.gnu.org/software/make/manual/make.html#Secondary-Expansion
.SECONDEXPANSION:

# *** elementary ***
SRC_libft = $(wildcard src/utils/libft/*)
SRC_math = $(wildcard src/utils/math/*)
SRC_gnl = $(wildcard src/input/get_next_line/*)

# *** not elementary ***
SRC_linalg = $(wildcard src/utils/linalg/*)
SRC_load = $(wildcard src/input/load/*)
SRC_table = $(wildcard src/input/table/*)

SRC_convolution = $(wildcard src/editor/convolution/*)
SRC_mathart = $(rwildcard,src/editor/mathart,*c)
SRC_paint = $(wildcard src/editor/paint/*)

SRC_triangle_pair = $(wildcard src/geometry/triangle_pair/*)
SRC_triangle_arr = $(wildcard src/geometry/triangle_arr/*)

# *** elementary ***
BUILD_libft = $(patsubst src/%.c, build/%.o, $(SRC_libft))
BUILD_math = $(patsubst src/%.c, build/%.o, $(SRC_math))
BUILD_gnl = $(patsubst src/%.c, build/%.o, $(SRC_gnl))

# *** not elementary ***
BUILD_linalg = $(patsubst src/%.c, build/%.o, $(SRC_linalg)) $(BUILD_math)
BUILD_load = $(patsubst src/%.c, build/%.o, $(SRC_load)) $(BUILD_libft) $(BUILD_gnl)
BUILD_table = $(patsubst src/%.c, build/%.o, $(SRC_table)) $(BUILD_load) $(BUILD_math)

BUILD_convolution = $(patsubst src/%.c, build/%.o, $(SRC_convolution)) $(BUILD_table)
BUILD_mathart = $(patsubst src/%.c, build/%.o, $(SRC_mathart)) $(BUILD_table)
BUILD_paint = $(patsubst src/%.c, build/%.o, $(SRC_paint)) $(BUILD_table)

BUILD_triangle_pair = $(patsubst src/%.c, build/%.o, $(SRC_triangle_pair)) $(BUILD_libft) $(BUILD_linalg)
BUILD_triangle_arr = $(patsubst src/%.c, build/%.o, $(SRC_triangle_arr)) $(BUILD_triangle_pair)

# *** create unit_test ***

# *** create coding_examples ***

coding_examples/bin/geometry/triangle_pair/%.out: lib/geometry/triangle_pair.a lib/input/table.a
	@mkdir -p $(@D)
	$(CC) $(patsubst $(CODING_EXAMPLES)bin/%.out, $(CODING_EXAMPLES)src/%.c, $@) $^ -o $@
	chmod +x $@

# https://stackoverflow.com/questions/25589586/why-does-patsubst-stop-working-when-using-secondary-expansion-of

# Fix this.
coding_examples/bin/%.out: $$(dir $$@)
	echo lib/$(patsubst coding_examples/bin/%/,%,$^).a
# 	@echo lib/$(patsubst coding_examples/bin/%/,%,$(dir $@)).a
# 	@echo lib/$(notdir $(patsubst %/,%,$(dir $@))).a
# 	@mkdir -p $(@D)

# LIB_PATH = $(dir $(dir $@:%/=%))
# LIB := $(LIB_PATH:%/=%).a
# coding_examples/bin/%.out:
# 	@echo $(LIB_PATH)
# 	@echo lib/$(notdir $(patsubst %/,%,$(dir $@))).a

# https://stackoverflow.com/questions/9488256/use-directory-path-of-target-in-list-of-prerequisites-in-makefile

# lib/$(patsubst coding_examples/bin/%/, lib/%.a, $(dir $@)).a

# Search Idea
# 1.	makefile remove prefix of prerequisite

# coding_examples/bin/%.out: $$(subst coding_examples/bin/$%,lib/$%.a,$$(dir $$@))
# 	echo $^
# 	@mkdir -p $(@D)
# 	$(CC) $(patsubst $(CODING_EXAMPLES)bin/%.out, $(CODING_EXAMPLES)src/%.c, $@) $^ -o $@
# 	chmod +x $@

# *** create library ***

# my previous solution

# lib/%.a: $$(BUILD_$(patsubst $(@D)/%.a,%,$@))
# 	echo $$(BUILD_$(patsubst $(@D)/%.a,%,$@))
# 	@mkdir -p $(@D)
# 	ar rcs $@ $^

# ChatGPT said that my solution isn't working because $ inside
# BUILD_$(patsubst $(@D)/%.a,%,$@) is activated too early.
# The reason that echo print something is because
# Makefile create the variable name for Shell, but not for Makefile themselves.

# ChatGPT recommended me to use notdir and basename command.

# $(notdir names...)
# Extracts all but the directory-part of each file name in names. 
# If the file name contains no slash, it is left unchanged. 

# $(basename names...)
# extracts all but the suffix of each file name in names.

# Even if my solution were working correctly, 
# ChatGPT solution in this case work better because 
# it use shortcut from notdir and basename command, which improve readability,
# and thus easier to maintain.

# The takes away is reading the functions for files name section of Makefile manual first
# (a.k.a. https://ftp.gnu.org/old-gnu/Manuals/make-3.79.1/html_node/make_79.html )
# if you have to manipulating the string of the files/folders name according to correct 
# format like this, for example you might want to split string as arrays of string,
# with `,` or `/` as the separators.

lib/%.a: $$(BUILD_$$(notdir $$(basename $$@)))
	echo $^
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
	rm -r lib/
	rm -r build/
	rm -r $(CODING_EXAMPLES)bin/

clean_coding_examples:
	rm -r $(CODING_EXAMPLES)bin/

.PHONY: all clean test clean_coding_examples

# To Do Now
# Read this. https://stackoverflow.com/questions/25589586/why-does-patsubst-stop-working-when-using-secondary-expansion-of
