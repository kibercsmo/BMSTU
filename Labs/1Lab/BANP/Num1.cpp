#include <iostream>

int main(){
	setlocale(LC_ALL, "rus");
	std::cout << "�������� 10 ����:" << std::endl;
	bool b = 0;
	int a = 0;
	int set[10];

	//���� �������
	for (int i = 0;i < 10;i++){
		std::cin >> set[i];
	}

	//����� �������
	std::cout << "��� ������:";
	for (int i = 0;i < 10;i++){
		std::cout << set[i] << ' ';
	}
	std::cout << std::endl;

	// C���� ��������� �������
	for (int i = 0; i < 10; i++) {
		a += set[i];
	}
	std::cout << "����� ���������: " << a << std::endl;
	a = 0;

	// ������������ ��������
	for (int i = 0; i < 10; i++) {
		if (set[i] > a){
			a = set[i];
		}
	}
	std::cout << "������������ �������: " << a << std::endl;
	a = 0;

	// ���������� �� ��������
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
	
	// ��������������� ������
	std::cout << "��������������� ������:";
	for (int i = 0; i < 10; i++) {
		std::cout << set[i] << ' ';
	}

	return 0;
}