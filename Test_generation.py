import numpy as np
import random as rd

f_write = open("tests.txt", 'w')
f_answer = open("answers.txt", 'w')


def make_test(func, mat_count, sqr_mat):
    for k in range(10):
        f_write.write(func + '\n\n')

        matrix1 = []
        matrix2 = []
        matrix = []
        result = []
        if mat_count == 2 and not sqr_mat:
            if mat_count == 2:
                length = rd.randint(2, 10)
                width = rd.randint(2, 10)
                if func == '+' or func == '-':
                    matrix1 = np.random.randint(10, size=(length, width))
                    matrix2 = np.random.randint(10, size=(length, width))
                elif func == '*':
                    matrix1 = np.random.randint(10, size=(width, length))
                    matrix2 = np.random.randint(10, size=(length, width))

                for i in range(len(matrix1)):
                    if i != length - 2:
                        f_write.write(' '.join([str(j) for j in matrix1[i]]) + '\n')
                    else:
                        f_write.write(' '.join([str(j) for j in matrix1[i]]) + '\n\n')

                for i in range(len(matrix2)):
                    if i != length - 2:
                        f_write.write(' '.join([str(j) for j in matrix2[i]]) + '\n')
                    else:
                        f_write.write(' '.join([str(j) for j in matrix2[i]]) + '\n\n')

                if func == '+':
                    result = matrix1 + matrix2
                elif func == '-':
                    result = matrix1 - matrix2
                elif func == '*':
                    result = np.dot(matrix1, matrix2)

                for i in range(len(result)):
                    if i != len(result) - 1:
                        f_answer.write(' '.join([str(j) for j in result[i]]) + '\n')
                    else:
                        f_answer.write(' '.join([str(j) for j in result[i]]) + '\n\n')

        elif mat_count == 1:
            if sqr_mat:
                dimension = rd.randint(2, 10)
                matrix = np.random.randint(10, size=(dimension, dimension))

                for i in range(len(matrix)):
                    if i != len(matrix) - 1:
                        f_write.write(' '.join([str(j) for j in matrix[i]]) + '\n')
                    else:
                        f_write.write(' '.join([str(j) for j in matrix[i]]) + '\n\n')

                if func == 'transpose':
                    result = np.transpose(matrix)
                elif func == 'triangle':
                    result = np.triu(matrix)

                for i in range(len(result)):
                    if i != len(result) - 1:
                        f_answer.write(' '.join([str(j) for j in result[i]]) + '\n')
                    else:
                        f_answer.write(' '.join([str(j) for j in result[i]]) + '\n\n')


make_test('+', 2, False)
make_test('-', 2, False)
make_test('*', 2, False)

make_test('transpose', 1, True)
make_test('triangle', 1, True)

# det
for i in range(10):
    f_write.write('det' + '\n\n')
    dimension = rd.randint(2, 10)
    matrix = np.random.randint(10, size=(dimension, dimension))
    for i in range(len(matrix)):
        if i != len(matrix) - 1:
            f_write.write(' '.join([str(j) for j in matrix[i]]) + '\n')
        else:
            f_write.write(' '.join([str(j) for j in matrix[i]]) + '\n\n')
    result = np.linalg.det(matrix)
    f_answer.write(str(result) + ']\n\n')

f_write.close()
f_answer.close()
