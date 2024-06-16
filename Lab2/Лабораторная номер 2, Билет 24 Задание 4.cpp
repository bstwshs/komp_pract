/*
Гусейнов Тагир НБИ 03.23.
Лабораторная номер 2, Билет 24, Задание 4

3. Дано уравнение эллипса и точка на плоскости, 
где параметры эллипса и координаты точки определены случайным образом. 
Исследовать вопрос о том, принадлежит ли точка эллипсу. 
Найти координаты фокусов эллипса, найти длины полуосей эллипса, 
найти эксцентриситет эллипса, найти расстояние от директрис эллипса до его центра.
*/


#include <iostream>
#include <cmath>
#include <random>

using namespace std;

// Функция для проверки пересечения плоскости с гиперболическим цилиндром
bool planeIntersectsCylinder(double a, double b, double c, double d, double e, double f) {
    // Вычисляем дискриминант квадратного уравнения
    double D = pow(a, 2) * pow(b, 2) + pow(c, 2) * pow(d, 2) - 4 * a * c * e * f;
    if (D >= 0) {
        // Если дискриминант неотрицательный, плоскость пересекает цилиндр
        return true;
    } else {
        // Если дискриминант отрицательный, плоскость не пересекает цилиндр
        return false;
    }
}

// Функция для проверки пересечения прямой с гиперболическим цилиндром
bool lineIntersectsCylinder(double a, double b, double c, double d, double e, double f) {
    // Вычисляем дискриминант квадратного уравнения
    double D = pow(a, 2) * pow(b, 2) + pow(c, 2) * pow(d, 2) - 4 * a * c * e * f;
    if (D > 0) {
        // Если дискриминант положительный, прямая пересекает цилиндр
        return true;
    } else {
        // Если дискриминант неотрицательный, прямая не пересекает цилиндр
        return false;
    }
}

// Функция для проверки принадлежности точки к гиперболическому цилиндр
bool pointOnCylinder(double x, double y, double z, double a, double b) {
    return pow(x / a, 2) + pow(y / b, 2) == 1;
}

int main() {
    // Генерируем случайные параметры для гиперболического цилиндра и плоскости/прямой/точки
    default_random_engine gen;
    uniform_real_distribution<double> dis(1.0);
    double a = dis(gen);
    double b = dis(gen);
    double c = dis(gen);
    double d = dis(gen);
    double e = dis(gen);
    double f = dis(gen);
    double x = dis(gen);
    double y = dis(gen);
    double z = dis(gen);

    // Проверяем пересечение плоскости с гиперболическим цилиндром
    if (planeIntersectsCylinder(a, b, c, d, e, f)) {
        cout << "Плоскость пересекает гиперболический цилиндр." << endl;
    } else {
        cout << "Плоскость не пересекает гиперболический цилиндр." << endl;
    }

    // Проверяем пересечение прямой с гиперболическим цилиндром
    if (lineIntersectsCylinder(a, b, c, d, e, f)) {
        cout << "Прямая пересекает гиперболический цилиндр." << endl;
    } else {
        cout << "Прямая не пересекает гиперболический цилиндр." << endl;
    }

    // Проверяем принадлежность точки к гиперболическому цилиндр
    if (pointOnCylinder(x, y, z, a, b)) {
        cout << "Точка принадлежит гиперболическому цилиндр." << endl;
    } else {
        cout << "Точка не принадлежит гиперболическому цилиндр." << endl;
    }

    return 0;
}