CC = gcc
CFLAGS = -Wall -std=c99 -g
srcdir = src
SRC = $(wildcard $(srcdir)/*.c)
OBJ = $(SRC:%.c=%.o)

NAME = a.out
MAT_SIZE = 1000

default: $(NAME)

a.out: $(OBJ)
	$(CC) $(OBJ) -o $@

$(OBJ): $(srcdir)/include/Matrix.h

$(srcdir)/main.o: $(srcdir)/example_matrices.h

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(srcdir)/example_matrices.h:
	src/create_random_matrix.py $(MAT_SIZE) $(srcdir)/

.PHONY: clean
clean:
	rm -vfr *~ $(NAME) $(srcdir)/example_matrices.h *.o $(OBJ)
