#ifndef GOBOARD_H
#define GOBOARD_H

#include <vector>

std::vector<std::vector<char>> initializeBoard(int size);

void displayGoBoard(const std::vector<std::vector<char>> &board);

#endif
