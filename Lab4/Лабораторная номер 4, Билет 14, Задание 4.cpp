// Гусейнов Тагир НБИ 03.23.
// Лабораторная номер 4, Билет 14, Задание 4

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printVector(vector<double> v) {
    for (double x : v) {
        cout << x << " ";
    }
    cout << endl;
}

void gaussianElimination(vector<vector<double>>& A, vector<double>& b) {
    int n = A.size();
    for (int i = 0; i < n; i++) {
        // Поиск максимума в этой колонке
        int maxRow = i;
        for (int k = i + 1; k < n; k++) {
            if (abs(A[k][i]) > abs(A[maxRow][i])) {
                maxRow = k;
            }
        }
        // Замена максимального элемента на текущий
        swap(A[i], A[maxRow]);
        swap(b[i], b[maxRow]);

        // Сделайте все строки ниже этой нулевыми в текущем столбце
        for (int k = i + 1; k < n; k++) {
            double c = A[k][i] / A[i][i];
            for (int j = i; j < n; j++) {
                A[k][j] -= c * A[i][j];
            }
            b[k] -= c * b[i];
        }
    }

    // Решите уравнение Ax=b для верхней треугольной матрицы A
    vector<double> x(n);
    x[n - 1] = b[n - 1] / A[n - 1][n - 1];
    for (int i = n - 2; i >= 0; i--) {
        double sum = 0;
        for (int j = i + 1; j < n; j++) {
            sum += A[i][j] * x[j];
        }
        x[i] = (b[i] - sum) / A[i][i];
    }

    cout << "Решение с помощью методом Прогонки: ";
    printVector(x);
}

int main() {
    // Определите коэффициенты системы
    vector<vector<double>> A({
        {-1, -1, 0, 0, 0},
        {7, -17, -8, 0, 0},
        {0, -9, 19, 8, 0},
        {0, 0, 7, -20, 4},
        {0, 0, 0, -4, 12}
    });
    vector<double> b({-4, 132, -59, -193, -40});

    gaussianElimination(A, b);

    return 0;
}