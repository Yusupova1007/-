#include <iostream>

using namespace std;
int min(int a, ...)
{
    setlocale(LC_ALL, "Russian");
    int* ptr = &a;
    ptr++;
    int result = INT32_MAX;
    while (a != 0)
    {
        if (*ptr < result)
            result = *ptr;
        a--;
        ptr++;
    }
    return result;
}
int main()
{
    int p = min(5, 16, 17, 18, 19, 20);
    cout << "Минимальный элемент: ";
    cout << p << endl;
    p = min(10, 12, 13, 6, 25, 9, 8, 34, 15, 24, 7);
    cout << "Минимальный элемент: ";
    cout << p << endl;
    cout << "Минимальный элемент: ";
    p = min(12, 13, 25, 17, 11, 16, 19, 10, 12, 18, 15, 24, 35);
    cout << p << endl;
    return 0;
}
