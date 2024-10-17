#pragma once

class Board
{
private:
  char cells[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};

public:
  void takeTurn(int pos, char mark);
  void clearBoard();
  char getMark(int row, int column);
};
