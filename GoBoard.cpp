#include "GoBoard.h"
#include <algorithm>
#include <cctype>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>

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

int convertCharToNumber(char letter)
{
    int asciiValue = static_cast<int>(letter);
    return asciiValue;
}

bool placeWhitePlayerMarkerOnGoBoard(int row, int col, std::vector<std::vector<char>> &goBoard)
{

    try
    {

        if (row < goBoard.size() && row >= 0 && col < goBoard[0].size() && col >= 0)
        {
            goBoard[row][col] = 'o';
            return true;
        }
        else
            throw std::out_of_range("Coordinates out of range of GoBoard!");
    }
    catch (std::out_of_range &e)
    {
        std::cerr << e.what() << std::endl;
        return false;
    }
}

bool placeBlackPlayerMarkerOnGoBoard(int row, int col, std::vector<std::vector<char>> &goBoard)
{
    try
    {

        if (row < goBoard.size() && row >= 0 && col < goBoard[0].size() && col >= 0)
        {
            goBoard[row][col] = 'x';
            return true;
        }
        else
            throw std::out_of_range("Coordinates out of range of GoBoard!");
    }
    catch (std::out_of_range &e)
    {
        std::cerr << e.what() << std::endl;
        return false;
    }
}

int convertStringNumberToInteger(std::string str, int boardSize)
{
    // Convert the first value to an integer
    try
    {
        int firstNumber = std::stoi(str) - 1;

        if (firstNumber > boardSize - 1 || firstNumber < 0)
            throw std::out_of_range("");
        // std::cout << "The first number is: " << firstNumber << std::endl;
        return firstNumber;
    }
    catch (const std::invalid_argument &e)
    {
        std::cerr << "Invalid argument for the first number: " << e.what() << std::endl;
        return -1;
    }
    catch (const std::out_of_range &e)
    {
        std::cerr << "First value is not in range!: " << e.what() << std::endl;
        return -1;
    }
}

int convertStringLetterToInteger(std::string str, int boardSize)
{
    // Convert the second value (capital letter) to a number
    try
    {
        std::string letterString = str;
        if (letterString.length() == 1)
        {
            if (!std::isupper(letterString[0]))
            {
                // Convert the entire string to uppercase
                std::transform(letterString.begin(), letterString.end(), letterString.begin(), [](unsigned char c)
                               { return std::toupper(c); });
            }

            char letter = letterString[0];
            int letterNumber = letter - 'A'; // Convert letter to position (A=1, B=2, ..., Z=26)

            if (letterNumber < 0 || letterNumber > boardSize)
                throw std::out_of_range("Second value is not in range!");

            return letterNumber;
        }
        else
            throw std::invalid_argument("Invalid second value");
    }
    catch (const std::out_of_range &e)
    {
        std::cerr << e.what() << std::endl;
        return -1;
    }
    catch (...)
    {
        return -1;
    }
}

int main()
{
    const int BOARD_SIZE = 19;
    std::vector<std::vector<char>> goBoard = initializeGoBoard(BOARD_SIZE);
    displayGoBoard(goBoard);
    bool isBlackTurn = true;

    while (true)
    {
        std::string input;
        std::cout << "Enter comma-separated values: ";
        std::getline(std::cin, input);
        // Split the input by commas
        std::vector<std::string> values;
        std::string::size_type start = 0, end;

        while ((end = input.find(',', start)) != std::string::npos)
        {
            values.push_back(input.substr(start, end - start));
            start = end + 1;
        }
        values.push_back(input.substr(start)); // Add the last substring

        if (values.size() < 2)
        {
            std::cerr << "Not enough values provided!" << std::endl;
            return 1;
        }

        int row = convertStringNumberToInteger(values[0], BOARD_SIZE);
        int col = convertStringLetterToInteger(values[1], BOARD_SIZE);

        if (row == -1 || col == -1)
        {
            std::cout << "Not a valid coordinate. Try again!";
            continue;
        }

        if (isBlackTurn)
        {
            placeBlackPlayerMarkerOnGoBoard(row, col, goBoard);
            isBlackTurn = false;
        }
        else
        {
            placeWhitePlayerMarkerOnGoBoard(row, col, goBoard);
            isBlackTurn = true;
        }

        displayGoBoard(goBoard);
    }

    return 0;
}
