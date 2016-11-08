#!/usr/bin/env python3

import random
import sys

MAX_NUMBER = 10**7


def randomMatrix(arg):
    matrix = list()
    for i in range(arg):
        line = list()
        for j in range(arg):
            number = random.uniform(-MAX_NUMBER, MAX_NUMBER)
            element = '{},'.format(number)
            line.append(element)
        line.append('\n')
        wholeLine = ''.join(line)
        matrix.append(wholeLine)
    result = ''.join(matrix)
    return result


def main(size, path=''):
    if path != '' and not path.endswith('/'):
        path += '/'
    with open(path + 'example_matrices.h', 'w') as file:
        file.write('#ifndef EXAMPLE_MATRICES_H\n')
        file.write('#define EXAMPLE_MATRICES_H\n\n')
        file.write('int MATRIX_SIZE = {};\n\n'.format(size))
        file.write('float MATRIX_1[{}] = {{\n'.format(size * size))
        file.write(randomMatrix(size))
        file.write('};\n\n')
        file.write('float MATRIX_2[{}] = {{\n'.format(size * size))
        file.write(randomMatrix(size))
        file.write('};\n\n')
        file.write('#endif // EXAMPLE_MATRICES_H\n')

if __name__ == '__main__':
    main(int(sys.argv[1]), sys.argv[2])
