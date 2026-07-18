# https://stackoverflow.com/questions/2206128/how-to-call-makefile-from-another-makefile

all:
	make -C src all
	make -C unit_test all

clean:
	make -C src clean
	make -C unit_test clean

# Lol, both Makefile tutorial and Suisei already cover .PHONY
# https://youtu.be/N029UUlH1Dc?si=8PragRfDm3MzFOBc
.PHONY: all clean
