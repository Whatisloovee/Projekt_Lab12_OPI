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

	cout << setw(70) << "���� ������" << endl << endl;

	cout << "������� ���������,������� ����� �������������" << endl;
	cin.getline(buff, 1024);
	cout << "������� ���� (����� �����)" << endl;
	cin >> key;
	for (int i = 0; i < strlen(buff); i++)
		buff[i] += key;
	cout << "���������" << endl;
	printf("%s", buff);
	cout << endl << endl;
	cout << "���� ������ ��������� �����������, �� ������� \"1\"" << endl;
	cin >> n;
	if (n == 1) {
		cout << "�����������" << endl;
		for (int i = 0; i < strlen(buff); i++)
			buff[i] -= key;
		printf("%s", buff);
		cout << endl;
	}
	system("pause");
	return 0;
	cin.get();
}