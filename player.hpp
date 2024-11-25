#pragma once
#include "board.hpp"

class Player
{
private:
  char mark{};

protected:
  Board *board;

public:
  virtual int getInput() = 0;
  virtual void test() = 0;
};
