#pragma once
#include "board.hpp"
#include "player.hpp"

class Swarm : public Player
{
private:
  char mark{};

public:
  Swarm(Board *board);
  int getInput() override;
  void test() override;
  char getMark() override;

};
