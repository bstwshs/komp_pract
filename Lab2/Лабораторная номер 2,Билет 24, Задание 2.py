# Гусейнов Тагир НБИ 03.23.
# Лабораторная номер 2,Билет 24, Задание 2

"""
2. Даны два вектора в пространстве, координаты которых определены случайным образом. 
Найти их длины, найти угол между ними, найти сумму и разность векторов, 
выяснить вопрос о том, что они параллельны или нет, найти их векторное произведение.
"""

import math
import numpy as np

# Генерация двух случайных векторов
v1 = np.array([np.random.randint(-10, 11), np.random.randint(-10, 11), np.random.randint(-10, 11)])
v2 = np.array([np.random.randint(-10, 11), np.random.randint(-10, 11), np.random.randint(-10, 11)])

# Определить длины векторов
def vector_length(v):
    return math.sqrt(sum(x**2 for x in v))

len_v1 = vector_length(v1)
len_v2 = vector_length(v2)
print("Длина v1:", len_v1)
print("Длина v2:", len_v2)

# Определить угол между векторами
def angle_between_vectors(v1, v2):
    dot_product = sum(x*y for x, y in zip(v1, v2))
    magnitude_product = len_v1 * len_v2
    cosine_angle = dot_product / magnitude_product
    angle = math.acos(cosine_angle)
    return math.degrees(angle)

angle = angle_between_vectors(v1, v2)
print("Угол между векторами:", angle)

# Определить сумму и разность векторов
v_sum = v1 + v2
v_diff = v1 - v2
print("Сумма векторов:", v_sum)
print("Разность векторов:", v_diff)

# Проверить, параллельны ли векторы
def are_parallel(v1, v2):
    return np.array_equal(np.cross(v1, v2), np.zeros(3))

if are_parallel(v1, v2):
    print("Векторы параллельны")
else:
    print("Векторы не параллельны")

# Определить скалярное произведение векторов
def vector_product(v1, v2):
    return np.cross(v1, v2)

vp = vector_product(v1, v2)
print("Скалярное произведение:", vp)