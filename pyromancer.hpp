#pragma once
#include "player.hpp"
#include <string>

class Pyromancer : public Player
{
private:
  char mark{};
  std::string archetype{"pyro"};
  bool moveUsed{false};

public:
  Pyromancer(Board *board, char mark);
  void fireball();
  int getInput() override;
  void test() override;
  char getMark() override;
  std::string getArchetype() override;

};
