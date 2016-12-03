#!/usr/bin/env python3

import random
import sys

MAX_NUMBER = 10**7


def randomMatrix(arg):
    matrix = list()
    for i in range(arg ** 2):
        matrix.append(str(random.uniform(-MAX_NUMBER, MAX_NUMBER)))
    result = ','.join(matrix) + '\n'
    return result


def main(size, filename='src/matrix_macros.txt'):
    with open(filename, 'w') as file:
        file.write('#define MATRIX_SIZE {}\n'.format(size))
        file.write('#define MATRIX_1 ')
        file.write(randomMatrix(size))
        file.write('#define MATRIX_2 ')
        file.write(randomMatrix(size))

if __name__ == '__main__':
    if len(sys.argv) == 3:
        main(int(sys.argv[1]), sys.argv[2])
    elif len(sys.argv) == 2:
        main(int(sys.argv[1]))
    else:
        main(512)
