#include <iostream>
#include <math.h>

using namespace std;
void print_array(int aarray[100][100], int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			cout << aarray[i][j] << '\t';
		cout << endl;
	}
	cout << endl;
}
int main()
{
	setlocale(LC_ALL, "Russian");
	int size_array;
	cout << "Введите размер матрицы: ";
	cin >> size_array;
	int aarray[100][100];
	srand(time(0));

	for (int i = 0; i < size_array; i++)
		for (int j = 0; j < size_array; j++)
			aarray[i][j] = rand();
	print_array(aarray, size_array);

	for (int i = 0; i < size_array; i++)
	{
		int min_value = aarray[i][0];
		int min_index = 0;

		for (int j = 1; j < size_array; ++j)	//ищем минимальный элемент в строке
			if (aarray[i][j] < min_value)
			{
				min_value = aarray[i][j];
				min_index = j;		 //запоминаем его индекс
			}
		int max_value = aarray[0][min_index];
		int max_index = 0;
		for (int k = 1; k < size_array; k++)	//ищем максимальный элемент в столбце
		{
			if (aarray[k][min_index] > max_value)
			{
				max_value = aarray[k][min_index];
				if (k == i)
					max_index = k;
				else
					max_index = -1;
			}
		}
	cout << "Элемент " << min_value;
	if (max_index == i)//если индекс максимального элемента совпадает с текущем индексом
		cout << " является седловой точкой";
	cout << '\n';
}
return 0;
}
