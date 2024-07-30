#include <iostream>
#include <string>
#include "board.h"

void drawBoard(const int size)
{
    const char columnLetters[19] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S'};

    std::cout << "  ";
    for (int i = 0; i < size; i++)
    {
        std::cout << "  ";
        std::cout << columnLetters[i];
        std::cout << "  ";
    }
    std::cout << "\n\n";

    for (int row = 0; row < size + 1; row++)
    {
        if (row < size)
        {
            std::cout << row + 1;
            std::cout << "  ";
        }

        for (int col = 0; col < size + 1; col++)
        {
        }
        std::cout << "\n\n";
    }
}

int main()
{
    drawBoard(9);

    return 0;
}
