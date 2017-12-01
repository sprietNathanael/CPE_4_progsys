CFLAGS = -Wall -Wextra -g
all: dijkstra.o log.o init prod conso clear

init: init.o
	gcc -o init init.o dijkstra.o log.o

clear: clear.o
	gcc -o clear clear.o dijkstra.o log.o

conso: conso.o
	gcc -o conso conso.o dijkstra.o log.o

prod: prod.o
	gcc -o prod prod.o dijkstra.o log.o

init.o: shared.h
	gcc -o init.o -c init.c $(CFLAGS)

clear.o: shared.h
	gcc -o clear.o -c clear.c $(CFLAGS)

conso.o: shared.h
	gcc -o conso.o -c conso.c $(CFLAGS)

prod.o: shared.h
	gcc -o prod.o -c prod.c $(CFLAGS)

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
	rm prod
	rm conso
	rm init
	rm clear