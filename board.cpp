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

void Board::clearBoard()
{
  int counter{1};
  for (int i = 0; i < 3; i++)
  {
    for (int k = 0; k < 3; k++)
    {
      cells[i][k] = to_string(counter).c_str()[0];
      counter++;
    }
  }
}
