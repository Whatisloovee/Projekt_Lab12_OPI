#include <windows.h>
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;
int Shifr_Cezyar()
{
	cin.get();
	setlocale(0, "RUS");

	char buff[1024];
	int n, key;

	cout << setw(70) << "\x1B[31m���� ������\033[0m\t\t" << endl << endl;

	cout << "\x1B[32m������� ���������,������� ����� �������������\033[0m" << endl;
	cin.getline(buff, 1024);
	cout << "\x1B[32m������� ���� (����� �����)\033[0m" << endl;
	cin >> key;
	for (int i = 0; i < strlen(buff); i++)
		buff[i] += key;
	cout << "\x1B[32m���������\033[0m" << endl;
	printf("\x1B[33m%s\033[0m", buff);
	cout << endl << endl;
	cout << "\x1B[32m���� ������ ��������� �����������, �� ������� \"1\"\033[0m" << endl;
	cin >> n;
	if (n == 1) {
		cout << "\x1B[32m�����������\033[0m" << endl;
		for (int i = 0; i < strlen(buff); i++)
			buff[i] -= key;
		printf("\x1B[33m%s\033[0m", buff);
		cout << endl;
	}
	system("pause");
	return 0;
	cin.get();
}