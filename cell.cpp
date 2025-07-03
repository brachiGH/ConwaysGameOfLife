#include <iostream>
#include "cell.h"


void draw_cell(int row, int col, const char symb)
{
    std::cout << "\x1b[" << row + 1 << ";" << col + 1 << "H";
    std::cout << symb;
};