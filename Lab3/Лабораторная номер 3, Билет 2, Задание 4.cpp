// Гусейнов Тагир НБИ 03.23.
// Лабораторная номер 3, Билет 3, Задание 4

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

const double EPS = 1e-6; // точность вычислений

double sum(double x) {
    double sum = 2;
    double term = 1 / (1 * pow(x, 2));

    for (int k = 1; ; k++) {
        term *= -1 / (k * (k + 1));
        sum += sin(k * x) * term;

        if (abs(term) < EPS) {
            break;
        }
    }

    return sum;
}

int main() {
    double x;
    cout << "Введите x: ";
    cin >> x;

    double result = sum(x);

    cout << fixed << setprecision(6) << "Сумма ряда: " << result << endl;

    return 0;
}