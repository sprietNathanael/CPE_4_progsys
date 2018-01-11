LDFLAGS =  -lpthread
CFLAGS = -Wall -Wextra -g

all:
	make exo1
	make exo2
	make exo3
	make exo4
	make exo4_bis
	make exo5

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

exo4: exo4.o
	gcc -o exo4 exo4.o $(LDFLAGS)

exo4.o:
	gcc -o exo4.o -c exo4.c $(CFLAGS)

exo4_bis: exo4_bis.o
	gcc -o exo4_bis exo4_bis.o $(LDFLAGS)

exo4_bis.o:
	gcc -o exo4_bis.o -c exo4_bis.c $(CFLAGS)

exo5: exo5.o
	gcc -o exo5 exo5.o $(LDFLAGS)

exo5.o:
	gcc -o exo5.o -c exo5.c $(CFLAGS)

clean:
	rm -f *.o

mrproper:
	make clean
	rm -f exo1
	rm -f exo2
	rm -f exo3
	rm -f exo4
	rm -f exo4_bis
	rm -f exo5

