#include <iostream>
#include <windows.h>
#include <string>

using namespace std;

int** allocateMatrix(int rows, int cols)
{
    int** matrix{new int*[rows]{}};
    for (int row{}; row < rows; row++)
    {
        matrix[row] = new int[cols]{};
    }
    return matrix;
}

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

void printMatrix(int** matrix, int rows, int cols, bool showBorders = true, string title = "Matrix")
{
    cout << title << '\n';

    const int cellWidth = 3;

    if (showBorders)
    {

        const int borderLen = 1 + cols * cellWidth;

        for (int symbol{}; symbol < borderLen; symbol++)
            cout << '*';
        cout << '\n';

        for (int row{}; row < rows; row++)
        {
            cout << '*';
            for (int col{}; col < cols; col++)
            {
                cout << ' ' << matrix[row][col];

                int digits = to_string(matrix[row][col]).size();
                for (int s{}; s < cellWidth - digits - 1; s++)
                    cout << ' ';
            }
            cout << "*\n";
        }

        for (int symbol{}; symbol < borderLen; symbol++)
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

    matrix = nullptr;

    return 0;

}