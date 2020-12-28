#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	double a, b, c, d, e, f, g, i;
	a = 1000;
	b = 0.0001;
	//Вычисление числителя
	c = pow((a - b), 3);
	d = pow(a, 3);
	e = 3 * a * (pow(b, 2));
	//Вычисление знаменателя
	f = pow(b, 3);
	g = 3 * (pow(a, 2)) * b;
	//Значение выражения
	i = (c - (d - e)) / f - g;
	cout << "Результат выражения при double=" << i << endl;
}