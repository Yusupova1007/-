#pragma warning (disable : 4996)
#include <iostream>
#include <Windows.h>
#include <io.h>
#include <stdio.h>

using namespace std;
const char discipline[4][20] = { " Математика"," Физика"," Русский язык"," Литература" };

void Rewrite();
void InsertBegin();

//Вставка одного школьника в конец файла
void Insert()
{
	FILE* pfile = fopen("myfile.txt", "a+");
	char buffer[100];
	cout << "Введите ФИО: ";
	cin >> buffer;
	fwrite(buffer, 1, 100, pfile);
	cout << "Введите класс:";
	cin >> buffer;
	fwrite(buffer, 1, 1, pfile);
	cout << "Введите номер телефона: ";
	cin >> buffer;
	fwrite(buffer, 1, 100, pfile);
	for (unsigned int i = 0; i < 4; i++)
	{
		cout << "Введите оценку по предмету" << discipline[i] << ": ";
		cin >> buffer;
		fwrite(buffer, 1, 1, pfile);
	}
	fclose(pfile);
}
//вставка одного школьника в начало файла
//метод копирует содержимое в память перезаписывает 
//старый файл новой записью и дописывает старые данные
void InsertBegin()
{
	FILE* pfile = fopen("myfile.txt", "r");
	fseek(pfile, 0, SEEK_END);
	unsigned int size = ftell(pfile);
	fseek(pfile, 0, SEEK_SET);
	char* buffer = new char[size];
	fread(buffer, 1, size, pfile);
	fclose(pfile);
	Rewrite();
	pfile = fopen("myfile.txt", "a+");
	fwrite(buffer, 1, size, pfile);
	fclose(pfile);
	delete[] buffer;
}
//перезапись файла
void Rewrite()
{
	FILE* pfile = fopen("myfile.txt", "w+");
	fclose(pfile);
	Insert();
}
//печать данных файла
void Print()
{
	FILE* pfile = fopen("myfile.txt", "r");
	char buffer[100];
	while (fread(buffer, 1, 100, pfile) != 0)
		if (*buffer == 0x00)
			fseek(pfile, 105, SEEK_CUR);
		else
		{
			cout << "\n\nФИО школьника: " << buffer;


			fread(buffer, 1, 1, pfile);
			cout << "\nКласс школьника: " << *buffer;

			fread(buffer, 1, 100, pfile);
			cout << "\nНомер телефона школьника: " << buffer;

			cout << "\nОценки по предметам: ";
			for (unsigned int i = 0; i < 4; i++)
			{
				fread(buffer, 1, 1, pfile);
				cout << "\n" << discipline[i] << ": " << *buffer;
			}
		}
	fclose(pfile);
}
//удаление школьника если у него есть хотя бы одна двойка
//метод не удаляет данные из файла, а только помечает его
void Delete2Scores()
{
	FILE* pfile = fopen("myfile.txt", "r+");
	fseek(pfile, 0, SEEK_SET);
	char buffer[205];
	while (fread(buffer, 1, 205, pfile) != 0 && *buffer != 0x00)
	{
		//цикл по предметам оценки содержатся в байтах 201, 202, 203, 204
		for (unsigned i = 201; i < 205; i++)
			if (buffer[i] == '2') //если
			{
				fseek(pfile, -205, SEEK_CUR);	//переходим на начало карточки школьника
				buffer[0] = 0x00;				//так как fread передвинул курсор к следующей позиции байт
				fwrite(buffer, 1, 1, pfile);	//перезаписывем один байт нулем	
				fseek(pfile, 204, SEEK_CUR);	//переходим на начало карточки следующего школьника
				break;
			}
	}
	fclose(pfile);
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int mode;
	do
	{
		cout << "\n1 - Перезаписать \n2 - Дополнить\n3 - Распечатать\n4 - Удалить все элементы, у которых есть 2 хотя бы по одному предмету\n5 - Дополнить в начало\n0 - Выйти из программы";
		cout << "\nЧто сделать с файлом:";
		cin >> mode;
		switch (mode)
		{
		case 1://Перезаписать
			Rewrite();
			break;
		case 2://Дополнить
			Insert();
			break;
		case 3://Распечатать
			Print();
			break;
		case 4://Удалить все элементы, у которых есть 2 хотя бы по одному предмету
			Delete2Scores();
			break;
		case 5://Дополнить в начало
			InsertBegin();
			break;
		case 0://Выйти из программы
			break;
		default:
			cout << "Ошибка\n";
		}
	} while (mode != 0);
	return 0;
}
