#include <iostream>
#include <windows.h>

using namespace std;

struct SafeArray 
{
    int* data;
    int size;
};

SafeArray createArray(int size)
{
    SafeArray arr;
    arr.data = new int[size]{};
    arr.size = size;
    return arr;
}

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    int size{};
    cout << "Введи размер массива: ";
    cin >> size;

    SafeArray arr = createArray(size);

    delete[] arr.data;
    return 0;
}