CC=mpicc
CFLAGS=-O3 -march=native 
OBJ=covid.o
LIBS=-lm

covid.x: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY:clean

clean:
	rm -f *.o *.x *.out *.dat *.csv output/*.csv *~ core
