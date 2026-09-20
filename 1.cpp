#include <iostream>
#include <windows.h>

/**
 * @brief Функция заполняет массив случайными числами
 * @param arr Ссылка на массив из 10 чисел
 */ 
void fillArray(int (&arr)[10])
{
    std::cout << "Введите 10 чисел ->\n";

    for (int& x : arr)
    {
        std::cin >> x;
    }
}

/**
 * @brief Функция выводит массив на экран
 * @param arr Ссылка на массив из 10 чисел
 * @details Функция перебирает элементы массива с помощью range-based
 */ 
void printArray(const int (&arr)[10])
{
    for (auto x : arr)
    {
        std::cout<< x << " ";
    }
}

/**
 * @brief Функция меняет местами 2 элемента массива
 * @param arr Ссылка на массив из 10 чисел
 * @param index1 Индекс 1 элемента
 * @param index2 Индекс 2 элемента
 * @details Функция swap меняет местами значения двух переменных
 */ 
void swapElements(int (&arr)[10], int index1, int index2)
{
    std::swap(arr[index1], arr[index2]);
}

/**
 * @brief Функция умножает элементы массива на 2
 * @param arr Ссылка на массив из 10 чисел
 */ 
void multipByTwo(int (&arr)[10])
{
    for (int& x : arr)
    {
        x = x * 2;
    }
}

/**
 * @brief Выполняет программу
 * @details Функция заполняет массив,выводт его,меняет местами элементы и умножает на 2
 * @return 0 при успешном завершении
 */ 
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