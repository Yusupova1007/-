#pragma warning (disable : 4996)
#include <iostream>
#include <windows.h>
#include <algorithm>

using namespace std;

//Печать фамилии, адреса и возраста
void PrintCart(const char* lastname = "Неизвестно",
	const char* address = "Неизвестно", int age = 0)
{
	cout << "Фамилия: " << lastname << endl;
	cout << "Адрес: " << address << endl;
	cout << "Возраст: ";
	if (age == 0)
		cout << "Неизвестно" << endl;
	else
		cout << age << endl;
	cout << endl;
}
//Нахождение максимального из элементов в списке параметров, стоящих на нечетных местах
int maxs(int a, ...)
{
	int* ptr = &a;
	ptr++;
	int result = INT32_MAX * -1;
	while (a != 0)
	{
		if (*ptr > result && a % 2 != 0)
			result = *ptr;
		a--;
		ptr++;
	}
	return result;
}
//Сортировка массива методом простого выбора
void sort(int* array, int count)
{
	for (int i = 0; i < count - 1; i++)
	{
		int IndexMin = i;

		for (int j = i + 1; j < count; j++)
		{
			if (array[j] < array[IndexMin])
				IndexMin = j;
		}
		swap(array[i], array[IndexMin]);
	}
}
//Печать массива
void Print(int* array, int count)
{
	for (int i = 0; i < count; ++i)
		cout << array[i] << '\t';
	cout << endl;
}
//Метод половинного деления0, 25x3 + x - 1, 2502 = 0
double f(double x)
{
	return 0.25 * pow(x, 3) + x - 1.2502;
}
void HalfDivision()
{
	double a = 0, b = 2.0, e = 1.0001, x;// объявление переменных
	while (fabs(a - b) >= e) // цикл
	{
		// проверка на разные знаки по концам отрезка
		if ((f(a) > 0 && f((a + b) / 2) < 0) || (f(a) < 0 && f((a + b) / 2) > 0))
			b = (a + b) / 2;
		else
			if ((f((a + b) / 2) > 0 && f(b) < 0) || (f((a + b) / 2) < 0 && f(b) > 0))
				a = (a + b) / 2;
			else
			{
				printf("! Нет корней !");
				return;
			}
	}
	x = (a + b) / 2;// вычисление х после завершения цикла
	printf("x=%f", x); // вывод результатов
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "Задание 1" << endl;
	PrintCart("Юсупова", "Геологов, 9", 20);
	PrintCart();
	PrintCart("Зеляева", "Мильчакова, 7", 25);
	cout << "Задание 2" << endl;
	cout << "Элементы: 7, 2, 5, 7, 8, 9, 500, 1" << endl;
	cout << "Максимальный элемент: " << maxs(7, 2, 5, 7, 8, 9, 500, 1) << endl;
	cout << endl;
	cout << "Задание 3" << endl;
	int array[20];
	srand(time(0));
	for (unsigned int i = 0; i < 20; i++)
		array[i] = rand();
	cout << "Не сортированный массив" << endl;
	Print(array, 20);
	sort(array, 20);
	cout << "Сортированный массив" << endl;
	Print(array, 20);
	cout << endl;
	cout << "Задание 4" << endl;
	HalfDivision();
	cout << endl;
	return 0;
}