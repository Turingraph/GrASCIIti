CC = cc -Wall -Wextra -Werror
BUFFER_SIZE = 42

# https://stackoverflow.com/questions/2483182/recursive-wildcards-in-gnu-make
SRC_01_MATH = $(wildcard src/utils/math/*)
SRC_01_LIBFT = $(wildcard src/utils/libft/*)
SRC_01_GNL = $(wildcard src/input/get_next_line/*.c)
SRC_02_LOAD = $(wildcard src/input/load/*.c)
SRC_02_TABLE = $(wildcard src/input/table/*.c)
SRC_02_SYNESTHESIA = $(wildcard src/input/synesthesia/*.c)
SRC_02_PAINT = $(wildcard src/editor/paint/*.c)
SRC_02_CONVOLUTION = $(wildcard src/editor/convolution/*.c)
SRC_02_TRIANGLE_ARR = $(wildcard src/graphic/triangle_arr/*.c)
SRC_02_TRIANGLE_PAIR = $(wildcard src/graphic/triangle_pair/*.c)

BUILD_01_MATH = $(patsubst src/%.c, build/%.o, $(SRC_01_MATH))
BUILD_01_LIBFT = $(patsubst src/%.c, build/%.o, $(SRC_01_LIBFT))
BUILD_01_GNL = $(patsubst src/%.c, build/%.o, $(SRC_01_GNL))
BUILD_02_LOAD = $(patsubst src/%.c, build/%.o, $(SRC_02_LOAD)) $(BUILD_01_LIBFT) $(BUILD_01_GNL)
BUILD_02_TABLE = $(patsubst src/%.c, build/%.o, $(SRC_02_TABLE)) $(BUILD_01_LIBFT) $(BUILD_01_MATH)
BUILD_02_SYNESTHESIA = $(patsubst src/%.c, build/%.o, $(SRC_02_SYNESTHESIA)) $(BUILD_01_LIBFT) $(BUILD_01_GNL)
BUILD_02_PAINT = $(patsubst src/%.c, build/%.o, $(SRC_02_PAINT)) $(BUILD_01_LIBFT) $(BUILD_01_MATH)
BUILD_02_CONVOLUTION = $(patsubst src/%.c, build/%.o, $(SRC_02_CONVOLUTION)) $(BUILD_02_TABLE)
BUILD_02_TRIANGLE_PAIR = $(patsubst src/%.c, build/%.o, $(SRC_02_TRIANGLE_PAIR)) $(BUILD_01_LIBFT) $(BUILD_01_MATH)
BUILD_02_TRIANGLE_ARR = $(patsubst src/%.c, build/%.o, $(SRC_02_TRIANGLE_ARR)) $(BUILD_02_TRIANGLE_PAIR) $(BUILD_01_LIBFT) $(BUILD_01_MATH)

#----------------------------------------------------------------------------------
# create testing file

test/bin/graphic/triangle_arr.out: lib/graphic/triangle_arr.a lib/input/load.a lib/input/table.a
	@mkdir -p $(@D)
	$(CC) $(patsubst test/bin/%.out, test/src/%.c, $@) $^ -o $@
	chmod +x $@

test/bin/graphic/triangle_pair.out: lib/graphic/triangle_pair.a lib/input/load.a lib/input/table.a
	@mkdir -p $(@D)
	$(CC) $(patsubst test/bin/%.out, test/src/%.c, $@) $^ -o $@
	chmod +x $@

test/bin/editor/convolution.out: lib/editor/convolution.a lib/input/load.a
	@mkdir -p $(@D)
	$(CC) $(patsubst test/bin/%.out, test/src/%.c, $@) $^ -o $@
	chmod +x $@

test/bin/editor/paint.out: lib/editor/paint.a lib/input/table.a lib/input/load.a
	@mkdir -p $(@D)
	$(CC) $(patsubst test/bin/%.out, test/src/%.c, $@) $^ -o $@
	chmod +x $@

test/bin/input/table.out: lib/input/table.a lib/input/load.a
	@mkdir -p $(@D)
	$(CC) $(patsubst test/bin/%.out, test/src/%.c, $@) $^ -o $@
	chmod +x $@

test/bin/input/synesthesia.out: lib/input/synesthesia.a
	@mkdir -p $(@D)
	$(CC) $(patsubst test/bin/%.out, test/src/%.c, $@) $^ -o $@
	chmod +x $@

test/bin/input/load.out: lib/input/load.a
	@mkdir -p $(@D)
	$(CC) $(patsubst test/bin/%.out, test/src/%.c, $@) $^ -o $@
	chmod +x $@

test/bin/input/get_next_line.out: lib/input/get_next_line.a
	@mkdir -p $(@D)
	$(CC) $(patsubst test/bin/%.out, test/src/%.c, $@) $^ -o $@
	chmod +x $@

test/bin/utils/libft.out: lib/utils/libft.a
	@mkdir -p $(@D)
	$(CC) $(patsubst test/bin/%.out, test/src/%.c, $@) $^ -o $@
	chmod +x $@

#----------------------------------------------------------------------------------
# create library

lib/graphic/triangle_arr.a: $(BUILD_02_TRIANGLE_ARR)
	@mkdir -p $(@D)
	ar rcs $@ $^

lib/graphic/triangle_pair.a: $(BUILD_02_TRIANGLE_PAIR)
	@mkdir -p $(@D)
	ar rcs $@ $^

lib/editor/convolution.a: $(BUILD_02_CONVOLUTION)
	@mkdir -p $(@D)
	ar rcs $@ $^

lib/editor/paint.a: $(BUILD_02_PAINT)
	@mkdir -p $(@D)
	ar rcs $@ $^

lib/input/synesthesia.a: $(BUILD_02_SYNESTHESIA)
	@mkdir -p $(@D)
	ar rcs $@ $^

lib/input/table.a: $(BUILD_02_TABLE)
	@mkdir -p $(@D)
	ar rcs $@ $^

lib/input/load.a: $(BUILD_02_LOAD)
	@mkdir -p $(@D)
	ar rcs $@ $^

lib/input/get_next_line.a: $(BUILD_01_GNL)
	@mkdir -p $(@D)
	ar rcs $@ $^

lib/utils/libft.a: $(BUILD_01_LIBFT)
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
