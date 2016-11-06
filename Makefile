CC=gcc
CFLAGS=-Wall -std=c99
SRCDIR=src

debug:clean
	$(CC) $(CFLAGS) -g -Wextra $(SRCDIR)/*.c
stable:clean
	$(CC) $(CFLAGS) $(SRCDIR)/*.c
clean:
	rm -vfr *~ a.out
