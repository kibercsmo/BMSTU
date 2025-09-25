#include <iostream>

int check(int a, char gls[12], char sgls[40]){
    char b;
    std::cin >> b;
    for (int i = 0;i<12;i++){
        if (b == gls[i]){
            a++;
            check(a,gls,sgls);
            return 0;
        }
    }
    for (int i = 0;i<40;i++){
        if (b == sgls[i]){
            check(a,gls,sgls);
            return 0;
        }
    }
    std::cout << a;
    return 0;
}

int main(){
    setlocale(LC_ALL,"rus");
    int a = 0;
    char gls[12] = {'A','a','E','e','I','i','O','o','U','u','Y','y'};
    char sgls[40] = {'B','b','C','c','D','d','F','f','G','g','H','h','J','j','K','k','L','l','M','m','N','n','P','p','Q','q','R','r','S','s','T','t','V','v','W','w','X','x','Z','z'};
    check(a,gls,sgls);
    return 0;
}

// Я написал самый неоптимизированный код на свете и горжусь этим!
// Я бесполезно забил память настолько насколько смог!

