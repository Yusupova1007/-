#include <iostream>
#include <complex>

using namespace std;
//Объявление функции, вычисляющей разность вещественных чисел
float Raznost_(float a, float b)
{
	return a - b;;
}
//Объявление функции, вычисляющей разность комплексных чисел
complex<double>Raznost_(complex<double>a, complex<double>b)
{
	return  a - b;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	float a, b;
	cout << "Введите первое вещественное число: " << endl;
	cin >> a;
	cout << "Введите  второе вещественное число: " << endl;
	cin >> b;
	cout << "Разность вещественных чисел: ";  //Разность вещественных чисел и вывод результата
	cout << Raznost_(a, b) << endl;

	complex <double> c1(52.0, 9.0); //Первое комплексное число вида: 52+9i
	complex <double> c2(7.0, 8.0); //Второе комплексное число вида: 7+8i
	cout << "Первое комплексное число: " << c1 << endl;
	cout << "Второе комплексное число: " << c2 << endl;
	cout << "Разность комплексных чисел: "; //Разность комплексных чисел и вывод результата
	cout << Raznost_(c1, c2) << endl;
	return 0;
}
