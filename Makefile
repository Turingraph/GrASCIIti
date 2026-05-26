
NAME = fdf.a
CC = cc -Wall -Wextra -Werror
SRC = src/
BUILD = build/
BIN = bin/
LIB = lib/
TEST = test.c

#----------------------------------------------------------------------------------

# ATOM LIBRARY

NAME_GNL = get_next_line
DIR_GNL = $(NAME_GNL)/
OBJ_GNL := get_next_line.o utils.o
BUILD_GNL = $(OBJ_GNL:%.o=$(BUILD)$(DIR_GNL)%.o)
LIB_GNL = $(LIB)$(NAME_GNL).a
BIN_GNL = $(BIN)$(NAME_GNL).out
BUFFER_SIZE = 41

NAME_LIB = libft
DIR_LIB = $(NAME_LIB)/
OBJ_LIB := arr.o atoi.o split.o utils.o
BUILD_LIB = $(OBJ_LIB:%.o=$(BUILD)$(DIR_LIB)%.o)
LIB_LIB = $(LIB)$(NAME_LIB).a
BIN_LIB = $(BIN)$(NAME_LIB).out

#----------------------------------------------------------------------------------

# MOLECULE LIBRARY

NAME_INP = input
DIR_INP = $(NAME_INP)/
OBJ_INP = all_lines.o ascii.o fdf.o table.o
BUILD_INP = $(OBJ_INP:%.o=$(BUILD)$(DIR_INP)%.o)
LIB_INP = $(LIB)$(NAME_INP).a
BIN_INP = $(BIN)$(NAME_INP).out

#----------------------------------------------------------------------------------

# CREATING MAIN LIBRARY

SUB_DIR = $(DIR_GNL) $(DIR_LIB)

all: $(NAME)

# $@ = $(NAME)
# $^ = $(BUILD_LIB) $(BUILD_GNL)
$(NAME): $(BUILD_LIB) $(BUILD_GNL)
	echo $@

# 	ar rcs $@ $^

#----------------------------------------------------------------------------------

# *** PROBLEM ! ***
# /usr/bin/ld: test.c:(.text+0x115): undefined reference to `ft_putnbr_fd' and many other undefined reference.
# so I cannot test if src/input/test.c works as expected or not.
$(BIN_INP): $(LIB_INP)
	$(CC) $(SRC)$(DIR_INP)$(TEST) $^ -o $@

$(LIB_INP): $(BUILD_INP)
	ar rcs $@ $^

$(BUILD)$(DIR_INP)%.o: $(SRC)$(DIR_INP)%.c 
	$(CC) -c $^ -L$(LIB_LIB) -l$(NAME_LIB).h $(LIB_GNL) -l$(NAME_GNL) -o $@

#----------------------------------------------------------------------------------

# CREATING ATOMIC LIBRARY

$(BIN_LIB): $(LIB_LIB)
	$(CC) $(SRC)$(DIR_LIB)$(TEST) $^ -o $@

$(BIN_GNL): $(LIB_GNL)
	$(CC) $(SRC)$(DIR_GNL)$(TEST) $^ -o $@

$(LIB_GNL): $(BUILD_GNL)
	ar rcs $@ $^

$(LIB_LIB): $(BUILD_LIB)
	ar rcs $@ $^

# $@ = %.o
# $^ = %.c

$(BUILD)$(DIR_GNL)%.o: $(SRC)$(DIR_GNL)%.c
	$(CC) -D BUFFER_SIZE=$(BUFFER_SIZE) -c $^ -o $@

$(BUILD)$(DIR_LIB)%.o: $(SRC)$(DIR_LIB)%.c
	$(CC) -c $^ -o $@

#----------------------------------------------------------------------------------

# DELETE FILES

binclean:
	rm -f $(BIN_GNL) $(BIN_LIB) $(BIN_INP)

fclean: clean
	rm -f $(LIB_GNL) $(LIB_LIB) $(LIB_INP)

clean:
	rm -f $(BUILD_GNL) $(BUILD_LIB) $(BUILD_INT)

re: binclean fclean clean $(BIN_GNL) $(BIN_LIB) all

.PHONY: re all clean fclean binclean

# valgrind --leak-check=full 
# valgrind --leak-check=full bin/...out input0 input1 ... inputn build/..0.a build/..1.a ...

#----------------------------------------------------------------------------------

# REFERENCE

# https://stackoverflow.com/questions/1139271/
# makefiles-with-source-files-in-different-directories
