#pragma once
#include "board.hpp"
#include <string>

class Console
{
private:
  Board *board{};
  std::string vertSeparator{" | "};
  std::string horizSeparator{"\n-----------\n"};
  std::string emptySpacer{" "};

public:
  Console(Board *board);
  std::string displayBoard();
};
