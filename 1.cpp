#include <iostream>
#include <windows.h>


void fillArray(int (&arr)[10])
{
    std::cout << "Введите 10 чисел ->\n";

    for (int& x : arr)
    {
        std::cin >> x;
    }
}
void printArray(const int (&arr)[10])
{
    for (auto x : arr)
    {
        std::cout<< x << " ";
    }
}

void swapElements(int (&arr)[10], int index1, int index2)
{
    std::swap(arr[index1], arr[index2]);
}

void multipByTwo(int (&arr)[10])
{
    for (int& x : arr)
    {
        x = x * 2;
    }
}


int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    int arr[10];
    fillArray(arr);

    std::cout << "Массив -> ";
    printArray(arr);

    std::cout << std::endl;

    swapElements(arr, 0, 9);
    std::cout << "Поменялись местами -> ";
    printArray(arr);

    std::cout << std::endl;

    multipByTwo(arr);
    std::cout << "Умножилось на 2 -> ";
    printArray(arr);
    
    return 0;
}