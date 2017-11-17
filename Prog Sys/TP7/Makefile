LIB=lib
BUILD=build

all:
	make exercice1
	make exercice2

exercice1:
	make -C ./exo1

exercice2:
	make -C ./exo2

djikstra.o:
	make -C $(LIB)/djikstra

clean:
	rm -f $(BUILD)/*.o

mrproper:
	make clean
	rm -f exo1_t1
	rm -f exo1_t2
	rm -f exo2_p2
	rm -f exo2_p2
