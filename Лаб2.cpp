#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	int n = 1;
	double a;
	double summ = 0;
	do
	{
		a = 1 / pow(2, n) + 1 / pow(3, n);
		summ += a;
		n++;
	} while (a > 0.0001);
	cout << "Сумма ряда:" << endl;
	cout << summ << endl;
	return 0;
}