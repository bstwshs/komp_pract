// Гусейнов Тагир НБИ 03.23.
// Лабораторная номер 4, Билет 14, Задание 3

#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

using namespace std;

void seidelMethod(const vector<vector<double>>& A, const vector<double>& b) {
    int n = A.size();
    vector<double> x(n);

    for (int i = 0; i < n; i++) {
        x[i] = b[i];
    }

    for (int iter = 0; iter < 1000; iter++) {
        for (int i = 0; i < n; i++) {
            double sum = 0;
            for (int j = 0; j < n; j++) {
                if (j != i) {
                    sum += A[i][j] * x[j];
                }
            }
            x[i] = (b[i] - sum) / A[i][i];
        }

        double resid = 0;
        for (int i = 0; i < n; i++) {
            resid += pow(b[i] - A[i][i] * x[i], 2);
        }
        resid = sqrt(resid);

        if (resid < 1e-4) {
            break;
        }
    }

    cout << "Решение с помощью метода Зейделя: ";
    for (int i = 0; i < n; i++) {
        cout << fixed << setprecision(4) << x[i] << " ";
    }
    cout << endl;
}

int main() {
    // Определите коэффициенты системы
    vector<vector<double>> A({
        {-22, -2, -6, 6},
        {3, -17, -3, 7},
        {2, 6, -17, 5},
        {-1, -8, 8, 23}
    });
    vector<double> b({96, -26, 35, -234});

    seidelMethod(A, b);

    return 0;
}