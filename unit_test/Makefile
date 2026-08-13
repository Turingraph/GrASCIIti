#-----------------------------------------------------------------------------------------------
# *** src ***

CC = cc -Wall -Wextra -Werror
remove_slash = $(patsubst %/,%,$1)
# get_obj_files = $(filter %.o, $1)
# get_lib_a_files = $(filter %.a, $^)

SRC_get_next_line = $(wildcard input/get_next_line/*.c)
SRC_load = $(wildcard input/load/*.c)
SRC_table = $(wildcard input/table/*.c)
SRC_libft = $(wildcard utils/libft/*.c)
SRC_math = $(wildcard utils/math/*.c)
SRC_triangle_pair = $(wildcard graphic/triangle_pair/*.c)

SRC_HELPER_libft = $(wildcard ../src/utils/libft/*.c)
SRC_HELPER_get_next_line = $(wildcard ../src/input/get_next_line/*.c)
OBJ_HELPER_libft = $(patsubst ../src/%.c, ../src/obj/%.o, $(SRC_HELPER_libft))
OBJ_HELPER_get_next_line = $(patsubst ../src/%.c, ../src/obj/%.o, $(SRC_HELPER_get_next_line))

HELPER_SRC = $(wildcard test_helpers/*.c)
HELPER_OBJ = $(patsubst %.c, obj/%.o, $(HELPER_SRC))

OUT_ALL = $(patsubst %.c, out/%.out,	\
	$(SRC_get_next_line)	\
	$(SRC_load) $(SRC_table) $(SRC_libft) $(SRC_math))

OUT_triangle = $(patsubst %.c, out/%.out, $(SRC_triangle_pair))

#-----------------------------------------------------------------------------------------------
# *** get input file ***
INPUT_FDFASCII_DIR = ../input_examples/fdf_to_ascii/
OUTPUT_DIR = clone_examples/

INPUT = $(filter-out $(wildcard ../input_examples/font/*), $(wildcard ../input_examples/*/*))
INPUT_FONT = $(wildcard ../input_examples/*/*/*)
OUTPUT = $(patsubst ../input_examples/%, $(OUTPUT_DIR)%, $(INPUT) $(INPUT_FONT))
OUTPUT_FDFASCII = $(patsubst ../input_examples/fdf/%.fdf, $(INPUT_FDFASCII_DIR)%.txt, $(wildcard ../input_examples/fdf/*))

#-----------------------------------------------------------------------------------------------
# *** obj, out, and lib ***
all: all_out all_output

all_out: $(OUT_ALL) $(OUT_triangle)
	@echo $^

$(OUT_triangle): out/%.out: obj/%.o
	@mkdir -p $(@D)
	@echo Yorushika said that $^
	$(CC) -o $@ $^ -L. ../src/lib/debug.a ../src/lib/debug_triangle.a ../src/lib/$(notdir $(call remove_slash, $(dir $@))).a ../src/lib/table.a

$(OUT_ALL): out/%.out: obj/%.o
	@mkdir -p $(@D)
	$(CC) -o $@ $^ -L. ../src/lib/debug.a ../src/lib/$(notdir $(call remove_slash, $(dir $@))).a

obj/%.o: %.c
	@mkdir -p $(@D)
	$(CC) -c $< -o $@

#-----------------------------------------------------------------------------------------------
# *** create output file ***
all_output: $(OUTPUT) $(OUTPUT_FDFASCII)

$(INPUT_FDFASCII_DIR)%.txt: ../input_examples/fdf/%.fdf
	@mkdir -p $(@D)
	touch $@

$(OUTPUT_DIR)%: ../input_examples/%
	@mkdir -p $(@D)
	touch $@

#-----------------------------------------------------------------------------------------------
# *** clean ***
clean: clean_out
# clean: clean_out clean_output

clean_out:
	rm -r -f out/
	rm -r -f lib/
	rm -r -f obj/

clean_output:
	rm -r -f $(INPUT_FDFASCII_DIR)
	rm -r -f $(OUTPUT_DIR)

.PHONY: all all_out all_output clean clean_out clean_output
