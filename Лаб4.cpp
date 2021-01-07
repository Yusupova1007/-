#include <iostream>
#include <math.h>
using namespace std;

//Метод печати массива, принимает указатель на массив и его размер
void print_array(int* aarray, int size)
{
	for (int i = 0; i < size; i++)
		cout << aarray[i] << '\t';
	cout << endl;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int size_array, delete_array;
	cout << "Введите размер массива: ";
	cin >> size_array;
	int aarray[100];
	srand(time(0));//делаем чтобы при следующим запуске получить новый набор чисел
	for (int i = 0; i < size_array; i++)
		aarray[i] = rand();	//заполняем массив случайными числами
	print_array(aarray, size_array);
	cout << "Удалите индекс: ";
	cin >> delete_array;

	for (int i = delete_array; i < size_array - 1; i++)//удаляем указанный элемент смещая его на 1 индекс
		aarray[i] = aarray[i + 1];
	size_array--;

	//Добавляем после первого четного элемента массива элемент со значением M[I - 1] + 2.
	cout << "Полученный массив: " << endl;
	for (int i = 0; i < size_array; i++)
		if (aarray[i] % 2 == 0)
		{
			i++;
			for (int j = size_array + 1; j >= i; j--)//увеличиваем массив на 1 элемент для добавления нового
				aarray[j] = aarray[j - 1];
			size_array++;
			aarray[i] = aarray[i - 1] + 2;
			break;
		}
	print_array(aarray, size_array);
	return 0;
}
