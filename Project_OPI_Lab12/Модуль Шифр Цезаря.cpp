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

	cout << setw(70) << "ШИФР ЦЕЗАРЯ" << endl << endl;

	cout << "Введите сообщение,которое будет закодированно" << endl;
	cin.getline(buff, 1024);
	cout << "Введите ключ (целое цисло)" << endl;
	cin >> key;
	for (int i = 0; i < strlen(buff); i++)
		buff[i] += key;
	cout << "Результат" << endl;
	printf("%s", buff);
	cout << endl << endl;
	cout << "Если хотите выполнить декодировку, то введите \"1\"" << endl;
	cin >> n;
	if (n == 1) {
		cout << "Декодировка" << endl;
		for (int i = 0; i < strlen(buff); i++)
			buff[i] -= key;
		printf("%s", buff);
		cout << endl;
	}
	system("pause");
	return 0;
	cin.get();
}