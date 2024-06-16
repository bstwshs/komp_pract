# Гусейнов Тагир НБИ 03.23.
# Лабораторная номер 2, Билет 24, Задание 1

"""
1. Даны две прямые на плоскости, а также точка, параметры прямых и координата 
точки определены случайным образом. 
Найти расстояния от точки до каждой прямой, найти точку пересечения прямых, 
найти расстояние от заданной точки до точки пересечения прямых, найти угол между прямыми.
"""

import math

# Определите координаты точки
x0, y0 = 1, 1

# Определите параметры прямых
a1, b1, c1 = 3, 4, -2
a2, b2, c2 = -2, 5, 3

# рассчитать расстояние от точки до каждой прямой
def distance_to_line(x0, y0, a, b, c):
    return abs(a*x0 + b*y0 + c) / math.sqrt(a**2 + b**2)

dist1 = distance_to_line(x0, y0, a1, b1, c1)
dist2 = distance_to_line(x0, y0, a2, b2, c2)

print("Расстояние до прямой 1:", dist1)
print("Расстояние до прямой 2:", dist2)

# рассчитать точку пересечения двух прямых
def intersection_point(a1, b1, c1, a2, b2, c2):
    D = a1*b2 - a2*b1
    if D == 0:
        print("Прямые параллельны")
        return None
    x = (c1*b2 - c2*b1) / D
    y = (a1*c2 - a2*c1) / D
    return x, y

x_int, y_int = intersection_point(a1, b1, c1, a2, b2, c2)
print("Точка пересечения:", (x_int, y_int))

# рассчитать расстояние от точки до точки пересечения
distance_to_int = math.sqrt((x_int - x0)**2 + (y_int - y0)**2)
print("Расстояние до точки пересечения:", distance_to_int)

# рассчитать угол между двумя прямыми
def angle_between_lines(a1, b1, c1, a2, b2, c2):
    numerator = abs(a1*a2 + b1*b2)
    denominator = math.sqrt(a1**2 + b1**2) * math.sqrt(a2**2 + b2**2)
    return math.acos(numerator / denominator)

angle = angle_between_lines(a1, b1, c1, a2, b2, c2)
print("Угол между прямыми:", math.degrees(angle))