CC = gcc
CFLAGS = -Wall -std=c99 -O2
srcdir = src
SRC = $(wildcard $(srcdir)/*.c)
OBJ = $(SRC:%.c=%.o)

NAME = a.out
MAT_SIZE = 1024

default: $(NAME)

a.out: $(OBJ)
	$(CC) $(OBJ) -o $@

$(OBJ): $(srcdir)/include/Matrix.h

$(srcdir)/main.o: $(srcdir)/matrix_macros.txt

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(srcdir)/matrix_macros.txt:
	python3 bin/create_random_matrix.py $(MAT_SIZE)

.PHONY: clean
clean:
	rm -vfr *~ $(NAME) $(srcdir)/*.txt *.o $(OBJ)
