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
void CopyFile1()
{
	FILE* pfile = fopen("F1.txt", "r");
	FILE* pfileF2 = fopen("F2.txt", "w+");
	char buffer[255];
	while (fgets(buffer, 255, pfile))
	{
		char k = *buffer;
		if (k >= 'K' && k <= 'N') //Проверка есть ли символ в диапазоне
			fputs(buffer, pfileF2);
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
	const char* conslist = "qwrtpsdfghjklzxcvbnmQWRTPSDFGHJKLZXCVBNM";
	int result = 0;
	while (*buffer != '\n')
	{
		//Цикл по алфавиту с согласными буквами
		for (size_t i = 0; i < 42; i++)
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
	cout << "количество согласных букв в файле F2: " << result << endl;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int mode;
	do
	{
		cout << "\n1 - Создать файл\n2 - Скопировать из файла F1 в файл F2 строки, начиная с N до K\n3 - Распечатать файл F2.\n4 - Подсчитать количество согласных букв в файле F2.\n0 - Выйти из программы";
		cout << "\nЧто сделать с файлом:";
		cin >> mode;
		switch (mode)
		{
		case 1:
			Create();
			break;
		case 2:
			CopyFile1();
			break;
		case 3:
			PrintSources();
			break;
		case 4:
			CalculateConsonants();
			break;
		case 0:
			break;
		default:
			cout << "Я вас не понимаю\n";
		}
	} while (mode != 0);
	return 0;
}