#include <iostream>

int main(){
    setlocale(LC_ALL,"rus");
    int a,b = 0;
    std::cout << "Введите число:";
    std::cin >> a;
    for (int i=1;i<a+1;i++){
        if (i%3==0 || i%5==0){
            b += i;
        }
    }
    std::cout << "Сумма: " << b;
    return 0;
}