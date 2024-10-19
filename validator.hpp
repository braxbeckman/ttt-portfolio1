#pragma once
#include "board.hpp"

class Validator
{
private:
  Board *board;

public:
  int getInput();
  bool getReplay();
  Validator(Board *board);
};
