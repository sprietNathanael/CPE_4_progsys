CFLAGS = -Wall -Wextra -g
all: dijkstra.o log.o init clear server

init: init.o
	gcc -o init init.o dijkstra.o log.o

clear: clear.o
	gcc -o clear clear.o dijkstra.o log.o

server: server.o
	gcc -o server server.o dijkstra.o log.o


init.o: shared.h
	gcc -o init.o -c init.c $(CFLAGS)

clear.o: shared.h
	gcc -o clear.o -c clear.c $(CFLAGS)

server.o: shared.h
	gcc -o server.o -c server.c $(CFLAGS)


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
	rm server

