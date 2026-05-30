CC = cc -Wall -Wextra -Werror

LIB = $(SRC_DIR:src/%/=lib/%.a)
SRC_DIR = $(wildcard src/*/)
SRC_FILES = $(wildcard src/*/*.c)
SRC_FILES_GNL = $(wildcard src/get_next_line/*.c)
SRC_FILES_LIB = $(wildcard src/libft/*.c)
SRC_FILES_INT = $(wildcard src/input/*.c) $(SRC_FILES_GNL) $(SRC_FILES_LIB)
SRC_FILES_TAB = $(wildcard src/table/*.c)

BUILDS = $(patsubst src/%.c, build/%.o, $(SRC_FILES))
BUILDS_GNL = $(patsubst src/%.c, build/%.o, $(SRC_FILES_GNL))
BUILDS_LIB = $(patsubst src/%.c, build/%.o, $(SRC_FILES_LIB))
BUILDS_INT = $(patsubst src/%.c, build/%.o, $(SRC_FILES_INT)) $(BUILDS_GNL) $(BUILDS_LIB)
BUILDS_TAB = $(patsubst src/%.c, build/%.o, $(SRC_FILES_TAB)) $(BUILDS_LIB)
BUFFER_SIZE = 42

#----------------------------------------------------------------------------------
# create testing file

test/bin/%.out: lib/%.a
	$(CC) $(patsubst test/bin/%.out, test/src/%.c, $@) $< -o $@

test/bin/table.out: lib/table.a lib/input.a
	$(CC) $(patsubst test/bin/%.out, test/src/%.c, $@) $^ -o $@

#----------------------------------------------------------------------------------
# create library

lib/input.a: $(BUILDS_INT)
	ar rcs $@ $^

lib/table.a: $(BUILDS_TAB)
	ar rcs $@ $^

lib/get_next_line.a: $(BUILDS_GNL)
	ar rcs $@ $^

lib/libft.a: $(BUILDS_LIB)
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
