import numpy as np
import random as rd

f_write = open("tests.txt", 'w')
f_answer = open("answers.txt", 'w')

# +
for i in range(10):
    f_write.write('+\n\n')
    length = rd.randint(2, 10)
    width = rd.randint(2, 10)
    matrix1 = np.random.randint(10, size=(length, width))
    matrix2 = np.random.randint(10, size=(length, width))

    for i in range(len(matrix1)):
        if i != len(matrix1) - 1:
            f_write.write(' '.join([str(j) for j in matrix1[i]]) + '\n')
        else:
            f_write.write(' '.join([str(j) for j in matrix1[i]]) + '\n\n')

    for i in range(len(matrix2)):
        if i != len(matrix2) - 1:
            f_write.write(' '.join([str(j) for j in matrix2[i]]) + '\n')
        else:
            f_write.write(' '.join([str(j) for j in matrix2[i]]) + '\n\n')

    result = matrix1 + matrix2
    for i in range(len(result)):
        if i != len(result) - 1:
            f_answer.write(' '.join([str(j) for j in result[i]]) + '\n')
        else:
            f_answer.write(' '.join([str(j) for j in result[i]]) + '\n\n')

# -
for i in range(10):
    f_write.write('-\n\n')
    length = rd.randint(2, 10)
    width = rd.randint(2, 10)
    matrix1 = np.random.randint(10, size=(length, width))
    matrix2 = np.random.randint(10, size=(length, width))

    for i in range(len(matrix1)):
        if i != len(matrix1) - 1:
            f_write.write(' '.join([str(j) for j in matrix1[i]]) + '\n')
        else:
            f_write.write(' '.join([str(j) for j in matrix1[i]]) + '\n\n')

    for i in range(len(matrix2)):
        if i != len(matrix2) - 1:
            f_write.write(' '.join([str(j) for j in matrix2[i]]) + '\n')
        else:
            f_write.write(' '.join([str(j) for j in matrix2[i]]) + '\n\n')

    result = matrix1 - matrix2
    for i in range(len(result)):
        if i != len(result) - 1:
            f_answer.write(' '.join([str(j) for j in result[i]]) + '\n')
        else:
            f_answer.write(' '.join([str(j) for j in result[i]]) + '\n\n')

# *
for i in range(10):
    f_write.write('*\n\n')
    length = rd.randint(2, 10)
    width = rd.randint(2, 10)
    matrix1 = np.random.randint(10, size=(length, width))
    matrix2 = np.random.randint(10, size=(width, length))

    for i in range(len(matrix1)):
        if i != len(matrix1) - 1:
            f_write.write(' '.join([str(j) for j in matrix1[i]]) + '\n')
        else:
            f_write.write(' '.join([str(j) for j in matrix1[i]]) + '\n\n')

    for i in range(len(matrix2)):
        if i != len(matrix2) - 1:
            f_write.write(' '.join([str(j) for j in matrix2[i]]) + '\n')
        else:
            f_write.write(' '.join([str(j) for j in matrix2[i]]) + '\n\n')

    result = np.matmul(matrix1, matrix2)
    for i in range(len(result)):
        if i != len(result) - 1:
            f_answer.write(' '.join([str(j) for j in result[i]]) + '\n')
        else:
            f_answer.write(' '.join([str(j) for j in result[i]]) + '\n\n')

# det
for i in range(10):
    f_write.write('det\n\n')
    dimension = rd.randint(2, 10)
    matrix = np.random.randint(10, size=(dimension, dimension))

    for i in range(len(matrix)):
        if i != len(matrix) - 1:
            f_write.write(' '.join([str(j) for j in matrix[i]]) + '\n')
        else:
            f_write.write(' '.join([str(j) for j in matrix[i]]) + '\n\n')

    result = np.linalg.det(matrix)
    f_answer.write(str(result) + '\n\n')

# triangle
for i in range(10):
    f_write.write('triangle\n\n')
    dimension = rd.randint(2, 10)
    matrix = np.random.randint(10, size=(dimension, dimension))

    for i in range(len(matrix)):
        if i != len(matrix) - 1:
            f_write.write(' '.join([str(j) for j in matrix[i]]) + '\n')
        else:
            f_write.write(' '.join([str(j) for j in matrix[i]]) + '\n\n')

    result = np.triu(matrix)
    for i in range(len(result)):
        if i != len(result) - 1:
            f_answer.write(' '.join([str(j) for j in result[i]]) + '\n')
        else:
            f_answer.write(' '.join([str(j) for j in result[i]]) + '\n\n')

# transpose
for i in range(10):
    f_write.write('transpose\n\n')
    dimension = rd.randint(2, 10)
    matrix = np.random.randint(10, size=(dimension, dimension))

    for i in range(len(matrix)):
        if i != len(matrix) - 1:
            f_write.write(' '.join([str(j) for j in matrix[i]]) + '\n')
        else:
            f_write.write(' '.join([str(j) for j in matrix[i]]) + '\n\n')

    result = np.transpose(matrix)
    for i in range(len(result)):
        if i != len(result) - 1:
            f_answer.write(' '.join([str(j) for j in result[i]]) + '\n')
        else:
            f_answer.write(' '.join([str(j) for j in result[i]]) + '\n\n')
