#include <iostream>
#include <windows.h>

using namespace std;

/**
 * @struct SafeArray
 * @brief Хранит динамический массив и количество его элементов
 */
struct SafeArray 
{
    int* data;
    int size;
};

/**
 * @brief Функция создаёт безопасный динамический массив
 * @param size Размер создаваемого массива
 * @return Структура SafeArray с выделенной памятью и обнулёнными элементами
 * @details Функция выделяет память под size элементов, обнуляет их и сохраняет адрес и размер в структуре SafeArray
 */ 
SafeArray createArray(int size)
{
    SafeArray arr;
    arr.data = new int[size]{};
    arr.size = size;
    return arr; // возвращает структуру
}

/**
 * @brief Функция выводит элементы массива на экран
 * @param arr Константная ссылка на структуру SafeArray
 */ 
void printSafe(const SafeArray& arr)
{
    for (int index{}; index < arr.size; index++)
    {
        cout << arr.data[index] << ' ';
    }
    cout << '\n';
}

/**
 * @brief Функция возвращает ссылку на элемент массива
 * @param arr Ссылка на структуру SafeArray
 * @param index Индекс требуемого элемента
 * @return Ссылка на элемент массива и на статическую переменную-заглушку
 */ 
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

/**
 * @brief Функция изменяет размер динамического массива
 * @param arr Ссылка на изменяемую структуру SafeArray
 * @param M Новый размер массива
 */ 
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

/**
 * @brief Выполняет программу
 * @details Функция запрашивает размер массива, создаёт SafeArray, заполняет
 * его, выводит, демонстрирует безопасный доступ к элементу через
 * getElement, изменяет размер массива и освобождает память
 * @return 0 при успешном завершении
 */
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