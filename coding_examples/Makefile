#-----------------------------------------------------------------------------------------------
# *** coding coding_examples src ***

CC = cc -Wall -Wextra -Werror
remove_slash = $(patsubst %/,%,$1)
# get_obj_files = $(filter %.o, $1)
# get_lib_a_files = $(filter %.a, $^)

.SECONDEXPANSION:

OUT_DIR = out/
SRC_VIEW = $(wildcard graphic/view/*.c)
OUT_VIEW = $(patsubst %.c, $(OUT_DIR)%.out, $(SRC_VIEW))
SRC_TRIANGLES = $(filter-out $(SRC_VIEW), $(wildcard graphic/*/*.c))
SRC_LINE = $(wildcard editor/line/*.c)
OUT_USE_TABLE = $(patsubst %.c, $(OUT_DIR)%.out, $(SRC_TRIANGLES) $(SRC_LINE))
SRC_PAINT = $(wildcard editor/paint/*.c)
OUT_PAINT = $(patsubst %.c, $(OUT_DIR)%.out, $(SRC_PAINT))
# https://stackoverflow.com/questions/10276202/exclude-source-file-in-compilation-using-makefile
SRC = $(filter-out $(SRC_PAINT) $(wildcard graphic/*/*.c) $(SRC_LINE), $(wildcard */*/*.c))
OUT = $(patsubst %.c, $(OUT_DIR)%.out, $(SRC))

#-----------------------------------------------------------------------------------------------
# *** obj and out ***
all: $(OUT) $(OUT_PAINT) $(OUT_USE_TABLE) $(OUT_VIEW)
	@echo $^

$(OUT_PAINT): out/%.out: obj/%.o
	@mkdir -p $(@D)
	$(CC) -o $@ $^ -L. ../src/lib/$(basename $(notdir $(call remove_slash, $(dir $@)).c)).a ../src/lib/mathart.a

$(OUT_USE_TABLE): out/%.out: obj/%.o
	@mkdir -p $(@D)
	$(CC) -o $@ $^ -L. ../src/lib/$(basename $(notdir $(call remove_slash, $(dir $@)).c)).a ../src/lib/table.a

$(OUT_VIEW): out/%.out: obj/%.o
	@mkdir -p $(@D)
	$(CC) -o $@ $^ -L. ../src/lib/$(basename $(notdir $(call remove_slash, $(dir $@)).c)).a \
		../src/lib/convolve.a ../src/lib/paint.a ../include/libmlx42.a -ldl -lglfw -pthread -lm

$(OUT): out/%.out: obj/%.o
	@mkdir -p $(@D)
	$(CC) -o $@ $^ -L. ../src/lib/$(basename $(notdir $(call remove_slash, $(dir $@)).c)).a

obj/%.o: %.c
	@mkdir -p $(@D)
	$(CC) -c $< -o $@

#-----------------------------------------------------------------------------------------------
# *** clean ***
clean:
	rm -r -f out/
	rm -r -f lib/
	rm -r -f obj/

.PHONY: all clean
