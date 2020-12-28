#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	int m, n, a;
	//Ввод начальных значений m,n
	cout << "Введите m: " << endl;
	cin >> m;
	cout << endl;
	cout << "Введите n: " << endl;
	cin >> n;
	bool b, c;
	//Вычисление значений выражений и вывод их на экран
	a = (m - ++n);
	b = (++m > --n);
	c = (--n < ++m);
	cout << endl;
	cout << "Значение выражения m-++n=" << a << endl;
	cout << "Значение выражения ++m>--n=" << b << endl;
	cout << "Значение выражения --n<++m=" << c << endl;
	cout << "m=" << m << "  " << "n=" << n << endl;
	return 0;
}