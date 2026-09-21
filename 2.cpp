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

void process(int*& arr, int size)
{
    int Neg1 = -1;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] < 0)
        {
            Neg1 = i;
            break;
        }
    }

    if (Neg1 != -1)
    {
        int newSize = Neg1;

        int* newArr = new int[newSize];

        for (int i = 0; i < newSize; i++)
        {
            newArr[i] = arr[i];
        }

        delete[] arr;
        arr = newArr;
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

    int newN = N;
    for (int i = 0; i < N; i++)
    {
        if (arr[i] < 0)
        {
            newN = i;
            break;
        }
    }

    process(arr, N);

    cout << "Массив после обработки: ";
    for (int i = 0; i < newN; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";

    delete[] arr;

    return 0;
}