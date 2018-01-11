LDFLAGS =  -lpthread -lm
CFLAGS = -Wall -Wextra -g

all:
	make exo1
	make exo2
	make exo3


exo1: exo1.o
	gcc -o exo1 exo1.o $(LDFLAGS)

exo1.o:
	gcc -o exo1.o -c exo1.c $(CFLAGS)

exo2: exo2.o
	gcc -o exo2 exo2.o $(LDFLAGS)

exo2.o:
	gcc -o exo2.o -c exo2.c $(CFLAGS)

exo3: exo3.o
	gcc -o exo3 exo3.o $(LDFLAGS)

exo3.o:
	gcc -o exo3.o -c exo3.c $(CFLAGS)


clean:
	rm -f *.o

mrproper:
	make clean
	rm -f exo1
	rm -f exo2
	rm -f exo3


