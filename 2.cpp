#include <iostream>
#include <windows.h>

using namespace std;

void fillArray(int* arr, int N)
{
    cout << "Введите элементы массива: ";
    for (int index{}; index < N; index++)
    {
        cin >> arr[index];
    }
}

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    int N{};
    cout << "Введите размер массива N: ";
    cin >> N;

    int* arr = new int[N];
    fillArray(arr, N);

    cout << "Ваш массив: ";
    for (int i = 0; i < N; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";

    delete[] arr;

    return 0;
}