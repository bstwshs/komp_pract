# Гусейнов Тагир НБИ 03.23.
# Лабораторная номер 3, Билет 3, Задание 2


import numpy as np
from scipy.integrate import quad
import math

# Определение функции
def func(x):
    return np.exp(-2 * x) * np.sin(2 * x)

# Метод прямоугольников
def rectangle_method(func, a, b, n):
    h = (b - a) / n
    result = 0
    for i in range(n):
        result += func(a + i * h) * h
    return result

# Вычисление интеграла с точностью до 10^-10
a = 0
b = np.inf
n_rect = 1000

I_rect, _ = quad(func, a, b)

print(f"Метод прямоугольников: {I_rect:.10f}")