#pragma once
#include "board.hpp"
#include <string>


class GameState
{
private:
  Board *board{};
  std::string isWinning{"false"};

public:
  GameState(Board *board);
  std::string checkStatus();
  void setStatus(std::string in);
};