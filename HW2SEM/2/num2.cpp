#include <iostream>

int main(){
    setlocale(LC_ALL,"rus");
    double a,b;
    std::cout << "Длинна: ";
    std::cin >> a;
    std::cout << "Ширина: ";
    std::cin >> b;
    std::cout << "Площадь: " << a*b;
    return 0;
}