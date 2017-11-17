exo1_t1: exo1_t1.o djikstra.o
	gcc -o exo1_t1 exo1_t1.o djikstra.o

exo1_t1.o: djikstra/djikstra.h
	gcc -o exo1_t1.o -c exo1_t1.c -W -Wall

djikstra.o:
	cd djikstra; make
	# make -f djikstra/Makefile

clean:
	rm -f exo1_t1/*.o
	rm -f djikstra/*.o