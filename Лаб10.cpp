#pragma warning (disable : 4996)
#include <iostream>
#include <Windows.h>

using namespace std;
void print_array(int** aarray, int size1, int size2)
{
	for (int i = 0; i < size1; i++)
	{
		for (int j = 0; j < size2; j++)
			cout << aarray[i][j] << '\t';
		cout << endl;
	}
	cout << endl;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(0));
	int** arraypp;
	int size_array;
	cout << "Введите размер: ";
	cin >> size_array;
	srand(time(0));

	arraypp = new int* [size_array];		//выделение памяти под массив указателей
	for (int i = 0; i < size_array; i++)
	{
		arraypp[i] = new int[size_array];	//выделение памяти под массив чисел
		for (int j = 0; j < size_array; j++)
		{
			arraypp[i][j] = rand();
		}
	}
	print_array(arraypp, size_array, size_array);

	cout << "Удалите строку: ";
	int deleteelement;
	cin >> deleteelement;
	deleteelement--;	//уменьшаем для удаления по номеру столбца
	delete[] arraypp[deleteelement];  //удаляем нужный элемент

	for (int i = deleteelement; i < size_array - 1; i++)  //смещаем указатели
		arraypp[i] = arraypp[i + 1];

	print_array(arraypp, size_array - 1, size_array); //size_array-1 - так как стало меньше на 1 строку

	for (int j = 0; j < size_array - 1; j++)	//освобождаем память каждого элемента массива	
	{
		delete[] arraypp[j];
	}
	delete[] arraypp; //освобождаем память массива указателей
	return 0;
}
