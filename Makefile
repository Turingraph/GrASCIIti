# ChatGPT recommended me this practice instead of repeating call Make command manually.
SUBDIRS = src unit_test coding_examples

all clean:
	for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir $@; \
	done

.PHONY: all clean
