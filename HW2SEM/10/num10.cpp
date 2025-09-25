#include <iostream>

int main(){
    setlocale(LC_ALL,"rus");
    int a;
    std::cout << "Введите число: ";
    std::cin >> a;
    if (a == 0){
        std::cout << "Введён 0";
    }
    else if(a > 0){
        std::cout << "Введено положительное число";
    }
    else{
        std::cout << "Введено отрицательное число";
    }
    return 0;
}