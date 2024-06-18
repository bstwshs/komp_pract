# Гусейнов Тагир НБИ 03.23.
# Лабораторная номер 6, Билет 6, Задание 1

import numpy as np
from scipy.optimize import minimize

# Определим оптимизируемую функцию
def f(x):
    return np.exp(x[0]**2 + x[1]**2) + np.log(4 + x[1]**2 + 2*x[2]**2)

# Определим начальные значения параметров
x0 = np.array([1.0, 1.0, 1.0])

# Определим границы для параметров
bounds = [(None, None), (None, None), (None, None)]

# Используем метод координатного спуска для оптимизации функции
res = minimize(f, x0, method="COBYLA", bounds=bounds)

# Выведите оптимальные значения x1, x2 и x3
print("Оптимальные значения:", res.x)
print("Оптимальные значения функции:", res.fun)