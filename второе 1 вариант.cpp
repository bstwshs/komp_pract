//второе 1 вариант с++
#include <iostream>
using namespace std;

	#include <iostream>
 
int findNumberX(int n) {
    int units = n % 10;
    int tens = (n / 10) % 10;
 
    int x = (tens * 10) + units;
 
    return x;
}
 
int main() {
    int n;
    std::cout << "Введите значение n: ";
    std::cin >> n;
 
    int x = findNumberX(n);
 
    std::cout << "Число x равно: " << x << std::endl;
 
    return 0;
}