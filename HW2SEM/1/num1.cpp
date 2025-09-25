#include <iostream>

int main(){
    setlocale(LC_ALL,"rus");
    int a;
    std::cout << "Колличество см: ";
    std::cin >> a;
    std::cout << "Метры: " << a/100 << std::endl << "Остаток: " << a%100;
    return 0;
}