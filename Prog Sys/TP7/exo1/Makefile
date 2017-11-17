LIB=../lib
BUILD=../build
BIN=..

all:
	make exo1_t1
	make exo1_t2

exo1_t2: exo1_t2.o djikstra.o
	gcc -o $(BIN)/exo1_t2 $(BUILD)/exo1_t2.o $(BUILD)/djikstra.o

exo1_t2.o: $(LIB)/djikstra/djikstra.h
	gcc -o $(BUILD)/exo1_t2.o -c exo1_t2.c -W -Wall

exo1_t1: exo1_t1.o djikstra.o
	gcc -o $(BIN)/exo1_t1 $(BUILD)/exo1_t1.o $(BUILD)/djikstra.o

exo1_t1.o: $(LIB)/djikstra/djikstra.h
	gcc -o $(BUILD)/exo1_t1.o -c exo1_t1.c -W -Wall

djikstra.o:
	make -C $(LIB)/djikstra
