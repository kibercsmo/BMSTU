#include <iostream>

int main()
{
	setlocale(LC_ALL, "rus");
	int a = 0;
	std::cout << "�������: ";
	std::cin >> a;
	if (a > 50) 
	{
		std::cout << "������� ����������.";
	}
	else if (a > 20){
		std::cout << "������������� ��������.";
	}
	else{
		std::cout << "������� �� ������, ������ ����������!";
	}
	return 0;
}