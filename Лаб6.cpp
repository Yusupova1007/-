#include <iostream>

using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	char string[1000];
	char digit[1000];
	cout << "Введите строку: ";
	gets_s(string);
	char* pstring = string;
	int digitCount = 0;
	cout << "Буквы: ";
	while (*pstring != 0x00) //перебираем всю строку на наличия букв
	{
		if (*pstring >= 'A' && *pstring <= 'Z')	//если символ является буквой
			cout << *pstring;				//то печатаем
		else
		{
			digit[digitCount] = *pstring;	//иначе записываем символ в отдельный массив
			digitCount++;
		}
		pstring++;
	}
	cout << endl;
	cout << "Цифры: ";
	for (int i = 0; i < digitCount; i++)	//печатаем оставшиеся символы
	{
		cout << digit[i];
	}
	cout << endl;
	return 0;
}
