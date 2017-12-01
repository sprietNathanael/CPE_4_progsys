CFLAGS = -Wall -Wextra -g
all: dijkstra.o log.o init clear P0 P1 P2

init: init.o
	gcc -o init init.o dijkstra.o log.o

clear: clear.o
	gcc -o clear clear.o dijkstra.o log.o

P0: P0.o
	gcc -o P0 P0.o dijkstra.o log.o

P1: P1.o
	gcc -o P1 P1.o dijkstra.o log.o

P2: P2.o
	gcc -o P2 P2.o dijkstra.o log.o

init.o: shared.h
	gcc -o init.o -c init.c $(CFLAGS)

clear.o: shared.h
	gcc -o clear.o -c clear.c $(CFLAGS)

P0.o: shared.h
	gcc -o P0.o -c P0.c $(CFLAGS)

P1.o: shared.h
	gcc -o P1.o -c P1.c $(CFLAGS)

P2.o: shared.h
	gcc -o P2.o -c P2.c $(CFLAGS)

dijkstra.o:
	cd dijkstra && make
	cp dijkstra/dijkstra.o .
	
log.o:
	cd log && make
	cp log/log.o .

clean:
	rm -f *.o
	cd dijkstra && make clean
	cd log && make clean

mrproper:
	make clean
	rm init
	rm clear
	rm P0
	rm P1
	rm P2

