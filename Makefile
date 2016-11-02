CC=gcc
CFLAGS="-Wall"

debug:clean
	$(CC) $(CFLAGS) -g -o matrixmultiplikation main.c
stable:clean
	$(CC) $(CFLAGS) -o matrixmultiplikation main.c
clean:
	rm -vfr *~ matrixmultiplikation
