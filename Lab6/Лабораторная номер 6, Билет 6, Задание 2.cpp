// Гусейнов Тагир НБИ 03.23.
// Лабораторная номер 6, Билет 6, Задание 2

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

// Определим функцию для оптимизации
double f(double x1, double x2) {
    return pow(x1, 2) + exp(pow(x1, 2) + pow(x2, 2)) + 4 * x1 + 3 * x2;
}

// Определим градиент функции
std::vector<double> grad(double x1, double x2) {
    std::vector<double> grad(2);
    grad[0] = 2 * x1 + 4 + 2 * x1 * exp(pow(x1, 2) + pow(x2, 2));
    grad[1] = 2 * x2 + 3;
    return grad;
}

int main() {
    const int max_iter = 5; // максимальное количество итераций
    const double tol = 1e-6; // допуск на сходимость

    // Инициализируйте начальное предположение для параметров
    double x1 = 1.0;
    double x2 = 1.0;

    // Инициализируйте градиент
    std::vector<double> grad_x = {0.0, 0.0};

    // метод градиентного спуска
    for (int i = 0; i < max_iter; i++) {
        grad_x = grad(x1, x2);
        double dir = -grad_x[0];
        double alpha = 0.1;
        while (true) {
            double new_x1 = x1 + dir * alpha;
            double new_x2 = x2;
            double new_f = f(new_x1, new_x2);
            if (new_f < f(x1, x2)) {
                x1 = new_x1;
                x2 = new_x2;
                break;
            }
            alpha *= 0.5;
        }
        cout << "Итерация " << i << ": " << f(x1, x2) << endl;
        if (sqrt(pow(grad_x[0], 2) + pow(grad_x[1], 2)) < tol) {
            break;
        }
    }

    cout << "Оптимальные значения: " << x1 << ", " << x2 << endl;
    return 0;
}