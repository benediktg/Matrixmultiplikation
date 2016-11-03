CC=gcc
CFLAGS=-Wall -std=c99
SRCDIR=src
INCLUDEDIR=src/include

debug:clean
	$(CC) $(CFLAGS) -g -Wextra -I$(INCLUDEDIR) $(SRCDIR)/*.c
stable:clean
	$(CC) $(CFLAGS) -I$(INCLUDEDIR) $(SRCDIR)/*.c
clean:
	rm -vfr *~ a.out
