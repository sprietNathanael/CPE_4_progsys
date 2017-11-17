LIB=../lib
BUILD=../build
BIN=..

all:
	make exo2_p1
	make exo2_p2

exo2_p2: exo2_p2.o djikstra.o
	gcc -o $(BIN)/exo2_p2 $(BUILD)/exo2_p2.o $(BUILD)/djikstra.o

exo2_p2.o: $(LIB)/djikstra/djikstra.h
	gcc -o $(BUILD)/exo2_p2.o -c exo2_p2.c -W -Wall

exo2_p1: exo2_p1.o djikstra.o
	gcc -o $(BIN)/exo2_p1 $(BUILD)/exo2_p1.o $(BUILD)/djikstra.o

exo2_p1.o: $(LIB)/djikstra/djikstra.h
	gcc -o $(BUILD)/exo2_p1.o -c exo2_p1.c -W -Wall

djikstra.o:
	make -C $(LIB)/djikstra
