exo1:
	make exo1_t1
	make exo1_t2

exo1_t2: exo1_t2.o djikstra.o
	gcc -o exo1_t2 exo1_t2.o djikstra/djikstra.o

exo1_t2.o: djikstra/djikstra.h
	gcc -o exo1_t2.o -c exo1_t2.c -W -Wall

exo1_t1: exo1_t1.o djikstra.o
	gcc -o exo1_t1 exo1_t1.o djikstra/djikstra.o

exo1_t1.o: djikstra/djikstra.h
	gcc -o exo1_t1.o -c exo1_t1.c -W -Wall

djikstra.o:
	# cd djikstra; make
	make -C djikstra

clean:
	rm -f *.o
	rm -f exo1_t1
	rm -f exo1_t2
	rm -f djikstra/*.o