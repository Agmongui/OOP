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


int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    int arr[10];
    fillArray(arr);

    std::cout << "Массив -> ";
    printArray(arr);

    std::cout << std::endl;
    
}