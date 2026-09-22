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

void reSizeArray(SafeArray& arr, int M)
{
    if (M == arr.size)
    {
        return;
    }

    if (M < arr.size)
    {
        cout << "Удаленные элементы: ";
        for (int i = M; i < arr.size; i++)
        {
            cout << arr.data[i] << ' ';
        }
    
    cout << endl;

    int* newData = new int[M];
    for (int i = 0; i < M; i++)
    {
        newData[i] = arr.data[i];
    }

    delete[] arr.data;
    arr.data = newData;
    arr.size = M;

    } else {

        int* newData = new int[M];

        for (int i = 0; i < arr.size; i++)
        {
            newData[i] = arr.data[i]; // копирую старые элементы
        }

        for (int i = arr.size; i < M; i++)
        {
            newData[i] = 0;
        }

        delete[] arr.data;
        arr.data = newData;
        arr.size = M;

    }
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

    getElement(arr, 2) = 999;
    cout << "Массив после изменения элемента: ";
    printSafe(arr);

    int M = 0;
    cout << "Введите новый размер массива: ";
    cin >> M;
    reSizeArray(arr, M);
    cout << "После изменения размера: ";
    printSafe(arr);

    delete[] arr.data;
    return 0;
}