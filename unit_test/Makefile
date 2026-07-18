#-----------------------------------------------------------------------------------------------
# *** src ***

CC = cc -Wall -Wextra -Werror
remove_slash = $(patsubst %/,%,$1)
get_obj_files = $(filter %.o, $1)
get_lib_a_files = $(filter %.a, $^)

# SRC_line = $(wildcard src/editor/line/*.c)
SRC_get_next_line = $(wildcard src/input/get_next_line/*.c)
SRC_load = $(wildcard src/input/load/*.c)
SRC_table = $(wildcard src/input/table/*.c)
SRC_libft = $(wildcard src/utils/libft/*.c)
SRC_math = $(wildcard src/utils/math/*.c)
SRC_line = $(wildcard src/editor/line/*.c)

SRC_HELPER_libft = $(wildcard ../src/utils/libft/*.c)
SRC_HELPER_get_next_line = $(wildcard ../src/input/get_next_line/*.c)
OBJ_HELPER_libft = $(patsubst ../src/%.c, ../src/obj/%.o, $(SRC_HELPER_libft))
OBJ_HELPER_get_next_line = $(patsubst ../src/%.c, ../src/obj/%.o, $(SRC_HELPER_get_next_line))

HELPER_SRC = $(wildcard test_helpers/*.c)
HELPER_OBJ = $(patsubst %.c, obj/%.o, $(HELPER_SRC))

OUT_ALL = $(patsubst src/%.c, out/%.out,	\
	$(SRC_get_next_line)	\
	$(SRC_load) $(SRC_table) $(SRC_libft) $(SRC_math))
OUT_LINE = $(patsubst src/%.c, out/%.out, $(SRC_line))

#-----------------------------------------------------------------------------------------------
# *** get input file ***
INPUT_LINE_DIR = ../input_examples/line/
INPUT_FDFASCII_DIR = ../input_examples/fdf_to_ascii/
OUTPUT_DIR = clone_examples/

INPUT = $(filter-out $(wildcard ../input_examples/font/*), $(wildcard ../input_examples/*/*))
INPUT_FONT = $(wildcard ../input_examples/*/*/*)
OUTPUT_LINE = $(addprefix $(INPUT_LINE_DIR)line_, 0 1 2 3 4 5 6 7);
OUTPUT = $(patsubst ../input_examples/%, $(OUTPUT_DIR)%, $(INPUT) $(INPUT_FONT))
OUTPUT_FDFASCII = $(patsubst ../input_examples/fdf/%.fdf, $(INPUT_FDFASCII_DIR)%.txt, $(wildcard ../input_examples/fdf/*))

#-----------------------------------------------------------------------------------------------
# *** obj, out, and lib ***
all: all_out all_output

all_out: $(OUT_ALL) $(OUT_LINE)
	@echo $^

$(OUT_ALL): out/%.out: lib/test_helpers.a obj/%.o
	@mkdir -p $(@D)
	$(CC) -o $@ $(call get_obj_files, $^) -L. $(call get_lib_a_files, $^) ../src/lib/$(basename $(notdir $(call remove_slash, $(dir $@)).c)).a

$(OUT_LINE): out/%.out: obj/%.o ../src/lib/table.a
	@mkdir -p $(@D)
	@echo Nujabes Yoasobi Wasabi
	$(CC) -o $@ $(call get_obj_files, $^) -L. $(call get_lib_a_files, $^) ../src/lib/$(basename $(notdir $(call remove_slash, $(dir $@)).c)).a ../src/lib/table.a

lib/test_helpers.a: $(HELPER_OBJ)
	@mkdir -p $(@D)
	ar rcs $@ $^ $(OBJ_HELPER_libft) $(OBJ_HELPER_get_next_line)

obj/test_helpers/%.o: test_helpers/%.c
	@mkdir -p $(@D)
	$(CC) -c $< -o $@

obj/%.o: src/%.c
	@mkdir -p $(@D)
	$(CC) -c $< -o $@

#-----------------------------------------------------------------------------------------------
# *** create output file ***
all_output: $(OUTPUT) $(OUTPUT_FDFASCII)
	@mkdir -p $(INPUT_LINE_DIR)
	touch $(OUTPUT_LINE)

$(INPUT_FDFASCII_DIR)%.txt: ../input_examples/fdf/%.fdf
	@mkdir -p $(@D)
	touch $@

$(OUTPUT_DIR)%: ../input_examples/%
	@mkdir -p $(@D)
	touch $@

#-----------------------------------------------------------------------------------------------
# *** clean ***
clean: clean_out clean_output

clean_out:
	rm -r -f out/
	rm -r -f lib/
	rm -r -f obj/

clean_output:
	rm -r -f $(INPUT_FDFASCII_DIR)
	rm -r -f $(OUTPUT_DIR)
	rm -r -f $(INPUT_LINE_DIR)

.PHONY: all all_out all_output clean clean_out clean_output
