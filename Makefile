CC = cc -Wall -Wextra -Werror

LIB = $(SRC_DIR:src/%/=lib/%.a)
SRC_DIR = $(wildcard src/*/)
SRC_FILES = $(wildcard src/*/*.c)
SRC_FILES_GNL = $(wildcard src/get_next_line/*.c)
SRC_FILES_LIB = $(wildcard src/libft/*.c)
SRC_FILES_INT = $(wildcard src/input/*.c) $(SRC_FILES_GNL) $(SRC_FILES_LIB)
SRC_FILES_MATH = $(wildcard src/math/*.c)
SRC_FILES_TABLE = $(wildcard src/table/*.c)
SRC_FILES_PAINT = $(wildcard src/paint/*.c)
SRC_FILES_CONVOLUTION = $(wildcard src/convolution/*.c)

BUILDS = $(patsubst src/%.c, build/%.o, $(SRC_FILES))
BUILDS_GNL = $(patsubst src/%.c, build/%.o, $(SRC_FILES_GNL))
BUILDS_LIB = $(patsubst src/%.c, build/%.o, $(SRC_FILES_LIB))
BUILDS_MATH = $(patsubst src/%.c, build/%.o, $(SRC_FILES_MATH))
BUILDS_INT = $(patsubst src/%.c, build/%.o, $(SRC_FILES_INT)) $(BUILDS_GNL) $(BUILDS_LIB)
BUILDS_TABLE = $(patsubst src/%.c, build/%.o, $(SRC_FILES_TABLE)) $(BUILDS_LIB) $(BUILD_MATH)
BUILDS_PAINT = $(patsubst src/%.c, build/%.o, $(SRC_FILES_PAINT)) $(BUILDS_LIB) $(BUILD_MATH)
BUILDS_CONVOLUTION = $(patsubst src/%.c, build/%.o, $(SRC_FILES_CONVOLUTION)) $(BUILDS_TABLE) $(BUILD_MATH)
BUFFER_SIZE = 42

#----------------------------------------------------------------------------------
# create testing file

test/bin/%.out: lib/%.a
	$(CC) $(patsubst test/bin/%.out, test/src/%.c, $@) $< -o $@

test/bin/table.out: lib/table.a lib/input.a lib/math.a
	$(CC) $(patsubst test/bin/%.out, test/src/%.c, $@) $^ -o $@

test/bin/paint.out: lib/paint.a lib/table.a lib/input.a lib/math.a
	$(CC) $(patsubst test/bin/%.out, test/src/%.c, $@) $^ -o $@

test/bin/convolution.out: lib/table.a lib/input.a lib/convolution.a lib/math.a
	$(CC) $(patsubst test/bin/%.out, test/src/%.c, $@) $^ -o $@

#----------------------------------------------------------------------------------
# create library

lib/convolution.a: $(BUILDS_CONVOLUTION)
	ar rcs $@ $^

lib/input.a: $(BUILDS_INT)
	ar rcs $@ $^

lib/table.a: $(BUILDS_TABLE)
	ar rcs $@ $^

lib/paint.a: $(BUILDS_PAINT)
	ar rcs $@ $^

lib/get_next_line.a: $(BUILDS_GNL)
	ar rcs $@ $^

lib/libft.a: $(BUILDS_LIB)
	ar rcs $@ $^

lib/math.a: $(BUILDS_MATH)
	ar rcs $@ $^

#----------------------------------------------------------------------------------
# set buffer_size

build/get_next_line/%.o: src/get_next_line/%.c
	$(CC) -D BUFFER_SIZE=$(BUFFER_SIZE) -c $^ -o $@

#----------------------------------------------------------------------------------
# create object files.

# ChatGPT said that object compilation has exactly one source file.
# So I have to use $< instead of $^.
build/%.o: src/%.c
	$(CC) -c $< -o $@

#----------------------------------------------------------------------------------
# clean

fclean: clean
	rm -f $(LIB)

clean:
	rm -f $(BUILDS)

re: binclean fclean clean all

.PHONY: re all clean fclean test
