#pragma once
#include "board.hpp"
#include "player.hpp"
#include <string>

enum state
{
  STOPPED,
  PLAYING,
  WON,
  TIE,
};

class GameState
{
private:
  char winner{};
  Board *board{};
  // std::string isWinning{"false"};
  state state{STOPPED};

public:
  GameState(Board *board);
  enum state checkStatus(Player *player);
  enum state checkStatus();
  void setStatus(std::string in);
  char getWinner();
};
