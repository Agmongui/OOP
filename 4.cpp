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

}