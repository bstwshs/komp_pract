// Гусейнов Тагир НБИ 03.23.
// Лабораторная номер 3, Билет 3, Задание 3

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

const double EPS = 1e-6; // точность вычислений

double sum(double x) {
    double sum = 0;
    double term = 1;

    for (int k = 1; ; k++) {
        term *= (-1) / (2 * k - 1);
        sum += term;

        if (abs(term) < EPS) {
            break;
        }
    }

    return sum;
}

int main() {
    double x = 0;

    cout << "Введите x: ";
    cin >> x;

    double result = sum(x);

    cout << fixed << setprecision(6) << "Сумма ряда: " << result << endl;

    return 0;
}