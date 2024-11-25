#pragma once
#include "board.hpp"
#include "player.hpp"

class Swarm : public Player
{
private:
  char mark{};

public:
  Swarm(Board *board);
  int getInput();
  void test();
};
