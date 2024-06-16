# Гусейнов Тагир НБИ 03.23.
# Лабораторная номер 3, Билет 2, Задание 1


import numpy as np

# Определение функции
def func(x):
    return x*(2 + x**2) - 1

# Определение точек разбиения
x = np.linspace(1, 2, 100)

# Метод прямоугольников
def rectangle_method(func, a, b, n):
    h = (b - a) / n
    result = 0
    for i in range(n):
        result += func(a + i * h) * h
    return result
    

# Вычисление интеграла с точностью до 10^-10
a = 1
b = 2
n_rect = 1000

I_rect = rectangle_method(func, a, b, n_rect)

print(f"Метод прямоугольников: {I_rect:.10f}")