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

void printSafe(const SafeArray& arr)
{
    for (int index{}; index < arr.size; index++)
    {
        cout << arr.data[index] << ' ';
    }
    cout << '\n';
}

int& getElement(SafeArray& arr, int index)
{
    if (index < 0 || index >= arr.size)
    {
        cout << "Индекс вышел за границы";
        static int a = 0;
        return a;
    }

    return arr.data[index];  
}


int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    int size{};
    cout << "Введи размер массива: ";
    cin >> size;

    SafeArray arr = createArray(size);

    cout << "Введите элементы массива:\n";

    for (int index{}; index < arr.size; index++)
    {
        cin >> arr.data[index];
    }
    cout << "Массив: ";
    printSafe(arr);


    delete[] arr.data;
    return 0;
}