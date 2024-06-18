/*
Гусейнов Тагир НБИ 03.23.
Лабораторная номер 2, Билет 24 Задание 3

3. Дано уравнение эллипса и точка на плоскости, 
где параметры эллипса и координаты точки определены случайным образом. 
Исследовать вопрос о том, принадлежит ли точка эллипсу. 
Найти координаты фокусов эллипса, найти длины полуосей эллипса, 
найти эксцентриситет эллипса, найти расстояние от директрис эллипса до его центра.
*/


#include <iostream>
#include <cmath>
#include <vector>
#include <random>

using namespace std;

// Функция проверки, лежит ли точка на эллипсе
bool pointOnEllipse(double x, double y, double a, double b, double c) {
    return (pow(x, 2) / pow(a, 2) + pow(y, 2) / pow(b, 2) - 1 + c == 0);
}

// Функция для расчета координат фокусов эллипса
pair<double, double> getFoci(double a, double b) {
    return make_pair(sqrt(pow(a, 2) - pow(b, 2)), 0);
}

// Функция для расчета длин полуосей эллипса
pair<double, double> getSemiAxes(double a, double b) {
    return make_pair(a, b);
}

// Функция для расчета эксцентриситета эллипса
double getEccentricity(double a, double b) {
    return sqrt(1 - pow(b / a, 2));
}

// Функция для расчета расстояния от директрис эллипса до центра
double distanceToDirectrices(double a, double b) {
    return abs(a * sqrt(1 - pow(b / a, 2)));
}

int main() {
    // Генерируем случайные параметры для эллипса и точки
    default_random_engine gen;
    uniform_real_distribution<double> dis(1.0);
    double a = dis(gen);
    double b = dis(gen);
    double c = dis(gen);
    double x = dis(gen);
    double y = dis(gen);

    // Проверяем, лежит ли точка на эллипсе
    if (pointOnEllipse(x, y, a, b, c)) {
        cout << "Точка лежит на эллипсе." << endl;
    } else {
        cout << "Точка не лежит на эллипсе." << endl;
    }

    // Расчитываем координаты фокусов
    pair<double, double> foci = getFoci(a, b);
    cout << "Фокусы: (" << foci.first << ", " << foci.second << ")" << endl;

    // Расчитываем длину полуосей
    pair<double, double> semiAxes = getSemiAxes(a, b);
    cout << "Длины полуосей: (" << semiAxes.first << ", " << semiAxes.second << ")" << endl;

    // Расчитываем эксцентриситет
    double eccentricity = getEccentricity(a, b);
    cout << "Эксцентриситет: " << eccentricity << endl;

    // Расчитываем расстояние от директрис до центра
    double distance = distanceToDirectrices(a, b);
    cout << "Расстояние от директрис до центра: " << distance << endl;

    return 0;
}