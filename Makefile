CC = gcc
CFLAGS = -Wall -std=c99 -fopenmp -O2
LDFLAGS = $(CFLAGS)
srcdir = src
SRC = $(wildcard $(srcdir)/*.c)
OBJ = $(SRC:%.c=%.o)

NAME = a.out
MAT_SIZE = 512

default: $(NAME)

a.out: $(OBJ)
	$(CC) $(LDFLAGS) $(OBJ) -o $@

$(OBJ): $(srcdir)/include/Matrix.h

$(srcdir)/main.o: $(srcdir)/matrix_macros.txt

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(srcdir)/matrix_macros.txt:
	python3 bin/create_random_matrix.py $(MAT_SIZE)

.PHONY: clean
clean:
	rm -vfr *~ $(NAME) $(srcdir)/*.txt *.o $(OBJ)
