CC=gcc
CFLAGS=-Wall -std=c99
SRCDIR=src
INCLUDEDIR=src/include

debug:clean
	$(CC) $(CFLAGS) -g -Wextra $(SRCDIR)/*.c $(INCLUDEDIR)/*.c
stable:clean
	$(CC) $(CFLAGS) $(SRCDIR)/*.c $(INCLUDEDIR)/*.c
clean:
	rm -vfr *~ a.out
