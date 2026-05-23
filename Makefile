
NAME = fdf.a
CC = cc -Wall -Wextra -Werror
SRC = src/
BUILD = build/
BIN = bin/
TEST = test.c

#----------------------------------------------------------------------------------

# ATOMIC LIBRARY

DIR_GNL = get_next_line/
OBJ_GNL := get_next_line.o utils.o
BUILD_GNL = $(OBJ_GNL:%.o=$(BUILD)$(DIR_GNL)%.o)
LIB_GNL = lib/get_next_line.a
BIN_GNL = $(BIN)get_next_line.out
BUFFER_SIZE = 1

DIR_LIB = libft/
OBJ_LIB := arr.o atoi.o putnbr_fd.o split.o
BUILD_LIB = $(OBJ_LIB:%.o=$(BUILD)$(DIR_LIB)%.o)
LIB_LIB = lib/libft.a
BIN_LIB = $(BIN)libft.out

#----------------------------------------------------------------------------------

# INPUT = input/
# MESH = mesh/
# SYNESTHESIA = synesthesia/

# SUB_DIR = $(GET_NEXT_LINE) $(INPUT) $(LIBFT) $(MESH) $(SYNESTHESIA)

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
	rm -f $(BIN_GNL) $(BIN_LIB)

fclean: clean
	rm -f $(LIB_GNL) $(LIB_LIB)

clean:
	rm -f $(BUILD_GNL) $(BUILD_LIB)

re: binclean fclean clean $(BIN_GNL) $(BIN_LIB) all

.PHONY: re all clean fclean binclean

#----------------------------------------------------------------------------------

# REFERENCE

# https://stackoverflow.com/questions/1139271/
# makefiles-with-source-files-in-different-directories
