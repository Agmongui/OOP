#include <iostream>
#include <windows.h>


void fillArray(int (&arr)[10])
{
    std::cout << "Введите 10 чисел ->";

    for (int& x : arr)
    {
        std::cin >> x;
    }
}

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    int arr[10];
    fillArray(arr);
}