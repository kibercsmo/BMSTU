#include <iostream>

int main(){
    setlocale(LC_ALL,"rus");
    int a;
    std::cout << "Введите число: ";
    std::cin >> a;
    if (a%2==0){
        std::cout << "Число чёное";
    }
    else{
        std::cout << "Число нечётное";
    }
    return 0;
}