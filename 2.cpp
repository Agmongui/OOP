#include <iostream>
#include <windows.h>

using namespace std;

void fillArray(int* arr, int size)
{
    cout << "Введите элементы массива:\n";
    for (int index{}; index < size; index++)
    {
        cin >> arr[index];
    }
}

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    int size{};
    cout << "Введите размер массива:";
    cin >> size;

    return 0;
}