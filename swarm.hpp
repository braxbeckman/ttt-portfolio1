#pragma once
#include "board.hpp"
#include "player.hpp"
#include <string>

class Swarm : public Player
{
private:
  char mark{};
  std::string archetype{"swarm"};

public:
  Swarm(Board *board, char mark);
  int getInput() override;
  void test() override;
  char getMark() override;
  std::string getArchetype() override;

};
