#include "Rectangle.h"
#include "Figure.h"
#include <iostream>
#include <io.h>
#include <fcntl.h>

using namespace std;

int main()
{
    _setmode(_fileno(stdout), _O_U16TEXT);

    Rectangle first(5, 3);

    wcout << L"Количество фигур: "
          << Figure::getFigureCount() << endl;

    return 0;
}