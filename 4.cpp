#include <iostream>
#include <windows.h>
#include <string>

using namespace std;

/**
 * @brief Выделяет память под двумерный динамический массив
 * @param rows Количество строк (студентов)
 * @param cols Количество столбцов (оценок)
 * @return Указатель на созданный двумерный массив
 */
int** allocateMatrix(int rows, int cols)
{
    int** matrix{new int*[rows]{}};
    for (int row{}; row < rows; row++)
    {
        matrix[row] = new int[cols]{};
    }
    return matrix;
}

/**
 * @brief Заполняет двумерный массив оценками с клавиатуры
 * @param matrix Указатель на двумерный динамический массив
 * @param rows Количество строк (студентов)
 * @param cols Количество столбцов (оценок)
 */
void fillMatrix(int** matrix, int rows, int cols)
{
    cout << "Введите оценки:\n";
    
    for (int i{}; i < rows; ++i)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << "Студент " << i + 1 << " его оценка " << j + 1 << ": ";
            cin >> matrix[i][j]; 
        }
    }
}

/**
 * @brief Выводит двумерный массив на экран
 * @param matrix Указатель на двумерный динамический массив
 * @param rows Количество строк массива
 * @param cols Количество столбцов массива
 * @param showBorders Определяет, нужно ли выводить рамку
 * @param title Заголовок, выводимый перед массивом
 */
void printMatrix(int** matrix, int rows, int cols, bool showBorders = true, string title = "Matrix")
{
    cout << title << '\n';

    const int cellWidth = 3; /// Ширина одной ячейки: пробел + цифра + пробел

    if (showBorders)
    {

        const int borderLen = 1 + cols * cellWidth; /// Длина верхней и нижней горизонтальной линии

        for (int symbol{}; symbol < borderLen; symbol++) // Верхняя граница
            cout << '*';
        cout << '\n';

        for (int row{}; row < rows; row++) // Строки с числами
        {
            cout << '*';
            for (int col{}; col < cols; col++)
            {
                cout << ' ' << matrix[row][col];

                int digits = to_string(matrix[row][col]).size(); // Добиваем пробелами до ширины ячейки
                for (int s{}; s < cellWidth - digits - 1; s++)
                    cout << ' ';
            }
            cout << "*\n";
        }

        for (int symbol{}; symbol < borderLen; symbol++) // Нижняя граница
            cout << '*';
        cout << '\n';
    }
    else
    {
        for (int row{}; row < rows; row++)
        {
            for (int col{}; col < cols; col++)
            {
                cout << matrix[row][col] << ' ';
            }
            cout << '\n';
        }
    }
}

/**
 * @brief Освобождает память, занятую двумерным массивом
 * @details Сначала освобождается память каждой вложенной строки затем — массива указателей
 * @param matrix Указатель на двумерный динамический массив
 * @param rows Количество строк массива
 */
void freeMatrix(int** matrix, int rows)
{
    for (int row{}; row < rows; row++)
    {
        delete[] matrix[row];
    }
    delete[] matrix;
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

    int rows{};
    int cols{};

    cout << "Кол-во студентов: ";
    cin >> rows;

    cout << "Кол-во оценок: ";
    cin >> cols;

    int** matrix {allocateMatrix(rows, cols)};
    fillMatrix(matrix, rows, cols);

    printMatrix(matrix, rows, cols);

    printMatrix(matrix, rows, cols, true, "\nТаблица оценок");

    printMatrix(matrix, rows, cols, false, "\nОценки без рамки");

    freeMatrix(matrix, rows);
    matrix = nullptr;

    return 0;
}