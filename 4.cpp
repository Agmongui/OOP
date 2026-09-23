#include <iostream>
#include <windows.h>

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
    cout << "Введите оценки: ";
    for (int i{}; i < rows; ++i)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << "Студент " << i + 1 << "его оценка " << j + 1 << ": ";
            cin >> matrix[i][j];
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

}