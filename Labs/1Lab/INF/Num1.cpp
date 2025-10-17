#include <iostream>

int main()
{
	setlocale(LC_ALL, "rus");
	int a = 0;
	std::cout << "Топливо: ";
	std::cin >> a;
	if (a > 50) 
	{
		std::cout << "Топлива достаточно.";
	}
	else if (a > 20){
		std::cout << "Рекомендуется заправка.";
	}
	else{
		std::cout << "Топливо на исходе, срочно заправтесь!";
	}
	return 0;
}