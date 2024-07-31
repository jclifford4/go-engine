#include "GoBoard.h"
#include <iostream>
#include <iomanip>

// Function to initialize the Go board
std::vector<std::vector<char>> initializeGoBoard(int size)
{
    return std::vector<std::vector<char>>(size, std::vector<char>(size, '.'));
}

// Function to display the Go board
void displayGoBoard(const std::vector<std::vector<char>> &board)
{
    int size = board.size();
    int width = 2; // Width for row numbers

    // Print column numbers
    std::cout << "     "; // Padding for row numbers
    for (int i = 0; i < size; ++i)
    {
        std::cout << (char)('A' + i) << " ";
    }
    std::cout << "\n";
    std::cout << std::endl;

    // Print rows with board content
    for (int i = 0; i < size; ++i)
    {
        std::cout << std::setw(width) << (i + 1) << "   "; // Print row number with fixed width
        for (int j = 0; j < size; ++j)
        {
            std::cout << board[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main()
{
    const int BOARD_SIZE = 19;
    std::vector<std::vector<char>> goBoard = initializeGoBoard(BOARD_SIZE);
    displayGoBoard(goBoard);

    return 0;
}
