// Гусейнов Тагир НБИ 03.23.
// Лабораторная номер 5, Билет 4, Задание 2


#include <iostream>
#include <cmath>

using namespace std;

// Функция для вычисления интерполированного значения
double interpolate(double x, double x1, double y1) {
    double h = x - x1;
    return y1 + h * (h * (h * (h * y1 - 3*y1) + 2*y1) / 6);
}

int main() {
    const int N = 5; // колличество точек
    const double pi = 3.14159;
    const double x[] = {0.1*pi, 0.2*pi, 0.3*pi, 0.4*pi};
    const double y[] = {cos(x[0]), cos(x[1]), cos(x[2]), cos(x[3])};

    // Рассчитайте интерполированные значения
    double x_target = 0.25*pi;
    double error = 0;
    for (int i = 0; i < N; i++) {
        double interpolated_value = interpolate(x_target, x[i], y[i]);
        error += pow(interpolated_value - cos(x_target), 2);
    }
    error = sqrt(error / N);

    cout << "Интерполированное значение в точке x" << " = " << x_target << ": " << interpolate(x_target, x[0], y[0]) << endl;
    cout << "Погрешность: " << error << endl;

    return 0;
}