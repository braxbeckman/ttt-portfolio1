#include "board.hpp"
#include <iostream>

using namespace std;

void Board::takeTurn(int pos, char mark)
{
  int row{(pos - 1) / 3};
  int column{(pos - 1) % 3};

  cells[row][column] = mark;
}

char Board::getMark(int row, int column)
{
  return cells[row][column];
}
