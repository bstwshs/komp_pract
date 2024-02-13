// Четвертое 1 вариант с++

	#include <iostream>
 
bool isArithmeticProgressionMember(int n, int f, int s) {
    return (n - f) % s == 0;
}
 
int main() {
    int n, f, s;
    std::cout << "Введите число (n): ";
    std::cin >> n;
    std::cout << "Введите первый элемент (f): ";
    std::cin >> f;
    std::cout << "Введите шаг прогрессии (s): ";
    std::cin >> s;
 
    if (isArithmeticProgressionMember(n, f, s)) {
        std::cout << n << " является членом арифметической прогрессии с первым членом " << f << " и шагом движения " << s << ".\n";
    } else {
        std::cout << n << " не является членом арифметической прогрессии с первым членом " << f << " и шагом движения " << s << ".\n";
    }
 
    return 0;
}