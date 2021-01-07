#pragma warning (disable : 4996)
#include <iostream>
#include <Windows.h>
#include <io.h>
#include <stdio.h>

using namespace std;
//Создание файла F1 построчно
void Create()
{
	FILE* pfile = fopen("F1.txt", "w+");
	char buffer[255];
	do
	{
		cin >> buffer;
		if (*buffer == '0')
			break;
		fputs(buffer, pfile);
		fputs("\n", pfile);
	} while (*buffer != '0');
	fclose(pfile);
}
//Копирование файла F1 в F2
void CopyFile1(int N, int K)
{
	FILE* pfile = fopen("F1.txt", "r");
	FILE* pfileF2 = fopen("F2.txt", "w+");
	char buffer[255];
	int j = 0;
	while (fgets(buffer, 255, pfile))
	{
		if (j >= N && j <= K)
		{
			fputs(buffer, pfileF2);
		}
		j++;
	}
	fclose(pfile);
	fclose(pfileF2);
}
//Распечатка файла F2
void PrintSources()
{
	FILE* pfile = fopen("F2.txt", "r");
	char buffer[255];
	while (fgets(buffer, 255, pfile))
		cout << buffer;
	fclose(pfile);
}
//Подсчет согласных букв в одной строке
int isConsonants(char* buffer)
{
	//Алфавитный массив с согласными буквами
	const char* conslist = "бвгджзйклмнпрстфхцчшщБВГДЖЗЙКЛМНПРСТФХЦЧШЩ";
	int result = 0;
	while (*buffer != '\n')
	{
		//Цикл по алфавиту с согласными буквами
		for (size_t i = 0; i < 44; i++)
		if (conslist[i] == *buffer)
			{
				result++;
				break;
			}
		buffer++;
	}
	return result;
}
//Подсчет согласных букв
void CalculateConsonants()
{
	FILE* pfile = fopen("F2.txt", "r");
	char buffer[255];
	int result = 0;
	while (fgets(buffer, 255, pfile))
	{
		result += isConsonants(buffer);
	}
	fclose(pfile);
	cout << "Количество согласных букв в файле F2: " << result << endl;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int N, K;
	cout << "Введите строку:" << endl;
	Create();
	cout << endl;
	cout << "Введите с какой строки скопировать:" << endl;
	cin >> N;
	cout << "Введите до какой строки скопировать:" << endl;
	cin >> K;
	cout << endl;
	CopyFile1(N, K);
	cout << "Второй файл:" << endl;
	PrintSources();
	cout << endl;
	CalculateConsonants();
	return 0;
}
