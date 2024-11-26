#pragma once
#include "board.hpp"
#include <string>

class Player
{
private:
  char mark{};
  std::string archetype{};

protected:
  Board *board;

public:
  virtual int getInput() = 0;
  virtual void test() = 0;
  virtual char getMark() = 0;
  virtual std::string getArchetype() = 0;
};
