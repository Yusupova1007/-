#include <iostream>

using namespace std;
//Функция нахождения факториала
int factorial(int n)
{
	int F = 1;
	for (int i = 1; i <= n; ++i)
	{
		F *= i;
	}
	return F;
}

int main() {
	setlocale(LC_ALL, "Russian");
	double a = 0.1, b = 1, k = 10, n = 25, pi = 3.14, SN, SE, s, dx, Y, X, e = 0.0001;
	dx = ((b - a) / k);
	//Цикл выполняется от 0,1 до 1
	for (X = a; X <= b; X += dx) {
		SN = 0; SE = 0; s = 0;
		// Вычисляем сумму для заданного n
		for (int i = 1; i <= n; i++)
			SN += cos(i * pi / 4) * (pow(X, i)) / factorial(i);
		int i = 1;
		// Вычисляем сумму для заданной точности
		do {
			s = cos(i * pi / 4) * (pow(X, i)) / factorial(i);
			SE += s;
			i++;
		} while (fabs(SE) < e);
		// Вычисляем точное значение функции
		Y = (pow(e, X * cos(pi / 4)) * cos(X * sin(pi / 4)));
		//Вывод результатов
		cout << " X = " << X << "     " << " SN = " << SN << "     " << "  SE = " << SE << "     " << " Y = " << Y << endl;
	}
	return 0;
}