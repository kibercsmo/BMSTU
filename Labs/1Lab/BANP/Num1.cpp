#include <iostream>

int main(){
	setlocale(LC_ALL, "rus");
	std::cout << "Напишите 10 цифр:" << std::endl;
	bool b = 0;
	int a = 0;
	int set[10];

	//Ввод массива
	for (int i = 0;i < 10;i++){
		std::cin >> set[i];
	}

	//Вывод массива
	std::cout << "Ваш массив:";
	for (int i = 0;i < 10;i++){
		std::cout << set[i] << ' ';
	}
	std::cout << std::endl;

	// Cумма элементов массива
	for (int i = 0; i < 10; i++) {
		a += set[i];
	}
	std::cout << "Сумма элементов: " << a << std::endl;
	a = 0;

	// Максимальный эллемент
	for (int i = 0; i < 10; i++) {
		if (set[i] > a){
			a = set[i];
		}
	}
	std::cout << "Максимальный элемент: " << a << std::endl;
	a = 0;

	// Сортировка по убыванию
	while (b == 0)
	{
		for (int i = 0; i < 9; i++) {
			if (set[i] < set[i+1])
			{
				a = set[i];
				set[i] = set[i + 1];
				set[i + 1] = a;
				break;
			}
			else if(i == 8){
				b = 1;
			}
		}
	}
	
	// Остортированный массив
	std::cout << "Остортированный массив:";
	for (int i = 0; i < 10; i++) {
		std::cout << set[i] << ' ';
	}

	return 0;
}